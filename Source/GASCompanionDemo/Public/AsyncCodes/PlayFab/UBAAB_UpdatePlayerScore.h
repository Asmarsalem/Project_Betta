// Copyright 2021-2022 Mickael Daniel. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Interfaces/IHttpRequest.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "UBAAB_UpdatePlayerScore.generated.h"

/**
 * 
 */
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnReponseOutput,FString,Data,bool,IsSuccess);
UCLASS()
class GASCOMPANIONDEMO_API UUBAAB_UpdatePlayerScore : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable,meta=(BlueprintInternalUseOnly))
	static UUBAAB_UpdatePlayerScore* UpdatePlayerScore(float Score);
private:
	virtual void Activate() override;
	UPROPERTY(BlueprintAssignable)
	FOnReponseOutput OnReponseOutput;

	void OnResponse(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bConnectedSuccessfully);
};
