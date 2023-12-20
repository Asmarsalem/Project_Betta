// Copyright 2021-2022 Mickael Daniel. All Rights Reserved.


#include "Data/GamePlayEffectCalculation/UGEC_DamageCalculation.h"

#include "Abilities/Attributes/GSCAttributeSet.h"

struct DamageCapture
{
	DECLARE_ATTRIBUTE_CAPTUREDEF(Health)
	DECLARE_ATTRIBUTE_CAPTUREDEF(Damage)
	
	DamageCapture()
	{
		DEFINE_ATTRIBUTE_CAPTUREDEF(UGSCAttributeSet, Health, Target, true)
		DEFINE_ATTRIBUTE_CAPTUREDEF(UGSCAttributeSet, Damage, Target, true)

	}
	
};
static DamageCapture& GetDamageCapture()
{
	static DamageCapture DamageCaptureVar;
	return DamageCaptureVar;
}
UUGEC_DamageCalculation::UUGEC_DamageCalculation()
{
	RelevantAttributesToCapture.Add(GetDamageCapture().HealthDef);
	RelevantAttributesToCapture.Add(GetDamageCapture().DamageDef);
}

void UUGEC_DamageCalculation::Execute_Implementation(const FGameplayEffectCustomExecutionParameters& ExecParams,
	FGameplayEffectCustomExecutionOutput& ExecOutputs) const
{
	Super::Execute_Implementation(ExecParams, ExecOutputs);
	FGameplayEffectSpec Spec=ExecParams.GetOwningSpec();
	float BaseDamage = FMath::Max<float>(Spec.GetSetByCallerMagnitude(FGameplayTag::RequestGameplayTag(FName("SetByCaller.Damage")),false,-1.f),0.f);
	float HealthMagnitude = 0.0f;
	ExecParams.AttemptCalculateCapturedAttributeMagnitude(GetDamageCapture().HealthDef, FAggregatorEvaluateParameters(), HealthMagnitude);
	
	float OutHealth = HealthMagnitude - BaseDamage;
	
	ExecOutputs.AddOutputModifier(FGameplayModifierEvaluatedData(GetDamageCapture().HealthProperty, EGameplayModOp::Override, OutHealth));

	
}