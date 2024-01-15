// Copyright 2021-2022 Mickael Daniel. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "PatchingDemoGameInstance.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FPatchCompleteDelegate, bool, Succeeded);
/**
 * 
 */
UCLASS()
class UPatchingDemoGameInstance : public UGameInstance
{
	GENERATED_BODY()

	public:
	// Overrides
	virtual void Init() override;
	virtual void Shutdown() override;

	protected:
	//Tracks if our local manifest file is up to date with the one hosted on our website
	bool bIsDownloadManifestUpToDate;
	//Called when the chunk download process finishes
	void OnManifestUpdateComplete(bool bSuccess);

	public:
	UFUNCTION(BlueprintPure, Category = "Patching|Stats")
	void GetLoadingProgress(int32& BytesDownloaded, int32& TotalBytesToDownload, float& DownloadPercent, int32& ChunksMounted, int32& TotalChunksToMount, float& MountPercent) const;
	
	// Delegates
	// Fired when the patching process succeeds or fails
	UPROPERTY(BlueprintAssignable, Category="Patching");
	FPatchCompleteDelegate OnPatchComplete;

	protected:
	// List of Chunk IDs to try and download
	UPROPERTY(EditDefaultsOnly, Category="Patching")
	TArray<int32> ChunkDownloadList;

	public:
	// Starts the game patching process. Returns false if the patching manifest is not up to date. */
	UFUNCTION(BlueprintCallable, Category = "Patching")
	bool PatchGame();

protected:
	// Called when the chunk download process finishes
	void OnDownloadComplete(bool bSuccess);

	// Called whenever ChunkDownloader's loading mode is finished
	void OnLoadingModeComplete(bool bSuccess);

	// Called when ChunkDownloader finishes mounting chunks
	void OnMountComplete(bool bSuccess);
	
};
