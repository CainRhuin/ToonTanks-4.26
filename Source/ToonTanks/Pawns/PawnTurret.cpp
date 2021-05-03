// Copyright Total Rhuination Games


#include "PawnTurret.h"
#include "Kismet/GameplayStatics.h"
#include "PawnTank.h"

void APawnTurret::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!PlayerPawn || ReturnDistanceToPlayer() > FireRange) return;

	RotateTurret(PlayerPawn->GetActorLocation());
}

void APawnTurret::BeginPlay()
{
	Super::BeginPlay();

	GetWorld()->GetTimerManager().SetTimer(FireRateTimerHandle, this, &APawnTurret::CheckFireCondition, FireRate, true);

	PlayerPawn = Cast<APawnTank>(UGameplayStatics::GetPlayerPawn(this, 0));
}

void APawnTurret::HandleDestruction()
{
	Super::HandleDestruction();
	Destroy();
}

void APawnTurret::CheckFireCondition()
{
	// If player is valid || is dead then bail
	if (!PlayerPawn) return;
	// if player is in range then fire
	if (ReturnDistanceToPlayer() <= FireRange)
	{
		Fire();
	}

}

float APawnTurret::ReturnDistanceToPlayer()
{
	if (!PlayerPawn) return 0;

	return FVector::Dist(PlayerPawn->GetActorLocation(), GetActorLocation());
}