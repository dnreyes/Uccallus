// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "UccallusCharacter.h"
#include "Pedestal_.generated.h"

UCLASS()
class UCCALLUS_API APedestal_ : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APedestal_();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	//===Data===
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Lantern)
		TArray<FPieceInfo> InLanternPieceCollection;

	//===Functions===
	UFUNCTION(BlueprintCallable, Category = Lantern)
		virtual bool IsEquationValid();
	
	UFUNCTION(BlueprintCallable, Category = Pedestal)
		virtual void Activate();

	UFUNCTION(BlueprintCallable, Category = Pedestal)
		virtual void Move(int32 whereTo);

	UFUNCTION(BlueprintCallable, Category = Pedestal)
		virtual void Launch(int32 shootWhere);
	
};
