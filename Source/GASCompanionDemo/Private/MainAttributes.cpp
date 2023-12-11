// Copyright 2021-2022 Mickael Daniel. All Rights Reserved.


#include "MainAttributes.h"

#include "Net/UnrealNetwork.h"

// Sets default values
UMainAttributes::UMainAttributes()
{
	// Default constructor
}

void UMainAttributes::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
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

void UMainAttributes::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
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

void UMainAttributes::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    
    DOREPLIFETIME_CONDITION_NOTIFY(UMainAttributes, Speed, COND_None, REPNOTIFY_Always);
    
    
    DOREPLIFETIME_CONDITION_NOTIFY(UMainAttributes, Strength, COND_None, REPNOTIFY_Always);
    
    DOREPLIFETIME_CONDITION_NOTIFY(UMainAttributes, Intelligence, COND_None, REPNOTIFY_Always);
    
    DOREPLIFETIME_CONDITION_NOTIFY(UMainAttributes, Resilience, COND_None, REPNOTIFY_Always);
    
    DOREPLIFETIME_CONDITION_NOTIFY(UMainAttributes, Vigor, COND_None, REPNOTIFY_Always);
    
    DOREPLIFETIME_CONDITION_NOTIFY(UMainAttributes, Damage, COND_None, REPNOTIFY_Always);
    
    DOREPLIFETIME_CONDITION_NOTIFY(UMainAttributes, Armor, COND_None, REPNOTIFY_Always);
    
    DOREPLIFETIME_CONDITION_NOTIFY(UMainAttributes, MaxArmor, COND_None, REPNOTIFY_Always);
    
    DOREPLIFETIME_CONDITION_NOTIFY(UMainAttributes, ArmorPenetration, COND_None, REPNOTIFY_Always);
    
    DOREPLIFETIME_CONDITION_NOTIFY(UMainAttributes, LifeSteal, COND_None, REPNOTIFY_Always);
    
    DOREPLIFETIME_CONDITION_NOTIFY(UMainAttributes, CriticalDamage, COND_None, REPNOTIFY_Always);
    
    DOREPLIFETIME_CONDITION_NOTIFY(UMainAttributes, Dodge, COND_None, REPNOTIFY_Always);
    
    DOREPLIFETIME_CONDITION_NOTIFY(UMainAttributes, CriticalChance, COND_None, REPNOTIFY_Always);
    
    DOREPLIFETIME_CONDITION_NOTIFY(UMainAttributes, CriticalResistance, COND_None, REPNOTIFY_Always);
    
    DOREPLIFETIME_CONDITION_NOTIFY(UMainAttributes, ReflectDamage, COND_None, REPNOTIFY_Always);
    
    DOREPLIFETIME_CONDITION_NOTIFY(UMainAttributes, Poison, COND_None, REPNOTIFY_Always);
    
    DOREPLIFETIME_CONDITION_NOTIFY(UMainAttributes, DeathStrike, COND_None, REPNOTIFY_Always);
    
    DOREPLIFETIME_CONDITION_NOTIFY(UMainAttributes, AttackRange, COND_None, REPNOTIFY_Always);

    DOREPLIFETIME_CONDITION_NOTIFY(UMainAttributes, AttackSpeed, COND_None, REPNOTIFY_Always);

    DOREPLIFETIME_CONDITION_NOTIFY(UMainAttributes,WaveLevel,COND_None,REPNOTIFY_Always)
    
     DOREPLIFETIME_CONDITION_NOTIFY(UMainAttributes,Gold,COND_None,REPNOTIFY_Always)
     
    DOREPLIFETIME_CONDITION_NOTIFY(UMainAttributes,Gems,COND_None,REPNOTIFY_Always)
    
    
    
    
}


void UMainAttributes::OnRep_Speed(const FGameplayAttributeData& OldSpeed)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UMainAttributes, Speed, OldSpeed);
}


void UMainAttributes::OnRep_Strength(const FGameplayAttributeData& OldStrength)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UMainAttributes, Strength, OldStrength);
}

void UMainAttributes::OnRep_Intelligence(const FGameplayAttributeData& OldIntelligence)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UMainAttributes, Intelligence, OldIntelligence);
}

void UMainAttributes::OnRep_Resilience(const FGameplayAttributeData& OldResilience)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UMainAttributes, Resilience, OldResilience);
}

void UMainAttributes::OnRep_Vigor(const FGameplayAttributeData& OldVigor)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UMainAttributes, Vigor, OldVigor);
}

void UMainAttributes::OnRep_Damage(const FGameplayAttributeData& OldDamage)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UMainAttributes, Damage, OldDamage);
}

void UMainAttributes::OnRep_Armor(const FGameplayAttributeData& OldArmor)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UMainAttributes, Armor, OldArmor);
}

void UMainAttributes::OnRep_MaxArmor(const FGameplayAttributeData& OldMaxArmor)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UMainAttributes, MaxArmor, OldMaxArmor);
}

void UMainAttributes::OnRep_ArmorPenetration(const FGameplayAttributeData& OldArmorPenetration)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UMainAttributes, ArmorPenetration, OldArmorPenetration);
}

void UMainAttributes::OnRep_LifeSteal(const FGameplayAttributeData& OldLifeSteal)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UMainAttributes, LifeSteal, OldLifeSteal);
}

void UMainAttributes::OnRep_CriticalDamage(const FGameplayAttributeData& OldCriticalDamage)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UMainAttributes, CriticalDamage, OldCriticalDamage);
}

void UMainAttributes::OnRep_Dodge(const FGameplayAttributeData& OldDodge)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UMainAttributes, Dodge, OldDodge);
}

void UMainAttributes::OnRep_CriticalChance(const FGameplayAttributeData& OldCriticalChance)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UMainAttributes, CriticalChance, OldCriticalChance);
}

void UMainAttributes::OnRep_CriticalResistance(const FGameplayAttributeData& OldCriticalResistance)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UMainAttributes, CriticalResistance, OldCriticalResistance);
}

void UMainAttributes::OnRep_ReflectDamage(const FGameplayAttributeData& OldReflectDamage)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UMainAttributes, ReflectDamage, OldReflectDamage);
}

void UMainAttributes::OnRep_Poison(const FGameplayAttributeData& OldPoison)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UMainAttributes, Poison, OldPoison);
}

void UMainAttributes::OnRep_DeathStrike(const FGameplayAttributeData& OldDeathStrike)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UMainAttributes, DeathStrike, OldDeathStrike);
}


void UMainAttributes::OnRep_AttackRange(const FGameplayAttributeData& OldAttackRange)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UMainAttributes, AttackRange, OldAttackRange);
}

void UMainAttributes::OnRep_AttackSpeed(const FGameplayAttributeData& OldAttackSpeed)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UMainAttributes,AttackSpeed,OldAttackSpeed);
}

void UMainAttributes::OnRep_WaveLevel(const FGameplayAttributeData& OldWaveLevel)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UMainAttributes,WaveLevel,OldWaveLevel)
}

void UMainAttributes::OnRep_Gold(const FGameplayAttributeData& OldGold)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UMainAttributes,Gold,OldGold)
}


void UMainAttributes::OnRep_Gems(const FGameplayAttributeData& OldGems)
{
        GAMEPLAYATTRIBUTE_REPNOTIFY(UMainAttributes,Gems,OldGems)
}




