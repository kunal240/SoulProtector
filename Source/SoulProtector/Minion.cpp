// Fill out your copyright notice in the Description page of Project Settings.
#include "Components/SphereComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Hermes.h"
#include "Minion.h"

// Sets default values
AMinion::AMinion()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


}

// Called when the game starts or when spawned
void AMinion::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AMinion::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMinion::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

float AMinion::TakeDamage(float DamageAmount, struct FDamageEvent const &DamageEvent, class AController *EventInstigator, AActor *DamageCauser)
{
	float DamageToApply = Super::TakeDamage(DamageAmount, DamageEvent, EventInstigator, DamageCauser);
	DamageToApply = FMath::Min(Health, DamageAmount);
	Health-=DamageToApply;
	UE_LOG(LogTemp, Error, TEXT("Damage taken, health now: %f"), Health);
	CheckHealth();
	return DamageToApply;
}

void AMinion::CheckHealth()
{
	if(Health <= 0.0f)
	{
		FTransform SpawnTransform;
		FActorSpawnParameters SpawnParameters;
		FVector Location = GetActorLocation();
		Location.Z=115.0f;


		UE_LOG(LogTemp, Warning, TEXT("Spawn Now and Vanish"));
		if(NormieClass != nullptr)
		{
			GetWorld()->SpawnActor<AActor>(NormieClass, Location, GetActorRotation(), SpawnParameters);
		}
		
		UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), TransformParticle, Location, GetActorRotation());
		Destroy();
	}
}