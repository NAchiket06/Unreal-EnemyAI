// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacter.h"

#include "GameFramework/CharacterMovementComponent.h"

// Sets default values
APlayerCharacter::APlayerCharacter()
{
	PrimaryActorTick.bCanEverTick = true;
	// SetupCamera();
}


///
/// Sets up the spring arm and camera component of the player.
/// 
void APlayerCharacter::SetupCamera()
{
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm"));
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm);
}

// Called when the game starts or when spawned
void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("Forward"),this,&APlayerCharacter::MoveForward);
	PlayerInputComponent->BindAxis(TEXT("Right"),this,&APlayerCharacter::MoveRight);
	PlayerInputComponent->BindAxis(TEXT("MouseX"),this,&APlayerCharacter::AddControllerYawInput);
	PlayerInputComponent->BindAxis(TEXT("MouseY"),this,&APlayerCharacter::AddControllerPitchInput);
	PlayerInputComponent->BindAction(TEXT("Shoot"),EInputEvent::IE_Pressed,this, &APlayerCharacter::SetShoot);
	PlayerInputComponent->BindAction(TEXT("Shoot"),EInputEvent::IE_Released,this, &APlayerCharacter::StopShoot);

}

void APlayerCharacter::MoveForward(float value)
{
	AddMovementInput(GetActorForwardVector() * value);
}

void APlayerCharacter::MoveRight(float value)
{
	AddMovementInput(GetActorRightVector() * value);
}


void APlayerCharacter::SetShoot()
{
	Shooting = true;
}

void APlayerCharacter::StopShoot()
{
	Shooting = false;
}

bool APlayerCharacter::IsShooting() const
{
	return Shooting;
}

