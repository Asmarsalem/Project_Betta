// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;

public class GASCompanionDemo : ModuleRules
{
	public GASCompanionDemo(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore","GASCompanion" });

		PrivateDependencyModuleNames.AddRange(new string[]
		{
			"GASCompanion",
			"GameplayTags",
			"GameplayAbilities",
			"PlayFab", "PlayFabCpp", "PlayFabCommon"
		});
		// Here is where you should set these flags
		bUseAVX = true;
		bEnableExceptions = true;
	}

}
