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
	virtual void		BeginPlay()	override;

private:
	ATank*				GetControlledTank( void ) const;
	ATank*				GetPlayerTank( void ) const;
};
