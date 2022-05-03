// Fill out your copyright notice in the Description page of Project Settings.


#include "OpenDoor.h"
#include "Components/BoxComponent.h"
#include "HermesGameModeBase.h"

// Sets default values
AOpenDoor::AOpenDoor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	BoxComp = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComp"));
	BoxComp->SetBoxExtent(FVector(300, 300, 150));
	BoxComp->SetVisibility(true);

}

// Called when the game starts or when spawned
void AOpenDoor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AOpenDoor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AOpenDoor::HandleHeroInsideEvent()
{
	OnHeroInside.ExecuteIfBound();
}

void AOpenDoor::NotifyActorBeginOverlap(AActor* OtherActor)
{
	HandleHeroInsideEvent();
}

