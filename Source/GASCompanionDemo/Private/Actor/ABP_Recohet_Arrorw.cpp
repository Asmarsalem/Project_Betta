// Copyright 2021-2022 Mickael Daniel. All Rights Reserved.


#include "Actor/ABP_Recohet_Arrorw.h"

#include "AbilitySystemComponent.h"
#include "AbilitySystemInterface.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"


// Sets default values
AABP_Recohet_Arrorw::AABP_Recohet_Arrorw()
{
	// Init Root Component
	DefaultSceneRoot=CreateDefaultSubobject<USceneComponent>("Root");
	RootComponent = DefaultSceneRoot;
	// init Static Mesh
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMesh->SetupAttachment(RootComponent);
	// init Box Component
	BoxComponent=CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComponent"));
	BoxComponent->SetupAttachment(StaticMesh);
	// Init Projectile
	ProjectileMovementComponent=CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovementComponent"));
}

// Called when the game starts or when spawned
void AABP_Recohet_Arrorw::BeginPlay()
{
	Super::BeginPlay();
	BoxComponent->OnComponentBeginOverlap.AddDynamic(this,&AABP_Recohet_Arrorw::OnComponentBeginOvelarp);
	
}

void AABP_Recohet_Arrorw::OnComponentBeginOvelarp(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	/*if( OtherActor && OtherActor != GetInstigator())
	{Bouncing();
		if(IAbilitySystemInterface* AbilitySystemInterface=Cast<IAbilitySystemInterface>(OtherActor->GetInstigator()))
		{
			UAbilitySystemComponent* AbilitySystemComponent=Cast<UAbilitySystemComponent>(AbilitySystemInterface->GetAbilitySystemComponent());
			FGameplayEffectSpecHandle EffectSpecHandle = AbilitySystemComponent->MakeOutgoingSpec(GameplayEffect, 0.f, AbilitySystemComponent->MakeEffectContext());
			if(EffectSpecHandle.IsValid())
			{
				UE_LOG(LogTemp,Error,TEXT("ApplyGameplayEffectSpecToTarget"));
				AbilitySystemComponent->ApplyGameplayEffectSpecToTarget(*EffectSpecHandle.Data.Get(),AbilitySystemComponent);
			}
		}
	}*/
}

void AABP_Recohet_Arrorw::Bouncing()
{
	if(CurrentIndex>MaxIndex)
	{
		K2_DestroyActor();
	}
	CurrentIndex++;
	TArray<AActor*> OutActors;
	float ClosetActorDistance;
	UGameplayStatics::GetAllActorsOfClass(this,AiParent,OutActors);
	AActor* ClosetActor=UGameplayStatics::FindNearestActor(FVector::Zero(),OutActors,ClosetActorDistance);
	FRotator ActorRotation=UKismetMathLibrary::FindLookAtRotation(GetActorLocation(),ClosetActor->GetActorLocation());
	FVector VelocityCalculation=UKismetMathLibrary::GetForwardVector(ActorRotation)*ProjectileVelocitySpeed;
	ProjectileMovementComponent->Velocity=VelocityCalculation;
}



