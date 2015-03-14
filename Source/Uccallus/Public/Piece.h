// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Gem.h"
#include "Piece.generated.h"

UENUM(BlueprintType)
enum class EPieceType : uint8
{
	P_Add = 1   UMETA(DisplayName = "Add"),
	P_Subtract = 3   UMETA(DisplayName = "Subtract"),
	P_Multiply = 5   UMETA(DisplayName = "Multiply"),
	P_Exponent = 8   UMETA(DisplayName = "Exponent"),
};

USTRUCT(BlueprintType)
struct FPieceInfo
{
	GENERATED_USTRUCT_BODY()

		UPROPERTY(BlueprintReadWrite)
		UTexture2D* PieceIcon;

	UPROPERTY(BlueprintReadWrite)
		EPieceType PieceType;

	UPROPERTY(BlueprintReadWrite)
		int32 Count;
};

/**
* Ingame piece actor
*/
UCLASS()
class UCCALLUS_API APiece : public AActor
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Properties)
		EPieceType PieceType = EPieceType::P_Add;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Properties)
		UTexture2D* PieceIcon;
};