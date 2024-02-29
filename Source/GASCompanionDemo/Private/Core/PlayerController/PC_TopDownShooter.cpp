// Copyright 2021-2022 Mickael Daniel. All Rights Reserved.


#include "Core/PlayerController/PC_TopDownShooter.h"

#include "AbilitySystemComponent.h"
#include "AbilitySystemInterface.h"
#include "MainAttributes.h"
#include "GameFramework/Character.h"
#include "GameFramework/PlayerStart.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetArrayLibrary.h"
#include "Kismet/KismetMathLibrary.h"

void APC_TopDownShooter::spawnCharacter(TSubclassOf<ACharacter> characterClass)
{
	
	// Set Local Var
	TArray<AActor*> FoundActors;
	const TSubclassOf<APlayerStart>ActorClass ;
	// Set Default Spawn Location
	const FVector defaultLocationFVector(0.0f,0.0f,240.0f);
	const FRotator defaultRotation(0.0f,-180.0f,0.0f);
	const FVector defaultScale(1.0f,1.0f,1.0f);
	FTransform spawnLocationTransform (defaultRotation,defaultLocationFVector,defaultScale);
	// Get All Actor Of Class APlayerStart
	UGameplayStatics::GetAllActorsOfClass(this,ActorClass,FoundActors);
	// If The APlayerStart Is Not Empty
	if (FoundActors.Num() > 0)
	{
		// Set Spawn Location Based On FoundActors
		const int32 randomIndex=FMath::RandRange(0,FoundActors.Num()-1);
		const AActor* selectedActor = FoundActors[randomIndex];
		spawnLocationTransform.SetLocation(selectedActor->GetActorLocation());
	}
	
	//Spawn Actor
	FActorSpawnParameters spawnParam;
	spawnParam.Owner=this;
	spawnParam.Instigator=GetInstigator();
	ACharacter* character=GetWorld()->SpawnActor<ACharacter>(characterClass,spawnLocationTransform,spawnParam);
	APawn* pawnCharacter = Cast<APawn>(character);
	if(character)
	{
		Possess(pawnCharacter);
	}
	
	
}

void APC_TopDownShooter::AutoAttack(TSubclassOf<AActor> ArrowType,float InRate)
{
	const  TArray<TEnumAsByte<EObjectTypeQuery>> ObjectTypes={UEngineTypes::ConvertToObjectType(ECC_Pawn)};
	FHitResult HitResult;
	GetHitResultUnderCursorForObjects(ObjectTypes,true,HitResult);
	if(!UKismetSystemLibrary::K2_IsValidTimerHandle(InOutHandle))
	{
		if(ACharacter* Char=Cast<ACharacter>(HitResult.GetActor()))
		{
			FTimerDelegate InDelegate=FTimerDelegate::CreateLambda([this](){GWorld->GetTimerManager().ClearTimer(InOutHandle);});
			GWorld->GetTimerManager().SetTimer(InOutHandle,InDelegate,InRate,false);
			FVector PawnLocation=GetPawn()->GetActorLocation();
			FTransform ArrowTransform;
			ArrowTransform.SetLocation(PawnLocation);
			FRotator ArrowRotation= UKismetMathLibrary::FindLookAtRotation(PawnLocation,HitResult.Location);
			ArrowTransform.SetRotation(FQuat(ArrowRotation));
			ArrowTransform.SetScale3D(FVector(10.f, 10.f, 10.f)); // Set scale
			FActorSpawnParameters SpawnParameters;

			AActor* SpawnedActor = GetWorld()->SpawnActor<AActor>(ArrowType, ArrowTransform);
		}
	}
}

void APC_TopDownShooter::AutoAim(TSubclassOf<AActor> EnemyClass,TSubclassOf<AActor> ArrowType )
{
	if(IAbilitySystemInterface* ability=Cast<IAbilitySystemInterface>(GetPawn()))
	{
		float AttackSpeed = ability->GetAbilitySystemComponent()->GetNumericAttribute(UMainAttributes::GetAttackSpeedAttribute());
		float AttackRange = ability->GetAbilitySystemComponent()->GetNumericAttribute(UMainAttributes::GetAttackRangeAttribute());
		if(!UKismetSystemLibrary::K2_IsValidTimerHandle(AutoAimOutHandle))
		{
			FTimerDelegate TimerDelegate=FTimerDelegate::CreateLambda([this]()
			{
				if (this && IsValid(this))
				{
					GetWorld()->GetTimerManager().ClearTimer(AutoAimOutHandle);
				}
			});
			
			TArray<AActor*> OutActors;
			UGameplayStatics::GetAllActorsOfClass(this,EnemyClass,OutActors);
			if (OutActors.Num() > 0)
			{
				if (APawn* LocalPawn  = GetPawn())
				{
					float Distance;
					FVector PawnLocation = LocalPawn->GetActorLocation();
					AActor* NearestActor = UGameplayStatics::FindNearestActor(PawnLocation,OutActors,Distance);
					if(NearestActor)
					{
						if(Distance<AttackRange)
						{
							FTransform ArrowTransform;
							FRotator ArrowRotation= UKismetMathLibrary::FindLookAtRotation(PawnLocation,NearestActor->GetActorLocation());
							ArrowTransform.SetRotation(FQuat(ArrowRotation));
							ArrowTransform.SetLocation(PawnLocation);
							FActorSpawnParameters SpawnParameters;
							SpawnParameters.Instigator=LocalPawn,
							GetWorld()->SpawnActor<AActor>(ArrowType, ArrowTransform,SpawnParameters);
							GetWorld()->GetTimerManager().SetTimer(AutoAimOutHandle,TimerDelegate,AttackSpeed,false);
						}
					}
				}
			}
		}
	};
}
