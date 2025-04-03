// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CountdownActor.generated.h"

class UBoxComponent;

UCLASS()
class MULTIPLAYERRACINGCAR_API ACountdownActor : public AActor
{
	GENERATED_BODY()
	
public:	
	ACountdownActor();
	virtual void Tick(float DeltaTime) override;

protected:
	virtual void BeginPlay() override;
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	
private:
	// Components
	UPROPERTY(VisibleAnywhere, Category = "CountdownActor")
	TObjectPtr<UBoxComponent> BoxCollisionComponent;

	UPROPERTY(Replicated, BlueprintReadOnly, Category = "CountdownActor", meta = (AllowPrivateAccess = "true"))
	int32 CountdownTime;

	UFUNCTION()
	void UpdateCountdown();

	UFUNCTION(Server, Reliable)
	void Server_StartCountdown();

	FTimerHandle CountdownTimerHandle;

};
