// Fill out your copyright notice in the Description page of Project Settings.

#include "Uccallus.h"
#include "Pickup.h"




APickup::APickup(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{

    bIsActive = true;

    /*CreateDefaultSubobject: create a component or subobject*/
    BaseCollisionComponent = ObjectInitializer.CreateDefaultSubobject<USphereComponent>(this, TEXT("BaseSphereComponent"));
    
    /*RootComponent: collision primitive that defines the 
      transform (loc, rot, scale) of this Actor*/
    RootComponent = BaseCollisionComponent;
    
    PickupMesh = ObjectInitializer.CreateDefaultSubobject<UStaticMeshComponent>(this, TEXT("PickupMesh"));
    
    PickupMesh->SetSimulatePhysics(true);
    
    PickupMesh->AttachTo(RootComponent);

}

void APickup::OnPickedUp_Implementation()
{
    //there is no default behavior for a pick up when its picked up.
}
