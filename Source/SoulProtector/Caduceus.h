// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Caduceus.generated.h"

UCLASS()
class SOULPROTECTOR_API ACaduceus : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACaduceus();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY(VisibleAnywhere)
	USceneComponent* Root;

	UPROPERTY(EditAnywhere)
	UParticleSystem* RayParticle;

	UPROPERTY(EditAnywhere)
	UParticleSystem* HitImpact;

	UPROPERTY(EditAnywhere)
	USoundBase* BeamEmit;

public:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UStaticMeshComponent* Mesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float MaxRange = 5000.0f;


public:
	void Cast();

	UFUNCTION(BlueprintCallable)
	void GetPlayerViewPointBP(AController* OwnerController, FVector& OutLoc, FRotator& OutRot) const;

};
