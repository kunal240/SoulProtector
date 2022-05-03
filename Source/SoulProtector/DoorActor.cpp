// Fill out your copyright notice in the Description page of Project Settings.


#include "DoorActor.h"
#include "OpenDoor.h"

// Sets default values
ADoorActor::ADoorActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	DoorFrame = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("DoorFrameMesh"));
	Door = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("DoorMesh"));
	DoorTimelineComp = CreateDefaultSubobject<UTimelineComponent>(TEXT("DoorTimelineComp"));

	//Setup our Attachments
	DoorFrame->SetupAttachment(RootComponent);
	Door->AttachToComponent(DoorFrame, FAttachmentTransformRules::KeepRelativeTransform);
	Door->SetRelativeLocation(FVector(0, 35, 0));

}

// Called when the game starts or when spawned
void ADoorActor::BeginPlay()
{
	Super::BeginPlay();

	//Binding our float track to our UpdateTimelineComp Function's output
	UpdateFunctionFloat.BindDynamic(this, &ADoorActor::UpdateTimelineComp);

	//If we have a float curve, bind it's graph to our update function
	if (DoorTimelineFloatCurve)
	{
		DoorTimelineComp->AddInterpFloat(DoorTimelineFloatCurve, UpdateFunctionFloat);
	}

	if (OpenDoorReference)
	{
		OpenDoorReference->OnHeroInside.BindUObject(this, &ADoorActor::OpenDoorEventFunction);
	}
	
}

// Called every frame
void ADoorActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ADoorActor::OpenDoorEventFunction()
{
	DoorTimelineComp->Play();
}

void ADoorActor::UpdateTimelineComp(float Output)
{
	FRotator DoorNewRotation = FRotator(0.0f, Output, 0.f);
	Door->SetRelativeRotation(DoorNewRotation);
}
