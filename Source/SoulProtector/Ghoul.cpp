// Fill out your copyright notice in the Description page of Project Settings.


#include "Ghoul.h"

// Sets default values
AGhoul::AGhoul()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AGhoul::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGhoul::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AGhoul::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

