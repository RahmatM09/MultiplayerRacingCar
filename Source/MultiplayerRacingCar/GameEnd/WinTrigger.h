// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "WinTrigger.generated.h"

class UBoxComponent;
class ARacingVehicle;

UCLASS()
class MULTIPLAYERRACINGCAR_API AWinTrigger : public AActor
{
	GENERATED_BODY()
	
public:	
	AWinTrigger();
	virtual void Tick(float DeltaTime) override;


protected:
	virtual void BeginPlay() override;

private:
	// Components
	UPROPERTY(VisibleAnywhere, Category = "Components")
	TObjectPtr<UBoxComponent> TriggerBox;

	TObjectPtr<ARacingVehicle> WinnerVehicle;

	// Handling winner
	UFUNCTION(Server, Reliable)
	void Server_HandleWinner(ARacingVehicle* Winner);

	UFUNCTION(NetMulticast, Reliable)
	void Net_Multicast_HandleWinner(ARacingVehicle* Winner);

	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);
};
