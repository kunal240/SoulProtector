// Fill out your copyright notice in the Description page of Project Settings.

#include "Kismet/GameplayStatics.h"
#include "Hermes.h"
#include "Minion.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "MinionAIController.h"

void AMinionAIController::BeginPlay()
{
    Super::BeginPlay();

    PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
    APawn* AIPawn = GetPawn();
    MinionPawn = Cast<AMinion>(GetPawn());

    if(AIBehavior != nullptr)
    {
        RunBehaviorTree(AIBehavior);
        GetBlackboardComponent()->SetValueAsObject(TEXT("Player"), PlayerPawn);
        GetBlackboardComponent()->SetValueAsVector(TEXT("StartLocation"), AIPawn->GetActorLocation());
    }

}

void AMinionAIController::Tick(float DeltaSeconds)
{
    Super::Tick(DeltaSeconds);

    /*if(LineOfSightTo(PlayerPawn) && MinionPawn->Health > 0.0f)
    {
        if(AIBehavior != nullptr)
        {
            GetBlackboardComponent()->SetValueAsVector(TEXT("PlayerLocation"), PlayerPawn->GetActorLocation());
            GetBlackboardComponent()->SetValueAsVector(TEXT("LastKnownPlayerLocation"), PlayerPawn->GetActorLocation());
        }
        
    }
    else
    {
        GetBlackboardComponent()->ClearValue(TEXT("PlayerLocation"));
    }*/

    /*if(MinionPawn != nullptr)
    {
        if(MinionPawn->Health <= 0.0f)
        {
            GetBlackboardComponent()->SetValueAsBool(TEXT("Dead"), true);
            GetBlackboardComponent()->ClearValue(TEXT("PlayerLocation"));
            GetBlackboardComponent()->ClearValue(TEXT("LastKnownPlayerLocation"));
        }
        else
        {
            GetBlackboardComponent()->SetValueAsBool(TEXT("Dead"), false);
            GetBlackboardComponent()->ClearValue(TEXT("Dead"));
        }
    }*/

}
