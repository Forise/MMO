// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/Headers/MMO_CharacterMovementComponent.h"
#include "MMO_BaseCharacter.generated.h"

UCLASS()
class MMO_PROJ_API AMMO_BaseCharacter : public APawn
{
	GENERATED_BODY()

public:

protected:
	AMMO_BaseCharacter(const FObjectInitializer &Object);
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Movement")
	UMMO_CharacterMovementComponent* CharacterMovementComponent;
};
