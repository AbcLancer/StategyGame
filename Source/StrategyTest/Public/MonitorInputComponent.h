// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "MonitorInputComponent.generated.h"

class UInputAction;
struct FInputActionValue;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class STRATEGYTEST_API UMonitorInputComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UMonitorInputComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	void LookAround(const FInputActionValue& InputActionValue);
	void RotateCamera(const FInputActionValue& InputActionValue);
	void ZoomCamera(const FInputActionValue& InputActionValue);
	void EnterRotateMode(const FInputActionValue& InputActionValue);
	void ExitRotateMode(const FInputActionValue& InputActionValue);
	void EnterDragCameraMode(const FInputActionValue& InputActionValue);
	void ExitDragCameraMode(const FInputActionValue& InputActionValue);
	void DragCamera(const FInputActionValue& InputActionValue);

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void Setup(class UInputComponent* PlayerInputComponent);

	/* �ƶ���� */
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "EnhancedInput|Action", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UInputAction> IA_Move;
	/* ��ת���ģʽ */
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "EnhancedInput|Action", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UInputAction> IA_RotateMode;
	/* ��ת��� */
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "EnhancedInput|Action", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UInputAction> IA_Rotate;
	/* Zoom */
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "EnhancedInput|Action", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UInputAction> IA_Zoom;
	/* �϶����ģʽ */
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "EnhancedInput|Action", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UInputAction> IA_DragCameraMode;
	/* �϶���� */
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "EnhancedInput|Action", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UInputAction> IA_DragCamera;

		
};
