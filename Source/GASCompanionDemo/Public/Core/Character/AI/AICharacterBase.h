// Copyright 2021-2022 Mickael Daniel. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "MainAttributes.h"
#include "Abilities/GSCAbilitySystemComponent.h"
#include "GameFramework/Character.h"
#include "AICharacterBase.generated.h"

UCLASS()
class GASCOMPANIONDEMO_API AAICharacterBase : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AAICharacterBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Gas")
	UGSCAbilitySystemComponent* GSCAbilitySystemComponent;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Gas")
	UMainAttributes* MainAttributes;
	
	void OnHealthChange(const FOnAttributeChangeData& Data)const;


	UFUNCTION(BlueprintCallable)
	void InitAb( UGSCAbilitySystemComponent* GSCAbilitySystem);
};


