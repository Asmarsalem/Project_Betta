// Copyright 2021-2022 Mickael Daniel. All Rights Reserved.


#include "Gas/GameplayEffect/CustomCalculation/UGEC_HealthCalculation.h"

#include "MainAttributes.h"
#include "Abilities/Attributes/GSCAttributeSet.h"

struct DamageCapture
{
	DECLARE_ATTRIBUTE_CAPTUREDEF(Armor)
	DECLARE_ATTRIBUTE_CAPTUREDEF(Health)
	DECLARE_ATTRIBUTE_CAPTUREDEF(Damage)
	
	DamageCapture()
	{
		DEFINE_ATTRIBUTE_CAPTUREDEF(UGSCAttributeSet, Health, Target, true)
		DEFINE_ATTRIBUTE_CAPTUREDEF(UMainAttributes, Armor, Target, true)
		DEFINE_ATTRIBUTE_CAPTUREDEF(UGSCAttributeSet, Damage, Target, true)

	}
	
};
static DamageCapture& GetDamageCapture()
{
	static DamageCapture DamageCaptureVar;
	return DamageCaptureVar;
}
UUGEC_HealthCalculation::UUGEC_HealthCalculation()
{
	RelevantAttributesToCapture.Add(GetDamageCapture().ArmorDef);
	RelevantAttributesToCapture.Add(GetDamageCapture().HealthDef);
	RelevantAttributesToCapture.Add(GetDamageCapture().DamageDef);
	
}

void UUGEC_HealthCalculation::Execute_Implementation(const FGameplayEffectCustomExecutionParameters& ExecParams,
	FGameplayEffectCustomExecutionOutput& ExecOutputs) const
{
	Super::Execute_Implementation(ExecParams, ExecOutputs);
	
	FGameplayEffectSpec Spec=ExecParams.GetOwningSpec();
	float BaseDamage = FMath::Max<float>(Spec.GetSetByCallerMagnitude(FGameplayTag::RequestGameplayTag(FName("SetByCaller.Damage")),false,-1.f),0.f);
	float ArmorMagnitude = 0.0f;
	float HealthMagnitude = 0.0f;
	ExecParams.AttemptCalculateCapturedAttributeMagnitude(GetDamageCapture().ArmorDef, FAggregatorEvaluateParameters(), ArmorMagnitude);
	ExecParams.AttemptCalculateCapturedAttributeMagnitude(GetDamageCapture().HealthDef, FAggregatorEvaluateParameters(), HealthMagnitude);
	
	GEngine->AddOnScreenDebugMessage(-1,5.F,FColor::Black,FString::Printf(TEXT("%f"),ArmorMagnitude));
	float OutArmor = ArmorMagnitude - BaseDamage;
	if (OutArmor < 0)
	{
		float OutHealth = HealthMagnitude - fabs(OutArmor);
		OutArmor = 0;

		ExecOutputs.AddOutputModifier(FGameplayModifierEvaluatedData(GetDamageCapture().ArmorProperty, EGameplayModOp::Override, OutArmor));
		ExecOutputs.AddOutputModifier(FGameplayModifierEvaluatedData(GetDamageCapture().HealthProperty, EGameplayModOp::Override, OutHealth));
	}
	else
	{
		ExecOutputs.AddOutputModifier(FGameplayModifierEvaluatedData(GetDamageCapture().ArmorProperty, EGameplayModOp::Override, OutArmor));
	}
	
}
