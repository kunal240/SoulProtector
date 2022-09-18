// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_RemoveBlackboardValue.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTTask_RemoveBlackboardValue::UBTTask_RemoveBlackboardValue()
{
    NodeName = TEXT("Clear Blackboard Value");
}

EBTNodeResult::Type UBTTask_RemoveBlackboardValue::ExecuteTask(UBehaviorTreeComponent &OwnerComp, uint8* NodeMemory)
{
    Super::ExecuteTask(OwnerComp, NodeMemory);

    const FName KeyName = GetSelectedBlackboardKey();
    OwnerComp.GetBlackboardComponent()->ClearValue(KeyName);

    return EBTNodeResult::Succeeded;
}