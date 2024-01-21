// Fill out your copyright notice in the Description page of Project Settings.


#include "MenuHUD.h"
#include "SJGAdvancedWidgetSwitcher.h"
#include "Widgets/SWeakWidget.h"
#include "Engine/Engine.h"

void AMenuHUD::BeginPlay()
{
	Super::BeginPlay();

	if (GEngine && GEngine->GameViewport)
	{
		AdvancedWidgetSwitcher = SNew(SJGAdvancedWidgetSwitcher).OwningHUD(this);
		GEngine->GameViewport->AddViewportWidgetContent(SAssignNew(WidgetContainer, SWeakWidget).PossiblyNullContent(AdvancedWidgetSwitcher.ToSharedRef()));
	}
}
