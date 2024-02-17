// Fill out your copyright notice in the Description page of Project Settings.


#include "Headers/MMO_CharacterMovementComponent.h"
#include "GameFramework/Character.h"

// Sets default values for this component's properties
UMMO_CharacterMovementComponent::UMMO_CharacterMovementComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UMMO_CharacterMovementComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UMMO_CharacterMovementComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                                    FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	
}

void UMMO_CharacterMovementComponent::MoveCharacter(ACharacter* character)
{
	FVector v = FVector(1);
	character->AddMovementInput(v);
}

