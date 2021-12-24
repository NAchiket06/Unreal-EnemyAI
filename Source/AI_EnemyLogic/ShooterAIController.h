// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "ShooterAIController.generated.h"

/**
 * 
 */
UCLASS()
class AI_ENEMYLOGIC_API AShooterAIController : public AAIController
{
	GENERATED_BODY()

public:
	void BeginPlay() override;
	void Tick(float DeltaSeconds) override;

	APawn *Player;

	UPROPERTY(EditAnywhere)
	float NavigationStopDistance = 100.f;
	
	UPROPERTY(EditAnywhere)
	class UBehaviorTree* AIBehavior;
};
