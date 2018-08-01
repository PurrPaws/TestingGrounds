// Fill out your copyright notice in the Description page of Project Settings.

#include "ChooseNextWaypoint.h"
#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "TP_ThirdPerson/PatrollingGuard.h"

EBTNodeResult::Type UChooseNextWaypoint::ExecuteTask(UBehaviorTreeComponent & OwnerComp, uint8 * NodeMemory)
{
	//initialization
	UBlackboardComponent* BlackboardComp = OwnerComp.GetBlackboardComponent();
	int32 Index = BlackboardComp->GetValueAsInt(IndexKey.SelectedKeyName);
	//Get Patrolpoints
	APatrollingGuard* ControlledGuard = Cast<APatrollingGuard>(OwnerComp.GetAIOwner()->GetPawn());
	TArray<AActor*> PatrolPoints = ControlledGuard->PatrolPoints;
	//Set Next Waypoint
	BlackboardComp->SetValueAsObject(WaypointKey.SelectedKeyName, PatrolPoints[Index]);
	//cycle index
	BlackboardComp->SetValueAsInt(IndexKey.SelectedKeyName, (Index + 1) % PatrolPoints.Num());
	UE_LOG(LogTemp, Warning, TEXT("Waypoint index: %i"),Index);
	return EBTNodeResult::Succeeded;
}
