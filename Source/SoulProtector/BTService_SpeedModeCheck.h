// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Services/BTService_BlackboardBase.h"
#include "BTService_SpeedModeCheck.generated.h"

/**
 * 
 */
UCLASS()
class SOULPROTECTOR_API UBTService_SpeedModeCheck : public UBTService_BlackboardBase
{
	GENERATED_BODY()
	
	public:
		UBTService_SpeedModeCheck();

	private:
		class AHermes* Hermes;
		class AGhoul* GhoulPawn;
		class AGhoulAIController* GhoulAIController;

	protected:
		virtual void TickNode(UBehaviorTreeComponent &OwnerComp, uint8 *NodeMemory, float DeltaSeconds) override;
};
