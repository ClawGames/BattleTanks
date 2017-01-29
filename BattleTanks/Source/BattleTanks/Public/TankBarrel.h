// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANKS_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	// -1 to 1
	void Elevate(float RelativeSpeed);

private:
	UPROPERTY(EditAnywhere, Category=Setup)
	float MaxDegreesPerSecond = 5;
	UPROPERTY(EditAnywhere, Category = Setup)
	float MinElevation = 0;
	UPROPERTY(EditAnywhere, Category = Setup)
	float MaxElevation = 40;
	
};
