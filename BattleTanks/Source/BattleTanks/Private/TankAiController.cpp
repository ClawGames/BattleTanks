// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTanks.h"
#include "Tank.h"
#include "TankAiController.h"

void ATankAiController::BeginPlay()
{
	Super::BeginPlay();
}

void ATankAiController::Tick(float DeltaTime)
{
	Super::Tick( DeltaTime );

	ATank* PlayerTank = GetPlayerTank();
	ATank* OurTank = GetControlledTank();
	if (PlayerTank)
	{
		OurTank->AimAt(PlayerTank->GetActorLocation());
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
		return PlayerTank;
	}
	else 
	{
		UE_LOG(LogTemp, Error, TEXT("We couldn't find players' tank"));
		return nullptr;
	}
}