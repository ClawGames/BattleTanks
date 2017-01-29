// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTanks.h"
#include "Tank.h"
#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay() {
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("PlayerController begin play"));

	ATank* ControlledTank = GetControlledTank();

	if (ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("Player tank: %s"), * ControlledTank->GetName());
	}
	else {
		UE_LOG(LogTemp, Error, TEXT("Error possesing a tank"));
	}

}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AimTowardsCrosshair();


}

void ATankPlayerController::AimTowardsCrosshair() const
{
	if (!GetControlledTank()) { return; }

	FVector HitLocation; // Out parameter

	if (GetSightRayHitLocation(HitLocation)) // Has side-effet, is going to line trace
	{
		GetControlledTank()->AimAt(HitLocation);
	}

	// Get world location if linetrace through crosshair
	// If it hits the landscape
		// Tell controlled tank to aim at this point
}

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}



bool ATankPlayerController::GetSightRayHitLocation(FVector& HitLocation) const
{
	// Find the crosshair position
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	FVector2D ScreenLocation = FVector2D(ViewportSizeX * CrossHairXLocation, ViewportSizeY * CrossHairYLocation);

	// "De-project" the screen position of the crosshair to a world direction
	FVector CameraWorldLocation;
	FVector LookDirection;

	if (DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, CameraWorldLocation, LookDirection))
	{
		FHitResult Hit;

		if (GetHitResultAtScreenPosition(ScreenLocation, ECollisionChannel::ECC_WorldStatic, false, Hit)) // TODO WE MAY HAVE A PROBLEM WITH ECC_WORLDSTATIC
		{
			HitLocation = Hit.Location;
			return true;
		}

	}

	// Line-trace along that look direction, and see what we hit (up to max range)
	return false;
}





