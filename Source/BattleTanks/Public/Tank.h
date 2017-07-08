// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "TankAimingComponent.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

UCLASS()
class BATTLETANKS_API ATank : public APawn
{
	GENERATED_BODY()

public:
							ATank();

	// Called every frame
	virtual void			Tick( float DeltaTime ) override;

	// Called to bind functionality to input
	virtual void			SetupPlayerInputComponent( class UInputComponent* PlayerInputComponent ) override;

	void					AimAt( const FVector& HitLocation );
	
	UFUNCTION( BlueprintCallable, Category = "Setup" )
	void					SetBarrelReference( UStaticMeshComponent* Barrel );
protected:
	// Called when the game starts or when spawned
	virtual void			BeginPlay() override;

	UTankAimingComponent*	TankAimingComponent;

private:
	UPROPERTY( EditAnywhere, Category = "Firing" )
	float					LaunchSpeed;
};
