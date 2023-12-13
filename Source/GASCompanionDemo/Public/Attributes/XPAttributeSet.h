// Copyright 2021 Mickael Daniel. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/Attributes/GSCAttributeSetBase.h"
#include "AbilitySystemComponent.h"
#include "XPAttributeSet.generated.h"

UCLASS()
class GASCOMPANIONDEMO_API UXPAttributeSet : public UGSCAttributeSetBase
{
	GENERATED_BODY()

public:

	// Sets default values for this AttributeSet attributes
	UXPAttributeSet();

    // AttributeSet Overrides
    virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;
    virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	virtual void PostAttributeChange(const FGameplayAttribute& Attribute, float OldValue, float NewValue) override;
    UPROPERTY(BlueprintReadOnly, Category = "XP", ReplicatedUsing = OnRep_CurrentXP)
    FGameplayAttributeData CurrentXP = 0.0;
    ATTRIBUTE_ACCESSORS(UXPAttributeSet, CurrentXP)    
    
    UPROPERTY(BlueprintReadOnly, Category = "XP", ReplicatedUsing = OnRep_NextLevelXPThreshold)
    FGameplayAttributeData NextLevelXPThreshold = 0.0;
    ATTRIBUTE_ACCESSORS(UXPAttributeSet, NextLevelXPThreshold)    
    
    UPROPERTY(BlueprintReadOnly, Category = "XP", ReplicatedUsing = OnRep_Level)
    FGameplayAttributeData Level = 0.0;
    ATTRIBUTE_ACCESSORS(UXPAttributeSet, Level)    

	UPROPERTY(BlueprintReadOnly,ReplicatedUsing=OnRep_xp)
	FGameplayAttributeData xp=100;
	ATTRIBUTE_ACCESSORS(UXPAttributeSet, xp);
	
	    UPROPERTY(BlueprintReadOnly, Category = "Upgrades_Propertie", ReplicatedUsing = OnRep_Stun)
    FGameplayAttributeData StunLevel = 0.0;
    ATTRIBUTE_ACCESSORS(UXPAttributeSet, StunLevel)    
    
    UPROPERTY(BlueprintReadOnly, Category = "Upgrades_Properties", ReplicatedUsing = OnRep_AttackRange)
    FGameplayAttributeData AttackRangeLevel = 0.0;
    ATTRIBUTE_ACCESSORS(UXPAttributeSet, AttackRangeLevel)    
    
    UPROPERTY(BlueprintReadOnly, Category = "Upgrades_Properties", ReplicatedUsing = OnRep_MovementSpeed)
    FGameplayAttributeData MovementSpeedLevel = 0.0;
    ATTRIBUTE_ACCESSORS(UXPAttributeSet, MovementSpeedLevel)    
    
    UPROPERTY(BlueprintReadOnly, Category = "Upgrades_Properties", ReplicatedUsing = OnRep_AttackSpeed)
    FGameplayAttributeData AttackSpeedLevel = 5.0f;
    ATTRIBUTE_ACCESSORS(UXPAttributeSet, AttackSpeedLevel)    
    
    UPROPERTY(BlueprintReadOnly, Category = "Upgrades_Properties", ReplicatedUsing = OnRep_IncreaseDamage)
    FGameplayAttributeData IncreaseDamageLevel = 0.0;
    ATTRIBUTE_ACCESSORS(UXPAttributeSet, IncreaseDamageLevel)    
    
    UPROPERTY(BlueprintReadOnly, Category = "Upgrades_Properties", ReplicatedUsing = OnRep_LifeSteal)
    FGameplayAttributeData LifeStealLevel = 0.0;
    ATTRIBUTE_ACCESSORS(UXPAttributeSet, LifeStealLevel)    
    
    UPROPERTY(BlueprintReadOnly, Category = "Upgrades_Properties", ReplicatedUsing = OnRep_ReflectDamage)
    FGameplayAttributeData ReflectDamageLevel = 0.0;
    ATTRIBUTE_ACCESSORS(UXPAttributeSet, ReflectDamageLevel)    
    
    UPROPERTY(BlueprintReadOnly, Category = "Upgrades_Properties", ReplicatedUsing = OnRep_knockBack)
    FGameplayAttributeData knockBackLevel = 0.0;
		ATTRIBUTE_ACCESSORS(UXPAttributeSet, knockBackLevel)    
    
    UPROPERTY(BlueprintReadOnly, Category = "Upgrades_Properties", ReplicatedUsing = OnRep_IncreaseMaxHp)
    FGameplayAttributeData IncreaseMaxHpLevel = 0.0;
    ATTRIBUTE_ACCESSORS(UXPAttributeSet, IncreaseMaxHpLevel)    
    
    UPROPERTY(BlueprintReadOnly, Category = "Upgrades_Properties", ReplicatedUsing = OnRep_IncreaseHealthRegen)
    FGameplayAttributeData IncreaseHealthRegenLevel = 0.0;
    ATTRIBUTE_ACCESSORS(UXPAttributeSet, IncreaseHealthRegenLevel)    
protected:
	
    UFUNCTION()
    virtual void OnRep_CurrentXP(const FGameplayAttributeData& OldCurrentXP);

    UFUNCTION()
    virtual void OnRep_NextLevelXPThreshold(const FGameplayAttributeData& OldNextLevelXPThreshold);

    UFUNCTION()
    virtual void OnRep_Level(const FGameplayAttributeData& OldLevel);

	UFUNCTION()
	virtual void OnRep_xp(const FGameplayAttributeData& OldXp);
	
	UFUNCTION()
	virtual void OnRep_Stun(const FGameplayAttributeData& OldStun);

	UFUNCTION()
	virtual void OnRep_AttackRange(const FGameplayAttributeData& OldAttackRange);

	UFUNCTION()
	virtual void OnRep_MovementSpeed(const FGameplayAttributeData& OldMovementSpeed);

	UFUNCTION()
	virtual void OnRep_AttackSpeed(const FGameplayAttributeData& OldAttackSpeed);

	UFUNCTION()
	virtual void OnRep_IncreaseDamage(const FGameplayAttributeData& OldIncreaseDamage);

	UFUNCTION()
	virtual void OnRep_LifeSteal(const FGameplayAttributeData& OldLifeSteal);

	UFUNCTION()
	virtual void OnRep_ReflectDamage(const FGameplayAttributeData& OldReflectDamage);

	UFUNCTION()
	virtual void OnRep_knockBack(const FGameplayAttributeData& OldknockBack);

	UFUNCTION()
	virtual void OnRep_IncreaseMaxHp(const FGameplayAttributeData& OldIncreaseMaxHp);

	UFUNCTION()
	virtual void OnRep_IncreaseHealthRegen(const FGameplayAttributeData& OldIncreaseHealthRegen);
};
