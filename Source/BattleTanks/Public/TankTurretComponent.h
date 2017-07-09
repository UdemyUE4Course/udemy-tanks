// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/StaticMeshComponent.h"
#include "TankTurretComponent.generated.h"

/**
 *
 */
UCLASS( ClassGroup = ( Tank ), meta = ( BlueprintSpawnableComponent ), hideCategories = ( "Collision" ) )
class BATTLETANKS_API UTankTurretComponent : public UStaticMeshComponent {
	GENERATED_BODY()
public:
	void	Turn( float RelativeSpeed );

private:
	UPROPERTY( EditAnywhere )
	float	MaxDegreesPerSecond = 10.0f;
};
