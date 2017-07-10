#include "BattleTanks.h"
#include "TankAIController.h"
#include "TankPlayerController.h"

ATankAIController::ATankAIController() {
	PrimaryActorTick.bCanEverTick = true;

}

ATank* ATankAIController::GetControlledTank( void ) const {
	return Cast<ATank>( GetPawn() );
}

void ATankAIController::BeginPlay() {
	Super::BeginPlay();

	ATank* playerTank = GetPlayerTank();
	if ( !playerTank ) {
		UE_LOG( LogTemp, Warning, TEXT( "No player Tank found" ) );
	}
}

ATank* ATankAIController::GetPlayerTank( void ) const {
	return Cast<ATank>( GetWorld()->GetFirstPlayerController()->GetPawn() );
}

void ATankAIController::Tick( float deltaTime ) {
	Super::Tick( deltaTime );
	if ( !GetControlledTank() ) { return; }

	AimAtPlayer();
}

void ATankAIController::AimAtPlayer( void ) {
	FVector playerLocation;
	if ( GetPlayerLocation( playerLocation ) ) {
		GetControlledTank()->AimAt( playerLocation );
	}
}

bool ATankAIController::GetPlayerLocation( FVector& PlayerLocation ) const {
	ATank* playerTank = GetPlayerTank();

	if ( playerTank ) {
		PlayerLocation = playerTank->GetActorLocation();
		return true;
	}

	PlayerLocation = FVector::ZeroVector;
	return false;
}