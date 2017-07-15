// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

class UTankBarrelComponent;
class UTankAimingComponent;
class UTankMovementComponent;

UCLASS()
class BATTLETANKS_API ATank : public APawn {
	GENERATED_BODY()

public:
									ATank();

	void							AimAt( const FVector& HitLocation );
	
	UFUNCTION( BlueprintCallable, Category = "Tank" )
	void							Fire();
protected:
	UPROPERTY( BlueprintReadWrite, Category = "Setup" )
	UTankBarrelComponent*			Barrel			= nullptr;

	UTankAimingComponent*			AimingComponent	= nullptr;
private:
	UPROPERTY( EditDefaultsOnly, Category = "Firing" )
	float							LaunchSpeed;

	UPROPERTY( EditDefaultsOnly, Category = "Setup" )
	TSubclassOf<class AProjectile>	ProjectileBlueprint;

	UPROPERTY( EditDefaultsOnly, Category = "Firing" )
	float							ReloadTimeInSeconds		= 3.0f;
	double							m_lastFireTime			= 0.0f;
};
