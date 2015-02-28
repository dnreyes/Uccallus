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
    GE_Yellow  UMETA(DisplayName = "Yellow"),
    GE_Green   UMETA(DisplayName = "Green"),
    GE_Red     UMETA(DisplayName = "Red"),
    GE_Pearl   UMETA(DisplayName = "Pearl"),
    GE_Diamond UMETA(DisplayName = "Diamond")
};
UCLASS()
class UCCALLUS_API AGem : public AActor
{
	GENERATED_BODY()
	
public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Enum)
    EGemtypeEnum GemtypeEnum;
	
};
