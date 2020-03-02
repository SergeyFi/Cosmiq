// Copyright 2020 Sergey Firsov. All Rights Reserved.


#include "HullComponent.h"

// Sets default values for this component's properties
UHullComponent::UHullComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}


// Called when the game starts
void UHullComponent::BeginPlay()
{
	Super::BeginPlay();
}


// Called every frame
void UHullComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

