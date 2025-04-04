// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "GameEndAnnouncement.generated.h"

class UTextBlock;
/**
 * 
 */
UCLASS()
class MULTIPLAYERRACINGCAR_API UGameEndAnnouncement : public UUserWidget
{
	GENERATED_BODY()

public:
	void DisplayEndGameMenu(FString EndGameResult);

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UTextBlock> EndGameText;
};
