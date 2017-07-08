#include "BattleTanks.h"
#include "TankPlayerController.h"


ATank* ATankPlayerController::GetControlledTank( void ) const {
	return Cast<ATank>( GetPawn() );
}

void ATankPlayerController::BeginPlay() {
	Super::BeginPlay();

	ATank* possessedTank = GetControlledTank();
	if ( possessedTank ) {
		UE_LOG( LogTemp, Warning, TEXT( "Player Controller Possesed Tank with name %s" ), *possessedTank->GetName() );
	} else {
		UE_LOG( LogTemp, Warning, TEXT( "No Controlled Tank" ) );
	}
}