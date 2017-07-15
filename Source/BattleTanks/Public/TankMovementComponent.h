// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/NavMovementComponent.h"
#include "TankMovementComponent.generated.h"

class UTankTrackComponent;

/**
 * 
 */
UCLASS( ClassGroup = ( Tank ), meta = ( BlueprintSpawnableComponent ) )
class BATTLETANKS_API UTankMovementComponent : public UNavMovementComponent {
	GENERATED_BODY()

public:
	UFUNCTION( BlueprintCallable, Category = "Input" )
	void					IntendMoveForward( float speed );

	UFUNCTION( BlueprintCallable, Category = "Input" )
	void					IntendTurnRight( float speed );

	UFUNCTION( BlueprintCallable, Category = "Setup" )
	void					Initialize( UTankTrackComponent* leftTrackToSet, UTankTrackComponent* rightTrackToSet );

	void					RequestDirectMove( const FVector& MoveVelocity, bool bForceMaxSpeed ) override;
private:
	UTankTrackComponent*	LeftTrack	= nullptr;
	UTankTrackComponent*	RightTrack	= nullptr;
	
};
