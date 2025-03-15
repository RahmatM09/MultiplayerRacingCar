// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "StartMenu.generated.h"

/// forward declare
class UButton;
class UMultiplayerSessionsSubsystem;
/**
 * 
 */
UCLASS()
class MULTIPLAYERRACINGCAR_API UStartMenu : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "StartMenu")
	void StartMenu();

protected:
	virtual bool Initialize() override;
	
private:
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UButton> StartGame;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UButton> JoinGame;

	FString MapLocation = {TEXT("/Game/Maps/Lobby?listen")};

	UPROPERTY()
	TObjectPtr<UMultiplayerSessionsSubsystem> SessionsSubsystem;

	UFUNCTION()
	void StartGameClicked();

	UFUNCTION()
	void JoinGameClicked();

	void RemoveMenu();

	/// Delegate Callback functions
	UFUNCTION()
	void OnMultiplayerCreateSession(bool bWasSuccessful);
	
};
