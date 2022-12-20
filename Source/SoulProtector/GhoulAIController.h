// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "GhoulAIController.generated.h"

/**
 * 
 */
UCLASS()
class SOULPROTECTOR_API AGhoulAIController : public AAIController
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;
	
private:
	UPROPERTY(EditAnywhere)
	class UBehaviorTree* GhoulBehavior;
	
};
