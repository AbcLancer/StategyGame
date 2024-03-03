// Fill out your copyright notice in the Description page of Project Settings.


#include "BigWorldController.h"
#include "EnhancedInputComponent.h"
#include "InputActionValue.h"
#include "EnhancedInputSubsystems.h"
#include "Engine/LocalPlayer.h"
#include "Camera/CameraComponent.h"

#include "LogHelper.h"

ABigWorldController::ABigWorldController()
{
	bShowMouseCursor = true;
}

void ABigWorldController::SetupInputComponent()
{
	Super::SetupInputComponent();
	// 激活默认的InputContext
	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		// 清理之前的mapping
		Subsystem->ClearAllMappings();
		Subsystem->AddMappingContext(DefaultMappingContext, 0);
	}
}
