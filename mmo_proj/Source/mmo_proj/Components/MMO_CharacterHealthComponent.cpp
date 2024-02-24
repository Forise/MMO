// Fill out your copyright notice in the Description page of Project Settings.


#include "Headers/MMO_CharacterHealthComponent.h"

// Sets default values for this component's properties
UMMO_CharacterHealthComponent::UMMO_CharacterHealthComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UMMO_CharacterHealthComponent::BeginPlay()
{
	Super::BeginPlay();

	check(MaxHealth >0);
	Health = MaxHealth;


	AActor* ComponentOwner = GetOwner();
	if (ComponentOwner)
	{
		ComponentOwner->OnTakeAnyDamage.AddDynamic(this, &UMMO_CharacterHealthComponent::TakeDamage);
	}
}


void UMMO_CharacterHealthComponent::TakeDamage(AActor* DamageActor, float Damage, const UDamageType* DamageType,
	AController* InstigatedBy, AActor* DamageCauser)
{

	if(Damage <=0) return;
	
	Damage = FMath::Min(Health, Damage);
	Health = FMath::Clamp(Health - Damage, 0.0f, MaxHealth);
	SetHealth(Health);

	if (DamageType)
	{
		//if (DamageType->IsA<UMFireDamageType>())
		//{
		//	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::Printf(TEXT("DaamgeType: Fire")));
		//	//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::Printf(TEXT("Damage Causer %s"), *DamageCauser->GetName()));
		//}
		//else if (DamageType->IsA<UMFrostDamageType>())
		//{
		//	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::Printf(TEXT("DaamgeType: Frost")));
		//}
	}
}

// Called every frame
void UMMO_CharacterHealthComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

