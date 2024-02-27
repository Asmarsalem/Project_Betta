// Copyright 2021-2022 Mickael Daniel. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Abilities/GameplayAbility.h"
#include "UAC_Evilios.generated.h"


UCLASS(ClassGroup=(Character), meta=(BlueprintSpawnableComponent))
class GASCOMPANIONDEMO_API UUAC_Evilios : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UUAC_Evilios();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	/*
	 *	Auto Aim Funcs
	 */
	UFUNCTION(BlueprintCallable , Category=" Custom | Attack | Range ")
	void AutoAim();
	UFUNCTION()
	void SpawnActor(float AttackRange);
	UFUNCTION()
	void ArrowType(FTransform ArrowTransform,APawn* LocalPawn);
	/*
	*	Auto Aim VArs
	*/
	UPROPERTY()
	FTimerHandle ArrowTypeHandle;
	UPROPERTY()
	FTimerHandle AutoAimOutHandle;
	/*
	 *	Init Vars
	 */
	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite,Category="Config | Vars")
	TSubclassOf<AActor> EnemyClass;
	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite,Category="Config | Vars")
	TSubclassOf<AActor> SingleArrow;
	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite,Category="Config | Vars")
	TSubclassOf<AActor> RecochetArrow;
	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite,Category="Config | Vars")
	TSubclassOf<UGameplayAbility> MultiArrow;
	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite,Category="Config | Vars")
	int MultiArrowsIndex;
	UPROPERTY()
	int CurrentArrowIndex;
	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite,Category="Config | Vars")
	float RecochetCoolDown;
};
