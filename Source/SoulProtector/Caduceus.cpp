// Fill out your copyright notice in the Description page of Project Settings.


#include "Caduceus.h"
#include "Components/StaticMeshComponent.h"
#include "Kismet/GameplayStatics.h"
#include "DrawDebugHelpers.h"

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

void ACaduceus::Cast()
{
	UE_LOG(LogTemp, Warning, TEXT("Casting Healing Ray at %s "), *GetActorLocation().ToString());

	//UGameplayStatics::SpawnEmitterAttached(RayParticle, Mesh, TEXT("EmitRay"), ((FVector)(ForceInit)), FRotator::ZeroRotator, EAttachLocation::SnapToTarget);
	UGameplayStatics::SpawnSoundAttached(BeamEmit, Mesh, TEXT("EmitRay"));
	FVector Location;
	FRotator Rotation;

	APawn* OwnerPawn = GetOwner<APawn>();

	if(OwnerPawn != nullptr)
	{
		AController* OwnerController = OwnerPawn->GetController();
		if(OwnerController != nullptr)
		{
			FHitResult Hit;
			OwnerController->GetPlayerViewPoint(Location, Rotation);
		
			FVector End = Location + Rotation.Vector() * MaxRange;
			
			bool bSuccess = GetWorld()->LineTraceSingleByChannel(Hit, Location, End, ECollisionChannel::ECC_GameTraceChannel1);
			if(bSuccess)
			{
				DrawDebugPoint(GetWorld(), Hit.Location, 20, FColor::Cyan, true);
				DrawDebugLine(GetWorld(), Location, End, FColor::Yellow, true);
				FVector HitDirection = -Rotation.Vector();
				AActor* Hurt = Hit.GetActor();
				UE_LOG(LogTemp, Error, TEXT("%s is hit"), *Hurt->GetName());
			}
		}
	}
}
void ACaduceus::GetPlayerViewPointBP(AController* OwnerController, FVector& OutLoc, FRotator& OutRot) const
{
	if(OwnerController)
	{
		OwnerController->GetPlayerViewPoint(OutLoc, OutRot);
	}
}
