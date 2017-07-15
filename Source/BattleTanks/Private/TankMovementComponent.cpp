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

void UTankMovementComponent::RequestDirectMove( const FVector& MoveVelocity, bool bForceMaxSpeed ) {
	FVector movementVector		= MoveVelocity.GetSafeNormal();
	FVector aiForwardVector		= GetOwner()->GetActorForwardVector();

	FVector	crossProduct		= FVector::CrossProduct( aiForwardVector, movementVector );
	float	steeringMagnitude	= crossProduct.Size();
	float	zSign				= FMath::Abs<float>( crossProduct.Z ) / crossProduct.Z;

	IntendTurnRight( steeringMagnitude * zSign );
	IntendMoveForward( FVector::DotProduct( aiForwardVector, movementVector ) );
}