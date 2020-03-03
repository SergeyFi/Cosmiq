// Copyright 2020 Sergey Firsov. All Rights Reserved.


#include "ProjectileBase.h"

#include "Components/StaticMeshComponent.h"
#include "Components/SphereComponent.h"

#include "Cosmiq/Objects/DamageTypes/ShieldDamage.h"
#include "Cosmiq/Objects/DamageTypes/HullDamage.h"


#include "Kismet/GameplayStatics.h"

// Sets default values
AProjectileBase::AProjectileBase()
{
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	RootComponent = Mesh;

	CollisionSphere = CreateDefaultSubobject<USphereComponent>(TEXT("CollisionSphere"));
	CollisionSphere->SetupAttachment(Mesh);

}

// Called when the game starts or when spawned
void AProjectileBase::BeginPlay()
{
	Super::BeginPlay();
	
}

void AProjectileBase::ProjectileMovement(float DeltaTime)
{
	AddActorLocalOffset(GetActorForwardVector() * DeltaTime * ProjectileSpeed);
}

// Called every frame
void AProjectileBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	ProjectileMovement(DeltaTime);
}

void AProjectileBase::OnSphereOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor)
	{
		if (ShieldDamage > 0.0f)
		{
			TSubclassOf<UShieldDamage> ShieldDamageType;
			UGameplayStatics::ApplyDamage(OtherActor, ShieldDamage, GetInstigatorController(), this, ShieldDamageType);

			ShieldDamage = 0.0f;
		}

		if (HullDamage > 0.0f)
		{
			if (Cast<UStaticMeshComponent>(OverlappedComp))
			{
				TSubclassOf<UHullDamage> HullDamageType;
				UGameplayStatics::ApplyDamage(OtherActor, HullDamage, GetInstigatorController(), this, HullDamageType);

				Destroy();
			}
		}
	}
}

