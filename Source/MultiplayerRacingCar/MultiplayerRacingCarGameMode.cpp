// Copyright Epic Games, Inc. All Rights Reserved.

#include "MultiplayerRacingCarGameMode.h"
#include "MultiplayerRacingCarCharacter.h"
#include "UObject/ConstructorHelpers.h"

AMultiplayerRacingCarGameMode::AMultiplayerRacingCarGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
