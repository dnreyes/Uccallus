// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Lantern.generated.h"

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

public:
    
    ALantern(const FObjectInitializer& ObjectInitializer);
    
    //The clu cap in the lantern
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Power)
    int32 capacity;
    
    //Amount of clus that are not turned into gems
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Power)
    int32 cluCounter;
    
    //Tarray is just like a vector but for Unreal
    //Array holding the pieces currently in the lantern
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Power)
    TArray<AActor*> pieces;
    
    //Array holding the gems(clus that have been turned into gems)
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Power)
    TArray<AActor*> gems;
    
    //checks to see if lantern is empty
    bool isEmpty();
    
    //slowly decreases during the game
	UFUNCTION(BlueprintCallable, Category = Power)
    void decreaseCounter();
    
    //main function for adding more clus to the lantern
    int32 calculateMath(const TArray<FString> pieces);
    
    UFUNCTION(BlueprintCallable, Category = Power)
    void onPiecePickedUp(AActor* piece);
   
    //needs a pickup class
    void pickUpClus();
    
    //increases capacity when you pick up a new lantern piece
    UFUNCTION(BlueprintCallable, Category = Power)
    void increaseCap();
};
