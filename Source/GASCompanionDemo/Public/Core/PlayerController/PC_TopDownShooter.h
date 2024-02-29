// Copyright 2021-2022 Mickael Daniel. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TimerManager.h"
#include "PC_TopDownShooter.generated.h"

/**
 * 
 */
UCLASS()
class GASCOMPANIONDEMO_API APC_TopDownShooter : public APlayerController
{
     GENERATED_BODY()
    
    UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Custom | Spawn")
    void spawnCharacter(TSubclassOf<ACharacter> characterClass);

    UFUNCTION(BlueprintCallable , Category=" Custom | Attack | Range")
    void AutoAttack(TSubclassOf<AActor> ArrowType, float InRate);

	UFUNCTION(BlueprintCallable , Category=" Custom | Attack | Range ")
	void AutoAim(TSubclassOf<AActor> EnemyClass,TSubclassOf<AActor> ArrowType );

    UPROPERTY()
    FTimerHandle InOutHandle;
	UPROPERTY()
	FTimerHandle AutoAimOutHandle;
};
