// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_ChaseBehaviour.h"

#include "BehaviorTree/BlackboardComponent.h"
#include "Kismet/GameplayStatics.h"

UBTTask_ChaseBehaviour::UBTTask_ChaseBehaviour()
{
	NodeName = "Chase Behaviour";
}

EBTNodeResult::Type UBTTask_ChaseBehaviour::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);

	APawn *Player = UGameplayStatics::GetPlayerPawn(GetWorld(),0);
	
	OwnerComp.GetBlackboardComponent()->SetValueAsVector(TEXT("LastKnownLocation"),Player->GetActorLocation());

	return EBTNodeResult::Succeeded;
}
