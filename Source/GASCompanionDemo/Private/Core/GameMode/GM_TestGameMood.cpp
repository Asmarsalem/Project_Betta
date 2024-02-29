// Copyright 2021-2022 Mickael Daniel. All Rights Reserved.


#include "Core/GameMode/GM_TestGameMood.h"
// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystemComponent.h"
#include "AbilitySystemInterface.h"
#include "NavigationSystem.h"
#include "Attributes/XPAttributeSet.h"
#include "Components/TimelineComponent.h"
#include "Engine/CurveTable.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"
float timeLinePreviousValue;
bool reverse;

void AGM_TestGameMood::BeginPlay()
{
	Super::BeginPlay();
	FTimerDelegate Timerd=FTimerDelegate::CreateLambda([this]()
	{
		if (IsValid(this))
		{
			SpawnAiRef();
		}
	});
	GetWorld()->GetTimerManager().SetTimer(timeh,Timerd,1.5f,true);
}

void AGM_TestGameMood::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
	// Clear Timer Instance
	GetWorld()->GetTimerManager().ClearTimer(timeh);
}

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

	FVector AGM_TestGameMood::GetRandomReachableLocation(TSubclassOf<AActor> PlayerCharacter,bool& Success)
{
	// init Local Vars
	UNavigationSystemV1* NavSys = FNavigationSystem::GetCurrent<UNavigationSystemV1>(GetWorld());
	AActor* OutActors;
	FNavLocation ProjectedLocation;
	// Get All Actor Ref  
	OutActors=UGameplayStatics::GetActorOfClass(this,PlayerCharacter);
	// Get First Actor
	FVector PlayerLocation = OutActors->GetActorLocation();
	PlayerLocation.Z=300.f;
	if(!NavSys || !OutActors ){Success=false; return FVector::ZeroVector;}
	// Add the Spawn Points To Array
	TArray<FVector> PlayerLocationArray{FVector(PlayerLocation.X-3000.f,PlayerLocation.Y-1500.f,PlayerLocation.Z),
		FVector(PlayerLocation.X-3000.f,PlayerLocation.Y+1500.f,PlayerLocation.Z),
		FVector(PlayerLocation.X+3000,PlayerLocation.Y+1500.f,PlayerLocation.Z),
		FVector(PlayerLocation.X+3000.f,PlayerLocation.Y-1500.f,PlayerLocation.Z),
		FVector(PlayerLocation.X+3000.f,PlayerLocation.Y,PlayerLocation.Z),
		FVector(PlayerLocation.X-3000.f,PlayerLocation.Y,PlayerLocation.Z),
		FVector(PlayerLocation.X,PlayerLocation.Y+3000.f,PlayerLocation.Z),
		FVector(PlayerLocation.X,PlayerLocation.Y-3000.f,PlayerLocation.Z)
	};
	// Shuffle The Array
	if (PlayerLocationArray.Num() > 0)
	{
		for (int32 Index = 0; Index < PlayerLocationArray.Num() - 1; ++Index)
		{
			int32 RandomIndex = FMath::RandRange(Index, PlayerLocationArray.Num() - 1);
			if (RandomIndex != Index)
			{
				PlayerLocationArray.Swap(Index, RandomIndex);
			};
		};
	};
	// Check The Points If Valid In the Array 
	for(FVector PlayerLocationArrayRef : PlayerLocationArray)
	{
		if(NavSys->ProjectPointToNavigation(PlayerLocationArrayRef, ProjectedLocation, FVector::ZeroVector))
		{
			// valid Location
			Success=true;
			return PlayerLocationArrayRef;
		}
	}
	// Invalid Location
	Success=false;
	return FVector::ZeroVector;
}

bool AGM_TestGameMood::GetCurve(TSubclassOf<AActor> ArrayType,UCurveTable* Table,UAbilitySystemComponent* Ability)
{
	if (!Table || !Ability) return 0.0f;
		FName RowName = FName(TEXT("General"));
		static const FString ContextString(TEXT("LookupCurveValue"));

		// Assuming you want to get a FRichCurve from the UCurveTable
		FRealCurve* Curve = Table->FindCurve(RowName, ContextString, true);

		if (Curve)
		{
			TArray<AActor*> OutActor;
			UGameplayStatics::GetAllActorsOfClass(this,ArrayType,OutActor);
			int32 AbilityLevel=Ability->GetNumericAttribute(UXPAttributeSet::GetLevelAttribute());
			int CurveValue=Curve->Eval(FMath::Clamp(AbilityLevel,0,	Curve->GetNumKeys()));
			if(OutActor.Num() <= CurveValue){return true;};
			

		}
	return false;
}

TSubclassOf<APawn> AGM_TestGameMood::GetRandomAi(UAbilitySystemComponent* Gas)
{
	float CurrentLevel = 0;
	if(Ai.IsEmpty()){return nullptr;}
	
	if(Gas)
	{
		CurrentLevel = Gas->GetNumericAttribute(UXPAttributeSet::GetLevelAttribute())/10;
	}
	int AiIndex = 0;
	const float RandomNb=UKismetMathLibrary::RandomFloatInRange(0,SetAiArrayRandLength(CurrentLevel));
	UE_LOG(LogTemp,Error,TEXT("RandomNb:%f"),RandomNb);
	float CurrentNb = 0;
	float PreviousNb=0;
	for(float i=0;i<Ai.Num();i++)
	{
		 CurrentNb=(CurrentNb+(UKismetMathLibrary::Conv_IntToFloat(Ai.Num())-i))+CurrentLevel;
			UE_LOG(LogTemp,Error,TEXT("CurrentNb:%f"),CurrentNb);
		if(PreviousNb>RandomNb&&RandomNb<CurrentNb)
		{UE_LOG(LogTemp,Error,TEXT("index:%f"),i);
			AiIndex=i;
			break;
		}
		PreviousNb=CurrentNb;
	}
	return Ai[AiIndex];
}

float AGM_TestGameMood::SetAiArrayRandLength(float CurrentLevel)
{

	
	if(Ai.IsEmpty()){return false;}
	float TotalNb = 0;
	for(float i=0;i<Ai.Num();i++)
	{
		TotalNb=(TotalNb+(UKismetMathLibrary::Conv_IntToFloat(Ai.Num())-i))+CurrentLevel;
	}
	UE_LOG(LogTemp,Error,TEXT("TotalNb:%f"),TotalNb);
	return TotalNb;
}

