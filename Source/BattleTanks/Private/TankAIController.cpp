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
		UTankAimingComponent* aimingComponent = controlledTank->FindComponentByClass<UTankAimingComponent>();

		//Make sure there is an aiming component
		if ( !ensure( aimingComponent ) ) {
			return;
		}

		aimingComponent->AimAt( playerTank->GetActorLocation() );

		//Close enough to player and is locked
		if ( MoveToActor( playerTank, AcceptanceRadius, true, true, false ) == EPathFollowingRequestResult::AlreadyAtGoal &&
			 aimingComponent->GetFiringState() == EFiringStatus::Locked ) {
			aimingComponent->Fire();			
		}
	}
}