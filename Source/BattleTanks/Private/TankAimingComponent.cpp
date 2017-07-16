// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTanks.h"
#include "TankAimingComponent.h"
#include "TankBarrelComponent.h"
#include "TankTurretComponent.h"
#include "Projectile.h"

// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent() :
	BarrelMesh( nullptr )
{
	PrimaryComponentTick.bCanEverTick	= true;
}

void UTankAimingComponent::TickComponent( float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) {
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );
	
	if ( ( FPlatformTime::Seconds() - m_lastFireTime ) < ReloadTimeInSeconds ) {
		CurrentStatus = EFiringStatus::Reloading;
	} else if ( IsBarrelMoving() ) {
		CurrentStatus = EFiringStatus::Aiming;
	} else {
		CurrentStatus = EFiringStatus::Locked;
	}
}

void UTankAimingComponent::AimAt( const FVector& AimAtLocation ) {
	if ( ensure( BarrelMesh ) ) { 
		FVector	OutLaunchVelocity;
		FVector StartLocation		= BarrelMesh->GetSocketLocation( FName( "LaunchLocation" ) );
		if ( UGameplayStatics::SuggestProjectileVelocity(
				this,
				OutLaunchVelocity,
				StartLocation,
				AimAtLocation,
				LaunchSpeed,
				false,
				0.0f,
				0.0f, 
				ESuggestProjVelocityTraceOption::DoNotTrace
			) ) {
			FVector LaunchVector = OutLaunchVelocity.GetSafeNormal();

			MoveBarrel( LaunchVector );
			m_lastAimDirection = LaunchVector;
		}
	}
}

void UTankAimingComponent::Initialize( UTankBarrelComponent* barrel, UTankTurretComponent* turret ) {
	BarrelMesh = barrel;
	TurretMesh = turret;
}

void UTankAimingComponent::MoveBarrel( const FVector& AimDirection ) {
	FRotator CurrentRotation	= BarrelMesh->GetForwardVector().Rotation();
	FRotator TargetRotation		= AimDirection.Rotation();
	FRotator DeltaRotation		= TargetRotation - CurrentRotation;

	BarrelMesh->Elevate( DeltaRotation.Pitch );
	TurretMesh->Turn( DeltaRotation.Yaw );
}

void UTankAimingComponent::Fire() {
	if ( CurrentStatus != EFiringStatus::Reloading && ensure( BarrelMesh && ProjectileBlueprint ) ) {
		AProjectile* spawnedProjectile = GetWorld()->SpawnActor<AProjectile>(
			ProjectileBlueprint,
			BarrelMesh->GetSocketLocation( FName( "LaunchLocation" ) ),
			BarrelMesh->GetSocketRotation( FName( "LaunchLocation" ) )
		);

		spawnedProjectile->Launch( LaunchSpeed );

		//Reset timer
		m_lastFireTime = FPlatformTime::Seconds();
	}
}

bool UTankAimingComponent::IsBarrelMoving( void ) {
	if ( ensure( BarrelMesh ) ) {
		return !m_lastAimDirection.Equals( BarrelMesh->GetForwardVector(), 0.1f );
	} else {
		return false;
	}
}