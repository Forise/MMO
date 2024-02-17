// Fill out your copyright notice in the Description page of Project Settings.


#include "MMO_BaseCharacter.h"
#include "InputMappingContext.h"
#include "EnhancedInputSubsystems.h"

// Sets default values
AMMO_BaseCharacter::AMMO_BaseCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
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
	APlayerController* PC = Cast<APlayerController>(GetController());
	
	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PC->GetLocalPlayer());
	Subsystem->ClearAllMappings();
	Subsystem->AddMappingContext(InputMapping, 0);
}

