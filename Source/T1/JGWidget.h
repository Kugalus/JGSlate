#pragma once

#include "CoreMinimal.h"
#include "Runtime/UMG/Public/Blueprint/UserWidget.h" // i added UMG as a dependency, yet it is still fucked
#include "JGWidget.generated.h"

UCLASS()
class T1_API UJGWidget : public UUserWidget
{
	GENERATED_BODY()

protected:
	virtual void NativeConstruct() override;
};
