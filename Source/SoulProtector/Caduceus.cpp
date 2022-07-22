// Fill out your copyright notice in the Description page of Project Settings.


#include "Caduceus.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
ACaduceus::ACaduceus()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SetRootComponent(Root);

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(Root);

}

// Called when the game starts or when spawned
void ACaduceus::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACaduceus::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

