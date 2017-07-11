#include "BattleTanks.h"
#include "TankAIController.h"
#include "TankPlayerController.h"

ATankAIController::ATankAIController() {
	PrimaryActorTick.bCanEverTick = true;

}

void ATankAIController::Tick( float deltaTime ) {
	Super::Tick( deltaTime );

	ATank* playerTank		= Cast<ATank>( GetWorld()->GetFirstPlayerController()->GetPawn() );
	ATank* controlledTank	= Cast<ATank>( GetPawn() );
	
	if ( !( playerTank && controlledTank ) ) { return; }

	controlledTank->AimAt( playerTank->GetActorLocation() );
	controlledTank->Fire();
}