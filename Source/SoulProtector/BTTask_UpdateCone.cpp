// Fill out your copyright notice in the Description page of Project Settings.
#include "Kismet/GameplayStatics.h"
#include "AIController.h"
#include "BTTask_UpdateCone.h"

UBTTask_UpdateCone::UBTTask_UpdateCone()
{
    NodeName = TEXT("Update Cone Position");
}

EBTNodeResult::Type UBTTask_UpdateCone::ExecuteTask(UBehaviorTreeComponent &OwnerComp, uint8* NodeMemory)
{
    Super::ExecuteTask(OwnerComp, NodeMemory);

    if(OwnerComp.GetAIOwner() == nullptr)
    {
        return EBTNodeResult::Failed;
    }

    APawn* GhoulPawn = OwnerComp.GetAIOwner()->GetPawn();

    OwnerComp.GetBlackboardComponent()->SetValueAsVector(TEXT("StartLocation"), GhoulPawn->GetActorLocation());
    OwnerComp.GetBlackboardComponent()->SetValueAsVector(TEXT("ConeOrigin"), GhoulPawn->GetActorLocation());
    FVector ConeDirection = GhoulPawn->GetActorForwardVector();
    OwnerComp.GetBlackboardComponent()->SetValueAsVector(TEXT("ConeDirection"), ConeDirection);

    return EBTNodeResult::Succeeded;
}