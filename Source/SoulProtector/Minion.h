// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Minion.generated.h"

UCLASS()
class SOULPROTECTOR_API AMinion : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMinion();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<class AActor> NormieClass;

	UPROPERTY(EditAnywhere)
	UParticleSystem* TransformParticle;

	virtual void Revive();

	APawn* Playerpawn;

public:
	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const &DamageEvent, class AController *EventInstigator, AActor *DamageCauser) override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	float Health = 5000.0f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	float Infestation = 5000.0f;

	UFUNCTION(BlueprintCallable)
	void CheckHealth();

	UFUNCTION(BlueprintCallable)
	void CheckInfestation();

	UFUNCTION(BlueprintPure, Category="AliveStatus")
	bool VerifyLife();

	UFUNCTION(BlueprintCallable)
	bool Attack();

};
