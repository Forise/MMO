// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InputActionValue.h"
#include "GameFramework/Character.h"
#include "BaseCharacter.generated.h"


UCLASS()
class MMO_PROJ_API ABaseCharacter : public ACharacter
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* Camera;
	
	UPROPERTY(VisibleAnywhere, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* SpringArm;
private:
	APlayerController* _playerController;
protected:
	UPROPERTY(EditAnywhere, Category = "EnhancedInput")
	class UInputMappingContext* InputMapping;
	
	UPROPERTY(EditAnywhere, Category = "EnhancedInput")
	class UInputAction* MoveInputAction;

	UPROPERTY(EditAnywhere, Category = "EnhancedInput")
	class UInputAction* LookInputAction;

	UPROPERTY(EditAnywhere, Category = "EnhancedInput")
	class UInputAction* JumpInputAction;

	UPROPERTY(EditAnywhere, Category = "EnhancedInput")
	class UInputAction* SprintInputAction;

	UPROPERTY(EditAnywhere, Category = "EnhancedInput")
	class UInputAction* RMDInputAction;

	UPROPERTY(EditAnywhere, Category = "EnhancedInput")
	class UInputConfigData* InputConfigData;

	UPROPERTY(EditAnywhere, Category = "Movement")
	float SprintAdditionalSpeed;
	bool IsSprinting;

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Character")
	class UMMO_CharacterHealthComponent* HealthComponent;
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Sets default values for this character's properties
	ABaseCharacter();
	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	APlayerController* GetPC();
	void Move(const FInputActionValue& InputValue);
	void Look(const FInputActionValue& InputValue);
	void Jump();
	void Sprint();
	void UnSprint();
	void ShowMouseCursor();
	void HideMouseCursor();
};
