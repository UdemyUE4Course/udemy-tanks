// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AIController.h"
#include "Tank.h"
#include "TankAIController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANKS_API ATankAIController : public AAIController {
	GENERATED_BODY()
	
public:	
						ATankAIController();

	virtual void		BeginPlay()	override;
	virtual void		Tick( float deltaTime ) override;
private:
	ATank*				GetControlledTank( void ) const;
	ATank*				GetPlayerTank( void ) const;

	void				AimAtPlayer( void );
	bool				GetPlayerLocation( FVector& PlayerLocation ) const;
};
