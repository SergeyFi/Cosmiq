// Copyright 2020 Sergey Firsov. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "ShieldComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FShieldDelegate);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class COSMIQ_API UShieldComponent : public USceneComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UShieldComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Shield")
	float ShieldCurrent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Shield")
	float ShieldMax;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Shield")
	float RegenerationCooldown;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Shield")
	float RegenerationRate;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Shield")
	float RenenerationHeal;

	FTimerHandle RegenerationTimer;

	void StartRegeneration();

	void Regeneration();

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void Heal(float Heal);

	void DamageShield(float Damage);

	UPROPERTY(BlueprintAssignable, Category = "Shild component")
	FShieldDelegate OnShieldEnded;

	UPROPERTY(BlueprintAssignable, Category = "Shild component")
	FShieldDelegate OnShieldDamaged;

	UFUNCTION()
		void OnOwnerTakeDamage(
			class AActor* DamagedActor, float Damage, const class UDamageType* DamageType,
			class AController* InstigatedBy, class AActor* DamageCauser
		);

		
};
