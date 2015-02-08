// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Pickup.generated.h"

/**
 * 
 */
UCLASS()
class UCCALLUS_API APickup : public AActor
{
	GENERATED_BODY()
	
public:
    /*FObjectInitializer: interal class to finalize UObject creation 
     (initalize properties) after the real C++ constructor is called.*/
    APickup(const FObjectInitializer& ObjectInitializer);
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bIsActive;
    
    /*USphereComponent: a sphere generally used for simplecollision.
      Bounds are rendered as lines in the editor*/
    UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly)
    class USphereComponent* BaseCollisionComponent;
    
    
    /*StaticMeshComponent is used to create an instance of UStaticMesh.
     A static mesh is a piece of geomety that consists of a static set
     of polygons.
     
     Guessing this means were attaching it to a 3D model?*/
    UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly)
    class UStaticMeshComponent* PickupMesh;
	
    UFUNCTION(BlueprintNativeEvent)
    void OnPickedUp();
};
