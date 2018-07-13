// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PlayerTrophy.generated.h"

UCLASS()
class PARAFIESTA_API APlayerTrophy : public AActor
{
	GENERATED_BODY()
	
	//Scene (For Root Component)
	UPROPERTY(VisibleAnywhere, BluePrintReadWrite, Category = Scene, meta = (AllowPrivateAccess = "true"))
	class USceneComponent* Scene;

	//Player Meshes
	UPROPERTY(VisibleAnywhere, BluePrintReadWrite, Category = Mesh, meta = (AllowPrivateAccess = "true"))
	class USkeletalMeshComponent* PlayerOneMesh;

	UPROPERTY(VisibleAnywhere, BluePrintReadWrite, Category = Mesh, meta = (AllowPrivateAccess = "true"))
	class USkeletalMeshComponent* PlayerTwoMesh;

	UPROPERTY(VisibleAnywhere, BluePrintReadWrite, Category = Mesh, meta = (AllowPrivateAccess = "true"))
	class USkeletalMeshComponent* PlayerThreeMesh;

	UPROPERTY(VisibleAnywhere, BluePrintReadWrite, Category = Mesh, meta = (AllowPrivateAccess = "true"))
	class USkeletalMeshComponent* PlayerFourMesh;

	//Camera
	UPROPERTY(VisibleAnywhere, BluePrintReadWrite, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* Camera;
	
public:	
	// Sets default values for this actor's properties
	APlayerTrophy();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void load(int playerNum); // Add argument to get Player Number, and one to figure out the character selected
	
	
};
