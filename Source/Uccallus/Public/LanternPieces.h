// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "LanternPieces.generated.h"

/**
 * 
 */
UCLASS()
class UCCALLUS_API ALanternPieces : public AActor
{
	GENERATED_BODY()
public:
	/*This is the lantern piece i.d. It distinguish between whether it's
	 *an operator or variable */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pieces")
		FString name;
	/*This is the gem value you assign it. Some pieces do not accept input.*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pieces")
		int32 input;

	
};
