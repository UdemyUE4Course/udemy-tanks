#include "BattleTanks.h"
#include "TankAIController.h"
#include "TankPlayerController.h"
#include "TankAimingComponent.h"

ATankAIController::ATankAIController() {
	PrimaryActorTick.bCanEverTick = true;
}

void ATankAIController::Tick( float deltaTime ) {
	Super::Tick( deltaTime );

	ATank* playerTank = Cast<ATank>( GetWorld()->GetFirstPlayerController()->GetPawn() );
	
	if ( ensure( playerTank ) ) {
		UTankAimingComponent* aimingComponent = GetPawn()->FindComponentByClass<UTankAimingComponent>();

		//Make sure there is an aiming component
		if ( !ensure( aimingComponent ) ) {
			return;
		}

		//Aim and move
		aimingComponent->AimAt( playerTank->GetActorLocation() );
		MoveToActor( playerTank, AcceptanceRadius, true, true, false );

		//Close enough to player and is locked
		if ( aimingComponent->GetFiringState() == EFiringStatus::Locked ) {
			aimingComponent->Fire();			
		}
	}
}