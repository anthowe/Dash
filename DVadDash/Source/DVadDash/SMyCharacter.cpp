// Fill out your copyright notice in the Description page of Project Settings.

#include "SMyCharacter.h"


#include "Components/InputComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"

// Sets default values
ASMyCharacter::ASMyCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->bUsePawnControlRotation = true;
	SpringArm->SetupAttachment(RootComponent);

	CameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComp"));
	CameraComp->SetupAttachment(SpringArm);



}

// Called when the game starts or when spawned
void ASMyCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}


void ASMyCharacter::MoveForward(float Input)
{
	AddMovementInput(GetActorForwardVector()* Input);

	
	
}

void ASMyCharacter::MoveRight(float Input)
{
	AddMovementInput(GetActorRightVector()* Input);

}

void ASMyCharacter::MoveUp(float Input)
{
	AddMovementInput(GetActorUpVector()* Input);

}
void ASMyCharacter::Dash()
{
	return;
}
// Called every frame
void ASMyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ASMyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	
	PlayerInputComponent->BindAxis("MoveForward", this, &ASMyCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ASMyCharacter::MoveRight);
	PlayerInputComponent->BindAxis("MoveUp", this, &ASMyCharacter::MoveUp);
	PlayerInputComponent->BindAxis("Turn", this, &ASMyCharacter::AddControllerYawInput);
	PlayerInputComponent->BindAxis("Lookup", this, &ASMyCharacter::AddControllerPitchInput);
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
}

