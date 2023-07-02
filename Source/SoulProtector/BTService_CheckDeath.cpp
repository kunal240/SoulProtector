// Fill out your copyright notice in the Description page of Project Settings.


#include "BTService_CheckDeath.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Ghoul.h"
#include "AIController.h"

UBTService_CheckDeath::UBTService_CheckDeath()
{
    NodeName =  TEXT("Is Ghoul Dead");
}

void UBTService_CheckDeath::TickNode(UBehaviorTreeComponent &OwnerComp, uint8 *NodeMemory, float DeltaSeconds)
{
    Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

    AGhoul *Ghoul = Cast<AGhoul>(OwnerComp.GetAIOwner()->GetPawn());
    
    if(Ghoul == nullptr)
    {
        UE_LOG(LogTemp, Warning, TEXT("Null here"));
        return;
    }


    if(Ghoul->Health <= 0.0f)
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



