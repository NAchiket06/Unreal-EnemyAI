// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_AttackPlayer.h"

UBTTask_AttackPlayer::UBTTask_AttackPlayer()
{
	NodeName = "Attack Player";
}

EBTNodeResult::Type UBTTask_AttackPlayer::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);

	UE_LOG(LogTemp,Warning,TEXT("Hit Player"));

	return  EBTNodeResult::Succeeded;
}


