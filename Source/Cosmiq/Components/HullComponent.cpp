// Copyright 2020 Sergey Firsov. All Rights Reserved.


#include "HullComponent.h"
#include "GameFramework/Actor.h"

// Sets default values for this component's properties
UHullComponent::UHullComponent()
{
	PrimaryComponentTick.bCanEverTick = false;

	HullCurrent = HullMax;

	if (GetOwner()) GetOwner()->OnTakeAnyDamage.AddDynamic(this, &UHullComponent::OnOwnerTakeDamage);
}


// Called when the game starts
void UHullComponent::BeginPlay()
{
	Super::BeginPlay();
}


// Called every frame
void UHullComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}


void UHullComponent::Heal(float Heal)
{
	HullCurrent += Heal;

	if (HullCurrent > HullMax) HullCurrent = HullMax;
}


void UHullComponent::DamageHull(float Damage, AController* InstigatedBy)
{
	HullCurrent -= Damage;

	if (FMath::IsNearlyZero(HullCurrent) || HullCurrent < 0.0f)
	{
		OnHealthEnded.Broadcast(InstigatedBy);
		HullCurrent = 0.0f;
	}
}


void UHullComponent::OnOwnerTakeDamage(
	AActor* DamagedActor, float Damage, const UDamageType* DamageType, AController* InstigatedBy, AActor* DamageCauser
)
{
	DamageHull(Damage, InstigatedBy);
}

