#include "BattleTanks.h"
#include "TankTrackComponent.h"

UTankTrackComponent::UTankTrackComponent() {
	PrimaryComponentTick.bCanEverTick = true;
}

void UTankTrackComponent::BeginPlay() {
	Super::BeginPlay();

	OnComponentHit.AddDynamic( this, &UTankTrackComponent::OnHit );
}

void UTankTrackComponent::TickComponent( float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) {
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );

	float					slippageSpeed			= FVector::DotProduct( GetComponentVelocity(), GetRightVector() ); //Sideways movement
	FVector					correctionAcceleration	= ( -slippageSpeed / DeltaTime ) * GetRightVector(); //Acceleration needed to correct
	UStaticMeshComponent*	ownerTankRoot			= Cast<UStaticMeshComponent>( GetOwner()->GetRootComponent() ); //Component with mass
	FVector					correctionForce			= ( ownerTankRoot->GetMass() * correctionAcceleration ) * 0.4f; //The force for this mass

	ownerTankRoot->AddForce( correctionForce );
}

void UTankTrackComponent::SetThrottle( float throttle ) {
	FVector				forceApplied	= GetForwardVector() * throttle * MaxDrivingForce;
	FVector				forceLocation	= GetComponentLocation();

	USceneComponent*	rootComponent	= GetOwner()->GetRootComponent();
	Cast<UPrimitiveComponent>( rootComponent )->AddForceAtLocation( forceApplied, forceLocation );
}

void UTankTrackComponent::OnHit( UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit ) {
	
}