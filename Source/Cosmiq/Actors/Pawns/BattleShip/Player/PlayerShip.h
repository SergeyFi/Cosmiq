// Copyright 2020 Sergey Firsov. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Cosmiq/Actors/Pawns/BattleShip/BattleShip.h"
#include "PlayerShip.generated.h"


UCLASS()
class COSMIQ_API APlayerShip : public ABattleShip
{
	GENERATED_BODY()

public:
	APlayerShip();


protected:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class USpringArmComponent* SpringArm;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UCameraComponent* Camera;
};
