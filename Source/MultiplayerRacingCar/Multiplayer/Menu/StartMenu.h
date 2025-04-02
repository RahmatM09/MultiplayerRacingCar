// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Interfaces/OnlineSessionInterface.h"
#include "StartMenu.generated.h"

class UEditableTextBox;
class UCheckBox;
class UComboBoxString;
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

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UComboBoxString> NumberOfPlayers;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UCheckBox> bCustomSessionID;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UEditableTextBox> NewSessionID;

	FString MatchTypeName {TEXT("ProMultiplayerGame")};

	FString MapLocation = {TEXT("/Game/Maps/Lobby?listen")};

	UPROPERTY()
	TObjectPtr<UMultiplayerSessionsSubsystem> SessionsSubsystem;

	UFUNCTION()
	void StartGameClicked();

	UFUNCTION()
	void OnCustomSessionClicked(bool bIsChecked);

	UFUNCTION()
	void JoinGameClicked();

	void RemoveMenu();

	/// Delegate Callback functions
	UFUNCTION()
	void OnMultiplayerCreateSession(bool bWasSuccessful);
	void OnMultiplayerFindSessionsComplete(const TArray<FOnlineSessionSearchResult>& SearchResults, bool bWasSuccessful);
	void OnMultiplayerJoinSessionComplete(EOnJoinSessionCompleteResult::Type Result);
	
};
