// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PlayerAvatar.generated.h"

UCLASS()
class PARAFIESTA_API APlayerAvatar : public ACharacter
{
	GENERATED_BODY()
	//Camera boom
	UPROPERTY(VisibleAnywhere, BluePrintReadWrite, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

	//Camera
	UPROPERTY(VisibleAnywhere, BluePrintReadWrite, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* Camera;

	//Cube Spawner
	UPROPERTY(VisibleAnywhere, BluePrintReadWrite, Category = Cube, meta = (AllowPrivateAccess = "true"))
	class UStaticMeshComponent* SpawnerCube;

public:
	// Sets default values for this character's properties
	APlayerAvatar();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	//Camera Handling
	void ZoomOut();
	void ZoomIn();
	//Movement
	void MoveForward(float value);
	void MoveBackward(float value);
	void MoveLeft(float value);
	void MoveRight(float value);

private:
	int MAX_CAMERA_DISTANCE = 800;
	int MIN_CAMERA_DISTANCE = 200;
};
