// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_AttackPlayer.h"
#include "Kismet/GameplayStatics.h"

UBTTask_AttackPlayer::UBTTask_AttackPlayer()
{
	NodeName = "Attack Player";
}

EBTNodeResult::Type UBTTask_AttackPlayer::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);

	// SHOOTING BEHAVIOUR
	UE_LOG(LogTemp,Warning,TEXT("Hit Player"));
	AActor* Player  = Cast<AActor>(UGameplayStatics::GetPlayerCharacter(this,0));

	// FPointDamageEvent DamageEvent(10,)
	// if(Player != nullptr)
	// {
	// 	Player->TakeDamage(10,FDamageEvent::DamageTypeClass)
	// }
	
	return  EBTNodeResult::Succeeded;
}


