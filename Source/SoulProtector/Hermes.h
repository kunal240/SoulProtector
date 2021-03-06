// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Hermes.generated.h"

class ACaduceus;

UCLASS()
class SOULPROTECTOR_API AHermes : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AHermes();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

public:
	UFUNCTION(BlueprintPure, Category="LifeStatus")
	bool IsDead();

	UPROPERTY(BlueprintReadWrite)
	bool Aiming;

private:

	void MoveForward(float AxisValue);
	void MoveRight(float AxisValue);

	float Health = 100.0f;

	void Aim();
	void Retract();
	
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<ACaduceus> WeaponClass;

	UPROPERTY()
	ACaduceus* Caduceus;

};
