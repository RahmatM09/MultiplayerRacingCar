// Fill out your copyright notice in the Description page of Project Settings.


#include "StartMenu.h"

#include "Components/Button.h"
#include "MultiplayerRacingCar/Multiplayer/Subsystem/MultiplayerSessionsSubsystem.h"

void UStartMenu::StartMenu()
{
	AddToViewport();
	SetVisibility(ESlateVisibility::Visible);
	SetIsFocusable(true);

	if (UWorld* World = GetWorld())
	{
		if (APlayerController* PlayerController = World->GetFirstPlayerController())
		{
			FInputModeUIOnly InputMode;
			InputMode.SetWidgetToFocus(TakeWidget());
			InputMode.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
			PlayerController->SetInputMode(InputMode);
			PlayerController->SetShowMouseCursor(true);
		}
	}

	if (UGameInstance* GameInstance = GetGameInstance())
	{
		SessionsSubsystem = GameInstance->GetSubsystem<UMultiplayerSessionsSubsystem>();
		if (SessionsSubsystem)
		{
			SessionsSubsystem->MultiplayerCreateSessionCompleteDelegate.AddDynamic(this, &UStartMenu::OnMultiplayerCreateSession);
			SessionsSubsystem->MultiplayerFindSessionsCompleteDelegate.AddUObject(this, &UStartMenu::OnMultiplayerFindSessionsComplete);
			SessionsSubsystem->MultiplayerJoinSessionCompleteDelegate.AddUObject(this, &UStartMenu::OnMultiplayerJoinSessionComplete);
		}
	}
	
}

bool UStartMenu::Initialize()
{
	if (!Super::Initialize())
		return false;

	if (StartGame)
		StartGame->OnClicked.AddDynamic(this, &UStartMenu::StartGameClicked);
	if (JoinGame)
		JoinGame->OnClicked.AddDynamic(this, &UStartMenu::JoinGameClicked);

	return true;
}

void UStartMenu::StartGameClicked()
{
	if (SessionsSubsystem)
		SessionsSubsystem->CreateSession();
}

void UStartMenu::JoinGameClicked()
{
	if (SessionsSubsystem)
		SessionsSubsystem->JoinSession();
}

void UStartMenu::RemoveMenu()
{
	RemoveFromParent();
	if (UWorld* World = GetWorld())
	{
		if (APlayerController* PlayerController = World->GetFirstPlayerController())
		{
			FInputModeGameOnly InputMode;
			PlayerController->SetInputMode(InputMode);
			PlayerController->SetShowMouseCursor(false);
		}
	}
}

void UStartMenu::OnMultiplayerCreateSession(bool bWasSuccessful)
{
	if (bWasSuccessful)
	{
		if (UWorld* World = GetWorld())
		{
			World->ServerTravel(MapLocation);
			RemoveMenu();
		}
	}
}

void UStartMenu::OnMultiplayerFindSessionsComplete(const TArray<FOnlineSessionSearchResult>& SearchResults,
	bool bWasSuccessful)
{
	
}

void UStartMenu::OnMultiplayerJoinSessionComplete(EOnJoinSessionCompleteResult::Type Result)
{
	
}
