// Copyright 2021-2022 Mickael Daniel. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "Gi_TopDownShooter_GameInstance.generated.h"

/**
 * 
 */
DECLARE_DYNAMIC_DELEGATE_OneParam(FCheckInternetConnection,bool,IsValid);
UCLASS()
class GASCOMPANIONDEMO_API UGi_TopDownShooter_GameInstance : public UGameInstance
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable,Category="PlayFab_Login")
	void Login(FString CustomId);

	UFUNCTION()
	void OnLoginSuccess(FClientLoginResult result, UObject* customData);
	UFUNCTION()
	void OnLoginFailure(FPlayFabError error, UObject* customData);
	UFUNCTION(BlueprintPure,Category="PlayFab_Login")
	FString GetWindowsDeviceID();

	UFUNCTION(BlueprintCallable)
	void CheckInternetConnection(FCheckInternetConnection GetResponse);
};
