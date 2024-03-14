// Copyright 2021-2022 Mickael Daniel. All Rights Reserved.


#include "GlobalFunc/UBFL_GlobalFunc.h"

#include "Kismet/GameplayStatics.h"

void UUBFL_GlobalFunc::RestartTheCurentLevel(const UObject* WorldContextObject)
{
	UGameplayStatics::OpenLevel(WorldContextObject,FName(UGameplayStatics::GetCurrentLevelName(WorldContextObject,true)),true);
}

FString UUBFL_GlobalFunc::RemoveFromEnd(FString Input,FString InPrefix)
{
	Input.RemoveFromEnd(InPrefix);
	return Input;
}

FString UUBFL_GlobalFunc::RemoveFromStart(FString Input,FString InPrefix)
{
	Input.RemoveFromStart(InPrefix);
	return Input;
}
