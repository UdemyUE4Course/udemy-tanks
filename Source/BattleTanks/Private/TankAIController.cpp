#include "BattleTanks.h"
#include "TankAIController.h"
#include "TankPlayerController.h"

ATank* ATankAIController::GetControlledTank( void ) const {
	return Cast<ATank>( GetPawn() );
}

void ATankAIController::BeginPlay() {
	Super::BeginPlay();

	ATank* playerTank = GetPlayerTank();
	if ( playerTank ) {
		UE_LOG( LogTemp, Warning, TEXT( "AIController Found Player Tank with name %s" ), *playerTank->GetName() );
	} else {
		UE_LOG( LogTemp, Warning, TEXT( "No player Tank found" ) );
	}
}

ATank* ATankAIController::GetPlayerTank( void ) const {
	return Cast<ATank>( GetWorld()->GetFirstPlayerController()->GetPawn() );
}