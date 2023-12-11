// Copyright 2021-2022 Mickael Daniel. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "Gi_TopDownShooter_GameInstance.generated.h"

/**
 * 
 */
UCLASS()
class GASCOMPANIONDEMO_API UGi_TopDownShooter_GameInstance : public UGameInstance
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable,Category="PlayFab_Login")
	void Login();
	
};
