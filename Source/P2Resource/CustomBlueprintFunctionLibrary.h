// Fill out your copyright notice in the Description page of Project Settings.

//Include Guard
#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"

#include "CustomBlueprintFunctionLibrary.generated.h"

/**
 *
 */
UCLASS()
class P2RESOURCE_API UCustomBlueprintFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	static void Print(FString text)
	{
		UE_LOG(LogTemp, Warning, TEXT("%s"), *text);

		if (GEngine)
			GEngine->AddOnScreenDebugMessage(-1, 2, FColor::Emerald,
				FString::Printf(TEXT("%s"), *text));
	}

	UFUNCTION(BlueprintCallable, Category = "Helper Functions")
	static void SortByBoundsSize(UPARAM(ref) TArray<AActor*>& arr);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Helper Functions")
		static bool HasComponent(const AActor* actor, const FName tag, const TSubclassOf<UActorComponent> componentClass);
};

//alias = rename a type to provide an easier alternative
typedef UCustomBlueprintFunctionLibrary Helpers;
