#include "BattleTanks.h"
#include "TankPlayerController.h"


ATank* ATankPlayerController::GetControlledTank( void ) const {
	return Cast<ATank>( GetPawn() );
}

