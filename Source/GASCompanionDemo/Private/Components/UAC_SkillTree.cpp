// Copyright 2021-2022 Mickael Daniel. All Rights Reserved.


#include "Components/UAC_SkillTree.h"

#include "Kismet/DataTableFunctionLibrary.h"
#include "Kismet/KismetSystemLibrary.h"

// Sets default values for this component's properties
UUAC_SkillTree::UUAC_SkillTree()
{

}


// Called when the game starts
void UUAC_SkillTree::BeginPlay()
{
	Super::BeginPlay();

	InitComponent();
	
}

void UUAC_SkillTree::InitComponent()
{
	// Get TheSkillsCommonTreeItems Data Table
	UDataTable* Table=FindObject<UDataTable>(ANY_PACKAGE, *FName("DT_SkillsCommonTreeItems").ToString());
	
	if(Table)
	{
		UDataTableFunctionLibrary::GetDataTableRowNames(Table,Abilities);//Get The Row Names
	}
	// Get Character Class
	FString CharacterClass=(UKismetSystemLibrary::GetClassDisplayName(GetOwner()->GetInstigator()->GetClass()));
	// Filter The String Remove Bp and _C
	CharacterClass.RemoveFromEnd(TEXT("_C"));
	CharacterClass.RemoveFromStart(TEXT("BP_"));
	//Get Data Table Of The Character Class
	FString DataTableName = FString::Printf(TEXT("DT_%sSkillTree"), *CharacterClass);
	UDataTable* CharacterDataTable = FindObject<UDataTable>(ANY_PACKAGE, *DataTableName);
	if(CharacterDataTable)
	{
		// Get The Row Name And Add it to abilities array
		TArray<FName> CharacterOutRowNames;
		UDataTableFunctionLibrary::GetDataTableRowNames(CharacterDataTable,CharacterOutRowNames);
		UE_LOG(LogTemp,Error,TEXT("table length %d "),CharacterOutRowNames.Num());
		Abilities.Append(CharacterOutRowNames);
	}

}


