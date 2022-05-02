// Fill out your copyright notice in the Description page of Project Settings.


#include "Hermes.h"

// Sets default values
AHermes::AHermes()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AHermes::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AHermes::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AHermes::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &AHermes::MoveForward);
	PlayerInputComponent->BindAxis(TEXT("MoveRight"), this, &AHermes::MoveRight);
	PlayerInputComponent->BindAxis(TEXT("LookUp"), this, &APawn::AddControllerPitchInput);
	PlayerInputComponent->BindAxis(TEXT("Turn"), this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAction(TEXT("Jump"), EInputEvent::IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction(TEXT("Punch"), EInputEvent::IE_Pressed, this, &AHermes::ActionRight);
}

void AHermes::MoveForward(float AxisValue)
{
	AddMovementInput(GetActorForwardVector() * AxisValue);
}

void AHermes::MoveRight(float AxisValue)
{
	AddMovementInput(GetActorRightVector() * AxisValue);
}

void AHermes::ActionRight()
{
	UE_LOG(LogTemp, Warning, TEXT("Implement Combat"));
}
