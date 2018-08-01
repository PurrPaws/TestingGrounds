//© 2018 Ruben Versavel. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PatrolRoute.generated.h"
/**
* A "Route card" to help AI choose their next waypoint.
*/

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TESTINGGROUNDS_API UPatrolRoute : public UActorComponent
{
	GENERATED_BODY()

protected:
	UPatrolRoute();
	virtual void BeginPlay() override;
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

public:	
	//Getters
	TArray<AActor*> GetPatrolPoints();

private:
	//Variables
	UPROPERTY(EditAnywhere, Category = "Setup")
		TArray<AActor*> PatrolPoints;
};
