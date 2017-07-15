// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/PlayerController.h"
#include "Tank.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANKS_API ATankPlayerController : public APlayerController {
	GENERATED_BODY()
	
public:
						ATankPlayerController();

	virtual void		BeginPlay()	override;
	virtual void		Tick( float deltaTime ) override;
protected:
	UFUNCTION( BlueprintCallable, Category = "Setup" )
	ATank*				GetControlledTank() const;

	UFUNCTION( BlueprintImplementableEvent, Category = "Setup" )
	void				AimingComponentFound( class UTankAimingComponent* aimingComponent );
private:
	void				AimTowardsCrosshair( void );
	bool				GetSightRayHitLocation( FVector& HitLocation ) const;

	UPROPERTY( EditDefaultsOnly, Category = "Crosshair" )
	float				LineTraceRange;

	UPROPERTY( EditDefaultsOnly, Category = "Crosshair" )
	float				CrosshairXLocation;

	UPROPERTY( EditDefaultsOnly, Category = "Crosshair" )
	float				CrosshairYLocation;
};
