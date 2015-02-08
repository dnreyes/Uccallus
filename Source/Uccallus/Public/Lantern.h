// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Array.h"
#include "GameFramework/Actor.h"
#include "Lantern.generated.h"

/**
 * 
 */
UCLASS()
class UCCALLUS_API ALantern : public AActor
{
	GENERATED_BODY()
	
public:
    
    ALantern(const FObjectInitializer& ObjectInitializer);
    
    //The clu cap in the lantern
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Energy)
    int32 capacity;
    
    //Amount of clus that are not turned into gems
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Energy)
    int32 cluCounter;
    
    //Tarray is just like a vector but for Unreal
    //Array holding the pieces currently in the lantern
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Energy)
    TArray<AActor*> pieces;
    
    //Array holding the gems(clus that have been turned into gems)
    TArray<AActor*> gems;
    
    //checks to see if lantern is empty
    bool isEmpty();
    
    //slowly decreases during the game
    void decreaseCounter();
    
    //main function for adding more clus to the lantern
    int32 calculateMath(const TArray<FString> pieces);
    
    UFUNCTION(BlueprintCallable, Category = Energy)
    void onPiecePickedUp(AActor* piece);
    
private:
    //needs a pickup class
    void pickUpClus();
    
    //increases capacity when you pick up a new lantern piece
    UFUNCTION(BlueprintCallable, Category = Energy)
    void increaseCap();
    
    
	
};
