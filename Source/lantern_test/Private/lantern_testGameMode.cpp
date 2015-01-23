// Copyright 1998-2014 Epic Games, Inc. All Rights Reserved.

#include "lantern_test.h"
#include "lantern_testGameMode.h"
#include "lantern_testPlayerController.h"
#include "lantern_testCharacter.h"

Alantern_testGameMode::Alantern_testGameMode(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	// use our custom PlayerController class
	PlayerControllerClass = Alantern_testPlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/Blueprints/MyCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}