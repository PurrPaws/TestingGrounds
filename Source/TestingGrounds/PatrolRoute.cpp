// � 2018 Ruben Versavel. All Rights Reserved.

#include "PatrolRoute.h"


// Sets default values for this component's properties
UPatrolRoute::UPatrolRoute()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;
}

void UPatrolRoute::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void UPatrolRoute::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

TArray<AActor*> UPatrolRoute::GetPatrolPoints()
{
	return PatrolPoints;
}