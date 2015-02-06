// Fill out your copyright notice in the Description page of Project Settings.

#include <string>
#include <vector>
#include "Uccallus.h"
#include "Lantern.h"

using namespace std;

ALantern::ALantern(const FObjectInitializer& ObjectInitalizer)
	: Super(ObjectInitializer)
{
	capacity = 10;
	cluCounter = 10;
}

void ALantern::pickUpClus() {
	cluCounter++;
}

int ALantern::calculateMath(const vector<string> pieces) {

}

void ALantern::decreaseCounter() {
	cluCounter--;
}

bool ALantern::lanternEmpty(){
	return if (cluCounter == 0)
}

void ALantern::increaseCap() {
	capacity++;
}

void OnPiecePickedUp(string piece) {

}