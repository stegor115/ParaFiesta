// Fill out your copyright notice in the Description page of Project Settings.

#include "PlayerTrophy.h"
#include "Components/SkeletalMeshComponent.h"
#include "Components/SceneComponent.h"
#include "Camera/CameraComponent.h"


// Sets default values
APlayerTrophy::APlayerTrophy()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Scene = CreateDefaultSubobject<USceneComponent>(TEXT("Scene"));
	RootComponent = Scene;

	PlayerOneMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("PlayerOneMesh"));
	PlayerOneMesh->SetupAttachment(RootComponent);
	PlayerOneMesh->SetRelativeLocation(FVector(0.0f, -220.0f, 0.0f));
	PlayerOneMesh->SetRelativeRotation(FRotator(0.0f, 60.0f, 0.0f));

	PlayerTwoMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("PlayerTwoMesh"));
	PlayerTwoMesh->SetupAttachment(RootComponent);
	PlayerTwoMesh->SetRelativeLocation(FVector(0.0f, -75.0f, 0.0f));
	PlayerTwoMesh->SetRelativeRotation(FRotator(0.0f, 90.0f, 0.0f));

	PlayerThreeMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("PlayerThreeMesh"));
	PlayerThreeMesh->SetupAttachment(RootComponent);
	PlayerThreeMesh->SetRelativeLocation(FVector(0.0f, 75.0f, 0.0f));
	PlayerThreeMesh->SetRelativeRotation(FRotator(0.0f, 90.0f, 0.0f));

	PlayerFourMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("PlayerFourMesh"));
	PlayerFourMesh->SetupAttachment(RootComponent);
	PlayerFourMesh->SetRelativeLocation(FVector(0.0f, 220.0f, 0.0f));
	PlayerFourMesh->SetRelativeRotation(FRotator(0.0f, 120.0f, 0.0f));

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("TrophyCamera"));
	Camera->SetupAttachment(RootComponent);
	Camera->SetRelativeLocation(FVector(-310.0f, 0.0f, 160.0f));

}

// Called when the game starts or when spawned
void APlayerTrophy::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlayerTrophy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

