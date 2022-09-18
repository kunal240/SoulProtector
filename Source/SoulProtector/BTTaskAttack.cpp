// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTaskAttack.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AIController.h"
#include "Minion.h"

UBTTaskAttack::UBTTaskAttack()
{
    NodeName = TEXT("Attack Player");
}

EBTNodeResult::Type UBTTaskAttack::ExecuteTask(UBehaviorTreeComponent &OwnerComp, uint8* NodeMemory)
{
    Super::ExecuteTask(OwnerComp, NodeMemory);

    if(OwnerComp.GetAIOwner() == nullptr)
    {
        return EBTNodeResult::Failed;
    }

    return EBTNodeResult::Succeeded;
}
