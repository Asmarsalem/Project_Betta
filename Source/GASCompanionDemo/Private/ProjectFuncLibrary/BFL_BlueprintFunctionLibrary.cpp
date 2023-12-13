// Copyright 2021-2022 Mickael Daniel. All Rights Reserved.


#include "ProjectFuncLibrary/BFL_BlueprintFunctionLibrary.h"

bool UBFL_BlueprintFunctionLibrary::IsAndroid()
{
	if(PLATFORM_ANDROID)
	{
		return true;
	}
	return false;
}

bool UBFL_BlueprintFunctionLibrary::IsWindow()
{
	if(PLATFORM_WINDOWS)
	{
		return true;
	}
	return false;
}

bool UBFL_BlueprintFunctionLibrary::IsIos()
{
	if(PLATFORM_IOS)
	{
		return true;
	}
	return false;
}
