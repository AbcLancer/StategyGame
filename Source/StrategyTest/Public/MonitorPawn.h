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
	// �������
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	class UMonitorInputComponent* InputComp;
	// ��������
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	class UCameraComponent* CameraComp;

	// ������ұ���������ĵ��ɱ����
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	class USpringArmComponent* SpringArmComp;

	class USceneComponent* basescene;

	/** Ĭ�ϵ�InputMappingContext */
	/*   */
	///* �ƶ���� */
	//UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "EnhancedInput|Action", meta = (AllowPrivateAccess = "true"))
	//TObjectPtr<UInputAction> IA_Move;
	///* ��ת���ģʽ */
	//UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "EnhancedInput|Action", meta = (AllowPrivateAccess = "true"))
	//TObjectPtr<UInputAction> IA_RotateMode;
	///* ��ת��� */
	//UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "EnhancedInput|Action", meta = (AllowPrivateAccess = "true"))
	//TObjectPtr<UInputAction> IA_Rotate;
	///* Zoom */
	//UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "EnhancedInput|Action", meta = (AllowPrivateAccess = "true"))
	//TObjectPtr<UInputAction> IA_Zoom;
	///* �϶����ģʽ */
	//UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "EnhancedInput|Action", meta = (AllowPrivateAccess = "true"))
	//TObjectPtr<UInputAction> IA_DragCameraMode;
	///* �϶���� */
	//UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "EnhancedInput|Action", meta = (AllowPrivateAccess = "true"))
	//TObjectPtr<UInputAction> IA_DragCamera;

};
