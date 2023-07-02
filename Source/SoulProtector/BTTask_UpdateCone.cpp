// Fill out your copyright notice in the Description page of Project Settings.
#include "BTTask_UpdateCone.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"
#include "Math/Color.h"
#include "DrawDebugHelpers.h"
#include "AIController.h"


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
    APawn *PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);

    OwnerComp.GetBlackboardComponent()->SetValueAsVector(TEXT("StartLocation"), GhoulPawn->GetActorLocation());
    OwnerComp.GetBlackboardComponent()->SetValueAsVector(TEXT("ConeOrigin"), GhoulPawn->GetActorLocation());
    //FVector ConeDirection = GhoulPawn->GetActorForwardVector();
    FVector ConeDirection = GhoulPawn->GetActorRotation().Vector();
    FVector LocalConeDirection = UKismetMathLibrary::InverseTransformDirection(GhoulPawn->GetActorTransform(), ConeDirection);
    OwnerComp.GetBlackboardComponent()->SetValueAsVector(TEXT("ConeDirection"), ConeDirection);

    FColor Color;
    DrawDebugCone(GetWorld(), GhoulPawn->GetActorLocation(), ConeDirection, 50.0f, 1.58, 1.58, 4.0, Color.Emerald, false, 5.0f, 0U, 5.0f);
    DrawDebugDirectionalArrow(GetWorld(), GhoulPawn->GetActorLocation(), ConeDirection, 0.2f, Color.Green, false, 5.0f, 0, 5.0f);

    GhoulPawn->GetController()->LineOfSightTo(PlayerPawn);
    
    
    return EBTNodeResult::Succeeded;
}