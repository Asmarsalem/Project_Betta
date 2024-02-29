// Copyright 2021-2022 Mickael Daniel. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "MyGlobalStruct.generated.h"
USTRUCT(BlueprintType)
struct FMyGlobalStruct
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName = "ID", meta = (RowType))
	FName RowId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString MyString;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float MyFloat;
};