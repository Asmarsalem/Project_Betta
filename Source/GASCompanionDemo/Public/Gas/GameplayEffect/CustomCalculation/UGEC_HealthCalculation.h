// Copyright 2021-2022 Mickael Daniel. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayEffectExecutionCalculation.h"
#include "UGEC_HealthCalculation.generated.h"

/**
 * 
 */
UCLASS()
class GASCOMPANIONDEMO_API UUGEC_HealthCalculation : public UGameplayEffectExecutionCalculation
{
	GENERATED_BODY()
public:
	UUGEC_HealthCalculation();
	void Execute_Implementation(const FGameplayEffectCustomExecutionParameters& ExecParams, FGameplayEffectCustomExecutionOutput& ExecOutputs) const;
};
