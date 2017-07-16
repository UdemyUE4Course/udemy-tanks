// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

class UTankBarrelComponent;
class UTankAimingComponent;

UCLASS()
class BATTLETANKS_API ATank : public APawn {
	GENERATED_BODY()

public:
	ATank();
};
