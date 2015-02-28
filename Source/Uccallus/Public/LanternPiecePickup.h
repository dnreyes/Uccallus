// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Pickup.h"
#include "LanternPiecePickup.generated.h"

/**
 * 
 */
UCLASS()
class UCCALLUS_API ALanternPiecePickup : public APickup
{
	GENERATED_BODY()
	
public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Power)
    FString name;
    
    int value;
    
    void OnPickedUp_Implementation() override;
    
    ALanternPiecePickup(const FObjectInitializer& ObjectInitializer);
	
};
