// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Spawner.generated.h"

UCLASS()
class P2RESOURCE_API ASpawner : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ASpawner();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Spawner C++")
	TSubclassOf<AActor> classToSpawn;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Spawner C++")
	float secondsBetweenSpawns = 1;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Spawner C++")
	bool bIsSpawnEnabled = false;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Spawner C++")
	int maxSpawns = 3;

	int currentSpawns = 0;

	UFUNCTION(BlueprintNativeEvent)
	void Spawn();
	void Spawn_Implementation();

	FTimerHandle timer;

	UFUNCTION()
	void OnPawnDefeated()
	{
		currentSpawns--;
		if (!timer.IsValid())
		GetWorldTimerManager().SetTimer(
			timer,
			this,
			&ASpawner::Spawn,
			secondsBetweenSpawns,
			false);
	}
};
