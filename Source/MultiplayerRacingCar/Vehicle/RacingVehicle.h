// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "WheeledVehiclePawn.h"
#include "RacingVehicle.generated.h"

class UGameEndAnnouncement;

/**
 * 
 */
UCLASS()
class MULTIPLAYERRACINGCAR_API ARacingVehicle : public AWheeledVehiclePawn
{
	GENERATED_BODY()


public:
	UPROPERTY(EditAnywhere, Category = "WinnerAnnouncement")
	TObjectPtr<UGameEndAnnouncement> GameAnnouncement;
};
