// Copyright 2021-2022 Mickael Daniel. All Rights Reserved.


#include "Components/UAC_Mage.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Kismet/GameplayStatics.h"



// Called when the game starts
void UUAC_Mage::BeginPlay()
{
	Super::BeginPlay();
	AutoAttack();
	// ...
	
}

void UUAC_Mage::AutoAttack()
{
	if(!UKismetSystemLibrary::K2_IsValidTimerHandle(AutoAimOutHandle))
	{
		FTimerDelegate TimerDelegate=FTimerDelegate::CreateLambda([this]()
		{
			if (this && IsValid(this))
			{
				GetWorld()->GetTimerManager().ClearTimer(AutoAimOutHandle);
			}
		});
		GetWorld()->GetTimerManager().SetTimer(AutoAimOutHandle,TimerDelegate,4.f,false);
					
	};
}

void UUAC_Mage::FindTheNearetActor()
{
	if(!UKismetSystemLibrary::IsValidClass(FireSlashType)|| !AiType){return;}
	TArray<AActor*> OutActors;
	UGameplayStatics::GetAllActorsOfClass(this,AiType,OutActors);
	if (APawn* LocalPawn  = GetOwner()->GetInstigator())
	{
		FVector PawnLocation = LocalPawn->GetActorLocation();
		AActor* NearestActor = UGameplayStatics::FindNearestActor(PawnLocation,OutActors,Raduis_Dmg);
		if(UWorld* World=GetWorld())
		{
			check(NearestActor);
			FActorSpawnParameters SpawnParameters;
			SpawnParameters.Instigator=LocalPawn,
			World->SpawnActor<AActor>(FireSlashType,NearestActor->GetTransform(),SpawnParameters);
		}
	}
}

