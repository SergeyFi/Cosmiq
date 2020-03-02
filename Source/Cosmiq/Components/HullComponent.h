// Copyright 2020 Sergey Firsov. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HullComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FHealthEnded, AController*, Instigator);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class COSMIQ_API UHullComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UHullComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hull component")
	float HullCurrent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hull component")
	float HullMax;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void Heal(float Heal);

	void DamageHull(float Damage, AController* InstigatedBy);

	UFUNCTION()
		void OnOwnerTakeDamage(
			class AActor* DamagedActor, float Damage, const class UDamageType* DamageType, 
			class AController* InstigatedBy, class AActor* DamageCauser
		);

	UPROPERTY(BlueprintAssignable, Category = "Hull component")
	FHealthEnded OnHealthEnded;
};
