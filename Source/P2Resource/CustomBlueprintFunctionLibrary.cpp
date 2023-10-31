// Fill out your copyright notice in the Description page of Project Settings.


#include "CustomBlueprintFunctionLibrary.h"

//Just an example of how you can sort arrays by some property.
//Normally parameters passed by reference in UE4 C++ will become output pins.
//UPARAM(ref) forces arr to be an input pin in a blueprint node, instead of an output pin.
void UCustomBlueprintFunctionLibrary::SortByBoundsSize(UPARAM(ref) TArray<AActor*>& arr)
{
	Algo::Sort(arr, [](AActor* a1, AActor* a2) { return a1->GetSimpleCollisionRadius() < a2->GetSimpleCollisionRadius(); });
}

bool UCustomBlueprintFunctionLibrary::HasComponent(const AActor* actor, const FName tag, const TSubclassOf<UActorComponent> componentClass)
{
	if (!actor)
		return false;

	TArray<UActorComponent*> components = actor->GetComponentsByTag(componentClass, tag);
	if (components.Num() > 0)
		return true;
	return false;
}