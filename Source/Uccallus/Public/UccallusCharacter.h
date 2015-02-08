// Copyright 1998-2014 Epic Games, Inc. All Rights Reserved.
#pragma once

#include "GameFramework/Character.h"
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
    
    /***----------ADDED CODE BASED OF TUTORIAL----------***/
    
    /*
     * Radius of visibility will increase with each lantern piece found
     */
    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Energy)
    float lightRadius;
    
    
    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Energy)
    int32 energyLevel;
    
    /*
     * Collection volume
     * might be appliciable for all of the stuff that should be interactable
     * with the character.
     */
    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Energy)
    class USphereComponent* CollectionSphere;
    
    class ALantern* CharLantern;
    
    virtual void Tick(float DeltaSeconds) override;
    
protected:
    
    /*
     * called when we press a key, to collect the pieces inside the SphereComponent
     */
    UFUNCTION(BlueprintCallable, Category = Energy)
    void collectPieces();
    
    
    UFUNCTION(BlueprintImplementableEvent, Category = Energy)
    void addToLantern();
    
    virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;
    
};

