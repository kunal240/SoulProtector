// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Services/BTService_BlackboardBase.h"
#include "BTService_PresenceIndicator.generated.h"

/**
 * 
 */
UCLASS()
class SOULPROTECTOR_API UBTService_PresenceIndicator : public UBTService_BlackboardBase
{
	GENERATED_BODY()

public:
	UBTService_PresenceIndicator();

protected:
	virtual void TickNode(UBehaviorTreeComponent &OwnerComp, uint8 *NodeMemory, float DeltaSeconds) override;
	
};
