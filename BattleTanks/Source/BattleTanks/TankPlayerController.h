// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
class ATank;

UCLASS()
class BATTLETANKS_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

private:
	ATank* GetControlledTank() const;
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
	float CrossHairXLocation;

	UPROPERTY(EditAnywhere)
	float CrossHairYLocation;
	//Tart the tank to move barrel to point where the cursor is pointing

	void AimTowardsCrosshair() const;

	bool GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation);

	bool GetSightRayHitLocation(FVector& HitLocation) const;
};