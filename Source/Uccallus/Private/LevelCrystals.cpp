// Fill out your copyright notice in the Description page of Project Settings.

#include "Uccallus.h"
#include "LevelCrystals.h"

ALevelCrystals::ALevelCrystals(const FObjectInitializer& ObjectInitalizer) : Super(ObjectInitalizer) {
	wasHit = false;
}

void ALevelCrystals::OnBeamHit() {
	wasHit = true;
}
