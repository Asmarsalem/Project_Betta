// Copyright 2021-2022 Mickael Daniel. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "PC_TopDownShooter.generated.h"

/**
 * 
 */
UCLASS()
class GASCOMPANIONDEMO_API APC_TopDownShooter : public APlayerController
{
	GENERATED_BODY()
	UFUNCTION(BlueprintCallable , BlueprintAuthorityOnly , Category="PossessCharacter")
	void spawnCharacter(TSubclassOf<ACharacter> characteClass);
};
