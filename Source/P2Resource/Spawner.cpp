// Fill out your copyright notice in the Description page of Project Settings.

#include "Spawner.h"
#include "CustomBlueprintFunctionLibrary.h"
#include "BaseCPPPawn.h"

// Sets default values
ASpawner::ASpawner()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ASpawner::BeginPlay()
{
	Super::BeginPlay();
	Spawn();
}

// Called every frame
void ASpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASpawner::Spawn_Implementation()
{
	if (!IsValid(classToSpawn))
	{
		Helpers::Print("Set 'classToSpawn' Dummy");
		return;
	}

	if (!bIsSpawnEnabled)
		return;

	FVector location = GetActorLocation();
	FRotator rotation = GetActorRotation();
	FActorSpawnParameters spawnParams;
	spawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;
	AActor* spawnedActor = GetWorld()->SpawnActor(classToSpawn, &location, &rotation, spawnParams);

	currentSpawns++;

	ABaseCPPPawn* cpppawn = Cast<ABaseCPPPawn>(spawnedActor);
	if (cpppawn)
		cpppawn->OnPawnDefeatedDelegate.AddUniqueDynamic(this, &ASpawner::OnPawnDefeated);

	if (currentSpawns < maxSpawns)
		GetWorldTimerManager().SetTimer(timer, this, &ASpawner::Spawn, secondsBetweenSpawns, false);
	else
		timer.Invalidate();
}