// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PlayerTrophy.generated.h"

UENUM(BlueprintType)
enum class ESelectedChar : uint8
{
	SC_Countess UMETA(DisplayName = "Countess"),
	SC_Dekker UMETA(DisplayName = "Dekker"),
	SC_FengMao UMETA(DisplayName = "Feng Mao"),
	SC_Gadget UMETA(DisplayName = "Gadget"),
	SC_Grim UMETA(DisplayName = "Grim"),
	SC_Grux UMETA(DisplayName = "Grux"),
	SC_Howitzer UMETA(DisplayName = "Howitzer"),
	SC_Khaimera UMETA(DisplayName = "Khaimera"),
	SC_Kwang UMETA(DisplayName = "Kwang"),
	SC_Murdock UMETA(DisplayName = "Murdock"),
	SC_Muriel UMETA(DisplayName = "Muriel"),
	SC_Phase UMETA(DisplayName="Phase"),
	SC_Rampage UMETA(DisplayName = "Rampage"),
	SC_Riktor UMETA(DisplayName = "Riktor"),
	SC_Serath UMETA(DisplayName = "Serath"),
	SC_Sevarog UMETA(DisplayName = "Sevarog"),
	SC_Shinbi UMETA(DisplayName = "Shinbi"),
	SC_Twinblast UMETA(DisplayName = "Twinblast"),
	SC_Test UMETA(DisplayName = "test") //This is here because Twinblast wouldn't work for some reason without it.
};

UCLASS()
class PARAFIESTA_API APlayerTrophy : public AActor
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Enum, meta = (AllowPrivateAccess = "true"))
	ESelectedChar SelectedChar;
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

	UPROPERTY(VisibleAnywhere, BluePrintReadWrite, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* TallCamera;
	
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
