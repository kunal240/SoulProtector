// Fill out your copyright notice in the Description page of Project Settings.


#include "BTService_PlayerLocation.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Ghoul.h"
#include "AIController.h"

UBTService_PlayerLocation::UBTService_PlayerLocation()
{
    NodeName = TEXT("Update Trigger Location");
}

void UBTService_PlayerLocation::TickNode(UBehaviorTreeComponent &OwnerComp, uint8 *NodeMemory, float DeltaSeconds)
{
    Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

    APawn *PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);

    if(PlayerPawn == nullptr)
    {
        return;
    }

    TArray<AActor*> Triggers;
    FVector Trigger;
    UGameplayStatics::GetAllActorsWithTag(GetWorld(),TEXT("Trigger"), Triggers);

    if(Triggers[0] != nullptr)
    {
        Trigger = Triggers[0]->GetActorLocation();
    }
    else
    {
        Trigger = {76944.046875,91157.085938,487.743469};
    }
    
    //OwnerComp.GetBlackboardComponent()->SetValueAsVector(GetSelectedBlackboardKey(), PlayerPawn->GetActorLocation());
    OwnerComp.GetBlackboardComponent()->SetValueAsVector(GetSelectedBlackboardKey(), Trigger);
}

