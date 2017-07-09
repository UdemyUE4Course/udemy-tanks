// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"

class UTankBarrelComponent;
class UTankTurretComponent;

UCLASS( ClassGroup = ( Tank ), meta = ( BlueprintSpawnableComponent ) )
class BATTLETANKS_API UTankAimingComponent : public UActorComponent {
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
							UTankAimingComponent();
public:
	void					AimAt( const FVector& LocationToAim, float LaunchSpeed );
	void					SetBarrelReference( UTankBarrelComponent* BarrelToSet );
	void					SetTurretReference( UTankTurretComponent* TurretToSet );
private:
	void					MoveBarrel( const FVector& AimDirection );

	UTankBarrelComponent*	BarrelMesh;
	UTankTurretComponent*	TurretMesh;
};
