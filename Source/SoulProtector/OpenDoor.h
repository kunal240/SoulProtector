// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "OpenDoor.generated.h"

DECLARE_DELEGATE(FOnHeroInsideDelegate);

UCLASS()
class SOULPROTECTOR_API AOpenDoor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AOpenDoor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION()
	void HandleHeroInsideEvent();
	UPROPERTY(EditInstanceOnly, BlueprintReadWrite)
	class UBoxComponent* BoxComp;
	virtual void NotifyActorBeginOverlap(AActor* OtherActor);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	FOnHeroInsideDelegate OnHeroInside;

};
