#include "BattleTanks.h"
#include "TankAIController.h"
#include "TankPlayerController.h"
#include "TankAimingComponent.h"

ATankAIController::ATankAIController() {
	PrimaryActorTick.bCanEverTick = true;

}

void ATankAIController::Tick( float deltaTime ) {
	Super::Tick( deltaTime );

	ATank* playerTank		= Cast<ATank>( GetWorld()->GetFirstPlayerController()->GetPawn() );
	ATank* controlledTank	= Cast<ATank>( GetPawn() );
	
	if ( ensure( playerTank && controlledTank ) ) {
		if ( MoveToActor( playerTank, AcceptanceRadius, true, true, false ) == EPathFollowingRequestResult::AlreadyAtGoal ) {
			UTankAimingComponent* aimingComponent = controlledTank->FindComponentByClass<UTankAimingComponent>();
			if ( ensure( aimingComponent ) ) {
				aimingComponent->AimAt( playerTank->GetActorLocation() );
				aimingComponent->Fire();
			}			
		}
	}
}