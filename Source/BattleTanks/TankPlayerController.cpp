#include "BattleTanks.h"
#include "TankPlayerController.h"
#include "TankAimingComponent.h"

ATankPlayerController::ATankPlayerController() {
	PrimaryActorTick.bCanEverTick = true;
}

ATank* ATankPlayerController::GetControlledTank( void ) const {
	return Cast<ATank>( GetPawn() );
}

void ATankPlayerController::BeginPlay() {
	Super::BeginPlay();

	UTankAimingComponent* aimingComponent = GetControlledTank()->FindComponentByClass<UTankAimingComponent>();
	if ( ensure( aimingComponent ) ) {
		AimingComponentFound( aimingComponent );
	}
}

void ATankPlayerController::Tick( float deltaTime ) {
	Super::Tick( deltaTime );
	//Aim at crosshair

	AimTowardsCrosshair();
}

void ATankPlayerController::AimTowardsCrosshair( void ) {
	if ( ensure( GetControlledTank() ) ) {
		FVector HitLocation; //Out
		if ( GetSightRayHitLocation( HitLocation ) ) {
			GetControlledTank()->AimAt( HitLocation );
		}
	}
}

//Gets the hit location on the landscape and returns if it hit a landscape or not
bool ATankPlayerController::GetSightRayHitLocation( FVector& HitLocation ) const {
	//Find crosshair position
	int32	viewPortSizeX		= 0.0f;
	int32	viewPortSizeY		= 0.0f;

	GetViewportSize( viewPortSizeX, viewPortSizeY );

	FVector2D ScreenLocation( viewPortSizeX * CrosshairXLocation, viewPortSizeY * CrosshairYLocation );
	
	//Deproject screen to world
	FVector WorldLocation;
	FVector WorldDirection;
	if ( DeprojectScreenPositionToWorld( ScreenLocation.X, ScreenLocation.Y, WorldLocation, WorldDirection ) ) {
		//Line trace the landscape
		FHitResult	traceResult;
		FVector		traceDestination = WorldLocation + ( WorldDirection * LineTraceRange );

		if ( GetWorld()->LineTraceSingleByChannel(
				traceResult,
				WorldLocation,
				traceDestination,
				ECollisionChannel::ECC_Visibility ) 
			) {
			HitLocation = traceResult.Location;
			return true;
		}
	}

	HitLocation = FVector::ZeroVector;
	return false;
}
