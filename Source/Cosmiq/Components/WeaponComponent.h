// Copyright 2020 Sergey Firsov. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "WeaponComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class COSMIQ_API UWeaponComponent : public USceneComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UWeaponComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	// Weapon properties
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Weapon")
	float HullDamage;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Weapon")
	float ShieldDamage;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Weapon")
	float FirstShotWarmUp;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Weapon")
	float CooldownbetweenShot;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Weapon")
	TSubclassOf<class AProjectileBase> ProjectileClass;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Weapon")
	bool bCanFiring;

	// Weapon burst mode
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Weapon|Burst mode")
	bool bIsBurstFireMode;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Weapon|Burst mode")
	int32 BurstShotCount;

	// Other
	FTimerHandle TimerFiring;

	FTimerHandle TimerCoolDown;

	int32 CurrentFiringCount;

	void Firing();

	void StartWeaponCooldown();

	void WeaponCoolDownEnd();

public:
	void Fire();
};
