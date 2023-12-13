// Copyright 2021-2022 Mickael Daniel. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "BFL_BlueprintFunctionLibrary.generated.h"

/**
 * 
 */
UCLASS()
class GASCOMPANIONDEMO_API UBFL_BlueprintFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintPure,Category="Global_Library")
	static bool IsAndroid();
	UFUNCTION(BlueprintPure,Category="Global_Library")
	static bool IsWindow();
	UFUNCTION(BlueprintPure,Category="Global_Library")
	static bool IsIos();
};
