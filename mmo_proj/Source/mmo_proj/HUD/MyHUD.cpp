// Fill out your copyright notice in the Description page of Project Settings.


#include "Headers/MyHUD.h"
#include "Blueprint/UserWidget.h"

void AMyHUD::BeginPlay()
{
	Super::BeginPlay();

	const auto PlayerHUDWidget = CreateWidget<UUserWidget>(GetWorld(), PlayerHudWidgetClass);
	if (PlayerHUDWidget)
	{
		PlayerHUDWidget->AddToViewport();
	}
}
