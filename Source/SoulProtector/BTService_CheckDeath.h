// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Services/BTService_BlackboardBase.h"
#include "BTService_CheckDeath.generated.h"

/**
 * 
 */
UCLASS()
class SOULPROTECTOR_API UBTService_CheckDeath : public UBTService_BlackboardBase
{
	GENERATED_BODY()
	
public:
	UBTService_CheckDeath();

protected:
	virtual void TickNode(UBehaviorTreeComponent &OwnerComp, uint8 *NodeMemory, float DeltaSeconds) override;

};
