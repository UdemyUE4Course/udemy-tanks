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
	
	if ( ensure( playerTank && controlledTank ) ) {
		if ( MoveToActor( playerTank, AcceptanceRadius, true, true, false ) == EPathFollowingRequestResult::AlreadyAtGoal ) {
			controlledTank->AimAt( playerTank->GetActorLocation() );
			controlledTank->Fire();
		}
	}
}