// Copyright 2020 Sergey Firsov. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "BaseShip.generated.h"

UCLASS()
class COSMIQ_API ABaseShip : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ABaseShip();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UStaticMeshComponent* Mesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class USpringArmComponent* SpringArm;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UCameraComponent* Camera;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UHullComponent* HullComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UShieldComponent* ShieldComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UWeaponComponent* WeaponComponent;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
