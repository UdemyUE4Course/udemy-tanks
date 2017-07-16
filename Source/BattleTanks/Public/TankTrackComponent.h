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
					UTankTrackComponent();

	void			BeginPlay();
	virtual void	TickComponent( float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) override;

	UFUNCTION( BlueprintCallable, Category = Input )
	void			SetThrottle( float throttle );

	//Max force per track in newtons
	UPROPERTY( EditDefaultsOnly, Category = Driving )
	float			MaxDrivingForce = 400000.0f; //40 ton tank

private:
	UFUNCTION()
	void			OnHit( UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit );
};