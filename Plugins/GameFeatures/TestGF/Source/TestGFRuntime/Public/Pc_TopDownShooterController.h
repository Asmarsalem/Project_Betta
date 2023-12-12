// Copyright 2021-2022 Mickael Daniel. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Components/TimelineComponent.h"
#include "Pc_TopDownShooterController.generated.h"

UCLASS(Blueprintable,BlueprintType)
class TESTGFRUNTIME_API APc_TopDownShooterController : public APlayerController
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable , BlueprintAuthorityOnly , Category="PossessCharacter")
	void spawnCharacter(TSubclassOf<ACharacter> characteClass);
	/** Please add a function description */
};
