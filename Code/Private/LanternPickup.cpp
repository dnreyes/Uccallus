// Fill out your copyright notice in the Description page of Project Settings.
//Copied from https://github.com/Harrison1/UE4Programming/blob/master/Source/ThirdPersonTutorial/Private/BatteryPickup.cpp
#include "lantern_test.h"
#include "LanternPickup.h"

ALanternPickup::ALanternPickup(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	hasLantern = true;
}

void ALanternPickup::OnPickUp_Implementation() {
	Super::OnPickUp_Implementation();
	Destroy();
}