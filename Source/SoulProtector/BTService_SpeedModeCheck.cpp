// Fill out your copyright notice in the Description page of Project Settings.
#include "BTService_SpeedModeCheck.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"
#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Hermes.h"
#include "GhoulAIController.h"
#include "Ghoul.h"

UBTService_SpeedModeCheck::UBTService_SpeedModeCheck()
{
    NodeName = TEXT("Check Speed Mode");
}

void UBTService_SpeedModeCheck::TickNode(UBehaviorTreeComponent &OwnerComp, uint8 *NodeMemory, float DeltaSeconds)
{
    Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

    GhoulPawn = Cast<AGhoul>(OwnerComp.GetAIOwner()->GetPawn());
    Hermes = Cast<AHermes>(UGameplayStatics::GetPlayerPawn(this, 0));

    if(OwnerComp.GetAIOwner() == nullptr)
    {
        return;
    }

    if(Hermes == nullptr)
    {
        return;
    }

    if(GhoulPawn == nullptr)
    {
        return;
    }

    GhoulAIController = Cast<AGhoulAIController>(GhoulPawn->GetController());

    if(GhoulAIController == nullptr)
    {
        return;
    }

    const FName KeyName = GetSelectedBlackboardKey();

    UCharacterMovementComponent* MoveComp = Cast<UCharacterMovementComponent>(Hermes->GetCharacterMovement());

    if(MoveComp == nullptr)
	{
		return;
	}
    
	float CurrentSpeed = MoveComp->MaxWalkSpeed;
    float Distance = GhoulPawn->GetDistanceTo(Hermes);

    if(CurrentSpeed > 2600.0f && Distance < 150.0f)
    {
        OwnerComp.GetBlackboardComponent()->SetValueAsBool(KeyName, true);
    }
    else
    {
        OwnerComp.GetBlackboardComponent()->ClearValue(KeyName);
    }

}