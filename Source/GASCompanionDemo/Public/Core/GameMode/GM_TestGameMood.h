// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "Components/TimelineComponent.h"
#include "GM_TestGameMood.generated.h"

/**
 * 
 */
UCLASS()
class GASCOMPANIONDEMO_API AGM_TestGameMood : public AGameMode
{
	GENERATED_BODY()
public:
	UPROPERTY()
	UTimelineComponent* MyTimeline;
	
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
	
};