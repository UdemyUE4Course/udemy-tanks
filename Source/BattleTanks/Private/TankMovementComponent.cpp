// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTanks.h"
#include "TankMovementComponent.h"

void UTankMovementComponent::IntendMoveForward( float speed ) {
	UE_LOG( LogTemp, Warning, TEXT( "Moving forward at speed %f" ), speed );
}