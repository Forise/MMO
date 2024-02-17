// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MyUserWidget.generated.h"

/**
 * 
 */
UCLASS()
class MMO_PROJ_API UMyUserWidget : public UUserWidget
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable, Category="UI")
	float GetHealthPercent(AActor* Player) const;
	UFUNCTION(BlueprintCallable, Category="UI")
	AActor* GetActorTarget();
	
};