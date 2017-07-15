#include "BattleTanks.h"
#include "TankTrackComponent.h"

void UTankTrackComponent::SetThrottle( float throttle ) {
	FVector				forceApplied	= GetForwardVector() * throttle * MaxDrivingForce;
	FVector				forceLocation	= GetComponentLocation();

	USceneComponent*	rootComponent	= GetOwner()->GetRootComponent();

	Cast<UPrimitiveComponent>( rootComponent )->AddForceAtLocation( forceApplied, forceLocation );
}