// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "MMO_CharacterHealthComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MMO_PROJ_API UMMO_CharacterHealthComponent : public UActorComponent
{
	GENERATED_BODY()

	float Health = 0;
	
	
	void SetHealth(const float HealthValue) {Health = HealthValue;}

public:	
	// Sets default values for this component's properties
	UMMO_CharacterHealthComponent();

	UFUNCTION(BlueprintCallable, Category= "Health")
	float GetHealthPercent() const {return Health / MaxHealth;}
	float GetHealth() const {return Health;}

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	float MaxHealth = 100.0f;

	UFUNCTION()
	void TakeDamage(AActor* DamageActor, float Damage, const class UDamageType* DamageType, class AController* InstigatedBy, AActor* DamageCauser);


public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	
	
		
};
