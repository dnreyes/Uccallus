// Fill out your copyright notice in the Description page of Project Settings.

#include "Uccallus.h"
#include "Pedestal_.h"


// Sets default values
APedestal_::APedestal_()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APedestal_::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APedestal_::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

bool APedestal_::IsEquationValid()
{
	/*
	 *This function is to be used to check what
	 *equation is valid for certain pedestals
	 *It's overrideable, 
	 */
	return false;
}

void APedestal_::Activate()
{
	/*
	 *This function is to be used to activate the
	 *pedestal. Once the pedestal gets the equation
	 *from the lantern, the pedestal should read it
	 *and move to the right coordinate and then shoot
	 *a beam of light accordingly
	*/
}

void APedestal_::Move(int32 whereTo)
{
	/*
	 *This function is to be called after the pedestal
	 *is activated. It moves according to what is put
	 *in the equation.
	 */
}

void APedestal_::Launch(int32 shootWhere)
{
	/*
	 *This function is to be called after the pedestal
	 *moves to its new location. It shoots out a beam
	 *according to what is put in the equation.
	*/
}