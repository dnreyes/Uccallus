// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "UccallusCharacter.h"
#include "Piece.h"
#include "GameFramework/Actor.h"
#include "LPedestal.generated.h"

UCLASS()
class UCCALLUS_API ALPedestal : public AActor
{
	GENERATED_BODY()
	
public:	

	//===Functions===
	UFUNCTION(BlueprintCallable, Category = Lantern)
		bool IsEquationValid();

	UFUNCTION(BlueprintCallable, Category = Pedestal)
		void Activate();

	UFUNCTION(BlueprintCallable, Category = Pedestal)
		void Move(int32 B);

	UFUNCTION(BlueprintCallable, Category = Pedestal)
		void Launch(int32 M);

};
