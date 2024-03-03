// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"

#include "BigWorldController.generated.h"

class UInputMappingContext;
/**
 * 
 */
UCLASS()
class STRATEGYTEST_API ABigWorldController : public APlayerController
{
	GENERATED_BODY()
private:
	ABigWorldController();
protected:

	virtual void SetupInputComponent() override;
public:
	/** MappingContext */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UInputMappingContext> DefaultMappingContext;
};
