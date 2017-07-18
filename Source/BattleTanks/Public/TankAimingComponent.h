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
	Locked,
	OutOfAmmo
};

UCLASS( ClassGroup = ( Tank ), meta = ( BlueprintSpawnableComponent ) )
class BATTLETANKS_API UTankAimingComponent : public UActorComponent {
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
									UTankAimingComponent();
	
	virtual void					TickComponent( float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) override;

	void							AimAt( const FVector& LocationToAim );
	
	UFUNCTION( BlueprintCallable, Category = "Setup" )
	void							Initialize( UTankBarrelComponent* barrel, UTankTurretComponent* turret );

	UFUNCTION( BlueprintCallable, Category = "Firing" )
	void							Fire();

	EFiringStatus					GetFiringState() const;

	UFUNCTION( BlueprintCallable, Category = "Firing" )
	int								GetRoundsRemaining() const;
protected:
	UPROPERTY( BlueprintReadOnly, Category = "Status" )
	EFiringStatus					CurrentStatus = EFiringStatus::Aiming;
private:
	void							MoveBarrel( const FVector& AimDirection );
	bool							IsBarrelMoving( void );

	UTankBarrelComponent*			BarrelMesh;
	UTankTurretComponent*			TurretMesh;

	UPROPERTY( EditDefaultsOnly, Category = "Firing" )
	float							LaunchSpeed				= 10000.0f;

	UPROPERTY( EditDefaultsOnly, Category = "Setup" )
	TSubclassOf<class AProjectile>	ProjectileBlueprint		= nullptr;

	UPROPERTY( EditDefaultsOnly, Category = "Firing" )
	float							ReloadTimeInSeconds		= 3.0f;
	double							m_lastFireTime			= 0.0f;

	FVector							m_lastAimDirection		= FVector::ZeroVector;
	int								m_roundsRemaining		= 3;
};
