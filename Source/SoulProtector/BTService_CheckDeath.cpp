// Fill out your copyright notice in the Description page of Project Settings.


#include "BTService_CheckDeath.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Minion.h"
#include "AIController.h"

UBTService_CheckDeath::UBTService_CheckDeath()
{
    NodeName =  TEXT("Is Minion Dead");
}

void UBTService_CheckDeath::TickNode(UBehaviorTreeComponent &OwnerComp, uint8 *NodeMemory, float DeltaSeconds)
{
    Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

    AMinion *Minion = Cast<AMinion>(OwnerComp.GetAIOwner()->GetPawn());
    
    if(Minion == nullptr)
    {
        UE_LOG(LogTemp, Warning, TEXT("Null here"));
        return;
    }


    if(Minion->Health <= 0.0f)
    {
        OwnerComp.GetBlackboardComponent()->SetValueAsBool(GetSelectedBlackboardKey(), true);
        OwnerComp.GetBlackboardComponent()->ClearValue(TEXT("PlayerLocation"));
        OwnerComp.GetBlackboardComponent()->ClearValue(TEXT("LastKnownPlayerLocation"));
    }
    else
    {
        OwnerComp.GetBlackboardComponent()->ClearValue(GetSelectedBlackboardKey());
    }
}



