// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTanks.h"
#include "Tank.h"
#include "TankBarrelComponent.h"
#include "TankAimingComponent.h"
#include "TankTurretComponent.h"
#include "TankMovementComponent.h"
#include "Projectile.h"

// Sets default values
ATank::ATank() :
	LaunchSpeed( 10000.0f )
{}

void ATank::AimAt( const FVector& HitLocation ) {
	if ( AimingComponent ) {
		AimingComponent->AimAt( HitLocation, LaunchSpeed );
	}
}

void ATank::Fire() {
	bool bIsReloaded = ( FPlatformTime::Seconds() - m_lastFireTime ) > ReloadTimeInSeconds;
	if ( Barrel && bIsReloaded ) {
		AProjectile* spawnedProjectile = GetWorld()->SpawnActor<AProjectile>(
												ProjectileBlueprint,
												Barrel->GetSocketLocation( FName( "LaunchLocation" ) ),
												Barrel->GetSocketRotation( FName( "LaunchLocation" ) )
											);

		spawnedProjectile->Launch( LaunchSpeed );

		//Reset timer
		m_lastFireTime = FPlatformTime::Seconds();
	}
}