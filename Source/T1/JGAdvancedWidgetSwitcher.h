// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/ObjectMacros.h"
#include "Input/Reply.h"
#include "Widgets/SWidget.h"
#include "Components/ContentWidget.h"

#include "JGAdvancedWidgetSwitcher.generated.h"

/**
 * 
 */

class SJGAdvancedWidgetSwitcher;

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnLeftButtonClickedEvent);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnRightButtonClickedEvent);

UCLASS()
class JGAdvancedWidgetSwitcher : public UContentWidget
{
	GENERATED_UCLASS_BODY()

public:
	UPROPERTY(BlueprintAssignable, category = "Button|Event")
		FOnLeftButtonClickedEvent OnLeftButtonClicked;

	UPROPERTY(BlueprintAssignable, category = "Button|Event")
		FOnRightButtonClickedEvent OnRightButtonClicked;

#if WITH_EDITOR
	virtual const FText GetPaletteCategory() override;
#endif

public:
	virtual void SynchronizeProperties() override;

	virtual void ReleaseSlateResources(bool bReleaseChildren) override;

	virtual void PostLoad() override;

protected:
	// 
	//~ Begin UWidget Interface
	virtual TSharedRef<SWidget> RebuildWidget() override;
#if WITH_EDITOR
	virtual TSharedRef<SWidget> RebuildDesignWidget(TSharedRef<SWidget> Content) override { return Content; }
#endif
	//~ End UWidget Interface

protected:

	FReply SlateHandleLeftClicked();
	FReply SlateHandleRightClicked();
	TSharedPtr<SJGAdvancedWidgetSwitcher> MySwitcher;
};
