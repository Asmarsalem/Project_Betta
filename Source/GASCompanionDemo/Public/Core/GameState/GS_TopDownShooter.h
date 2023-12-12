// Copyright 2021-2022 Mickael Daniel. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameState.h"
#include "GS_TopDownShooter.generated.h"
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FhandleAddExpSignature);
/**
 * 
 */
UCLASS()

class GASCOMPANIONDEMO_API  AGS_TopDownShooter : public AGameState
{
	GENERATED_BODY()
public:
	// Override Default Func
	AGS_TopDownShooter();
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	
	// EXP
	UPROPERTY(Replicated,BlueprintReadOnly,Category="EXP")
	float Exp;
	UPROPERTY(EditDefaultsOnly,Replicated,BlueprintReadOnly,Category="EXP")
	float EXPRemaining;
	UFUNCTION(BlueprintCallable)
	void addExp(float value);
	UPROPERTY(BlueprintAssignable,Category="EXP")
	FhandleAddExpSignature handleAddExp;


};
