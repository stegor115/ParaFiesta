// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BoardSpot.generated.h"

UCLASS()
class PARAFIESTA_API ABoardSpot : public AActor
{
	GENERATED_BODY()

	//Scene (For Root Component)
	UPROPERTY(VisibleAnywhere, BluePrintReadWrite, Category = Scene, meta = (AllowPrivateAccess = "true"))
	class USceneComponent* Scene;

	UPROPERTY(VisibleAnywhere, BluePrintReadWrite, Category = Mesh, meta = (AllowPrivateAccess = "true"))
	class UStaticMeshComponent* BaseBlock;

	UPROPERTY(VisibleAnywhere, BluePrintReadWrite, Category = Mesh, meta = (AllowPrivateAccess = "true"))
	class UBoxComponent* TriggerBlock;
	
public:	
	// Sets default values for this actor's properties
	ABoardSpot();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	
	
};
