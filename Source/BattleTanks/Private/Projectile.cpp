// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTanks.h"
#include "Projectile.h"


// Sets default values
AProjectile::AProjectile() {
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	m_movementComponent = CreateDefaultSubobject<UProjectileMovementComponent>( FName( "Projectile Movement" ) );
	m_movementComponent->bAutoActivate = false;
}

// Called when the game starts or when spawned
void AProjectile::BeginPlay() {
	Super::BeginPlay();

}

// Called every frame
void AProjectile::Tick( float DeltaTime ) {
	Super::Tick( DeltaTime );

}

void AProjectile::Launch( float launchSpeed ) {
	m_movementComponent->SetVelocityInLocalSpace( FVector::ForwardVector * launchSpeed );
	m_movementComponent->Activate();
}