// Copyright 2020 Sergey Firsov. All Rights Reserved.


#include "BattleShip.h"

#include "Cosmiq/Components/ShieldComponent.h"
#include "Cosmiq/Components/WeaponComponent.h"
#include "Components/StaticMeshComponent.h"

ABattleShip::ABattleShip()
{
	ShieldComponent = CreateDefaultSubobject<UShieldComponent>(TEXT("ShieldComponent"));
	ShieldComponent->SetupAttachment(Mesh);

	WeaponComponent = CreateDefaultSubobject<UWeaponComponent>(TEXT("WeaponComponent"));
	WeaponComponent->SetupAttachment(Mesh);
}