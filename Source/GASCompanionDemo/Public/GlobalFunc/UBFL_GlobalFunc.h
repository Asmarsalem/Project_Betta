// Copyright 2021-2022 Mickael Daniel. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "UBFL_GlobalFunc.generated.h"

/**
 * 
 */
UCLASS()
class GASCOMPANIONDEMO_API UUBFL_GlobalFunc : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable,Category="Custom_Global_Func")
	static void RestartTheCurentLevel(const UObject* WorldContextObject);
	/*
	 * String Funcs
	 */
	UFUNCTION(BlueprintPure,Category="Custom_Global_Func | String")
	static FString  RemoveFromEnd(FString Input,FString InPrefix);
	UFUNCTION(BlueprintPure,Category="Custom_Global_Func | String")
	static FString  RemoveFromStart(FString Input,FString InPrefix);
};
