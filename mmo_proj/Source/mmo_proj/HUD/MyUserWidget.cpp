// Fill out your copyright notice in the Description page of Project Settings.


#include "Headers/MyUserWidget.h"

#include "mmo_proj/Components/Headers/MMO_CharacterHealthComponent.h"


float UMyUserWidget::GetHealthPercent(AActor* Player) const
{
	//Player = GetOwningPlayerPawn();
	if (!Player)return 0.0f;

	const auto Component = Player->GetComponentByClass(UMMO_CharacterHealthComponent::StaticClass());
	const auto HealthComponent = Cast<UMMO_CharacterHealthComponent>(Component);

	if(!HealthComponent) return 0.0f;
	return HealthComponent->GetHealthPercent();
}
/*
AActor* UMyUserWidget::GetActorTarget()
{
	auto Player = GetOwningPlayerPawn();
	if(!Player) return nullptr;

	const auto Component = Player->GetComponentByClass(USMTargetSystem::StaticClass());
	const auto TargetSystem = Cast<USMTargetSystem>(Component);

	if(!TargetSystem) return nullptr;
	return TargetSystem->GetCurrentTarget();
}
*/


AActor* UMyUserWidget::GetActorTarget()
{
	return nullptr;
}

