// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CustomBlueprintFunctionLibrary.h"
#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Components/CapsuleComponent.h" 
#include "Components/StaticMeshComponent.h"
#include "GameFramework/FloatingPawnMovement.h"

//Must be last
#include "BaseCPPPawn.generated.h"

DECLARE_DELEGATE(FCPPSingleDelegateSignature);
DECLARE_MULTICAST_DELEGATE(FCPPMultiDelegateSignature)
DECLARE_DYNAMIC_DELEGATE(FSingleDynamicSignature);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FMultiDynamicSignature);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnScoreChangedSignature, int32, NewScore);

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnPawnDefeatedSignature);

UCLASS()
class P2RESOURCE_API ABaseCPPPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ABaseCPPPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	UStaticMeshComponent* staticMesh = nullptr;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	UFloatingPawnMovement* movementComp = nullptr;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	UCapsuleComponent* capsuleComp = nullptr;

	UFUNCTION(BlueprintCallable)
	void PawnTakeDamage(int damage)
	{
		hp -= damage;
		if (hp <= 0)
		{
			//Broadcast = anything listening (bound to this delegate)
			//will now react with the functions they bound.
			OnPawnDefeatedDelegate.Broadcast();
			Die();
		}
	}

	UFUNCTION(BlueprintImplementableEvent)
	void Die();

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	int hp = 50;

	UPROPERTY(BlueprintAssignable)
	FOnPawnDefeatedSignature OnPawnDefeatedDelegate;
};
