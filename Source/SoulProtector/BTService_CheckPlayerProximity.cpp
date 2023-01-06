// Fill out your copyright notice in the Description page of Project Settings.

#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"
#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BTService_CheckPlayerProximity.h"

UBTService_CheckPlayerProximity::UBTService_CheckPlayerProximity()
{
    NodeName = TEXT("Check Player Proximity");
}

void UBTService_CheckPlayerProximity::TickNode(UBehaviorTreeComponent &OwnerComp, uint8 *NodeMemory, float DeltaSeconds)
{
    Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

    APawn* GhoulPawn = OwnerComp.GetAIOwner()->GetPawn();
    APawn *PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);

    if(OwnerComp.GetAIOwner() == nullptr)
    {
        return;
    }

    if(PlayerPawn == nullptr)
    {
        return;
    }

    if(GhoulPawn == nullptr)
    {
        return;
    }

    float Distance = GhoulPawn->GetDistanceTo(PlayerPawn);
    const FName KeyName = GetSelectedBlackboardKey();

    if(Distance < 120.0f)
    {   
        
        OwnerComp.GetBlackboardComponent()->SetValueAsBool(KeyName, true);
    }
    else
    {
        OwnerComp.GetBlackboardComponent()->ClearValue(KeyName);
    }

}