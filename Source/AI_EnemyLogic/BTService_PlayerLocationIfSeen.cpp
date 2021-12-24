// Fill out your copyright notice in the Description page of Project Settings.

// UPDATES THE PLAYER LOCATION CONTINUOSLY TO THE AI AGENT

#include "BTService_PlayerLocationIfSeen.h"

#include "AIController.h"
#include "PlayerCharacter.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/GameplayStatics.h"
#include "XMPP/Public/XmppMultiUserChat.h"

UBTService_PlayerLocationIfSeen::UBTService_PlayerLocationIfSeen()
{
	NodeName = "Update Player Location if in Range";
}

void UBTService_PlayerLocationIfSeen::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

	// GET PLAYER REFERENCE FOR AI
	// USED TO UPDATE PLAYER LOCATION AT EVERY TICK
	APawn *Player = UGameplayStatics::GetPlayerPawn(GetWorld(),0);

	// THIS REFERENCE IS TO THE PLAYERCHARACTER OF AI ITSELF. THIS IS USED TO CHANGE THE MOVEMENT SPEED OF AI WHEREVER NEEDED
	APlayerCharacter* playerRef = Cast<APlayerCharacter>(OwnerComp.GetAIOwner()->GetPawn());

	//OwnerComp.GetBlackboardComponent()->SetValueAsBool(TEXT("PlayerInView"),true);

	if(Player == nullptr)
	{
		return;
	}
	if (OwnerComp.GetAIOwner() == nullptr)
	{
		return;
	}
	
	/*
	 *	IF PLAYER IS IN VIEW OF ENEMY
	 *	SET WALK SPEED TO RUN SPEED TO START CHASE BEHAVIOUR
	 *	SET PLAYERINVIEW BOOL TO TRUE
	 *	UPDATE THE DISTANCE TO PLAYER
	 *	SET PLAYERDISTANCE VARIABLE 
	 *	UPDATE PLAYER LOCATION AS CURRENTPLAYERLOCATION
	 */
	if(OwnerComp.GetAIOwner()->LineOfSightTo(Player))
	{
		float DistanceToPlayer = (OwnerComp.GetAIOwner()->GetPawn()->GetActorLocation() - Player->GetActorLocation()).Size();
		playerRef->GetCharacterMovement()->MaxWalkSpeed = 600;
		OwnerComp.GetBlackboardComponent()->SetValueAsBool(TEXT("PlayerInView"),true);
		OwnerComp.GetBlackboardComponent()->SetValueAsFloat(TEXT("PlayerDistance"),DistanceToPlayer);
		OwnerComp.GetBlackboardComponent()->SetValueAsVector(TEXT("CurrentPlayerLocation"),Player->GetActorLocation());

		SetPlayerLastKnownLocation(OwnerComp,Player);
	}
	/*
	 *	WHEN AI LOSES SIGHT OF PLAYER
	 *	START CHASE BEHAVIOUR
	 *	CLEAR PLAYERINVIEW VARIABLE
	 *	CLEAR PLAYERDISTANCE
	 *	CLEAR CURRENT PLAYER LOCATION
	 *	SET THE LAST KNOWN LOCATION TO START SEARCH BEHAVIOUR
	 *	CHASE BEHAVIOUR IMPLEMENTED IN BTTASK 
	 *	
	 */
	else
	{
		OwnerComp.GetBlackboardComponent()->ClearValue(TEXT("PlayerInView"));
		OwnerComp.GetBlackboardComponent()->ClearValue(TEXT("PlayerDistance"));
		OwnerComp.GetBlackboardComponent()->ClearValue(TEXT("CurrentPlayerLocation"));
	}
	
}

void UBTService_PlayerLocationIfSeen::SetPlayerLastKnownLocation(UBehaviorTreeComponent& OwnerComp,APawn *Player)
{
	OwnerComp.GetBlackboardComponent()->SetValueAsVector(TEXT("LastKnownLocation"),Player->GetActorLocation());
}
