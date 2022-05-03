// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/TimelineComponent.h"
#include "DoorActor.generated.h"


UCLASS()
class SOULPROTECTOR_API ADoorActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADoorActor();

	UPROPERTY(EditInstanceOnly)
	UCurveFloat* DoorTimelineFloatCurve;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void OpenDoorEventFunction();
	UPROPERTY(EditInstanceOnly, BlueprintReadWrite)
	class AOpenDoor* OpenDoorReference;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* DoorFrame;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* Door;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	UTimelineComponent* DoorTimelineComp;

	//Float Track Signature to handle our update track event
	FOnTimelineFloat UpdateFunctionFloat;

	//Function which updates our Door's relative location with the timeline graph
	UFUNCTION()
	void UpdateTimelineComp(float Output);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
