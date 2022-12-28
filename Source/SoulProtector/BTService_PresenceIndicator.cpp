// Fill out your copyright notice in the Description page of Project Settings.


#include "BTService_PresenceIndicator.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Ghoul.h"
#include "AIController.h"

UBTService_PresenceIndicator::UBTService_PresenceIndicator()
{
    NodeName = TEXT("Execute Player Presence Check");
}

void UBTService_PresenceIndicator::TickNode(UBehaviorTreeComponent &OwnerComp, uint8 *NodeMemory, float DeltaSeconds)
{
    Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

    APawn *PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
    AGhoul* GhoulPawn = Cast<AGhoul>(OwnerComp.GetAIOwner()->GetPawn());

    if(PlayerPawn == nullptr)
    {
        return;
    }

    if(GhoulPawn == nullptr)
    {
        return;
    }

    if(GhoulPawn->CanSeeHermes)
    {
        OwnerComp.GetBlackboardComponent()->SetValueAsBool(GetSelectedBlackboardKey(), true);
    }
    else
    {
        OwnerComp.GetBlackboardComponent()->ClearValue(GetSelectedBlackboardKey());
    }
}

