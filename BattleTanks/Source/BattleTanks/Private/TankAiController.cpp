// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTanks.h"
#include "Tank.h"
#include "TankAiController.h"

void ATankAiController::Tick(float DeltaTime)
{
	Super::Tick( DeltaTime );

	ATank* PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	ATank* OurTank = Cast<ATank>(GetPawn());

	if (PlayerTank)
	{
		OurTank->AimAt(PlayerTank->GetActorLocation());
		OurTank->Fire();
	}
	else {
		UE_LOG(LogTemp, Error, TEXT("We couldn't find players' tank"));
		return;
	}

}

