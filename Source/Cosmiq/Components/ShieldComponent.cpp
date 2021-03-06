// Copyright 2020 Sergey Firsov. All Rights Reserved.


#include "ShieldComponent.h"
#include "Engine/World.h"
#include "TimerManager.h"

#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"

#include "GameFramework/Actor.h"
#include "Cosmiq/Objects/DamageTypes/ShieldDamage.h"

// Sets default values for this component's properties
UShieldComponent::UShieldComponent()
{
	PrimaryComponentTick.bCanEverTick = false;

	ShieldCurrent = ShieldMax;

	SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere"));
	SphereComponent->SetupAttachment(this);

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	StaticMesh->SetupAttachment(SphereComponent);
	StaticMesh->SetCollisionProfileName(TEXT("NoCollision"));

	if (GetOwner()) GetOwner()->OnTakeAnyDamage.AddDynamic(this, &UShieldComponent::OnOwnerTakeDamage);
}


// Called when the game starts
void UShieldComponent::BeginPlay()
{
	Super::BeginPlay();
}


void UShieldComponent::StartRegeneration()
{
	UWorld* World = GetWorld();

	if (World) World->GetTimerManager().SetTimer(RegenerationTimer, this, &UShieldComponent::Regeneration, RegenerationRate, true, RegenerationCooldown);
}

void UShieldComponent::Regeneration()
{
	Heal(RenenerationHeal);

	if (ShieldCurrent == ShieldMax)
	{
		UWorld* World = GetWorld();

		if (World) World->GetTimerManager().ClearTimer(RegenerationTimer);
	}
}

// Called every frame
void UShieldComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}

void UShieldComponent::Heal(float Heal)
{
	ShieldCurrent += Heal;

	if (ShieldCurrent > ShieldMax) ShieldCurrent = ShieldMax;
}

void UShieldComponent::DamageShield(float Damage, AActor* DamageCauser)
{
	ShieldCurrent -= Damage;

	OnShieldDamaged.Broadcast();

	if (ShieldCurrent < 0.0f || FMath::IsNearlyZero(ShieldCurrent))
	{
		ShieldCurrent = 0.0f;

		OnShieldEnded.Broadcast();

		StartRegeneration();
	}
	else
	{
		if (DamageCauser)
		{
			DamageCauser->Destroy();
		}
	}
}

void UShieldComponent::OnOwnerTakeDamage(AActor* DamagedActor, float Damage, const UDamageType* DamageType, AController* InstigatedBy, AActor* DamageCauser)
{
	if (Cast<UShieldDamage>(DamageType))
	{
		DamageShield(Damage, DamageCauser);
	}
}

