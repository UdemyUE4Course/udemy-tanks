// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTanks.h"
#include "TankMovementComponent.h"
#include "TankTrackComponent.h"

void UTankMovementComponent::IntendMoveForward( float speed ) {
	if ( !( LeftTrack && RightTrack ) ) { return; }

	LeftTrack->SetThrottle( speed );
	RightTrack->SetThrottle( speed );
}

void UTankMovementComponent::IntendTurnRight( float speed ) {
	if ( !( LeftTrack && RightTrack ) ) { return; }

	LeftTrack->SetThrottle( speed );
	RightTrack->SetThrottle( -speed );
}

void UTankMovementComponent::Initialize( UTankTrackComponent* leftTrackToSet, UTankTrackComponent* rightTrackToSet ) {
	if ( !( leftTrackToSet && rightTrackToSet ) ) { return; }

	LeftTrack	= leftTrackToSet;
	RightTrack	= rightTrackToSet;
}