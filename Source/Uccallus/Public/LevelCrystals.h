// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "LevelCrystals.generated.h"

/**
 * 
 */
UCLASS()
class UCCALLUS_API ALevelCrystals : public AActor
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Level Crystals")
	bool wasHit;
	
	void OnBeamHit();
	
	ALevelCrystals(const FObjectInitializer& ObjectInitializer);

};
