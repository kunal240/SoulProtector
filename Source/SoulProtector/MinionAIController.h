// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Minion.h"
#include "CoreMinimal.h"
#include "AIController.h"
#include "MinionAIController.generated.h"

/**
 * 
 */
UCLASS()
class SOULPROTECTOR_API AMinionAIController : public AAIController
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaSeconds) override;

	AMinion* MinionPawn;

private:
	APawn* PlayerPawn;

	UPROPERTY(EditAnywhere)
	class UBehaviorTree* AIBehavior;
	
};
