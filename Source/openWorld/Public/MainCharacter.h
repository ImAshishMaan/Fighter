// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MainCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;
class UStaticMeshComponent;
class UAnimSequence;

UCLASS()
class OPENWORLD_API AMainCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMainCharacter();

protected:

	UPROPERTY(EditAnywhere)
	USpringArmComponent* SpringArmComp;

	UPROPERTY(EditAnywhere)
	UCameraComponent* CameraComp;

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* SwordComp;

	UPROPERTY(EditAnywhere)
	UAnimSequence* AttackAnimation;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void MoveForward(float InputValue);
	void MoveRight(float InputValue);
	void Turn(float InputValue);
	void LookUp(float InputValue);

	int Damage;

	void StartAttack();
	
public:
	UFUNCTION(BlueprintCallable)
	void LineTrace();

	UPROPERTY(BlueprintReadWrite)
	bool bIsAttacking;

};
