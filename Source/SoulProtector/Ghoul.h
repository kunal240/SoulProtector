// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Ghoul.generated.h"

UCLASS()
class SOULPROTECTOR_API AGhoul : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AGhoul();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool CanSeeHermes;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	float Health = 100.0f;

	UFUNCTION(BlueprintPure, Category="Check if Alive")
	bool CheckLife();

};
