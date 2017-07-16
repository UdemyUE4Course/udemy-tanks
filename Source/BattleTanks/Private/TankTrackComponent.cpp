#include "BattleTanks.h"
#include "TankTrackComponent.h"

UTankTrackComponent::UTankTrackComponent() {
	
}

void UTankTrackComponent::BeginPlay() {
	Super::BeginPlay();

	OnComponentHit.AddDynamic( this, &UTankTrackComponent::OnHit );
}


void UTankTrackComponent::SetThrottle( float throttle ) {
	m_currentThrottle = FMath::Clamp<float>( m_currentThrottle + throttle, -1.0f, 1.0f );
}

void UTankTrackComponent::DriveTrack( void ) {
	FVector				forceApplied	= GetForwardVector() * m_currentThrottle * MaxDrivingForce;
	FVector				forceLocation	= GetComponentLocation();

	USceneComponent*	rootComponent	= GetOwner()->GetRootComponent();
	Cast<UPrimitiveComponent>( rootComponent )->AddForceAtLocation( forceApplied, forceLocation );
}

void UTankTrackComponent::OnHit( UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit ) {
	ApplySidewaysForce();
	DriveTrack();

	m_currentThrottle = 0.0f;
}

void UTankTrackComponent::ApplySidewaysForce( void ) {
	float					slippageSpeed			= FVector::DotProduct( GetComponentVelocity(), GetRightVector() ); //Sideways movement
	FVector					correctionAcceleration	= ( -slippageSpeed / GetWorld()->DeltaTimeSeconds ) * GetRightVector(); //Acceleration needed to correct
	UStaticMeshComponent*	ownerTankRoot			= Cast<UStaticMeshComponent>( GetOwner()->GetRootComponent() ); //Component with mass
	FVector					correctionForce			= ( ownerTankRoot->GetMass() * correctionAcceleration ) * 0.4f; //The force for this mass

	ownerTankRoot->AddForce( correctionForce );
}