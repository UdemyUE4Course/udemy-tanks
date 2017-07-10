// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTanks.h"
#include "Tank.h"
#include "TankBarrelComponent.h"
#include "TankAimingComponent.h"
#include "TankTurretComponent.h"


// Sets default values
ATank::ATank() :
	TankAimingComponent( nullptr ),
	LaunchSpeed( 10000.0f ) 
{
	PrimaryActorTick.bCanEverTick	= false;
	TankAimingComponent				= CreateDefaultSubobject<UTankAimingComponent>( FName( "AimingComponent" ) );
}

// Called when the game starts or when spawned
void ATank::BeginPlay() {
	Super::BeginPlay();

}

// Called to bind functionality to input
void ATank::SetupPlayerInputComponent( UInputComponent* PlayerInputComponent ) {
	Super::SetupPlayerInputComponent( PlayerInputComponent );

}

void ATank::AimAt( const FVector& HitLocation ) {
	TankAimingComponent->AimAt( HitLocation, LaunchSpeed );
}

void ATank::SetBarrelReference( UTankBarrelComponent* BarrelToSet ) {
	TankAimingComponent->SetBarrelReference( BarrelToSet );
}

void ATank::SetTurretReference( UTankTurretComponent* BarrelToSet ) {
	TankAimingComponent->SetTurretReference( BarrelToSet );
}

void ATank::Fire() {
	UE_LOG( LogTemp, Warning, TEXT( "Tank firing" ) );
}