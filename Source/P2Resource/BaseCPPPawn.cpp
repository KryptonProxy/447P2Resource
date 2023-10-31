// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseCPPPawn.h"

// Sets default values
ABaseCPPPawn::ABaseCPPPawn()
{
	// Set this pawn to call Tick() every frame. You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	staticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("RootMesh"));
	capsuleComp = CreateDefaultSubobject<UCapsuleComponent>(TEXT("CapsuleCollider"));
	movementComp = CreateDefaultSubobject<UFloatingPawnMovement>(TEXT("FloatingPawnMovement"));

	SetRootComponent(capsuleComp);
	staticMesh->AttachToComponent(RootComponent,
		FAttachmentTransformRules::KeepRelativeTransform);
}

// Called when the game starts or when spawned
void ABaseCPPPawn::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ABaseCPPPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}