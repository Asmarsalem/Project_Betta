// Copyright 2021-2022 Mickael Daniel. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayEffect.h"
#include "Components/BoxComponent.h"
#include "GameFramework/Actor.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "ABP_Recohet_Arrorw.generated.h"

UCLASS()
class GASCOMPANIONDEMO_API AABP_Recohet_Arrorw : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AABP_Recohet_Arrorw();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Define Components
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category="Components | Viewport")
	USceneComponent* DefaultSceneRoot;
	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category="Components | Viewport")
	UStaticMeshComponent* StaticMesh;
	UPROPERTY(VisibleAnywhere,BlueprintReadWrite, Category="Components | Viewport")
	UBoxComponent* BoxComponent;
	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category="Components | Viewport")
	UProjectileMovementComponent* ProjectileMovementComponent;
	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category="Components | Config")
	TSubclassOf<AActor> AiParent;

	
	// Init Vars
	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite, Category="Components | ProjectileMovementComponent")
	int MaxIndex;
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly, Category="Components | ProjectileMovementComponent")
	float ProjectileVelocitySpeed;
	UPROPERTY()
	int CurrentIndex;

	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly, Category="GAS | GameplayEffect")
	TSubclassOf<UGameplayEffect> GameplayEffect;

	//Default Func
	UFUNCTION()
	void OnComponentBeginOvelarp(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);
	UFUNCTION(BlueprintCallable, Category="Components | ProjectileMovementComponent | Func")
	void Bouncing();
	
};
