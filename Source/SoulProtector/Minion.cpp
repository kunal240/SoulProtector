// Fill out your copyright notice in the Description page of Project Settings.
#include "TimerManager.h"
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

	Playerpawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
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
	DamageToApply = FMath::Min(Infestation, DamageAmount);
	Infestation-=DamageToApply;
	UE_LOG(LogTemp, Error, TEXT("Damage taken, corruption now: %f"), Infestation);
	CheckInfestation();
	return DamageToApply;
}

void AMinion::CheckHealth()
{
	FTimerHandle Timer;

	if(Health <= 0.0f)
	{
		GetWorldTimerManager().SetTimer(Timer, this, &AMinion::Revive, 60.0f,  false);
	}
}

void AMinion::CheckInfestation()
{
	if(Infestation <= 0.0f)
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

bool AMinion::VerifyLife()
{
	if(Health <= 0.0f)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void AMinion::Revive()
{
	if(IsValid(this))
	{
		UE_LOG(LogTemp, Error, TEXT("Reviving Now"));
		Health = 5000.0f;
	}
}

bool AMinion::Attack()
{
	if(GetDistanceTo(Playerpawn) < 250.0f)
	{
		return true;
	}
	else
	{
		return false;
	}
}