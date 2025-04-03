// Fill out your copyright notice in the Description page of Project Settings.


#include "CountdownActor.h"

#include "Components/BoxComponent.h"
#include "Net/UnrealNetwork.h"

ACountdownActor::ACountdownActor()
{
	PrimaryActorTick.bCanEverTick = true;
	bReplicates = true;
	bAlwaysRelevant = true;

	BoxCollisionComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollisionComponent"));
	SetRootComponent(BoxCollisionComponent);
	BoxCollisionComponent->SetCollisionResponseToAllChannels(ECR_Block);

	CountdownTime = 8;
	
}

void ACountdownActor::BeginPlay()
{
	Super::BeginPlay();

	if (HasAuthority())
	{
		Server_StartCountdown();
	}
}


void ACountdownActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACountdownActor::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(ACountdownActor, CountdownTime);
}


void ACountdownActor::Server_StartCountdown_Implementation()
{
	GetWorld()->GetTimerManager().SetTimer(CountdownTimerHandle, this, &ACountdownActor::UpdateCountdown, 1.f, true);
}

void ACountdownActor::UpdateCountdown()
{
	if (HasAuthority())
	{
		CountdownTime--;
		if (CountdownTime <= 0)
		{
			GetWorld()->GetTimerManager().ClearTimer(CountdownTimerHandle);
			Destroy();
		}
	}
}

