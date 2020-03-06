// Copyright 2020 Sergey Firsov. All Rights Reserved.


#include "BaseShip.h"

#include "Cosmiq/Components/HullComponent.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
ABaseShip::ABaseShip()
{
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	RootComponent = Mesh;

	HullComponent = CreateDefaultSubobject<UHullComponent>(TEXT("HullComponent"));

}

// Called when the game starts or when spawned
void ABaseShip::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABaseShip::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABaseShip::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

