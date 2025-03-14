// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "StartMenu.generated.h"

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
};
