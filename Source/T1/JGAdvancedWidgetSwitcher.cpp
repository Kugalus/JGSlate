// Fill out your copyright notice in the Description page of Project Settings.


#include "JGAdvancedWidgetSwitcher.h"

TSharedRef<SWidget> JGAdvancedWidgetSwitcher::RebuildWidget()
{
	MySwitcher = SNew(SJGAdvancedWidgetSwitcher)
		.OnLeftClicked(BIND_UOBJECT_DELEGATE(FOnLeftButtonClicked, SlateHandleLeftClicked))
		.OnRightClicked(BIND_UOBJECT_DELEGATE(FOnRightButtonClicked, SlateHandleRightClicked))
	return TSharedRef<SWidget>();
}

FReply JGAdvancedWidgetSwitcher::SlateHandleLeftClicked()
{
	OnLeftButtonClicked.Broadcast();
	return FReply::Handled();
}

void JGAdvancedWidgetSwitcher::SynchronizeProperties()
{
	Super::SynchronizeProperties();

	if (!MySwitcher.IsValid())
	{
		return;
	}
}

void JGAdvancedWidgetSwitcher::PostLoad()
{
	Super::PostLoad();
}
