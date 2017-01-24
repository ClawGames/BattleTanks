// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTanks.h"
#include "TankAiController.h"

void ATankAiController::BeginPlay()
{
	ATank* PlayerTank = GetPlayerTank();

	if (PlayerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("Ai tank: %s"), *PlayerTank->GetName());
	}
	else {
		UE_LOG(LogTemp, Error, TEXT("Error possesing a tank"));
	}
}

ATank* ATankAiController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAiController::GetPlayerTank() const 
{
	ATank* PlayerTank = nullptr;
	PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());

	if (PlayerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("We found our player tank. It is called %s"), *PlayerTank->GetName());
		return PlayerTank;
	}
	else 
	{
		UE_LOG(LogTemp, Error, TEXT("We couldn't find players' tank"));
		return nullptr;
	}
}