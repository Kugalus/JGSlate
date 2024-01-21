// Fill out your copyright notice in the Description page of Project Settings.


#include "SJGAdvancedWidgetSwitcher.h"

#define LOCTEXT_NAMESPACE "AdvancedWidgetSwitcher"

void SJGAdvancedWidgetSwitcher::Construct(const FArguments& InArgs)
{
	OwningHUD = InArgs._OwningHUD;

	const FText LeftButtonText = LOCTEXT("LeftButtonName", "-1");
	const FText RightButtonText = LOCTEXT("RightButtonName", "+1");

	ChildSlot
		[
		SNew(SHorizontalBox)


		+ SHorizontalBox::Slot()
		.HAlign(HAlign_Right)
		[
			SNew(SButton)
			.OnClicked(this, &SJGAdvancedWidgetSwitcher::OnLeftClicked)
			.Text(LeftButtonText)
		]

		+ SHorizontalBox::Slot()
		.HAlign(HAlign_Fill)
		[
			SNew(SWidgetSwitcher)
			.WidgetIndex(0)
			+ SWidgetSwitcher::Slot()
			[
				SNew(SImage)

			]
		]

		+ SHorizontalBox::Slot()
		.HAlign(HAlign_Left)
		[
			SNew(SButton)
			.OnClicked(this, &SJGAdvancedWidgetSwitcher::OnRightClicked)
			.Text(RightButtonText)
		]
		];
}

FReply SJGAdvancedWidgetSwitcher::OnLeftClicked() const
{

		return FReply::Handled();
}

FReply SJGAdvancedWidgetSwitcher::OnRightClicked() const
{
	return FReply::Handled();
}

#undef LOCTEXT_NAMESPACE