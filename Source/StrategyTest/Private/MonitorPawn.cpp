// Fill out your copyright notice in the Description page of Project Settings.


#include "MonitorPawn.h"
#include "LogHelper.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"

// Sets default values
AMonitorPawn::AMonitorPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	basescene = CreateDefaultSubobject<USceneComponent>(TEXT("LookatPoint"));
	SetRootComponent(basescene);

	SpringArmComp = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraSpring"));

	//Setup Camera Boom attachment to the Root component of the class
	SpringArmComp->SetupAttachment(basescene);

	CameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));

	//Set FollowCamera attachment to the Camera Boom
	CameraComp->SetupAttachment(SpringArmComp);

	InputComp = CreateDefaultSubobject<UMonitorInputComponent>(TEXT("MonitorInput"));

	////Setup Camera Boom attachment to the Root component of the class
	//InputComp->SetupAttachment(basescene);

}

// Called when the game starts or when spawned
void AMonitorPawn::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(GameInfo, Log, TEXT("Start Pawn"));
}

// Called every frame
void AMonitorPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMonitorPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	UE_LOG(GameInfo, Log, TEXT("Start Pawn Input"));
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	InputComp->Setup(PlayerInputComponent);
	//if (UEnhancedInputComponent* PlayerEnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	//{
	//	PlayerEnhancedInputComponent->BindAction(IA_Move, ETriggerEvent::Triggered, this, &AMonitorPawn::LookAround);
	//	PlayerEnhancedInputComponent->BindAction(IA_Rotate, ETriggerEvent::Triggered, this, &AMonitorPawn::RotateCamera);
	//	PlayerEnhancedInputComponent->BindAction(IA_Zoom, ETriggerEvent::Triggered, this, &AMonitorPawn::ZoomCamera);
	//	PlayerEnhancedInputComponent->BindAction(IA_RotateMode, ETriggerEvent::Started, this, &AMonitorPawn::EnterRotateMode);
	//	PlayerEnhancedInputComponent->BindAction(IA_RotateMode, ETriggerEvent::Completed, this, &AMonitorPawn::ExitRotateMode);
	//	PlayerEnhancedInputComponent->BindAction(IA_DragCameraMode, ETriggerEvent::Started, this, &AMonitorPawn::EnterDragCameraMode);
	//	PlayerEnhancedInputComponent->BindAction(IA_DragCameraMode, ETriggerEvent::Completed, this, &AMonitorPawn::ExitDragCameraMode);
	//	PlayerEnhancedInputComponent->BindAction(IA_DragCamera, ETriggerEvent::Triggered, this, &AMonitorPawn::DragCamera);
	//	UE_LOG(GameInfo, Log, TEXT("Set Pawn Input complete"));
	//	/*PlayerInputComponent->BindAxis("MoveRight", this, &AExampleCharacter::MoveRight);
	//	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	//	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);*/
	//}

}

//void AMonitorPawn::LookAround(const FInputActionValue& InputActionValue)
//{
//	const FVector2D Value = InputActionValue.Get<FVector2D>();
//	// 移动相机
//	const FRotator MovementRotation(0.0f, GetControlRotation().Yaw, 0.0f);
//	if (Value.X != 0.0f)
//	{
//		// const FVector MovementDirection = MovementRotation.RotateVector(FVector::RightVector);
//		const FVector MovementDirection = GetActorRightVector();  // actor在世界空间下的右方向
//		AddMovementInput(MovementDirection, Value.X);
//	}
//
//	if (Value.Y != 0.0f)
//	{
//		// const FVector MovementDirection = MovementRotation.RotateVector(FVector::ForwardVector);
//		const FVector MovementDirection = GetActorForwardVector();
//		AddMovementInput(MovementDirection, Value.Y);
//	}
//	// FVector WorldDirection = (CachedDestination - ControlledPawn->GetActorLocation()).GetSafeNormal();
//	// ControlledPawn->AddMovementInput(WorldDirection, 1.0, false);
//
//}
//
//void AMonitorPawn::RotateCamera(const FInputActionValue& InputActionValue)
//{
//	const FVector2D Value = InputActionValue.Get<FVector2D>();
//	UE_LOG(GameInfo, Log, TEXT("Rotate at(% f, % f)"), Value.X, Value.Y);
//	
//
//	if (Value.X != 0.0f || Value.Y != 0.0f)
//	{
//		FRotator n;
//		n.Yaw = Value.X;
//		// n.Roll = Value.Y;
//		AddActorLocalRotation(n);
//		// SpringArmComp->AddRelativeRotation(n);
//		// AddActorWorldRotation(n);
//	}
//	/*if (Value.Y != 0.0f)
//	{
//		AddControllerPitchInput(Value.Y);
//	}*/
//}
//
//// 通过调整弹簧臂的长度实现zoom效果
//void AMonitorPawn::ZoomCamera(const FInputActionValue& InputActionValue)
//{
//	const float Value = InputActionValue.Get<float>();
//	UE_LOG(GameInfo, Log, TEXT("zoom at % f"), Value);
//	SpringArmComp->TargetArmLength += Value*10;
//}
//
//void AMonitorPawn::EnterRotateMode(const FInputActionValue& InputActionValue)
//{
//	const bool Value = InputActionValue.Get<bool>();
//	UE_LOG(GameInfo, Log, TEXT("enter Rotate mode"));
//}
//void AMonitorPawn::ExitRotateMode(const FInputActionValue& InputActionValue)
//{
//	const bool Value = InputActionValue.Get<bool>();
//	UE_LOG(GameInfo, Log, TEXT("exit Rotate mode"));
//}
//
//void AMonitorPawn::EnterDragCameraMode(const FInputActionValue& InputActionValue)
//{
//	const bool Value = InputActionValue.Get<bool>();
//	UE_LOG(GameInfo, Log, TEXT("开始拖动镜头"));
//}
//
//void AMonitorPawn::ExitDragCameraMode(const FInputActionValue& InputActionValue)
//{
//	const bool Value = InputActionValue.Get<bool>();
//	UE_LOG(GameInfo, Log, TEXT("停止拖动镜头"));
//}
//
//void AMonitorPawn::DragCamera(const FInputActionValue& InputActionValue)
//{
//}

