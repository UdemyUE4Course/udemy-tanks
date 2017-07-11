// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTanks.h"
#include "Tank.h"
#include "TankBarrelComponent.h"
#include "TankAimingComponent.h"
#include "TankTurretComponent.h"
#include "Projectile.h"

// Sets default values
ATank::ATank() :
	TankAimingComponent( nullptr ),
	LaunchSpeed( 10000.0f ),
	m_barrel( nullptr )
{
	PrimaryActorTick.bCanEverTick	= false;
	TankAimingComponent				= CreateDefaultSubobject<UTankAimingComponent>( FName( "AimingComponent" ) );
}

// Called when the game starts or when spawned
void ATank::BeginPlay() {
	Super::BeginPlay();

}

// Called to bind functionality to input
void ATank::SetupPlayerInputComponent( UInputComponent* PlayerInputComponent ) {
	Super::SetupPlayerInputComponent( PlayerInputComponent );

}

void ATank::AimAt( const FVector& HitLocation ) {
	TankAimingComponent->AimAt( HitLocation, LaunchSpeed );
}

void ATank::SetBarrelReference( UTankBarrelComponent* BarrelToSet ) {
	m_barrel = BarrelToSet;

	TankAimingComponent->SetBarrelReference( BarrelToSet );
}

void ATank::SetTurretReference( UTankTurretComponent* BarrelToSet ) {
	TankAimingComponent->SetTurretReference( BarrelToSet );
}

void ATank::Fire() {
	bool bIsReloaded = ( FPlatformTime::Seconds() - m_lastFireTime ) > ReloadTimeInSeconds;
	if ( m_barrel && bIsReloaded ) {
		AProjectile* spawnedProjectile = GetWorld()->SpawnActor<AProjectile>(
												ProjectileBlueprint,
												m_barrel->GetSocketLocation( FName( "LaunchLocation" ) ),
												m_barrel->GetSocketRotation( FName( "LaunchLocation" ) )
											);

		spawnedProjectile->Launch( LaunchSpeed );

		//Reset timer
		m_lastFireTime = FPlatformTime::Seconds();
	}
}