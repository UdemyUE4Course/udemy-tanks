// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/StaticMeshComponent.h"
#include "TankTrackComponent.generated.h"

/**
 * 
 */
UCLASS( ClassGroup = ( Tank ), meta = ( BlueprintSpawnableComponent ) )
class BATTLETANKS_API UTankTrackComponent : public UStaticMeshComponent {
	GENERATED_BODY()
public:
	UFUNCTION( BlueprintCallable, Category = Input )
	void SetThrottle( float throttle );

	//Max force per track in newtons
	UPROPERTY( EditDefaultsOnly, Category = Driving )
	float MaxDrivingForce = 400000.0f; //40 ton tank
};