// Copyright 2021 Mickael Daniel. All Rights Reserved.


#include "Attributes/XPAttributeSet.h"
#include "GameplayEffectExtension.h"
#include "Core/GameMode/GM_TestGameMood.h"
#include "Net/UnrealNetwork.h"

// Sets default values
UXPAttributeSet::UXPAttributeSet()
{
	// Set default values for this Set Attributes here
}

void UXPAttributeSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
    // This is called whenever attributes change, so for max attributes we want to scale the current totals to match
    Super::PreAttributeChange(Attribute, NewValue);
}

void UXPAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
    Super::PostGameplayEffectExecute(Data);
	FGSCAttributeSetExecutionData ExecutionData;
	GetExecutionDataFromMod(Data, ExecutionData);
    

 


    
	AActor* SourceActor = ExecutionData.SourceActor;
	AActor* TargetActor = ExecutionData.TargetActor;
   
	// And cast SourceActor / TargetActor to whatever Character classes you may be using and need access to

    const FGameplayTagContainer SourceTags = ExecutionData.SourceTags;
    const FGameplayEffectContextHandle Context = ExecutionData.Context;

	// ...
}

void UXPAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);

    DOREPLIFETIME_CONDITION_NOTIFY(UXPAttributeSet, CurrentXP, COND_None, REPNOTIFY_Always);

    DOREPLIFETIME_CONDITION_NOTIFY(UXPAttributeSet, NextLevelXPThreshold, COND_None, REPNOTIFY_Always);

    DOREPLIFETIME_CONDITION_NOTIFY(UXPAttributeSet, Level, COND_None, REPNOTIFY_Always);

    DOREPLIFETIME_CONDITION_NOTIFY(UXPAttributeSet,xp,COND_None,REPNOTIFY_Always);
    DOREPLIFETIME_CONDITION_NOTIFY(UXPAttributeSet, StunLevel, COND_None, REPNOTIFY_Always);
    
    DOREPLIFETIME_CONDITION_NOTIFY(UXPAttributeSet, AttackRangeLevel, COND_None, REPNOTIFY_Always);
    
    DOREPLIFETIME_CONDITION_NOTIFY(UXPAttributeSet, MovementSpeedLevel, COND_None, REPNOTIFY_Always);
    
    DOREPLIFETIME_CONDITION_NOTIFY(UXPAttributeSet, AttackSpeedLevel, COND_None, REPNOTIFY_Always);
    
    DOREPLIFETIME_CONDITION_NOTIFY(UXPAttributeSet, IncreaseDamageLevel, COND_None, REPNOTIFY_Always);
    
    DOREPLIFETIME_CONDITION_NOTIFY(UXPAttributeSet, LifeStealLevel, COND_None, REPNOTIFY_Always);
    
    DOREPLIFETIME_CONDITION_NOTIFY(UXPAttributeSet, ReflectDamageLevel, COND_None, REPNOTIFY_Always);
    
    DOREPLIFETIME_CONDITION_NOTIFY(UXPAttributeSet, knockBackLevel, COND_None, REPNOTIFY_Always);
    
    DOREPLIFETIME_CONDITION_NOTIFY(UXPAttributeSet, IncreaseMaxHpLevel, COND_None, REPNOTIFY_Always);
    
    DOREPLIFETIME_CONDITION_NOTIFY(UXPAttributeSet, IncreaseHealthRegenLevel, COND_None, REPNOTIFY_Always);
    
}

void UXPAttributeSet::PostAttributeChange(const FGameplayAttribute& Attribute, float OldValue, float NewValue)
{
    Super::PostAttributeChange(Attribute, OldValue, NewValue);
    if (Attribute.GetNumericValue(this)>=GetNextLevelXPThreshold()&&Attribute==GetCurrentXPAttribute())
    {
        SetNextLevelXPThreshold(GetNextLevelXPThreshold()*2);
        UE_LOG(LogTemp,Error,TEXT("LevelUP"));
        SetLevel(GetLevel()+1);
        if(AGM_TestGameMood* Gamemode=Cast<AGM_TestGameMood>(GetOwningActor()))
        {
            Gamemode->onAttributeChange.Broadcast(GetCurrentXP(),GetNextLevelXPThreshold(),GetLevel());
        }
    }
}

void UXPAttributeSet::OnRep_CurrentXP(const FGameplayAttributeData& OldCurrentXP)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UXPAttributeSet, CurrentXP, OldCurrentXP);
}

void UXPAttributeSet::OnRep_NextLevelXPThreshold(const FGameplayAttributeData& OldNextLevelXPThreshold)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UXPAttributeSet, NextLevelXPThreshold, OldNextLevelXPThreshold);
}

void UXPAttributeSet::OnRep_Level(const FGameplayAttributeData& OldLevel)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UXPAttributeSet, Level, OldLevel);
}

void UXPAttributeSet::OnRep_xp(const FGameplayAttributeData& OldXp)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UXPAttributeSet,xp,OldXp);
}

void UXPAttributeSet::OnRep_Stun(const FGameplayAttributeData& OldStun)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UXPAttributeSet,StunLevel,OldStun);
}

void UXPAttributeSet::OnRep_AttackRange(const FGameplayAttributeData& OldAttackRange)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UXPAttributeSet,AttackRangeLevel,OldAttackRange);
}

void UXPAttributeSet::OnRep_MovementSpeed(const FGameplayAttributeData& OldMovementSpeed)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UXPAttributeSet,MovementSpeedLevel,OldMovementSpeed);
}

void UXPAttributeSet::OnRep_AttackSpeed(const FGameplayAttributeData& OldAttackSpeed)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UXPAttributeSet,AttackSpeedLevel,OldAttackSpeed);
}

void UXPAttributeSet::OnRep_IncreaseDamage(const FGameplayAttributeData& OldIncreaseDamage)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UXPAttributeSet,IncreaseDamageLevel,OldIncreaseDamage);
}

void UXPAttributeSet::OnRep_LifeSteal(const FGameplayAttributeData& OldLifeSteal)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UXPAttributeSet,LifeStealLevel,OldLifeSteal);
}

void UXPAttributeSet::OnRep_ReflectDamage(const FGameplayAttributeData& OldReflectDamage)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UXPAttributeSet,ReflectDamageLevel,OldReflectDamage);
}

void UXPAttributeSet::OnRep_knockBack(const FGameplayAttributeData& OldknockBack)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UXPAttributeSet,knockBackLevel,OldknockBack);
}

void UXPAttributeSet::OnRep_IncreaseMaxHp(const FGameplayAttributeData& OldIncreaseMaxHp)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UXPAttributeSet,IncreaseMaxHpLevel,OldIncreaseMaxHp);
}

void UXPAttributeSet::OnRep_IncreaseHealthRegen(const FGameplayAttributeData& OldIncreaseHealthRegen)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UXPAttributeSet,IncreaseHealthRegenLevel,OldIncreaseHealthRegen);
}
