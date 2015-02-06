// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <string>
#include <vector>

#include "GameFramework/Actor.h"
#include "Lantern.generated.h"

using namespace std;
/**
 * Lantern Main Class. This class deals with the
 * main functionality of the lantern class,
 * such as checking if it is empty, what pieces
 * it has, which function to use, etc.
 */
UCLASS()
class UCCALLUS_API ALantern : public AActor
{
	GENERATED_BODY()

private:
	void pickUpClus();

	int calculateMath(const vector<string> pieces);

	void decreaseCounter();

	bool lanternEmpty();

	void increaseCap();

	void OnPiecePickedUp(string piece);

public:
	string pieceName;
	
	int cluCounter;
	
	int capacity;

};
