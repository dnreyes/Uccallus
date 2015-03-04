// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Gem.generated.h"

/**
 * 
 */

UENUM(BlueprintType)
enum class EGemtypeEnum : uint8
{
    GE_Yellow  =  1   UMETA(DisplayName = "Yellow"),
    GE_Green   =  3   UMETA(DisplayName = "Green"),
    GE_Red     =  5   UMETA(DisplayName = "Red"),
    GE_Pearl   =  8   UMETA(DisplayName = "Pearl"),
    GE_Diamond = 13   UMETA(DisplayName = "Diamond")
};
UCLASS()
class UCCALLUS_API AGem : public AActor
{
	GENERATED_BODY()
	
public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Enum)
    EGemtypeEnum GemtypeEnum;
	
};
