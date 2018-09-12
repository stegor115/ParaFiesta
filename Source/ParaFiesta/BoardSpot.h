// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BoardSpot.generated.h"

UENUM(BlueprintType)
enum class EBoardPiece : uint8
{
	E_Start UMETA(DisplayName = "Start"), //0
	E_Good UMETA(DisplayName = "Good"), //1
	E_Bad UMETA(DisplayName = "Bad"), //2
	E_LeftOrRight UMETA(DisplayName = "Left or right"), //3
	E_UpOrDown UMETA(DisplayName = "Up or down") //4
};

UENUM(BlueprintType)
enum class EDirection : uint8
{
	E_Left UMETA(DisplayName = "Left"), //0
	E_Right UMETA(DisplayName = "Right"), //1
	E_Up UMETA(DisplayName = "Up"), //2
	E_Down UMETA(DisplayName = "Down"), //3
	E_Pause UMETA(DisplayName = "Pause for choice")
};

UCLASS()
class PARAFIESTA_API ABoardSpot : public AActor
{
	GENERATED_BODY()

	//UProperties

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Enum, meta = (AllowPrivateAccess = "true"))
	EBoardPiece BoardPiece;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Enum, meta = (AllowPrivateAccess = "true"))
	EDirection Direction;

	//Scene (For Root Component)
	UPROPERTY(VisibleAnywhere, BluePrintReadWrite, Category = Scene, meta = (AllowPrivateAccess = "true"))
	class USceneComponent* Scene;

	UPROPERTY(VisibleAnywhere, BluePrintReadWrite, Category = Mesh, meta = (AllowPrivateAccess = "true"))
	class UStaticMeshComponent* PlaneTop;

	UPROPERTY(VisibleAnywhere, BluePrintReadWrite, Category = Mesh, meta = (AllowPrivateAccess = "true"))
	class UStaticMeshComponent* PlaneFront;

	UPROPERTY(VisibleAnywhere, BluePrintReadWrite, Category = Mesh, meta = (AllowPrivateAccess = "true"))
	class UStaticMeshComponent* PlaneRight;

	UPROPERTY(VisibleAnywhere, BluePrintReadWrite, Category = Mesh, meta = (AllowPrivateAccess = "true"))
	class UStaticMeshComponent* PlaneLeft;

	UPROPERTY(VisibleAnywhere, BluePrintReadWrite, Category = Mesh, meta = (AllowPrivateAccess = "true"))
	class UBoxComponent* TriggerBlock;

	//UFunctions

	//Overlap
	UFUNCTION()
	void BeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex, bool bFromSweep, const FHitResult &SweepResult);

	UFUNCTION()
	void EndOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
	
public:	
	// Sets default values for this actor's properties
	ABoardSpot();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//Gets
	EDirection GetDirection();
	bool GetOverlap();
	//Functionality
	void MoreToMove(AActor* OverlappingActor);

private:
	bool overlapped = false; 
	EDirection direction = EDirection::E_Left;
};
