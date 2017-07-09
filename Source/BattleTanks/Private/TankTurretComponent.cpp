// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTanks.h"
#include "TankTurretComponent.h"

void UTankTurretComponent::Turn( float RelativeSpeed ) {
	//Clamp to sane values
	RelativeSpeed = FMath::Clamp<float>( RelativeSpeed, -1.0f, 1.0f );

	float YawChange				= RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	
	SetRelativeRotation( FRotator( 0.0f, RelativeRotation.Yaw + YawChange, 0.0f ) );
}