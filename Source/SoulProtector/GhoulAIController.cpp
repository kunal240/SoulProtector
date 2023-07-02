// Fill out your copyright notice in the Description page of Project Settings.


#include "GhoulAIController.h"
#include "Kismet/GameplayStatics.h"
#include "BehaviorTree/BlackboardComponent.h"

void AGhoulAIController::BeginPlay()
{
    Super::BeginPlay();

    if(GhoulBehavior != nullptr)
    {
        RunBehaviorTree(GhoulBehavior);

        APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);

        if(PlayerPawn)
        {
            GetBlackboardComponent()->SetValueAsVector(TEXT("PlayerLocation"), PlayerPawn->GetActorLocation());
            GetBlackboardComponent()->SetValueAsObject(TEXT("Hermes"), PlayerPawn);
        }

        if(GetPawn())
        {
            GetBlackboardComponent()->SetValueAsVector(TEXT("StartLocation"), GetPawn()->GetActorLocation());
            GetBlackboardComponent()->SetValueAsObject(TEXT("SelfActor"), GetPawn());
        }
    }
}

