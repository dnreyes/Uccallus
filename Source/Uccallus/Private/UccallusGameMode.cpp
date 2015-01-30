// Copyright 1998-2014 Epic Games, Inc. All Rights Reserved.

#include "Uccallus.h"
#include "UccallusGameMode.h"
#include "UccallusPlayerController.h"
#include "UccallusCharacter.h"

AUccallusGameMode::AUccallusGameMode(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	// use our custom PlayerController class
	PlayerControllerClass = AUccallusPlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/Blueprints/MyCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}