// © 2018 Ruben Versavel. All Rights Reserved.

#include "ChooseNextWaypoint.h"
#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "PatrolRoute.h"

EBTNodeResult::Type UChooseNextWaypoint::ExecuteTask(UBehaviorTreeComponent & OwnerComp, uint8 * NodeMemory)
{
	//initialization
	UBlackboardComponent* BlackboardComp = OwnerComp.GetBlackboardComponent();
	int32 Index = BlackboardComp->GetValueAsInt(IndexKey.SelectedKeyName);
	APawn* ControlledPawn = OwnerComp.GetAIOwner()->GetPawn();
	UPatrolRoute* PatrolRouteComp = ControlledPawn->FindComponentByClass<UPatrolRoute>();
	if (!ensure(PatrolRouteComp)) { return EBTNodeResult::Failed; }
	//Get Patrolpoints 
	TArray<AActor*> PatrolPoints = PatrolRouteComp->GetPatrolPoints();
	if (PatrolPoints.Num() == 0) { UE_LOG(LogTemp, Warning, TEXT("No patrol points on %s"), *ControlledPawn->GetName()); return EBTNodeResult::Failed; }
	//Set Next Waypoint
	BlackboardComp->SetValueAsObject(WaypointKey.SelectedKeyName, PatrolPoints[Index]);
	//cycle index
	BlackboardComp->SetValueAsInt(IndexKey.SelectedKeyName, (Index + 1) % PatrolPoints.Num());

	return EBTNodeResult::Succeeded;
}
