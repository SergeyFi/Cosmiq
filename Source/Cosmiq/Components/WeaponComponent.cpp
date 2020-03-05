// Copyright 2020 Sergey Firsov. All Rights Reserved.


#include "WeaponComponent.h"
#include "Engine/World.h"
#include "TimerManager.h"
#include "Cosmiq/Actors/Projectiles/ProjectileBase.h"

// Sets default values for this component's properties
UWeaponComponent::UWeaponComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}


// Called when the game starts
void UWeaponComponent::BeginPlay()
{
	Super::BeginPlay();
	
}

void UWeaponComponent::Firing()
{
	if (GetWorld())
	{
		FActorSpawnParameters SpawnParams;
		SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

		GetWorld()->SpawnActor<AProjectileBase>(ProjectileClass, GetComponentTransform(), SpawnParams);

		CurrentFiringCount += 1;

		if ((!bIsBurstFireMode && CurrentFiringCount > 0 ) || (bIsBurstFireMode && CurrentFiringCount >= BurstShotCount))
		{
			GetWorld()->GetTimerManager().ClearTimer(TimerFiring);

			// weapon cool down, after -> bIsFiring = false
		}
	}
}

void UWeaponComponent::Fire()
{
	if (!bIsFiring)
	{
		if (GetWorld())
		{
			bIsFiring = true;

			GetWorld()->GetTimerManager().SetTimer(TimerFiring, this, &UWeaponComponent::Firing,
				CooldownbetweenShot, true, FirstShotWarmUp);
		}
	}
}

