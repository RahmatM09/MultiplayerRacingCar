// Fill out your copyright notice in the Description page of Project Settings.


#include "GameEndAnnouncement.h"

#include "Components/TextBlock.h"

void UGameEndAnnouncement::DisplayEndGameMenu(FString EndGameResult)
{
	AddToViewport();
	SetVisibility(ESlateVisibility::Visible);
	SetIsFocusable(true);

	EndGameText->SetText(FText::FromString(EndGameResult));
}
