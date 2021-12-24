// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "BTTask_GetNextPatrolLocation.generated.h"

/**
 * 
 */
UCLASS()
class AI_ENEMYLOGIC_API UBTTask_GetNextPatrolLocation : public UBTTask_BlackboardBase
{
	GENERATED_BODY()

public:
	UBTTask_GetNextPatrolLocation();

	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
};
