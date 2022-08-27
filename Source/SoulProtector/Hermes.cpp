// Fill out your copyright notice in the Description page of Project Settings.
#include "Components/SphereComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Hermes.h"
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

	TArray<UActorComponent*> Collision = GetComponentsByClass(CollisionClass);
	for(int i = 0; i < Collision.Num(); i++)
	{
		UE_LOG(LogTemp, Warning, TEXT("%s"), *Collision[i]->GetName());
	}
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