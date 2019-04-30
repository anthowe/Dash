// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "SMyCharacter.generated.h"

UCLASS()
class DVADDASH_API ASMyCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ASMyCharacter();

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
	class USpringArmComponent* SpringArm;

	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
	class UCameraComponent* CameraComp;

	


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	

	void MoveForward(float Input);

	void MoveRight(float Input);

	void MoveUp(float Input);

	UFUNCTION(BlueprintCallable, Category = "Components")
	void Dash();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	
	
};
