// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_CancelChase.h"

#include "BehaviorTree/BlackboardComponent.h"

UBTTask_CancelChase::UBTTask_CancelChase()
{
	NodeName = "Cancel Chase";
}

EBTNodeResult::Type UBTTask_CancelChase::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);

	// USED TO GET OUT OF CHASE BEHAVIOUR AFTER ENEMY SEARCHES FOR THE PLAYER AFTER 2 ITERATIONS
	OwnerComp.GetBlackboardComponent()->ClearValue(TEXT("LastKnownLocation"));

	return EBTNodeResult::Succeeded;
}
