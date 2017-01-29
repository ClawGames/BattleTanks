// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTanks.h"
#include "TankBarrel.h"


void UTankBarrel::Elevate(float RelativeSpeed)
{
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, 1);

	float ElevationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;

	float ClampedElevation = FMath::Clamp<float>(RelativeRotation.Pitch + ElevationChange, MinElevation, MaxElevation);

	SetRelativeRotation(FRotator(ClampedElevation, 0, 0));
}
