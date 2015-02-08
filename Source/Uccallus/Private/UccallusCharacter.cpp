// Copyright 1998-2014 Epic Games, Inc. All Rights Reserved.


#include "Uccallus.h"
#include "UccallusCharacter.h"
#include "LanternPiecePickup.h"
//#include "Lantern.h"
#include "Animation/AnimInstance.h"

AUccallusCharacter::AUccallusCharacter(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
    
    lightRadius = 10.0f;
    
    //collisions
    CollectionSphere = ObjectInitializer.CreateDefaultSubobject<USphereComponent>(this, TEXT("CollectionSphere"));
    CollectionSphere->AttachTo(RootComponent);
    CollectionSphere->SetSphereRadius(200.f);
    
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

}

void AUccallusCharacter::SetupPlayerInputComponent(class UInputComponent* InputComponent) {
	//set up gameplay key bindings

	check(InputComponent);

    InputComponent->BindAction("CollectPickups", IE_Pressed, this, &AUccallusCharacter::collectPieces);
}

void AUccallusCharacter::collectPieces()
{
    //get all overlapping actors and store them in a collected Actors array
    
    TArray<AActor*> collectedActors;
    CollectionSphere->GetOverlappingActors(collectedActors);
    
    for(int32 iCollected = 0; iCollected < collectedActors.Num(); ++iCollected) {
        //Cast the collected Actor to ALanternPiecePickup
        
        ALanternPiecePickup* const TestPiece = Cast<ALanternPiecePickup>(collectedActors[iCollected]);
        
        if (TestPiece && !TestPiece->IsPendingKill() && TestPiece->bIsActive)
        {
            TestPiece->OnPickedUp();
            TestPiece->bIsActive = false;
        }
    }
}