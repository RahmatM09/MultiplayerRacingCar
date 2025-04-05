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
	
	if (HasAuthority())
	{
		Multicast_PlaySounds();
	}
	else
	{
		Server_RequestPlaySounds();
	}
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

void ARacingVehicle::Server_RequestPlaySounds_Implementation()
{
	Multicast_PlaySounds();
}

void ARacingVehicle::Multicast_PlaySounds_Implementation()
{
	if (IdleSound)
	{
		IdleAudioComponent->SetSound(IdleSound);
		IdleAudioComponent->Play();
		IdleAudioComponent->SetVolumeMultiplier(1.f);
	}
	if (AccelerateSound)
	{
		AccelerateAudioComponent->SetSound(AccelerateSound);
		AccelerateAudioComponent->Play();
		AccelerateAudioComponent->SetVolumeMultiplier(0.f);
	}
	if (EngineSound)
	{
		EngineAudioComponent->SetSound(EngineSound);
		EngineAudioComponent->Play();
		EngineAudioComponent->SetVolumeMultiplier(0.f);
	}
}
