// Copyright 1998-2014 Epic Games, Inc. All Rights Reserved.

#include "Uccallus.h"
#include "UccallusCharacter.h"
#include "Animation/AnimInstance.h"

AUccallusCharacter::AUccallusCharacter(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{

	/******----------------Added Code---------------******/

	lightRadius = 10.0f;
	energyLevel = 10;

	/******------------End of Added Code------------******/

	// Set size for player capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	// Don't rotate character to camera direction
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Rotate character to moving direction
	GetCharacterMovement()->RotationRate = FRotator(0.f, 640.f, 0.f);
	GetCharacterMovement()->bConstrainToPlane = true;
	GetCharacterMovement()->bSnapToPlaneAtStart = true;

	// Create a camera boom...
	CameraBoom = ObjectInitializer.CreateDefaultSubobject<USpringArmComponent>(this, TEXT("CameraBoom"));
	CameraBoom->AttachTo(RootComponent);
	CameraBoom->bAbsoluteRotation = true; // Don't want arm to rotate when character does
	CameraBoom->TargetArmLength = 800.f;
	CameraBoom->RelativeRotation = FRotator(-60.f, 0.f, 0.f);
	CameraBoom->bDoCollisionTest = false; // Don't want to pull camera in when it collides with level

	// Create a camera...
	TopDownCameraComponent = ObjectInitializer.CreateDefaultSubobject<UCameraComponent>(this, TEXT("TopDownCamera"));
	TopDownCameraComponent->AttachTo(CameraBoom, USpringArmComponent::SocketName);
	TopDownCameraComponent->bUsePawnControlRotation = false; // Camera does not rotate relative to arm

	for (int i = 0; i < NUM_GEMTYPES; ++i)
	{
		FGemInfo NewInfo;
		NewInfo.GemType = (EGemType)i;
		GemCollection.Insert(NewInfo, i);
	}
}

FGemInfo AUccallusCharacter::PickupGem(const APickupGem* GemActor)
{
	for (int i = 0; i < NUM_GEMTYPES; ++i)
	{
		if (GemCollection[i].GemType == GemActor->GemType)
		{
			GemCollection[i].Count++;
			return GemCollection[i];
		}
	}

	return FGemInfo();
}

FPieceInfo AUccallusCharacter::PickupPiece(const APickupPiece* PieceActor)
{
	int i = 0;
	int NumPieces = PieceCollection.Num();
	for (; i < NumPieces; ++i)
	{
		if (PieceCollection[i].PieceType == PieceActor->PieceType) break;
	}

	FPieceInfo Result;

	if (i < NumPieces)
	{
		PieceCollection[i].Count++;
		Result = PieceCollection[i];
	}
	else
	{
		Result.Count = 1;
		Result.PieceType = PieceActor->PieceType;
		PieceCollection.Add(Result);
	}

	return Result;
}