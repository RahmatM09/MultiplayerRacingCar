// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "WheeledVehiclePawn.h"
#include "RacingVehicle.generated.h"

class UGameEndAnnouncement;
class UAudioComponent;
class USoundBase;
/**
 * 
 */
UCLASS()
class MULTIPLAYERRACINGCAR_API ARacingVehicle : public AWheeledVehiclePawn
{
	GENERATED_BODY()

public:
	ARacingVehicle();
	
	UPROPERTY(EditAnywhere, Category = "WinnerAnnouncement")
	TObjectPtr<UGameEndAnnouncement> GameAnnouncement;

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	
private:
	// Audio Components
	UPROPERTY(VisibleAnywhere, Category = "Audio Components")
	TObjectPtr<UAudioComponent> IdleAudioComponent;

	UPROPERTY(VisibleAnywhere, Category = "Audio Components")
	TObjectPtr<UAudioComponent> AccelerateAudioComponent;

	UPROPERTY(VisibleAnywhere, Category = "Audio Components")
	TObjectPtr<UAudioComponent> EngineAudioComponent;

	// Audio Variable
	UPROPERTY(Replicated, EditAnywhere, Category = "Audio")
	TObjectPtr<USoundBase> IdleSound;

	UPROPERTY(Replicated, EditAnywhere, Category = "Audio")
	TObjectPtr<USoundBase> AccelerateSound;

	UPROPERTY(Replicated, EditAnywhere, Category = "Audio")
	TObjectPtr<USoundBase> EngineSound;
	
};
