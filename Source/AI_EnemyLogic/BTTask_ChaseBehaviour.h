// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "BTTask_ChaseBehaviour.generated.h"

/**
 * 
 */
UCLASS()
class AI_ENEMYLOGIC_API UBTTask_ChaseBehaviour : public UBTTask_BlackboardBase
{
	GENERATED_BODY()
	UBTTask_ChaseBehaviour();
protected:
    
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

};
