// Copyright 1998-2014 Epic Games, Inc. All Rights Reserved.
#pragma once

#include "GameFramework/Character.h"
#include "Gem.h"
#include "Piece.h"
#include "InLanternPiece.h"
#include "UccallusCharacter.generated.h"

class ALantern;

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

	/***----------ADDED CODE BASED OF TUTORIAL----------***/

	/*
	* Radius of visibility will increase with each lantern piece found
	*/
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Power)
		float lightRadius;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Power)
		int32 energyLevel;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Lantern)
		TArray<AInLanternPiece*> InLanternCollection;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Lantern)
		TArray<FPieceInfo> PieceCollection;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Lantern)
		TArray<FGemInfo> GemCollection;

	UFUNCTION(BlueprintCallable, Category = LanternCollection)
		FGemInfo PickupGem(const AGem* GemActor);

	UFUNCTION(BlueprintCallable, Category = LanternCollection)
		FPieceInfo PickupPiece(const APiece* PieceActor);
};