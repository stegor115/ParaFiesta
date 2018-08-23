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

	ConstructorHelpers::FObjectFinder<UStaticMesh>plane(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Plane.Shape_Plane'"));

	//Top Plane
	PlaneTop = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Top"));
	PlaneTop->SetupAttachment(RootComponent);
	PlaneTop->SetStaticMesh(plane.Object);
	PlaneTop->SetRelativeScale3D(FVector(2.0f, 2.0f, 1.0f));
	PlaneTop->SetRelativeLocation(FVector(0.0f, 0.0f, 50.0f));
	PlaneTop->CastShadow = false;
	
	//If Enum Board Piece type, set texture

	//Front Plane
	PlaneFront = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Front"));
	PlaneFront->SetupAttachment(RootComponent);
	PlaneFront->SetStaticMesh(plane.Object);
	PlaneFront->SetRelativeScale3D(FVector(2.0f, 0.5f, 1.0f));
	PlaneFront->SetRelativeRotation(FRotator(0.0f, 0.0f, 90.0f));
	PlaneFront->SetRelativeLocation(FVector(0.0f, 100.0f, 25.0f));
	PlaneFront->CastShadow = false;

	//Right Plane
	PlaneRight = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Right"));
	PlaneRight->SetupAttachment(RootComponent);
	PlaneRight->SetStaticMesh(plane.Object);
	PlaneRight->SetRelativeScale3D(FVector(2.0f, 0.5f, 1.0f));
	PlaneRight->SetRelativeRotation(FRotator(180.0f, -90.0f, 90.0f));
	PlaneRight->SetRelativeLocation(FVector(100.0f, 0.0f, 25.0f));
	PlaneRight->CastShadow = false;

	//Left Plane
	PlaneLeft = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Left"));
	PlaneLeft->SetupAttachment(RootComponent);
	PlaneLeft->SetStaticMesh(plane.Object);
	PlaneLeft->SetRelativeScale3D(FVector(2.0f, 0.5f, 1.0f));
	PlaneLeft->SetRelativeRotation(FRotator(180.0f, -90.0f, -90.0f));
	PlaneLeft->SetRelativeLocation(FVector(-100.0f, 0.0f, 25.0f));
	PlaneLeft->CastShadow = false;


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

