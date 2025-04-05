// Fill out your copyright notice in the Description page of Project Settings.


#include "RacingVehicle.h"
#include "Components/AudioComponent.h"
#include "Net/UnrealNetwork.h"

ARacingVehicle::ARacingVehicle()
{
	PrimaryActorTick.bCanEverTick = true;
	bReplicates = true;
	bAlwaysRelevant = true;

	IdleAudioComponent = CreateDefaultSubobject<UAudioComponent>(TEXT("IdleAudioComponent"));
	IdleAudioComponent->SetupAttachment(GetRootComponent());
	IdleAudioComponent->bAutoActivate = false;

	AccelerateAudioComponent = CreateDefaultSubobject<UAudioComponent>(TEXT("AccelerateAudioComponent"));
	AccelerateAudioComponent->SetupAttachment(GetRootComponent());
	AccelerateAudioComponent->bAutoActivate = false;

	EngineAudioComponent = CreateDefaultSubobject<UAudioComponent>(TEXT("EngineAudioComponent"));
	EngineAudioComponent->SetupAttachment(GetRootComponent());
	EngineAudioComponent->bAutoActivate = false;
	
}

void ARacingVehicle::BeginPlay()
{
	Super::BeginPlay();
}

void ARacingVehicle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ARacingVehicle::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(ARacingVehicle, IdleSound);
	DOREPLIFETIME(ARacingVehicle, AccelerateSound);
	DOREPLIFETIME(ARacingVehicle, EngineSound);
}
