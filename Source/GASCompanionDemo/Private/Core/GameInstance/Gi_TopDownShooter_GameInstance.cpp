// Copyright 2021-2022 Mickael Daniel. All Rights Reserved.


#include "Core/GameInstance/Gi_TopDownShooter_GameInstance.h"

#include "GlobalMacro.h"
#include "GenericPlatform/HttpRequestImpl.h"
#include "PlayFab/Classes/PlayFabClientModels.h"
#include "PlayFab/Classes/PlayFabClientAPI.h"
#if PLATFORM_WINDOWS
#include "Windows/AllowWindowsPlatformTypes.h"
#include <windows.h>
#include "Windows/HideWindowsPlatformTypes.h"
#endif

void UGi_TopDownShooter_GameInstance::Login(FString CustomId)
{
	FClientLoginWithCustomIDRequest Request;
	Request.CreateAccount=true;
	Request.CustomId=CustomId;
	
	UPlayFabClientAPI::FDelegateOnSuccessLoginWithCustomID LoginSuccess;
	LoginSuccess.BindUFunction(this,FName("OnLoginSuccess"));
	UPlayFabClientAPI::FDelegateOnFailurePlayFabError Error;
	Error.BindUFunction(this,FName("OnLoginFailure"));
	
	UPlayFabClientAPI::LoginWithCustomID(Request,LoginSuccess,Error,nullptr);
}

void UGi_TopDownShooter_GameInstance::OnLoginSuccess(FClientLoginResult result, UObject* customData)
{
	print("True");
}

void UGi_TopDownShooter_GameInstance::OnLoginFailure(FPlayFabError error, UObject* customData)
{
	print("False");
}

FString UGi_TopDownShooter_GameInstance::GetWindowsDeviceID()
{
	
	if (!PLATFORM_WINDOWS)
	{
		return TEXT("");
	}
	
	TCHAR VolumeNameBuffer[100];
	TCHAR FileSystemNameBuffer[100];
	DWORD VolumeSerialNumber;
	DWORD MaximumComponentLength;
	DWORD FileSystemFlags;

	// Replace "C:\\" with the appropriate drive if necessary
	if (GetVolumeInformation(TEXT("C:\\"), VolumeNameBuffer, 100, &VolumeSerialNumber, &MaximumComponentLength, &FileSystemFlags, FileSystemNameBuffer, 100))
	{
		return FString::Printf(TEXT("%lu"), VolumeSerialNumber);
	}

	return TEXT("");

}

void UGi_TopDownShooter_GameInstance::CheckInternetConnection(FCheckInternetConnection GetResponse)
{
	FHttpModule& HttpModule  = FHttpModule::Get();
	const TSharedRef<IHttpRequest> HttpRequest = HttpModule.CreateRequest();
	HttpRequest->SetVerb("Get");
	HttpRequest->SetURL("https://www.google.com");
	HttpRequest->OnProcessRequestComplete().BindLambda([GetResponse](FHttpRequestPtr Request,FHttpResponsePtr Response, bool bConnectedSuccessfully)
	{
		GetResponse.ExecuteIfBound(bConnectedSuccessfully);
	});
	HttpRequest->ProcessRequest();
	
}


