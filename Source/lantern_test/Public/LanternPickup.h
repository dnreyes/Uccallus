// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Pickup.h"
#include "LanternPickup.generated.h"

/**
 * Copied from https://github.com/Harrison1/UE4Programming/blob/master/Source/ThirdPersonTutorial/Public/BatteryPickup.h
 */
UCLASS()
class LANTERN_TEST_API ALanternPickup : public APickup
{
	GENERATED_BODY()
	
public:
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Lantern)
		bool hasLantern;
	
	void OnPickUp_Implementation() override;

	ALanternPickup(const FObjectInitializer& ObjectInitializer);

};
