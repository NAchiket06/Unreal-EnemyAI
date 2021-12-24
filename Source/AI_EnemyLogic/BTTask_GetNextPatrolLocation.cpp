// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_GetNextPatrolLocation.h"

#include "AIController.h"
#include "PlayerCharacter.h"
#include "ShooterAIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

UBTTask_GetNextPatrolLocation::UBTTask_GetNextPatrolLocation()
{ 
	NodeName = "Get Patrol Location";
}

EBTNodeResult::Type UBTTask_GetNextPatrolLocation::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);


	// GET OWNER REFRENCE AND THE PLAYERCHARACTER REFRENCE TO SET THE PATROLPOINTS
	
	if(OwnerComp.GetAIOwner() == nullptr)
	{
		UE_LOG(LogTemp,Warning,TEXT("aiowner NUllptr"));
	}
	APlayerCharacter* playerRef = Cast<APlayerCharacter>(OwnerComp.GetAIOwner()->GetPawn());

	if(playerRef == nullptr)
	{
		UE_LOG(LogTemp,Warning,TEXT("player NUllptr"));
	}
	// SINCE THE PLAYER IS IN PATROL MODE, SET THE MAX WALK SPEED TO WALK SPEED

	playerRef->GetCharacterMovement()->MaxWalkSpeed = 300;
	// GET THE CURRENT INDEX OF PATROL POINT FROM THE BLACKBOARD WHICH THE ENEMT IS CURRENTLY AT. 

	int Index = OwnerComp.GetBlackboardComponent()->GetValueAsInt("PatrolIndex");
	
	FVector GuardLocation = playerRef->PatrolPoints[Index];

	OwnerComp.GetBlackboardComponent()->SetValueAsVector(TEXT("GuardLocation"),GuardLocation);

	OwnerComp.GetBlackboardComponent()->ClearValue(TEXT("LastKnownLocation"));

	return EBTNodeResult::Succeeded;
}
