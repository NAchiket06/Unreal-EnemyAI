// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PatrolPoints.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/Character.h"
#include "GameFramework/SpringArmComponent.h"
#include "PlayerCharacter.generated.h"

UCLASS()
class AI_ENEMYLOGIC_API APlayerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APlayerCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


private:
	void MoveForward(float value);
	void MoveRight(float value);
	void SetShoot();
	void StopShoot();

	void SetupCamera();
	
public:

	UPROPERTY(EditAnywhere)
	USpringArmComponent *SpringArm;

	UPROPERTY(EditAnywhere)
	UCameraComponent *Camera;
	
	UPROPERTY(BlueprintReadOnly,EditAnywhere)
	bool Shooting = false;

	UFUNCTION(BlueprintPure)
	bool IsShooting() const;
	
	UPROPERTY(BlueprintReadOnly,EditAnywhere)
	float isWalking = false;
	
	UPROPERTY(EditAnywhere)
	FVector PatrolPoints[5];
};

