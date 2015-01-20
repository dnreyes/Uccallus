// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Pickup.generated.h"

/**
 * Copied from https://github.com/Harrison1/UE4Programming/blob/master/Source/ThirdPersonTutorial/Public/Pickup.h
 * May be changed later to better fit our needs
 */

UCLASS()
class LANTERN_TEST_API APickup : public AActor
{
	GENERATED_BODY()
	
public:

	APickup(const FObjectInitializer& ObjectInitializer);

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool isActive;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly)
	class USphereComponent* BaseCollisionComponent;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly)
	class UStaticMeshComponent* PickupMesh;

	UFUNCTION(BlueprintNativeEvent)
		void OnPickUp();
	
	
};
