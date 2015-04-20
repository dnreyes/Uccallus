// Copyright 1998-2014 Epic Games, Inc. All Rights Reserved.

#include "Uccallus.h"
#include "UccallusCharacter.h"
#include "Animation/AnimInstance.h"
#include "Engine.h"

AUccallusCharacter::AUccallusCharacter(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{

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
		NewInfo.GemType = (EGemType)(i + 1);
		GemCollection.Insert(NewInfo, i);
	}
}

FGemInfo AUccallusCharacter::CollectionAddGem(const EGemType GemType)
{
	for (int i = 0; i < NUM_GEMTYPES; ++i)
	{
		if (GemCollection[i].GemType == GemType)
		{
			GemCollection[i].Count++;
			return GemCollection[i];
		}
	}

	return FGemInfo();
}

FPieceInfo AUccallusCharacter::CollectionAddPiece(const EPieceType PieceType)
{
	int i = 0;
	int NumPieces = PieceCollection.Num();
	for (; i < NumPieces; ++i)
	{
		if (PieceCollection[i].PieceType == PieceType) break;
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
		Result.PieceType = PieceType;
		PieceCollection.Add(Result);
	}

	return Result;
}

void AUccallusCharacter::CollectionDepleteGem(const EGemType GemType)
{
	for (int i = 0; i < NUM_GEMTYPES; ++i)
	{
		if (GemCollection[i].GemType == GemType)
		{
			GemCollection[i].Count = FMath::Max(0, GemCollection[i].Count - 1);
			return;
		}
	}
}

void AUccallusCharacter::CollectionDepletePiece(const EPieceType PieceType)
{
	int i = 0;
	int NumPieces = PieceCollection.Num();
	for (; i < NumPieces; ++i)
	{
		if (PieceCollection[i].PieceType == PieceType)
		{
			PieceCollection[i].Count = FMath::Max(0, PieceCollection[i].Count - 1);
			if (PieceCollection[i].Count <= 0)
			{
				PieceCollection.RemoveAt(i);
			}
			return;
		}
	}
}

FGemInfo AUccallusCharacter::PickupGem(const APickupGem* GemActor)
{
	return CollectionAddGem(GemActor->GemType);
}


FPieceInfo AUccallusCharacter::PickupPiece(const APickupPiece* PieceActor)
{
	return CollectionAddPiece(PieceActor->PieceType);
}

void AUccallusCharacter::LanternInsertPiece(EPieceType PieceType, int32 SlotIndex)
{
	if (InLanternCollection.Num() >= LanternMaxNumPieces) return;

	FInLanternPiece Result;
	Result.PieceType = PieceType;

	InLanternCollection.Insert(Result, SlotIndex);
}

FInLanternPiece AUccallusCharacter::LanternRemovePiece(int32 SlotIndex)
{
	FInLanternPiece Result;

	if (InLanternCollection.Num() > SlotIndex)
	{
		Result = InLanternCollection[SlotIndex];
		if (Result.PieceGems.Num() > 0)
		{
			for (const EGemType &Gem : Result.PieceGems)
			{
				if (Gem != EGemType::G_None)
				{
					CollectionAddGem(Gem);
				}
			}
		}
		InLanternCollection.RemoveAt(SlotIndex);
	}

	return Result;
}

void AUccallusCharacter::LanternPieceInsertGem(EGemType GemType, int32 PieceSlotIndex, int32 GemSlotIndex)
{
	if (InLanternCollection[PieceSlotIndex].PieceGems.Num() <= GemSlotIndex)
	{
		InLanternCollection[PieceSlotIndex].PieceGems.Empty();
		InLanternCollection[PieceSlotIndex].PieceGems.AddUninitialized(GemSlotIndex + 1);
	}

	InLanternCollection[PieceSlotIndex].PieceGems[GemSlotIndex] = GemType;
	
}

EGemType AUccallusCharacter::LanternPieceRemoveGem(int32 PieceSlotIndex, int32 GemSlotIndex)
{
	FInLanternPiece Piece = InLanternCollection[PieceSlotIndex];
	EGemType Result;
	if (Piece.PieceGems.Num() > GemSlotIndex)
	{
		Result = Piece.PieceGems[GemSlotIndex];
		InLanternCollection[PieceSlotIndex].PieceGems[GemSlotIndex] = EGemType::G_None;
	}
	return Result;
}

//Returns the color of the gem within the constant piece inside the lantern
EGemType AUccallusCharacter::GetLanternCollectionGemType(int32 PieceSlotIndex, int32 GemSlotIndex) {
	return InLanternCollection[PieceSlotIndex].PieceGems[GemSlotIndex];
}

//Returns the name of the pieces within the lantern
EPieceType AUccallusCharacter::GetLanternCollectionPieceType(int32 PieceSlotIndex) {
	return InLanternCollection[PieceSlotIndex].PieceType;
}

//checks to see if the equation inside the lantern is an actual equation
//if the lantern is empty or the equation is not right, then it will return false
//if it correlates to an equation, then it will return true.
bool AUccallusCharacter::IsEquationValid() {
	//empty case
	if (InLanternCollection.Num() == 0){
		UE_LOG(LogTemp, Log, TEXT("There is nothing in the lantern. Hooray!"));
		return false;
	}
	//lantern contains something inside
		//case for y = x or y = const
	else if (InLanternCollection.Num() == 1) {
		//get the piece type from the first slot since there's only one piece
		//EPieceType P = GetLanternCollectionPieceType(0);
		EPieceType P = GetLanternCollectionPieceType(1);
		//UE_LOG(LogTemp, Log, TEXT("Piece is currently %s"), P);
		//If it's anything but a const piece or a variable x, it's not a valid equation for this case.
		if ((P != EPieceType::P_Const) || (P != EPieceType::P_Var)){
			//For debugging only, DELETE WHEN FINISHED USING
			UE_LOG(LogTemp, Log, TEXT("The piece is not a constant nor a variable"));
			return false;
		}
		else {
			//For debugging only, DELETE WHEN FINISHED USING
			UE_LOG(LogTemp, Log, TEXT("The piece is a constant or a variable."));
			return true;
		}
	}
	//Else it is an actual equation
	else {
		//The smallest amount of pieces should follow n + n
		if (InLanternCollection.Num() > 2)
			return true;
		else return false;
	}
	//return false;
}
