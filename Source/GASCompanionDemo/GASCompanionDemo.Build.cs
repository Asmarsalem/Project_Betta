// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;

public class GASCompanionDemo : ModuleRules
{
	public GASCompanionDemo(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {"NavigationSystem", "Core", "CoreUObject", "Engine", "InputCore","GASCompanion","TestGFRuntime","PlayFab","HTTP"});

		PrivateDependencyModuleNames.AddRange(new string[]
		{
			"GASCompanion",
			"GameplayTags",
			"GameplayAbilities",
			"PlayFab", "PlayFabCpp", "PlayFabCommon", "TestGFRuntime","FirebaseFeatures", "ChunkDownloader"
		});
		// Here is where you should set these flags
		bUseAVX = true;
		bEnableExceptions = true;
	}

}
