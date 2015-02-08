// Fill out your copyright notice in the Description page of Project Settings.

#include <string>
#include <vector>
#include "Uccallus.h"
#include "Lantern.h"

using namespace std;

<<<<<<< HEAD
ALantern::ALantern(const FObjectInitializer& ObjectInitalizer) : Super(ObjectInitalizer)
{
    capacity = 10;
    cluCounter = 10;
}

//needs a pickup class
void ALantern::pickUpClus()
{
    
}

int32 ALantern::calculateMath(const TArray<FString> pieces){
    //should probably look at UnrealMathUtility.h
    //                    and GenericPlatform.h
    return 0;
}

//slowly decreases during the game
//probably needs a tick override
void ALantern::decreaseCounter(){
    cluCounter--;
}

//checks to see if lantern is empty
bool ALantern::isEmpty(){
    if(cluCounter == 0) {
        return true;
    }
    return false;
}

//increases capacity when you pick up a new lantern piece
//this might be a blueprint thing
void ALantern::increaseCap()
{
    capacity += 10;
}

//append a new piece to string vector
//add a new piece to interact with in the lantern
void ALantern::onPiecePickedUp(AActor* piece)
{
    pieces.Add(piece);
    increaseCap();
=======
ALantern::ALantern(const FObjectInitializer& ObjectInitalizer)
	: Super(ObjectInitializer)
{
	capacity = 10;
	cluCounter = 10;
}

void ALantern::pickUpClus() {
	cluCounter++;
>>>>>>> FETCH_HEAD
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