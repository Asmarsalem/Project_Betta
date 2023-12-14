// Copyright 2021-2022 Mickael Daniel. All Rights Reserved.


#include "Core/PlayerController/PC_TopDownShooter.h"

#include "GameFramework/Character.h"
#include "GameFramework/PlayerStart.h"
#include "Kismet/GameplayStatics.h"

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
