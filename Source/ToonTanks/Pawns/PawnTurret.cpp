// Copyright Total Rhuination Games


#include "PawnTurret.h"
#include "Kismet/GameplayStatics.h"

void APawnTurret::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void APawnTurret::BeginPlay()
{
	Super::BeginPlay();

	GetWorld()->GetTimerManager().SetTimer(FireRateTimerHandle, this, &APawnTurret::CheckFireCondition, FireRate, true);
}

void APawnTurret::CheckFireCondition()
{
	// If player is valid || is dead then bail

	// if player is in range then fire

	UE_LOG(LogTemp, Warning, TEXT("Fire Condition Checked"));
}