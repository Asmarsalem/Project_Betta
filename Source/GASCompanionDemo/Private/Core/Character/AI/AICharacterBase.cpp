// Copyright 2021-2022 Mickael Daniel. All Rights Reserved.


#include "Core/Character/AI/AICharacterBase.h"

#include "Abilities/Attributes/GSCAttributeSet.h"
#include "Attributes/XPAttributeSet.h"


// Sets default values
AAICharacterBase::AAICharacterBase()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AAICharacterBase::BeginPlay()
{
	Super::BeginPlay();
	if(!GSCAbilitySystemComponent)
	{
		UE_LOG(LogTemp, Error, TEXT("Connected"))
	}

}

// Called every frame
void AAICharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
void AAICharacterBase::OnHealthChange(const FOnAttributeChangeData& Data)const
{
	UE_LOG(LogTemp, Error, TEXT("Killed"));
}

void AAICharacterBase::InitAb( UGSCAbilitySystemComponent* GSCAbilitySystem)
{
	if (GSCAbilitySystem)
	{
		GSCAbilitySystemComponent=GSCAbilitySystem;
		if(const UGSCAttributeSet* Att =Cast<UGSCAttributeSet>(GSCAbilitySystemComponent->GetAttributeSet(UAttributeSet::StaticClass())))
		{
			UE_LOG(LogTemp, Error, TEXT("Done"));
			GSCAbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(Att->GetHealthAttribute()).AddUObject(this,&AAICharacterBase::OnHealthChange);
		}
	}
}

// Called to bind functionality to input
void AAICharacterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

