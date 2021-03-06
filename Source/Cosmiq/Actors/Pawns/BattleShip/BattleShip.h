// Copyright 2020 Sergey Firsov. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Cosmiq/Actors/Pawns/BaseShip.h"
#include "BattleShip.generated.h"


UCLASS()
class COSMIQ_API ABattleShip : public ABaseShip
{
	GENERATED_BODY()

public:
	ABattleShip();

protected:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UShieldComponent* ShieldComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UWeaponComponent* WeaponComponent;
	
};
