// Fill out your copyright notice in the Description page of Project Settings.


#include "ShooterAIController.h"

#include "BehaviorTree/BlackboardComponent.h"
#include "Kismet/GameplayStatics.h"

void AShooterAIController::BeginPlay()
{
	Super::BeginPlay();

	Player = UGameplayStatics::GetPlayerPawn(this,0);

	if(AIBehavior != nullptr)
	{
		RunBehaviorTree(AIBehavior);

		// Player Is not in view of Enemy
		if(LineOfSightTo(Player))
		{
			GetBlackboardComponent()->SetValueAsVector(TEXT("PlayerLocation"),Player->GetActorLocation());
		}
		GetBlackboardComponent()->SetValueAsVector(TEXT("StartLocation"),GetPawn()->GetActorLocation());
	}
}

void AShooterAIController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	
}
