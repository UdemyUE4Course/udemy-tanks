// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/StaticMeshComponent.h"
#include "TankBarrelComponent.generated.h"

/**
 *
 */
UCLASS( ClassGroup = ( Tank ), meta = ( BlueprintSpawnableComponent ), hideCategories = ( "Collision" ) )
class BATTLETANKS_API UTankBarrelComponent : public UStaticMeshComponent {
	GENERATED_BODY()

public:
	//-1 is max speed down, 1 is max speed up
	void			Elevate( float RelativeSpeed );

private:
	UPROPERTY( EditAnywhere, Category = "Movement" )
	float			MaxDegreesPerSecond	= 10.0f;

	UPROPERTY( EditAnywhere, Category = "Movement" )
	float			MinElevationAngle	= 0.0f;

	UPROPERTY( EditAnywhere, Category = "Movement" )
	float			MaxElevationAngle	= 40.0f;
};
