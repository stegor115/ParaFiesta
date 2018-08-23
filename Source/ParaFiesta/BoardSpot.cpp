// Fill out your copyright notice in the Description page of Project Settings.

#include "BoardSpot.h"
//Components
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"
//Other
#include "Runtime/CoreUObject/Public/UObject/ConstructorHelpers.h"


// Sets default values
ABoardSpot::ABoardSpot()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Scene = CreateDefaultSubobject<USceneComponent>(TEXT("Scene"));
	RootComponent = Scene;

	BaseBlock = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Base"));
	BaseBlock->SetupAttachment(RootComponent);
	ConstructorHelpers::FObjectFinder<UStaticMesh>cube(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube'"));
	BaseBlock->SetStaticMesh(cube.Object);
	BaseBlock->SetRelativeScale3D(FVector(2.0f, 2.0f, 0.5f));
	BaseBlock->CastShadow = false;

	TriggerBlock = CreateDefaultSubobject<UBoxComponent>(TEXT("Trigger"));
	TriggerBlock->SetupAttachment(RootComponent);
	TriggerBlock->SetRelativeLocation(FVector(0.0f, 0.0f, 90.0f));
	TriggerBlock->SetRelativeScale3D(FVector(2.0f, 2.0f, 1.0f));

}

// Called when the game starts or when spawned
void ABoardSpot::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABoardSpot::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

