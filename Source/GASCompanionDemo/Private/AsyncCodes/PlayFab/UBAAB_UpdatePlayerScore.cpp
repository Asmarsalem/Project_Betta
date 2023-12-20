// Copyright 2021-2022 Mickael Daniel. All Rights Reserved.


#include "AsyncCodes/PlayFab/UBAAB_UpdatePlayerScore.h"

#include "HttpModule.h"
#include "PlayFabCommonSettings.h"
#include "Interfaces/IHttpResponse.h"

UUBAAB_UpdatePlayerScore* UUBAAB_UpdatePlayerScore::UpdatePlayerScore(float Score)
{
	UUBAAB_UpdatePlayerScore* UpdatePlayerScoreInstance=NewObject<UUBAAB_UpdatePlayerScore>();
	FHttpModule& HttpModule=FHttpModule::Get();
	TSharedRef<IHttpRequest> Request=HttpModule.CreateRequest();
	Request->SetVerb("POST");
	Request->SetURL("https://BCEEB.playfabapi.com/Client/UpdatePlayerStatistics");
	FString SessionTicket=PlayFabCommon::PlayFabCommonSettings::clientSessionTicket;
	Request->SetHeader("X-Authorization",SessionTicket);
	Request->SetHeader("Content-Type","application/json");
	FString StaticName="TDleaderboard";
	int32 ScoreInt = FMath::RoundToInt(Score);
	FString JsonString = FString::Printf(TEXT("{\"Statistics\": [{\"StatisticName\": \"%s\", \"Value\": \"%d\"}]}"), *StaticName,ScoreInt);
	Request->SetContentAsString(JsonString);
	Request->OnProcessRequestComplete().BindUObject(UpdatePlayerScoreInstance,&UUBAAB_UpdatePlayerScore::OnResponse);
	Request->ProcessRequest();
	return UpdatePlayerScoreInstance;
}

void UUBAAB_UpdatePlayerScore::Activate()
{
	Super::Activate();
}

void UUBAAB_UpdatePlayerScore::OnResponse(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bConnectedSuccessfully)
{
	bool IsValid= Response.Get()->GetResponseCode()==200 && bConnectedSuccessfully;
	OnReponseOutput.Broadcast(Response.Get()->GetContentAsString(),IsValid);
}
