// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Gem.h"
#include "Piece.generated.h"

UENUM(BlueprintType)
enum class EPieceType : uint8
{
	P_Add			UMETA(DisplayName = "Add"),
	P_Subtract		UMETA(DisplayName = "Subtract"),
	P_Multiply		UMETA(DisplayName = "Multiply"),
	P_Exponent		UMETA(DisplayName = "Exponent"),
	P_Var			UMETA(DisplayName = "Variable"),
	P_Log			UMETA(DisplayName = "Logarithm"),
	P_Sqrt			UMETA(DisplayName = "Root"),
	P_Half			UMETA(DisplayName = "Half")
};

USTRUCT(BlueprintType)
struct FPieceInfo
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(BlueprintReadWrite)
		EPieceType PieceType;

	UPROPERTY(BlueprintReadWrite)
		int32 Count;
};

USTRUCT(BlueprintType)
struct FInLanternPiece
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(BlueprintReadWrite)
		EPieceType PieceType;

	UPROPERTY(BlueprintReadWrite)
		TArray<EGemType> PieceGems;
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
};