// Fill out your copyright notice in the Description page of Project Settings.

#include "Uccallus.h"
#include "Lantern.h"
#include "LanternPiecePickup.h"



ALanternPiecePickup::ALanternPiecePickup(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
    
}

void ALanternPiecePickup::OnPickedUp_Implementation()
{
    Super::OnPickedUp_Implementation();
    Destroy();
}