// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "InputActionValue.h"
#include "MonitorInputComponent.h"

#include "MonitorPawn.generated.h"

class UInputMappingContext;
class UInputAction;
class USceneComponent;
struct FInputActionValue;

UCLASS()
class STRATEGYTEST_API AMonitorPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AMonitorPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	/*void LookAround(const FInputActionValue& InputActionValue);
	void RotateCamera(const FInputActionValue& InputActionValue);
	void ZoomCamera(const FInputActionValue& InputActionValue);
	void EnterRotateMode(const FInputActionValue& InputActionValue);
	void ExitRotateMode(const FInputActionValue& InputActionValue);
	void EnterDragCameraMode(const FInputActionValue& InputActionValue);
	void ExitDragCameraMode(const FInputActionValue& InputActionValue);
	void DragCamera(const FInputActionValue& InputActionValue);*/

public:
	// 输入组件
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	class UMonitorInputComponent* InputComp;
	// 摄像机组件
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	class UCameraComponent* CameraComp;

	// 跟随玩家背后摄像机的弹簧臂组件
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	class USpringArmComponent* SpringArmComp;

	class USceneComponent* basescene;

	/** 默认的InputMappingContext */
	/*   */
	///* 移动相机 */
	//UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "EnhancedInput|Action", meta = (AllowPrivateAccess = "true"))
	//TObjectPtr<UInputAction> IA_Move;
	///* 旋转相机模式 */
	//UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "EnhancedInput|Action", meta = (AllowPrivateAccess = "true"))
	//TObjectPtr<UInputAction> IA_RotateMode;
	///* 旋转相机 */
	//UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "EnhancedInput|Action", meta = (AllowPrivateAccess = "true"))
	//TObjectPtr<UInputAction> IA_Rotate;
	///* Zoom */
	//UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "EnhancedInput|Action", meta = (AllowPrivateAccess = "true"))
	//TObjectPtr<UInputAction> IA_Zoom;
	///* 拖动相机模式 */
	//UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "EnhancedInput|Action", meta = (AllowPrivateAccess = "true"))
	//TObjectPtr<UInputAction> IA_DragCameraMode;
	///* 拖动相机 */
	//UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "EnhancedInput|Action", meta = (AllowPrivateAccess = "true"))
	//TObjectPtr<UInputAction> IA_DragCamera;

};
