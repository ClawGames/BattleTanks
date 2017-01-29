// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AIController.h"
#include "TankAiController.generated.h"

/**
 * 
 */
class ATank;

UCLASS()
class BATTLETANKS_API ATankAiController : public AAIController
{
	GENERATED_BODY()
	
public:
private:

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

	ATank* GetControlledTank() const;

	ATank* GetPlayerTank() const;
};
