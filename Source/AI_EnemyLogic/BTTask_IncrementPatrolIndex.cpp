// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_IncrementPatrolIndex.h"
#include "AIController.h"
#include "PlayerCharacter.h"
#include "BehaviorTree/BlackboardComponent.h"

EBTNodeResult::Type UBTTask_IncrementPatrolIndex::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);
	
	int index = OwnerComp.GetBlackboardComponent()->GetValueAsInt("PatrolIndex");

	APlayerCharacter* playerRef = Cast<APlayerCharacter>(OwnerComp.GetAIOwner()->GetPawn());

	if(playerRef == nullptr || playerRef->PatrolPointLength == 0)
	{
		UE_LOG(LogTemp,Warning,TEXT("player NUllptr or Vector length set to 0"));
	}
	
	index = (index + 1) % playerRef->PatrolPointLength;

	OwnerComp.GetBlackboardComponent()->SetValueAsInt("PatrolIndex", index);
	
	return EBTNodeResult::Succeeded;
}
