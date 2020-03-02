// Copyright 2020 Sergey Firsov. All Rights Reserved.


#include "ShieldComponent.h"

// Sets default values for this component's properties
UShieldComponent::UShieldComponent()
{
	PrimaryComponentTick.bCanEverTick = false;

}


// Called when the game starts
void UShieldComponent::BeginPlay()
{
	Super::BeginPlay();

	
}


// Called every frame
void UShieldComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}

