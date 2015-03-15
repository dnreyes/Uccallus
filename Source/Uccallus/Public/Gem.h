// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Gem.generated.h"

/**
*
*/

const int32 NUM_GEMTYPES = 5;

UENUM(BlueprintType)
enum class EGemType : uint8
{
	G_Yellow		UMETA(DisplayName = "Yellow"),
	G_Green			UMETA(DisplayName = "Green"),
	G_Red			UMETA(DisplayName = "Red"),
	G_Pearl			UMETA(DisplayName = "Pearl"),
	G_Diamond		UMETA(DisplayName = "Diamond")
};

USTRUCT(BlueprintType)
struct FGemInfo
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(BlueprintReadWrite)
		EGemType GemType;

	UPROPERTY(BlueprintReadWrite)
		int32 Count;
};

UCLASS()
class UCCALLUS_API AGem : public AActor
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Properties)
		EGemType GemType = EGemType::G_Yellow;
};
