// Fill out your copyright notice in the Description page of Project Settings.

#include "Uccallus.h"
#include "Lantern.h"

using namespace std;

ALantern::ALantern(const FObjectInitializer& ObjectInitalizer) : Super(ObjectInitalizer)
{
    capacity = 10;
    cluCounter = 10;
}

//needs a pickup class
void ALantern::pickUpClus()
{
    
}

//main function for adding more clus to the lantern
float ALantern::calculateMath(const TArray<FString> pieces){
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
}

