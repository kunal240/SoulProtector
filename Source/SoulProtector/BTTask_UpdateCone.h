// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BTTask_UpdateCone.generated.h"

/**
 * 
 */
UCLASS()
class SOULPROTECTOR_API UBTTask_UpdateCone : public UBTTaskNode
{
	GENERATED_BODY()

public:
	UBTTask_UpdateCone();

protected:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent &OwnerComp, uint8* NodeMemory) override;
	
};
