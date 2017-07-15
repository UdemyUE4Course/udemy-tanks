// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTanks.h"
#include "TankAimingComponent.h"
#include "TankBarrelComponent.h"
#include "TankTurretComponent.h"

// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent() :
	BarrelMesh( nullptr )
{
}

void UTankAimingComponent::AimAt( const FVector& AimAtLocation, float LaunchSpeed ) {
	if ( !BarrelMesh ) { return; }

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