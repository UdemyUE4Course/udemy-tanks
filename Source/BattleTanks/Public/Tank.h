// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

class UTankBarrelComponent;

UCLASS()
class BATTLETANKS_API ATank : public APawn
{
	GENERATED_BODY()

public:
									ATank();

	// Called to bind functionality to input
	virtual void					SetupPlayerInputComponent( class UInputComponent* PlayerInputComponent ) override;

	void							AimAt( const FVector& HitLocation );
	
	UFUNCTION( BlueprintCallable, Category = "Setup" )
	void							SetBarrelReference( UTankBarrelComponent* Barrel );

	UFUNCTION( BlueprintCallable, Category = "Setup" )
	void							SetTurretReference( class UTankTurretComponent* Turret );

	UFUNCTION( BlueprintCallable, Category = "Tank" )
	void							Fire();
protected:
	// Called when the game starts or when spawned
	virtual void					BeginPlay() override;

	class UTankAimingComponent*		TankAimingComponent;

private:
	UPROPERTY( EditDefaultsOnly, Category = "Firing" )
	float							LaunchSpeed;

	UPROPERTY( EditDefaultsOnly, Category = "Setup" )
	TSubclassOf<class AProjectile>	ProjectileBlueprint;

	UTankBarrelComponent*			m_barrel;

	UPROPERTY( EditDefaultsOnly, Category = "Firing" )
	float							ReloadTimeInSeconds		= 3.0f;
	double							m_lastFireTime			= 0.0f;
};
