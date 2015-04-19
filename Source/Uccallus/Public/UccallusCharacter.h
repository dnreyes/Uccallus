// Copyright 1998-2014 Epic Games, Inc. All Rights Reserved.
#pragma once

#include "GameFramework/Character.h"
#include "PickupGem.h"
#include "PickupPiece.h"
#include "UccallusCharacter.generated.h"

UCLASS(Blueprintable)
class AUccallusCharacter : public ACharacter
{
	GENERATED_BODY()

		/** Top down camera */
		UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* TopDownCameraComponent;

	/** Camera boom positioning the camera above the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;


public:
	AUccallusCharacter(const FObjectInitializer& ObjectInitializer);

	/** Returns TopDownCameraComponent subobject **/
	FORCEINLINE class UCameraComponent* GetTopDownCameraComponent() const { return TopDownCameraComponent; }

	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Lantern)
		int32 LanternMaxNumPieces = 13;

	//====Game Data====

	/*
	* Radius of visibility will increase with each lantern piece found
	*/
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Power)
		float LightRadius;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Power)
		int32 EnergyLevel;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Collection)
		TArray<FInLanternPiece> InLanternCollection;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Collection)
		TArray<FPieceInfo> PieceCollection;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Collection)
		TArray<FGemInfo> GemCollection;

	//=====Collection Functions=====

	UFUNCTION(BlueprintCallable, Category = Collection)
		FGemInfo CollectionAddGem(const EGemType GemType);

	UFUNCTION(BlueprintCallable, Category = Collection)
		FPieceInfo CollectionAddPiece(const EPieceType PieceType);

	UFUNCTION(BlueprintCallable, Category = Collection)
		void CollectionDepleteGem(const EGemType GemType);

	UFUNCTION(BlueprintCallable, Category = Collection)
		void CollectionDepletePiece(const EPieceType PieceType);

	UFUNCTION(BlueprintCallable, Category = Collection)
		FGemInfo PickupGem(const APickupGem* GemActor);

	UFUNCTION(BlueprintCallable, Category = Collection)
		FPieceInfo PickupPiece(const APickupPiece* PieceActor);

	//=====In Lantern Collection Functions=====

	UFUNCTION(BlueprintCallable, Category = LanternCollection)
		void LanternInsertPiece(EPieceType PieceType, int32 SlotIndex);

	UFUNCTION(BlueprintCallable, Category = LanternCollection)
		FInLanternPiece LanternRemovePiece(int32 SlotIndex);

	UFUNCTION(BlueprintCallable, Category = LanternCollection)
		void LanternPieceInsertGem(EGemType GemType, int32 PieceSlotIndex, int32 GemSlotIndex);

	UFUNCTION(BlueprintCallable, Category = LanternCollection)
		EGemType LanternPieceRemoveGem(int32 PieceSlotIndex, int32 GemSlotIndex);
};