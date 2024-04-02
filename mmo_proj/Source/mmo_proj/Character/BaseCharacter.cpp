// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseCharacter.h"

#include <mmo_proj/Components/Headers/MMO_CharacterHealthComponent.h>
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputMappingContext.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "mmo_proj/Data/InputConfigData.h"

// Sets default values
ABaseCharacter::ABaseCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	HealthComponent = CreateDefaultSubobject<UMMO_CharacterHealthComponent>("Health Component");


	SpringArm = CreateDefaultSubobject<USpringArmComponent>("SpringArm");
	SpringArm->SetupAttachment(RootComponent);
	SpringArm->bUsePawnControlRotation = true;

	Camera = CreateDefaultSubobject<UCameraComponent>("Camera");
	Camera->SetupAttachment(SpringArm);

	bUseControllerRotationYaw = false;
	GetCharacterMovement()->bOrientRotationToMovement = false;
}

void ABaseCharacter::Move(const FInputActionValue& InputValue)
{
	FVector2D InputVector = InputValue.Get<FVector2D>();
	if(IsValid(Controller))
	{
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

		AddMovementInput(ForwardDirection, InputVector.Y);
		AddMovementInput(RightDirection, InputVector.X);
	}
}

void ABaseCharacter::Look(const FInputActionValue& InputValue)
{
	FVector2D InputVector = InputValue.Get<FVector2D>();
	if(IsValid(Controller))
	{
		AddControllerYawInput(InputVector.X);
		AddControllerPitchInput(InputVector.Y);
	}
}

void ABaseCharacter::ShowMouseCursor()
{
	if (!GetPC()->ShouldShowMouseCursor())
	{
		GetPC()->SetShowMouseCursor(true);
	}
}

void ABaseCharacter::HideMouseCursor()
{
	if (GetPC()->ShouldShowMouseCursor())
	{
		GetPC()->SetShowMouseCursor(false);
	}
}

void ABaseCharacter::Jump()
{
	Super::Jump();
}

void ABaseCharacter::Sprint()
{
	if(!IsSprinting)
	{
		GetCharacterMovement()->MaxWalkSpeed += SprintAdditionalSpeed;
		IsSprinting = true;
	}
}

void ABaseCharacter::UnSprint()
{
	if(IsSprinting)
	{
		GetCharacterMovement()->MaxWalkSpeed -= SprintAdditionalSpeed;
		IsSprinting = false;
	}
}

// Called when the game starts or when spawned
void ABaseCharacter::BeginPlay()
{
	Super::BeginPlay();
}

APlayerController* ABaseCharacter::GetPC()
{
	if(_playerController == nullptr)
	{
		_playerController = Cast<APlayerController>(GetController());
	}
	return _playerController;
}

// Called every frame
void ABaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void ABaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	// Get the player controller
	//PC = Cast<APlayerController>(GetController());
 
	// Get the local player subsystem
	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetPC()->GetLocalPlayer());
	// Clear out existing mapping, and add our mapping
	Subsystem->ClearAllMappings();
	Subsystem->AddMappingContext(InputMapping, 0);
	
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if(UEnhancedInputComponent* Input = CastChecked<UEnhancedInputComponent>(PlayerInputComponent))
	{
		Input->BindAction(InputConfigData->InputRMD, ETriggerEvent::Completed, this, &ABaseCharacter::ShowMouseCursor);
		Input->BindAction(InputConfigData->InputRMD, ETriggerEvent::Triggered, this, &ABaseCharacter::HideMouseCursor);
		Input->BindAction(InputConfigData->InputMove, ETriggerEvent::Triggered, this, &ABaseCharacter::Move);
		Input->BindAction(InputConfigData->InputLook, ETriggerEvent::Triggered, this, &ABaseCharacter::Look);
		Input->BindAction(InputConfigData->InputJump, ETriggerEvent::Triggered, this, &ABaseCharacter::Jump);
		Input->BindAction(InputConfigData->InputSprint, ETriggerEvent::Triggered, this, &ABaseCharacter::Sprint);
		Input->BindAction(InputConfigData->InputSprint, ETriggerEvent::Completed, this, &ABaseCharacter::UnSprint);
	}
}

