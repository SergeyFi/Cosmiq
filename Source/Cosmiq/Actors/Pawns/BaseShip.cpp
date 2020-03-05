// Copyright 2020 Sergey Firsov. All Rights Reserved.


#include "BaseShip.h"

#include "Cosmiq/Components/HullComponent.h"
#include "Cosmiq/Components/ShieldComponent.h"
#include "Cosmiq/Components/WeaponComponent.h"

#include "Components/StaticMeshComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"


// Sets default values
ABaseShip::ABaseShip()
{
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	RootComponent = Mesh;

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(Mesh);

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm);

	HullComponent = CreateDefaultSubobject<UHullComponent>(TEXT("HullComponent"));
	
	ShieldComponent = CreateDefaultSubobject<UShieldComponent>(TEXT("ShieldComponent"));
	ShieldComponent->SetupAttachment(Mesh);

	WeaponComponent = CreateDefaultSubobject<UWeaponComponent>(TEXT("WeaponComponent"));

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

