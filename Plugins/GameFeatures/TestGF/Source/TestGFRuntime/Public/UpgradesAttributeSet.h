// Copyright 2021-2022 Mickael Daniel. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "Abilities/Attributes/GSCAttributeSetBase.h"
#include "UpgradesAttributeSet.generated.h"

UCLASS()
class TESTGFRUNTIME_API UUpgradesAttributeSet : public UGSCAttributeSetBase
{
	GENERATED_BODY()

public:

	// Sets default values for this AttributeSet attributes
	UUpgradesAttributeSet();

    // AttributeSet Overrides
    virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;
    virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
        
    UPROPERTY(BlueprintReadOnly, Category = "Upgrades_Propertie", ReplicatedUsing = OnRep_Stun)
    FGameplayAttributeData Stun = 0.0;
    ATTRIBUTE_ACCESSORS(UUpgradesAttributeSet, Stun)    
    
    UPROPERTY(BlueprintReadOnly, Category = "Upgrades_Properties", ReplicatedUsing = OnRep_AttackRange)
    FGameplayAttributeData AttackRange = 0.0;
    ATTRIBUTE_ACCESSORS(UUpgradesAttributeSet, AttackRange)    
    
    UPROPERTY(BlueprintReadOnly, Category = "Upgrades_Properties", ReplicatedUsing = OnRep_MovementSpeed)
    FGameplayAttributeData MovementSpeed = 0.0;
    ATTRIBUTE_ACCESSORS(UUpgradesAttributeSet, MovementSpeed)    
    
    UPROPERTY(BlueprintReadOnly, Category = "Upgrades_Properties", ReplicatedUsing = OnRep_AttackSpeed)
    FGameplayAttributeData AttackSpeed = 0.0;
    ATTRIBUTE_ACCESSORS(UUpgradesAttributeSet, AttackSpeed)    
    
    UPROPERTY(BlueprintReadOnly, Category = "Upgrades_Properties", ReplicatedUsing = OnRep_IncreaseDamage)
    FGameplayAttributeData IncreaseDamage = 0.0;
    ATTRIBUTE_ACCESSORS(UUpgradesAttributeSet, IncreaseDamage)    
    
    UPROPERTY(BlueprintReadOnly, Category = "Upgrades_Properties", ReplicatedUsing = OnRep_LifeSteal)
    FGameplayAttributeData LifeSteal = 0.0;
    ATTRIBUTE_ACCESSORS(UUpgradesAttributeSet, LifeSteal)    
    
    UPROPERTY(BlueprintReadOnly, Category = "Upgrades_Properties", ReplicatedUsing = OnRep_ReflectDamage)
    FGameplayAttributeData ReflectDamage = 0.0;
    ATTRIBUTE_ACCESSORS(UUpgradesAttributeSet, ReflectDamage)    
    
    UPROPERTY(BlueprintReadOnly, Category = "Upgrades_Properties", ReplicatedUsing = OnRep_knockBack)
    FGameplayAttributeData knockBack = 0.0;
		ATTRIBUTE_ACCESSORS(UUpgradesAttributeSet, knockBack)    
    
    UPROPERTY(BlueprintReadOnly, Category = "Upgrades_Properties", ReplicatedUsing = OnRep_IncreaseMaxHp)
    FGameplayAttributeData IncreaseMaxHp = 0.0;
    ATTRIBUTE_ACCESSORS(UUpgradesAttributeSet, IncreaseMaxHp)    
    
    UPROPERTY(BlueprintReadOnly, Category = "Upgrades_Properties", ReplicatedUsing = OnRep_IncreaseHealthRegen)
    FGameplayAttributeData IncreaseHealthRegen = 0.0;
    ATTRIBUTE_ACCESSORS(UUpgradesAttributeSet, IncreaseHealthRegen)    

protected:
    
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
