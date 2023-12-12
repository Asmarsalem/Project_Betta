// Copyright 2021-2022 Mickael Daniel. All Rights Reserved.

#include "Core/GameState/GS_TopDownShooter.h"
#include "Net/UnrealNetwork.h"

AGS_TopDownShooter::AGS_TopDownShooter()
{
	bReplicates=true;
}

void AGS_TopDownShooter::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AGS_TopDownShooter, Exp);
}

void AGS_TopDownShooter::addExp(float value)
{
	
	if (HasAuthority())
	{
		
		Exp+=value;
		if (Exp>=EXPRemaining)
		{
			EXPRemaining=EXPRemaining*2;
			
		}
		handleAddExp.Broadcast();
	}
}




