// Fill out your copyright notice in the Description page of Project Settings.


#include "MMO_BaseCharacter.h"

#include "Components/CapsuleComponent.h"

// Sets default values
AMMO_BaseCharacter::AMMO_BaseCharacter(const FObjectInitializer &Object)
{
	CharacterMovementComponent = CreateDefaultSubobject<UMMO_CharacterMovementComponent>("MovementComponent");
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	//CharacterMovementComponent = Cast<UMMO_CharacterMovementComponent>(ACharacter::GetMovementComponent());
}

// Called when the game starts or when spawned
void AMMO_BaseCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMMO_BaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void AMMO_BaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

