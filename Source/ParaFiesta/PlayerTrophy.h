// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Sound/SoundCue.h"
#include "PlayerTrophy.generated.h"

UENUM(BlueprintType)
enum class ESelectedChar : uint8
{
	SC_Countess UMETA(DisplayName = "Countess"), //0
	SC_Dekker UMETA(DisplayName = "Dekker"), //1
	SC_FengMao UMETA(DisplayName = "Feng Mao"), //2
	SC_Gadget UMETA(DisplayName = "Gadget"), //3
	SC_Grim UMETA(DisplayName = "Grim"), //4
	SC_Grux UMETA(DisplayName = "Grux"), //5
	SC_Howitzer UMETA(DisplayName = "Howitzer"), //6
	SC_Khaimera UMETA(DisplayName = "Khaimera"), //7
	SC_Kwang UMETA(DisplayName = "Kwang"), //8
	SC_Murdock UMETA(DisplayName = "Murdock"), //9
	SC_Muriel UMETA(DisplayName = "Muriel"), //10
	SC_Phase UMETA(DisplayName="Phase"), //11
	SC_Rampage UMETA(DisplayName = "Rampage"), //12
	SC_Riktor UMETA(DisplayName = "Riktor"), //13
	SC_Serath UMETA(DisplayName = "Serath"), //14
	SC_Sevarog UMETA(DisplayName = "Sevarog"), //15
	SC_Shinbi UMETA(DisplayName = "Shinbi"), //16
	SC_Twinblast UMETA(DisplayName = "Twinblast") //17
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
	//Loading characters in
	UFUNCTION(BlueprintCallable, Category="Character")
	void startLoadChoice(int playerNum, ESelectedChar playerChoice); // Add argument to get Player Number, and one to figure out the character selected
	void finalLoadChoice(USkeletalMeshComponent* playerMesh, USkeletalMesh* skeleton, UAnimBlueprint* animBlueprint, USoundCue* soundIntro, UAnimSequence* animLevelStart, UAnimSequence* animIdle);

	//All character load functions, this is needed because it is not possible to initialize variables in a switch case statement
	void loadCountess(USkeletalMeshComponent* playerMesh);
	void loadDekker(USkeletalMeshComponent* playerMesh);
	void loadFengMao(USkeletalMeshComponent* playerMesh);
	void loadGadget(USkeletalMeshComponent* playerMesh);
	void loadGrim(USkeletalMeshComponent* playerMesh);
	void loadGrux(USkeletalMeshComponent* playerMesh);
	void loadHowitzer(USkeletalMeshComponent* playerMesh);
	void loadKhaimera(USkeletalMeshComponent* playerMesh);
	void loadKwang(USkeletalMeshComponent* playerMesh);
	void loadMurdock(USkeletalMeshComponent* playerMesh);
	void loadMuriel(USkeletalMeshComponent* playerMesh);
	void loadPhase(USkeletalMeshComponent* playerMesh);
	void loadRampage(USkeletalMeshComponent* playerMesh);
	void loadRiktor(USkeletalMeshComponent* playerMesh);
	void loadSerath(USkeletalMeshComponent* playerMesh);
	void loadSevarog(USkeletalMeshComponent* playerMesh);
	void loadShinbi(USkeletalMeshComponent* playerMesh);
	void loadTwinblast(USkeletalMeshComponent* playerMesh);

	USkeletalMeshComponent* getPlayerMesh(int playerNum); //Retrives correct player's mesh component
	
	
};
