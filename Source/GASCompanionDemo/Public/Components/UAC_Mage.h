// Copyright 2021-2022 Mickael Daniel. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "UAC_Mage.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class GASCOMPANIONDEMO_API UUAC_Mage : public UActorComponent
{
	GENERATED_BODY()

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// auto attack
	//Vars
	UPROPERTY(EditAnywhere,Category="AutoAttacK|Var")
	FTimerHandle AutoAimOutHandle;
	UPROPERTY(EditAnywhere,Category="AutoAttacK|Var")
	TSubclassOf<AActor> FireSlashType;
	UPROPERTY(EditAnywhere,Category="AutoAttacK|Var")
	TSubclassOf<AActor> AiType;
	UPROPERTY(EditAnywhere,Category="AutoAttacK|Var")
	float Raduis_Dmg;
	//Funcs
	UFUNCTION(BlueprintCallable,Category="AutoAttacK|Func")
	void AutoAttack();
	UFUNCTION(Category="AutoAttacK|Func")
	void FindTheNearetActor();

};
