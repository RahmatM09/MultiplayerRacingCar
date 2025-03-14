// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Interfaces/OnlineSessionInterface.h"
#include "MultiplayerSessionsSubsystem.generated.h"

/// Forward Declaration
class IOnlineSubsystem;


/**
 * 
 */
UCLASS()
class MULTIPLAYERRACINGCAR_API UMultiplayerSessionsSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	UMultiplayerSessionsSubsystem();

	UFUNCTION(BlueprintCallable, Category = "Multiplayer")
	void CreateSession();

	UFUNCTION(BlueprintCallable, Category = "Multiplayer")
	void JoinSession();

protected:
	/// Delegate Callback functions
	void OnCreateSessionComplete(FName SessionName, bool bWasSuccessful);
	void OnFindSessionsComplete(bool bWasSuccessful);
	void OnJoinSessionComplete(FName SessionName, EOnJoinSessionCompleteResult::Type Result);
	
private:
	/// Multiplayer Subsystem Variables
	IOnlineSubsystem* OnlineSubsystem;
	IOnlineSessionPtr SessionInterface;
	TSharedPtr<FOnlineSessionSearch> SessionSearchSettings;

	/// Multiplayer Delegates
	FOnCreateSessionCompleteDelegate OnCreateSessionCompleteDelegate;
	FOnFindSessionsCompleteDelegate OnFindSessionsCompleteDelegate;
	FOnJoinSessionCompleteDelegate OnJoinSessionCompleteDelegate;
	
};
