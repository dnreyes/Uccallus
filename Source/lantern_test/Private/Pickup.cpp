// Fill out your copyright notice in the Description page of Project Settings.

//Copied from https://github.com/Harrison1/UE4Programming/blob/master/Source/ThirdPersonTutorial/Private/Pickup.cpp

#include "lantern_test.h"
#include "Pickup.h"

APickup::APickup(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	isActive = true;

	BaseCollisionComponent = ObjectInitializer.CreateDefaultSubobject<USphereComponent>(this, TEXT("BaseSphereComponent"));

	RootComponent = BaseCollisionComponent;

	PickupMesh = ObjectInitializer.CreateDefaultSubobject<UStaticMeshComponent>(this, TEXT("PickupMesh"));

	PickupMesh->SetSimulatePhysics(true);

	PickupMesh->AttachTo(RootComponent);

}

void APickup::OnPickUp_Implementation() {
	//do nothing
}