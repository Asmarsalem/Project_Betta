// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;
using System.Collections.Generic;

public class GASCompanionDemoTarget : TargetRules
{
	public GASCompanionDemoTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V2;

		ExtraModuleNames.AddRange( new string[] { "GASCompanionDemo" } );

		if (Target.Platform == UnrealTargetPlatform.Android)
		{
			ExtraModuleNames.AddRange(new string[] { "OnlineSubsystem", "OnlineSubsystemGooglePlay", "AndroidAdvertising" });
		}

	}
}
