// Fill out your copyright notice in the Description page of Project Settings.


#include "MonitorInputComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "GameFramework/SpringArmComponent.h"
#include "LogHelper.h"

// Sets default values for this component's properties
UMonitorInputComponent::UMonitorInputComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UMonitorInputComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UMonitorInputComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UMonitorInputComponent::Setup(UInputComponent* PlayerInputComponent)
{
	if (UEnhancedInputComponent* PlayerEnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		PlayerEnhancedInputComponent->BindAction(IA_Move, ETriggerEvent::Triggered, this, &UMonitorInputComponent::LookAround);
		PlayerEnhancedInputComponent->BindAction(IA_Rotate, ETriggerEvent::Triggered, this, &UMonitorInputComponent::RotateCamera);
		PlayerEnhancedInputComponent->BindAction(IA_Zoom, ETriggerEvent::Triggered, this, &UMonitorInputComponent::ZoomCamera);
		PlayerEnhancedInputComponent->BindAction(IA_RotateMode, ETriggerEvent::Started, this, &UMonitorInputComponent::EnterRotateMode);
		PlayerEnhancedInputComponent->BindAction(IA_RotateMode, ETriggerEvent::Completed, this, &UMonitorInputComponent::ExitRotateMode);
		PlayerEnhancedInputComponent->BindAction(IA_DragCameraMode, ETriggerEvent::Started, this, &UMonitorInputComponent::EnterDragCameraMode);
		PlayerEnhancedInputComponent->BindAction(IA_DragCameraMode, ETriggerEvent::Completed, this, &UMonitorInputComponent::ExitDragCameraMode);
		PlayerEnhancedInputComponent->BindAction(IA_DragCamera, ETriggerEvent::Triggered, this, &UMonitorInputComponent::DragCamera);
		UE_LOG(GameInfo, Log, TEXT("Set Pawn Input complete"));
		/*PlayerInputComponent->BindAxis("MoveRight", this, &AExampleCharacter::MoveRight);
		PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
		PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);*/
	}
}
void UMonitorInputComponent::LookAround(const FInputActionValue& InputActionValue)
{
	const FVector2D Value = InputActionValue.Get<FVector2D>();
	auto aa = Cast<APawn>(GetOwner());
	// 移动相机
	// const FRotator MovementRotation(0.0f, GetControlRotation().Yaw, 0.0f);
	if (Value.X != 0.0f)
	{
		// const FVector MovementDirection = MovementRotation.RotateVector(FVector::RightVector);
		const FVector MovementDirection = aa->GetActorRightVector();  // actor在世界空间下的右方向
		aa->AddMovementInput(MovementDirection, Value.X);
	}

	if (Value.Y != 0.0f)
	{
		// const FVector MovementDirection = MovementRotation.RotateVector(FVector::ForwardVector);
		const FVector MovementDirection = aa->GetActorForwardVector();
		aa->AddMovementInput(MovementDirection, Value.Y);
	}
	// FVector WorldDirection = (CachedDestination - ControlledPawn->GetActorLocation()).GetSafeNormal();
	// ControlledPawn->AddMovementInput(WorldDirection, 1.0, false);

}

void UMonitorInputComponent::RotateCamera(const FInputActionValue& InputActionValue)
{
	const FVector2D Value = InputActionValue.Get<FVector2D>();
	UE_LOG(GameInfo, Log, TEXT("Rotate at(% f, % f)"), Value.X, Value.Y);
	auto aa = Cast<APawn>(GetOwner());

	if (Value.X != 0.0f || Value.Y != 0.0f)
	{
		FRotator n;
		n.Yaw = Value.X;
		// n.Roll = Value.Y;
		aa->AddActorLocalRotation(n);
		// SpringArmComp->AddRelativeRotation(n);
		// AddActorWorldRotation(n);
	}
	/*if (Value.Y != 0.0f)
	{
		AddControllerPitchInput(Value.Y);
	}*/
}

// 通过调整弹簧臂的长度实现zoom效果
void UMonitorInputComponent::ZoomCamera(const FInputActionValue& InputActionValue)
{
	const float Value = InputActionValue.Get<float>();
	UE_LOG(GameInfo, Log, TEXT("zoom at % f"), Value);
	auto aa = Cast<APawn>(GetOwner());
	auto SpringArmComp = aa->FindComponentByClass<USpringArmComponent>();
	SpringArmComp->TargetArmLength += Value * 10;
}

void UMonitorInputComponent::EnterRotateMode(const FInputActionValue& InputActionValue)
{
	const bool Value = InputActionValue.Get<bool>();
	UE_LOG(GameInfo, Log, TEXT("enter Rotate mode"));
}
void UMonitorInputComponent::ExitRotateMode(const FInputActionValue& InputActionValue)
{
	const bool Value = InputActionValue.Get<bool>();
	UE_LOG(GameInfo, Log, TEXT("exit Rotate mode"));
}

void UMonitorInputComponent::EnterDragCameraMode(const FInputActionValue& InputActionValue)
{
	const bool Value = InputActionValue.Get<bool>();
	UE_LOG(GameInfo, Log, TEXT("开始拖动镜头"));
}

void UMonitorInputComponent::ExitDragCameraMode(const FInputActionValue& InputActionValue)
{
	const bool Value = InputActionValue.Get<bool>();
	UE_LOG(GameInfo, Log, TEXT("停止拖动镜头"));
}

void UMonitorInputComponent::DragCamera(const FInputActionValue& InputActionValue)
{

}

