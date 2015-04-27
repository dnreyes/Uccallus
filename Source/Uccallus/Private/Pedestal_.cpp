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

