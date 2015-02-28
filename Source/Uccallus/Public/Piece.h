// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Gem.h"
#include "Piece.generated.h"

/**
 * 
 */
UCLASS()
class UCCALLUS_API APiece : public AActor
{
	GENERATED_BODY()
	
public:
    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Piece)
    FString id;
    
    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Piece)
    EGemtypeEnum input;
    
    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Piece)
    bool checkInput;
	
};
