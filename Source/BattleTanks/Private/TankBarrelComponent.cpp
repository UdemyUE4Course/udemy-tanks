// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTanks.h"
#include "TankBarrelComponent.h"

void UTankBarrelComponent::Elevate( float RelativeSpeed ) {
	//Clamp to sane values
	RelativeSpeed = FMath::Clamp<float>( RelativeSpeed, -1.0f, 1.0f );

	float ElevationChange		= RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	float RawNewElevation		= RelativeRotation.Pitch + ElevationChange;
	float ClampedNewElevation	= FMath::Clamp<float>( RawNewElevation, MinElevationAngle, MaxElevationAngle );

	SetRelativeRotation( FRotator( ClampedNewElevation, 0.0f, 0.0f ) );
}