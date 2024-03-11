// Copyright 2021-2022 Mickael Daniel. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "UAC_SkillTree.generated.h"

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class GASCOMPANIONDEMO_API UUAC_SkillTree : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UUAC_SkillTree();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	/*
	 * Init Funcs
	 */
	UFUNCTION(BlueprintCallable,Category="Init | Func ")
	void InitComponent();
	/*
	* Init Funcs
	*/
	UPROPERTY(BlueprintReadWrite,Category="Init | Vars ")
	TArray<FName> Abilities;
};
