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
	UpdateSound(DeltaTime);
}


void ARacingVehicle::UpdateSound(float DeltaTime)
{
	if (!EngineAudioComponent || !AccelerateAudioComponent || !IdleAudioComponent) return;

	float CurrentSpeed = GetVelocity().Size() * 0.0223694f;

	float TargetIdleSoundVolume = (CurrentSpeed < 10.f) ? 1.f : 0.f;
	float TargetEngineSoundVolume = (CurrentSpeed >= 10.f) ? 1.f : 0.f;

	float IdleValume = FMath::FInterpTo(IdleAudioComponent->VolumeMultiplier, TargetIdleSoundVolume, DeltaTime, 3.f);
	float EngineVolume = FMath::FInterpTo(EngineAudioComponent->VolumeMultiplier, TargetEngineSoundVolume, DeltaTime, 3.f);
	
	IdleAudioComponent->SetVolumeMultiplier(IdleValume);
	EngineAudioComponent->SetVolumeMultiplier(EngineVolume);
	
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
