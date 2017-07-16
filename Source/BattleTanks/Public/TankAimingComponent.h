// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"

class UTankBarrelComponent;
class UTankTurretComponent;

UENUM()
enum class EFiringStatus : uint8 {
	Reloading,
	Aiming,
	Locked
};

UCLASS( ClassGroup = ( Tank ), meta = ( BlueprintSpawnableComponent ) )
class BATTLETANKS_API UTankAimingComponent : public UActorComponent {
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
									UTankAimingComponent();

	void							AimAt( const FVector& LocationToAim );
	
	UFUNCTION( BlueprintCallable, Category = "Setup" )
	void							Initialize( UTankBarrelComponent* barrel, UTankTurretComponent* turret );

	UFUNCTION( BlueprintCallable, Category = "Firing" )
	void							Fire();
protected:
	UPROPERTY( BlueprintReadOnly, Category = "Status" )
	EFiringStatus					CurrentStatus = EFiringStatus::Aiming;
private:
	void							MoveBarrel( const FVector& AimDirection );

	UTankBarrelComponent*			BarrelMesh;
	UTankTurretComponent*			TurretMesh;

	UPROPERTY( EditDefaultsOnly, Category = "Firing" )
	float							LaunchSpeed				= 10000.0f;

	UPROPERTY( EditDefaultsOnly, Category = "Setup" )
	TSubclassOf<class AProjectile>	ProjectileBlueprint		= nullptr;

	UPROPERTY( EditDefaultsOnly, Category = "Firing" )
	float							ReloadTimeInSeconds		= 3.0f;
	double							m_lastFireTime			= 0.0f;
};
