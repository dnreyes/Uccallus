// Fill out your copyright notice in the Description page of Project Settings.

#include "Uccallus.h"
#include "UccallusCharacter.h"
#include "Piece.h"
#include "LPedestal.h"

ALPedestal::ALPedestal(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{

}

bool ALPedestal::IsEquationValid(){
	int i = 0;
	int NumPieces = HeroCharacter->PieceCollection.Num();
	UE_LOG(LogTemp, Log, TEXT("NumPieces: %d"), NumPieces);
}

void ALPedestal::Activate() {

}

void ALPedestal::Move(int32 B){

}

void ALPedestal::Launch(int32 M){

}
