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
