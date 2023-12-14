// Copyright 2021-2022 Mickael Daniel. All Rights Reserved.


#include "Core/GameMode/GM_TestGameMood.h"
// Fill out your copyright notice in the Description page of Project Settings.


#include "core/GameMode/GM_TestGameMood.h"

#include "Components/TimelineComponent.h"
float timeLinePreviousValue;
bool reverse;
void AGM_TestGameMood::startNewWave(UCurveFloat* CurveFloat)
{
	reverse=false;
	timeLinePreviousValue=0.f;
	// Time Line Init
	MyTimeline = NewObject<UTimelineComponent>(this, FName("MyTimeline"));
  
	if (!MyTimeline)// Handle the error appropriately
		{
		return;
		}
	MyTimeline->CreationMethod = EComponentCreationMethod::UserConstructionScript;
	this->BlueprintCreatedComponents.Add(MyTimeline);

	// Create float Track instance
	FOnTimelineFloat TimelineFunction;
	TimelineFunction.BindUFunction(this, FName("onFloatTrackUpdate"));
	MyTimeline->AddInterpFloat(CurveFloat, TimelineFunction);
	//Create Finished Func Instance 
	FOnTimelineEventStatic FTimeLine;
	FTimeLine.BindUFunction(this,FName("onTimeLineFinished"));
	MyTimeline->SetTimelineFinishedFunc(FTimeLine);
  
	// Start The Time Line 
	MyTimeline->RegisterComponent();
	MyTimeline->PlayFromStart();

}

void AGM_TestGameMood::onFloatTrackUpdate(float value)
{
	// Convert value To Int
	const int intValue=FMath::TruncToInt(value);
	const double doubleValue= value - intValue;
		// On Trend Change
		if( (reverse && value > timeLinePreviousValue) || (!reverse && value < timeLinePreviousValue) )
		{
			
			// Float Validator
			if(( doubleValue < 0.1) || (doubleValue > 0.9) )
			{
				OnTimelineEvent(FMath::RoundToFloat(value));
			}
			
			reverse = !reverse;
		}
	// Update timeLinePreviousValue Value
	timeLinePreviousValue=value;
}