// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Gem.generated.h"

/**
*
*/

UENUM(BlueprintType)
enum class EGemType : uint8
{
	G_Yellow = 1   UMETA(DisplayName = "Yellow"),
	G_Green = 3   UMETA(DisplayName = "Green"),
	G_Red = 5   UMETA(DisplayName = "Red"),
	G_Pearl = 8   UMETA(DisplayName = "Pearl"),
	G_Diamond = 13   UMETA(DisplayName = "Diamond")
};

USTRUCT(BlueprintType)
struct FGemInfo
{
	GENERATED_USTRUCT_BODY()

		UPROPERTY(BlueprintReadWrite)
		UTexture2D* GemIcon;

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

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Properties)
		UTexture2D* GemIcon;
};
