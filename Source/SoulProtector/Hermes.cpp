// Fill out your copyright notice in the Description page of Project Settings.
#include "Hermes.h"
#include "Components/ActorComponent.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Caduceus.h"

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
	
	Caduceus = GetWorld()->SpawnActor<ACaduceus>(WeaponClass);

	if(Caduceus == nullptr)
	return; 

	Caduceus->SetActorHiddenInGame(true);
	Caduceus->AttachToComponent(GetMesh(), FAttachmentTransformRules::KeepRelativeTransform, TEXT("WeaponSocket"));
	Caduceus->SetOwner(this);

	Hermes = Cast<AHermes>(UGameplayStatics::GetPlayerPawn(this, 0));
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
	PlayerInputComponent->BindAxis(TEXT("LookUpRate"), this, &APawn::AddControllerPitchInput);
	PlayerInputComponent->BindAxis(TEXT("TurnRate"), this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAction(TEXT("Jump"), EInputEvent::IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction(TEXT("Aim"), EInputEvent::IE_Pressed, this, &AHermes::Aim);
	PlayerInputComponent->BindAction(TEXT("Aim"), EInputEvent::IE_Released, this, &AHermes::Retract);
	PlayerInputComponent->BindAction(TEXT("Sprint"), EInputEvent::IE_Pressed,this, &AHermes::FasterSpeed);
	PlayerInputComponent->BindAction(TEXT("Sprint"), EInputEvent::IE_Released,this, &AHermes::NormalSpeed);
}

void AHermes::MoveForward(float AxisValue)
{
	AddMovementInput(GetActorForwardVector() * AxisValue);
}

void AHermes::MoveRight(float AxisValue)
{
	AddMovementInput(GetActorRightVector() * AxisValue);
}

bool AHermes::IsDead()
{
	return Health <= 0.f;
}

void AHermes::Aim()
{
	UE_LOG(LogTemp, Warning, TEXT("Aiming"));
	Aiming = true;
	Caduceus->SetActorHiddenInGame(false);
	Caduceus->Cast();
}

void AHermes::Retract()
{
	UE_LOG(LogTemp, Warning, TEXT("NotAiming"));
	Aiming = false;
	Caduceus->SetActorHiddenInGame(true);
}

void AHermes::FasterSpeed()
{
	UE_LOG(LogTemp, Warning, TEXT("Make him fast"));
	UCharacterMovementComponent* MoveComp = Cast<UCharacterMovementComponent>(Hermes->GetCharacterMovement());
	
	if(MoveComp == nullptr)
	{
		return;
	}
	
	float CurrentSpeed = MoveComp->MaxWalkSpeed;
	UE_LOG(LogTemp, Warning, TEXT("%f"), CurrentSpeed);
	MoveComp->MaxWalkSpeed = MoveComp->MaxWalkSpeed * 10;
	UE_LOG(LogTemp, Warning, TEXT("%f"), MoveComp->MaxWalkSpeed);

	DisplayDash();
}

void AHermes::NormalSpeed()
{
	DisplayDash();
	
	UE_LOG(LogTemp, Error, TEXT("Make him normal"));
	UCharacterMovementComponent* MoveComp = Cast<UCharacterMovementComponent>(Hermes->GetCharacterMovement());

	if(MoveComp == nullptr)
	{
		return;
	}

	float CurrentSpeed = MoveComp->MaxWalkSpeed;
	UE_LOG(LogTemp, Error, TEXT("%f"), CurrentSpeed);
	MoveComp->MaxWalkSpeed = 2600.0;
	UE_LOG(LogTemp, Error, TEXT("%f"), MoveComp->MaxWalkSpeed);

}

