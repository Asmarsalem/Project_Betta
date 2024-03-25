// Copyright 2021-2022 Mickael Daniel. All Rights Reserved.


#include "Components/UAC_Evilios.h"

#include "AbilitySystemInterface.h"
#include "MainAttributes.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"




// Called when the game starts
void UUAC_Evilios::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


void UUAC_Evilios::AutoAim()
{
	
	if(IAbilitySystemInterface* ability=Cast<IAbilitySystemInterface>(GetOwner()->GetInstigator()))
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
			SpawnActor(AttackRange);
			GetWorld()->GetTimerManager().SetTimer(AutoAimOutHandle,TimerDelegate,AttackSpeed,false);
					
		};
	};
}

void UUAC_Evilios::SpawnActor(float AttackRange)
{
	TArray<AActor*> OutActors;
	UGameplayStatics::GetAllActorsOfClass(this,EnemyClass,OutActors);
	if (OutActors.Num() > 0)
	{
		if (APawn* LocalPawn  = GetOwner()->GetInstigator())
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
					ArrowType(ArrowTransform,LocalPawn);
				}
			}
		}
	}
}

void UUAC_Evilios::ArrowType(FTransform ArrowTransform,APawn* LocalPawn)
{
	if(UWorld* World=GetWorld())
	{
		TSubclassOf<AActor> ArrowType=RecochetArrow;
		if(CurrentArrowIndex>=MultiArrowsIndex)
		{
			IAbilitySystemInterface* AbilitySystemInterface=Cast<IAbilitySystemInterface>(GetOwner()->GetInstigator());
			AbilitySystemInterface->GetAbilitySystemComponent()->TryActivateAbilityByClass(MultiArrow,true);
			CurrentArrowIndex=0;
			return;
		}
		CurrentArrowIndex++;
		FTimerDelegate const& InDelegate=FTimerDelegate::CreateLambda([this]()
		{
			if (this && IsValid(this))
			{
				GetWorld()->GetTimerManager().ClearTimer(ArrowTypeHandle);
			}
		});
		if (UKismetSystemLibrary::K2_IsTimerActiveHandle(World,ArrowTypeHandle))
		{
			ArrowType=SingleArrow;
		}
		else
		{
			World->GetTimerManager().SetTimer(ArrowTypeHandle,InDelegate,RecochetCoolDown,false);
		}
		FActorSpawnParameters SpawnParameters;
		SpawnParameters.Instigator=LocalPawn;
		if(ArrowType)
		{
			World->SpawnActor<AActor>(ArrowType, ArrowTransform,SpawnParameters);
		}
	}
}


