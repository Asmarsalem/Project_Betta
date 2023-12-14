// Copyright 2021-2022 Mickael Daniel. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/Attributes/GSCAttributeSetBase.h"
#include "AbilitySystemComponent.h"
#include "MainAttributes.generated.h"

UCLASS()
class GASCOMPANIONDEMO_API UMainAttributes : public UGSCAttributeSetBase
{
	GENERATED_BODY()

public:

	// Sets default values for this AttributeSet attributes
	UMainAttributes();

    // AttributeSet Overrides
    virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;
    virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
        
   
    
    UPROPERTY(BlueprintReadOnly, Category = "Vital", ReplicatedUsing = OnRep_Speed)
    FGameplayAttributeData Speed = 0.0;
    ATTRIBUTE_ACCESSORS(UMainAttributes, Speed)    
	
    
    UPROPERTY(BlueprintReadOnly, Category = "Primary", ReplicatedUsing = OnRep_Strength)
    FGameplayAttributeData Strength = 0.0;
    ATTRIBUTE_ACCESSORS(UMainAttributes, Strength)    
    
    UPROPERTY(BlueprintReadOnly, Category = "Primary", ReplicatedUsing = OnRep_Intelligence)
    FGameplayAttributeData Intelligence = 0.0;
    ATTRIBUTE_ACCESSORS(UMainAttributes, Intelligence)    
    
    UPROPERTY(BlueprintReadOnly, Category = "Primary", ReplicatedUsing = OnRep_Resilience)
    FGameplayAttributeData Resilience = 0.0;
    ATTRIBUTE_ACCESSORS(UMainAttributes, Resilience)    
    
    UPROPERTY(BlueprintReadOnly, Category = "Primary", ReplicatedUsing = OnRep_Vigor)
    FGameplayAttributeData Vigor = 0.0;
    ATTRIBUTE_ACCESSORS(UMainAttributes, Vigor)    
    
    UPROPERTY(BlueprintReadOnly, Category = "Secondary", ReplicatedUsing = OnRep_Damage)
    FGameplayAttributeData Damage = 0.0;
    ATTRIBUTE_ACCESSORS(UMainAttributes, Damage)    
    
    UPROPERTY(BlueprintReadOnly, Category = "Secondary", ReplicatedUsing = OnRep_Armor)
    FGameplayAttributeData Armor = 0.0;
    ATTRIBUTE_ACCESSORS(UMainAttributes, Armor)    
    
    UPROPERTY(BlueprintReadOnly, Category = "Secondary", ReplicatedUsing = OnRep_MaxArmor)
    FGameplayAttributeData MaxArmor = 0.0;
    ATTRIBUTE_ACCESSORS(UMainAttributes, MaxArmor)    
    
    UPROPERTY(BlueprintReadOnly, Category = "Secondary", ReplicatedUsing = OnRep_ArmorPenetration)
    FGameplayAttributeData ArmorPenetration = 0.0;
    ATTRIBUTE_ACCESSORS(UMainAttributes, ArmorPenetration)    
    
    UPROPERTY(BlueprintReadOnly, Category = "Secondary", ReplicatedUsing = OnRep_LifeSteal)
    FGameplayAttributeData LifeSteal = 0.0;
    ATTRIBUTE_ACCESSORS(UMainAttributes, LifeSteal)    
    
    UPROPERTY(BlueprintReadOnly, Category = "Secondary", ReplicatedUsing = OnRep_CriticalDamage)
    FGameplayAttributeData CriticalDamage = 0.0;
    ATTRIBUTE_ACCESSORS(UMainAttributes, CriticalDamage)    
    
    UPROPERTY(BlueprintReadOnly, Category = "Secondary", ReplicatedUsing = OnRep_Dodge)
    FGameplayAttributeData Dodge = 0.0;
    ATTRIBUTE_ACCESSORS(UMainAttributes, Dodge)    
    
    UPROPERTY(BlueprintReadOnly, Category = "Secondary", ReplicatedUsing = OnRep_CriticalChance)
    FGameplayAttributeData CriticalChance = 0.0;
    ATTRIBUTE_ACCESSORS(UMainAttributes, CriticalChance)    
    
    UPROPERTY(BlueprintReadOnly, Category = "Secondary", ReplicatedUsing = OnRep_CriticalResistance)
    FGameplayAttributeData CriticalResistance = 0.0;
    ATTRIBUTE_ACCESSORS(UMainAttributes, CriticalResistance)    
    
    UPROPERTY(BlueprintReadOnly, Category = "Secondary", ReplicatedUsing = OnRep_ReflectDamage)
    FGameplayAttributeData ReflectDamage = 0.0;
    ATTRIBUTE_ACCESSORS(UMainAttributes, ReflectDamage)    
    
    UPROPERTY(BlueprintReadOnly, Category = "Secondary", ReplicatedUsing = OnRep_Poison)
    FGameplayAttributeData Poison = 0.0;
    ATTRIBUTE_ACCESSORS(UMainAttributes, Poison)    
    
    UPROPERTY(BlueprintReadOnly, Category = "Secondary", ReplicatedUsing = OnRep_DeathStrike)
    FGameplayAttributeData DeathStrike = 0.0;
    ATTRIBUTE_ACCESSORS(UMainAttributes, DeathStrike)    
    
    UPROPERTY(BlueprintReadOnly, Category = "Secondary", ReplicatedUsing = OnRep_AttackRange)
    FGameplayAttributeData AttackRange = 0.0;
    ATTRIBUTE_ACCESSORS(UMainAttributes, AttackRange)

	UPROPERTY(BlueprintReadOnly, Category = "Secondary", ReplicatedUsing = OnRep_AttackSpeed)
	FGameplayAttributeData AttackSpeed = 0.0;
	ATTRIBUTE_ACCESSORS(UMainAttributes, AttackSpeed)

	UPROPERTY(BlueprintReadOnly, Category = "Secondary", ReplicatedUsing = OnRep_WaveLevel)
	FGameplayAttributeData WaveLevel = 0.0;
	ATTRIBUTE_ACCESSORS(UMainAttributes, WaveLevel)

	UPROPERTY(BlueprintReadOnly, Category = "Secondary", ReplicatedUsing = OnRep_Gold)
	FGameplayAttributeData Gold = 0.0;
	ATTRIBUTE_ACCESSORS(UMainAttributes, Gold)

	UPROPERTY(BlueprintReadOnly, Category = "Secondary", ReplicatedUsing = OnRep_Gems)
	FGameplayAttributeData Gems = 0.0;
	ATTRIBUTE_ACCESSORS(UMainAttributes, Gems)

	UPROPERTY(BlueprintReadOnly, Category = "Vital", ReplicatedUsing = OnRep_KnockBack)
	FGameplayAttributeData KnockBack = 0.0;
	ATTRIBUTE_ACCESSORS(UMainAttributes, KnockBack)    

	
	

protected:
	

    UFUNCTION()
    virtual void OnRep_Speed(const FGameplayAttributeData& OldSpeed);
	

    UFUNCTION()
    virtual void OnRep_Strength(const FGameplayAttributeData& OldStrength);

    UFUNCTION()
    virtual void OnRep_Intelligence(const FGameplayAttributeData& OldIntelligence);

    UFUNCTION()
    virtual void OnRep_Resilience(const FGameplayAttributeData& OldResilience);

    UFUNCTION()
    virtual void OnRep_Vigor(const FGameplayAttributeData& OldVigor);

    UFUNCTION()
    virtual void OnRep_Damage(const FGameplayAttributeData& OldDamage);

    UFUNCTION()
    virtual void OnRep_Armor(const FGameplayAttributeData& OldArmor);

    UFUNCTION()
    virtual void OnRep_MaxArmor(const FGameplayAttributeData& OldMaxArmor);

    UFUNCTION()
    virtual void OnRep_ArmorPenetration(const FGameplayAttributeData& OldArmorPenetration);

    UFUNCTION()
    virtual void OnRep_LifeSteal(const FGameplayAttributeData& OldLifeSteal);

    UFUNCTION()
    virtual void OnRep_CriticalDamage(const FGameplayAttributeData& OldCriticalDamage);

    UFUNCTION()
    virtual void OnRep_Dodge(const FGameplayAttributeData& OldDodge);

    UFUNCTION()
    virtual void OnRep_CriticalChance(const FGameplayAttributeData& OldCriticalChance);

    UFUNCTION()
    virtual void OnRep_CriticalResistance(const FGameplayAttributeData& OldCriticalResistance);

    UFUNCTION()
    virtual void OnRep_ReflectDamage(const FGameplayAttributeData& OldReflectDamage);

    UFUNCTION()
    virtual void OnRep_Poison(const FGameplayAttributeData& OldPoison);

    UFUNCTION()
    virtual void OnRep_DeathStrike(const FGameplayAttributeData& OldDeathStrike);
	

    UFUNCTION()
    virtual void OnRep_AttackRange(const FGameplayAttributeData& OldAttackRange);

	UFUNCTION()
	virtual void OnRep_AttackSpeed(const FGameplayAttributeData& OldAttackSpeed);

	UFUNCTION()
	virtual void OnRep_WaveLevel(const FGameplayAttributeData& OldWaveLevel);

	UFUNCTION()
	virtual void OnRep_Gold(const FGameplayAttributeData& OldGold);

	UFUNCTION()
	virtual void OnRep_Gems(const FGameplayAttributeData& OldGems);

	UFUNCTION()
	virtual void OnRep_KnockBack(const FGameplayAttributeData& OldKnockBack);
	
};
