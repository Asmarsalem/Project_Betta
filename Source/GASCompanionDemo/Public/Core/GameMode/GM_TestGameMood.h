// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "Components/TimelineComponent.h"
#include "GM_TestGameMood.generated.h"

/**
 * 
 */
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FAttributeChangeSignature,float,CurrentXp,float,MaxXP,float,Level);

UCLASS()
class GASCOMPANIONDEMO_API AGM_TestGameMood : public AGameMode
{
	GENERATED_BODY()
public:
	// override default Func
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
	/*
	 * Init Vars
	 */
	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite,Category="Init | Vars")
	TArray<TSubclassOf<APawn>> Ai;
	UPROPERTY()
	int AiArrayRandLength;
	UPROPERTY()
	UTimelineComponent* MyTimeline;
	/*
	 * Init Func
	 */
	UFUNCTION(Category="Init | Funcs")
	bool SetAiArrayRandLength();
	
	// Wave System
	UFUNCTION(BlueprintCallable,Category="WaveSystem",meta=(Tooltip="Start New Wave Based On Curve Float"))
	void startNewWave(UCurveFloat* CurveFloat);
	
	// Blue Print Implementable Funcs
	UFUNCTION()
	void onFloatTrackUpdate(float value);
	UFUNCTION(BlueprintImplementableEvent,Category="WaveSystem",meta=(Tooltip="The Event Will Trigger When The Spawn Wave Finishes"))
	void onTimeLineFinished();
	UFUNCTION(BlueprintImplementableEvent,Category="WaveSystem")
	void OnTimelineEvent(float value);
	/*
	 *	Gas
	 */
	UPROPERTY(BlueprintAssignable)
	FAttributeChangeSignature onAttributeChange;
		
	UFUNCTION(BlueprintPure)
	FVector GetRandomReachableLocation(TSubclassOf<AActor> PlayerLocation,bool& Success);
	
	UFUNCTION(BlueprintPure)
	bool GetCurve(TSubclassOf<AActor> ArrayType,UCurveTable* Table,UAbilitySystemComponent* Ability);

	UPROPERTY(EditAnywhere,BlueprintReadOnly)
	FTimerHandle timeh;
	UFUNCTION(BlueprintImplementableEvent)
	void SpawnAiRef();

	UFUNCTION(BlueprintPure ,Category="WaveSystem")
	TSubclassOf<APawn> GetRandomAi();


};