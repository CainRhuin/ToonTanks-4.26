// Copyright Total Rhuination Games.

#include "PawnBase.h"
#include "Components/CapsuleComponent.h"

// Sets default values
APawnBase::APawnBase()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CapsuleComp = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule Collider"));
	RootComponent = CapsuleComp;

	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Base Mesh"));
	BaseMesh->SetupAttachment(RootComponent);

	TurretMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Turret Mesh"));
	TurretMesh->SetupAttachment(BaseMesh);

	ProjectileSpawnPoint = CreateDefaultSubobject<USceneComponent>(TEXT("Projectile Spawn Point"));
	ProjectileSpawnPoint->SetupAttachment(TurretMesh);
}

void APawnBase::RotateTurret(FVector LookAtTarget)
{
	// Update TurretMesh rotation to face towards the LookAtTarget passed in from child classes
	FVector LookAtTargetCleaned = FVector(LookAtTarget.X, LookAtTarget.Y, TurretMesh->GetComponentLocation().Z);
	FVector StartLocation = TurretMesh->GetComponentLocation();

	FRotator TurretRotation = FVector(LookAtTargetCleaned - StartLocation).Rotation();
	TurretMesh->SetWorldRotation(TurretRotation);
	// TurretMesh->SetWorldRotation()...
}

void APawnBase::Fire()
{
	UE_LOG(LogTemp, Warning, TEXT("Fire Condition Success"));
	// Get ProjectileSpawnPoint location && Rotation-> Spawn Projectile class at location firing towards rotation
}

void APawnBase::HandleDestruction()
{
	// --- Universal functionality ---
	// Play death effects particle, sound and camera shake.

	// --- Then do child overrides
	// -- PawnTuret -- Inform GameMode Turret died -> Then destroy self.

	// -- PawnTank -- Inform GameMode Player died -> Then Hide() all components && stop movement input.
}


