// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTanks.h"
#include "TankAimingComponent.h"
#include "TankBarrelComponent.h"

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
		UE_LOG( LogTemp, Warning, TEXT( "Launching at vector: %s" ), *LaunchVector.ToString() );
	}
}

void UTankAimingComponent::SetBarrelReference( UTankBarrelComponent* BarrelToSet ) {
	BarrelMesh = BarrelToSet;
}

void UTankAimingComponent::MoveBarrel( const FVector& AimDirection ) {
	FRotator CurrentRotation	= BarrelMesh->GetSocketRotation( FName( "LaunchLocation" ) );
	FRotator TargetRotation		= AimDirection.Rotation();
	FRotator DeltaRotation		= TargetRotation - CurrentRotation;

	BarrelMesh->Elevate( 5.0f );
}