// Copyright 2021-2022 Mickael Daniel. All Rights Reserved.


#include "UpgradesAttributeSet.h"
#include "Net/UnrealNetwork.h"

// Sets default values
UUpgradesAttributeSet::UUpgradesAttributeSet()
{
	// Default constructor
}

void UUpgradesAttributeSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
    // This is called whenever attributes change, so for max attributes we want to scale the current totals to match
    Super::PreAttributeChange(Attribute, NewValue);

    // Set adjust code here
    //
    // Example:
    //
    // If a Max value changes, adjust current to keep Current % of Current to Max
    //
    // if (Attribute == GetMaxHealthAttribute())
    // {
    //     AdjustAttributeForMaxChange(Health, MaxHealth, NewValue, GetHealthAttribute());
    // }
}

void UUpgradesAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
    Super::PostGameplayEffectExecute(Data);

    FGSCAttributeSetExecutionData ExecutionData;
    GetExecutionDataFromMod(Data, ExecutionData);

    // Set clamping or handling or "meta" attributes here (like damages)

    // Example 1: Using helpers to handle each attribute in their own methods (See GSCAttributeSet.cpp)

    // if (Data.EvaluatedData.Attribute == GetHealthAttribute())
    // {
    //     HandleHealthAttribute(ExecutionData);
    // }

    // Example 2: Basic example to clamp the value of an Health Attribute between 0 and another MaxHealth Attribute

    // if (Data.EvaluatedData.Attribute == GetHealthAttribute())
    // {
    //     SetHealth(FMath::Clamp(GetHealth(), 0.f, GetMaxHealth()));
    // }
}

void UUpgradesAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
        
    DOREPLIFETIME_CONDITION_NOTIFY(UUpgradesAttributeSet, Stun, COND_None, REPNOTIFY_Always);
    
    DOREPLIFETIME_CONDITION_NOTIFY(UUpgradesAttributeSet, AttackRange, COND_None, REPNOTIFY_Always);
    
    DOREPLIFETIME_CONDITION_NOTIFY(UUpgradesAttributeSet, MovementSpeed, COND_None, REPNOTIFY_Always);
    
    DOREPLIFETIME_CONDITION_NOTIFY(UUpgradesAttributeSet, AttackSpeed, COND_None, REPNOTIFY_Always);
    
    DOREPLIFETIME_CONDITION_NOTIFY(UUpgradesAttributeSet, IncreaseDamage, COND_None, REPNOTIFY_Always);
    
    DOREPLIFETIME_CONDITION_NOTIFY(UUpgradesAttributeSet, LifeSteal, COND_None, REPNOTIFY_Always);
    
    DOREPLIFETIME_CONDITION_NOTIFY(UUpgradesAttributeSet, ReflectDamage, COND_None, REPNOTIFY_Always);
    
    DOREPLIFETIME_CONDITION_NOTIFY(UUpgradesAttributeSet, knockBack, COND_None, REPNOTIFY_Always);
    
    DOREPLIFETIME_CONDITION_NOTIFY(UUpgradesAttributeSet, IncreaseMaxHp, COND_None, REPNOTIFY_Always);
    
    DOREPLIFETIME_CONDITION_NOTIFY(UUpgradesAttributeSet, IncreaseHealthRegen, COND_None, REPNOTIFY_Always);
}

void UUpgradesAttributeSet::OnRep_Stun(const FGameplayAttributeData& OldStun)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UUpgradesAttributeSet, Stun, OldStun);
}

void UUpgradesAttributeSet::OnRep_AttackRange(const FGameplayAttributeData& OldAttackRange)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UUpgradesAttributeSet, AttackRange, OldAttackRange);
}

void UUpgradesAttributeSet::OnRep_MovementSpeed(const FGameplayAttributeData& OldMovementSpeed)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UUpgradesAttributeSet, MovementSpeed, OldMovementSpeed);
}

void UUpgradesAttributeSet::OnRep_AttackSpeed(const FGameplayAttributeData& OldAttackSpeed)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UUpgradesAttributeSet, AttackSpeed, OldAttackSpeed);
}

void UUpgradesAttributeSet::OnRep_IncreaseDamage(const FGameplayAttributeData& OldIncreaseDamage)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UUpgradesAttributeSet, IncreaseDamage, OldIncreaseDamage);
}

void UUpgradesAttributeSet::OnRep_LifeSteal(const FGameplayAttributeData& OldLifeSteal)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UUpgradesAttributeSet, LifeSteal, OldLifeSteal);
}

void UUpgradesAttributeSet::OnRep_ReflectDamage(const FGameplayAttributeData& OldReflectDamage)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UUpgradesAttributeSet, ReflectDamage, OldReflectDamage);
}

void UUpgradesAttributeSet::OnRep_knockBack(const FGameplayAttributeData& OldknockBack)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UUpgradesAttributeSet, knockBack, OldknockBack);
}

void UUpgradesAttributeSet::OnRep_IncreaseMaxHp(const FGameplayAttributeData& OldIncreaseMaxHp)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UUpgradesAttributeSet, IncreaseMaxHp, OldIncreaseMaxHp);
}

void UUpgradesAttributeSet::OnRep_IncreaseHealthRegen(const FGameplayAttributeData& OldIncreaseHealthRegen)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UUpgradesAttributeSet, IncreaseHealthRegen, OldIncreaseHealthRegen);
}
