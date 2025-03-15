// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "StartMenu.generated.h"

/// forward delcare
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

	UPROPERTY()
	TObjectPtr<UMultiplayerSessionsSubsystem> SessionsSubsystem;

	UFUNCTION()
	void StartGameClicked();

	UFUNCTION()
	void JoinGameClicked();
	
};
