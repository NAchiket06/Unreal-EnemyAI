// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_IncrementPatrolIndex.h"
#include "AIController.h"
#include "PlayerCharacter.h"
#include "BehaviorTree/BlackboardComponent.h"

EBTNodeResult::Type UBTTask_IncrementPatrolIndex::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);
	
	int index = OwnerComp.GetBlackboardComponent()->GetValueAsInt("PatrolIndex");

	index = (index + 1) % 5;

	OwnerComp.GetBlackboardComponent()->SetValueAsInt("PatrolIndex", index);
	
	return EBTNodeResult::Succeeded;
}
