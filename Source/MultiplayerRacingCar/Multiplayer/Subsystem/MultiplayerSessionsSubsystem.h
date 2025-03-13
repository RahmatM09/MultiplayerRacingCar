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

protected:
	UFUNCTION(BlueprintCallable, Category = "Multiplayer")
	void CreateSession();
	
	/// Delegate Callback functions
	void OnCreateSessionComplete(FName SessionName, bool bWasSuccessful);
	
private:
	/// Multiplayer Subsystem Variables
	IOnlineSubsystem* OnlineSubsystem;
	IOnlineSessionPtr SessionInterface;

	/// Multiplayer Delegates
	FOnCreateSessionCompleteDelegate OnCreateSessionCompleteDelegate;
	
};
