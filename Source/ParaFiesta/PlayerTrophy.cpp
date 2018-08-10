// Fill out your copyright notice in the Description page of Project Settings.

#include "PlayerTrophy.h"
//Components
#include "Components/SkeletalMeshComponent.h"
#include "Components/SceneComponent.h"
#include "Camera/CameraComponent.h"
//Stuff for components to use
#include "Engine/SkeletalMesh.h"
#include "Animation/AnimBlueprint.h"
#include "Animation/AnimSequence.h"
#include "Animation/AnimSingleNodeInstance.h"
//SoundCue goes in the header file for some reason
#include "Runtime/CoreUObject/Public/UObject/ConstructorHelpers.h"
#include "Kismet/GameplayStatics.h" //Used to play 2D sounds


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

	TallCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("TallCamera"));
	TallCamera->SetupAttachment(RootComponent);
	TallCamera->SetRelativeLocation(FVector(-310.0f, 0.0f, 230.0f));

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

void APlayerTrophy::startLoadChoice(int playerNum, ESelectedChar playerChoice) { //Callable from Blueprint
	//Get Player Mesh based on player number
	USkeletalMeshComponent* playerMesh = getPlayerMesh(playerNum);
	ESelectedChar choice; //Used to give to private enums after the first switch case
	//Order of below: Find skeleton, animation blueprint, sound, level start animation, idle animation, pass into final load function
	switch (playerChoice) {
	case ESelectedChar::SC_Countess:
		choice = ESelectedChar::SC_Countess;
		loadCountess(playerMesh);
		break;
	case ESelectedChar::SC_Dekker:
		choice = ESelectedChar::SC_Dekker;
		loadDekker(playerMesh);
		break;
	case ESelectedChar::SC_FengMao:
		choice = ESelectedChar::SC_FengMao;
		loadFengMao(playerMesh);
		break;
	case ESelectedChar::SC_Gadget:
		choice = ESelectedChar::SC_Gadget;
		loadGadget(playerMesh);
		break;
	case ESelectedChar::SC_Grim:
		choice = ESelectedChar::SC_Grim;
		loadGrim(playerMesh);
		break;
	case ESelectedChar::SC_Grux:
		choice = ESelectedChar::SC_Grux;
		loadGrux(playerMesh);
		break;
	case ESelectedChar::SC_Howitzer:
		choice = ESelectedChar::SC_Howitzer;
		loadHowitzer(playerMesh);
		break;
	case ESelectedChar::SC_Khaimera:
		choice = ESelectedChar::SC_Khaimera;
		loadKhaimera(playerMesh);
		break;
	case ESelectedChar::SC_Kwang:
		choice = ESelectedChar::SC_Kwang;
		loadKwang(playerMesh);
		break;
	case ESelectedChar::SC_Murdock:
		choice = ESelectedChar::SC_Murdock;
		loadMurdock(playerMesh);
		break;
	case ESelectedChar::SC_Muriel:
		choice = ESelectedChar::SC_Muriel;
		loadMuriel(playerMesh);
		break;
	case ESelectedChar::SC_Phase:
		choice = ESelectedChar::SC_Phase;
		loadPhase(playerMesh);
		break;
	case ESelectedChar::SC_Rampage:
		choice = ESelectedChar::SC_Rampage;
		loadRampage(playerMesh);
		break;
	case ESelectedChar::SC_Riktor:
		choice = ESelectedChar::SC_Riktor;
		loadRiktor(playerMesh);
		break;
	case ESelectedChar::SC_Serath:
		choice = ESelectedChar::SC_Serath;
		loadSerath(playerMesh);
		break;
	case ESelectedChar::SC_Sevarog:
		choice = ESelectedChar::SC_Sevarog;
		loadSevarog(playerMesh);
		break;
	case ESelectedChar::SC_Shinbi:
		choice = ESelectedChar::SC_Shinbi;
		loadShinbi(playerMesh);
		break;
	case ESelectedChar::SC_Twinblast:
		choice = ESelectedChar::SC_Twinblast;
		loadTwinblast(playerMesh);
		break;
	default:
		UE_LOG(LogTemp, Warning, TEXT("Default character case reached, DEBUG THIS"));
		break;
	} //end switch

	switch (playerNum) {
	case 1:
		playerOneChoice = choice;
		break;
	case 2:
		playerTwoChoice = choice;
		break;
	case 3:
		playerThreeChoice = choice;
		break;
	case 4:
		playerFourChoice = choice;
		break;
	default:
		UE_LOG(LogTemp, Warning, TEXT("Default choice case reached, DEBUG THIS"));
		break;
	} //end switch

	handleCamera(); //in case tall character is selected
} //end startLoadChoice

void APlayerTrophy::finalLoadChoice(USkeletalMeshComponent* playerMesh, USkeletalMesh* skeleton, UAnimBlueprint* animBlueprint, 
									USoundCue* soundIntro, UAnimSequence* animLevelStart, UAnimSequence* animIdle)
{
	playerMesh->SetVisibility(true); //In case it was invisible
	playerMesh->SetSkeletalMesh(skeleton); //Skeleton
	playerMesh->SetAnimInstanceClass(animBlueprint->GeneratedClass); //Animation Blueprint
	UGameplayStatics::PlaySound2D(this->GetWorld(), soundIntro, 1.0f, 1.0f, 0.0f); //Sound
	playerMesh->PlayAnimation(animLevelStart, false);
	tempSkele = playerMesh;
	tempAnimIdle = animIdle;
	//TO-DO: Restart Idle Animation.
	GetWorld()->GetTimerManager().SetTimer(AnimDelayTimerHandle, this, &APlayerTrophy::resetIdle, playerMesh->GetSingleNodeInstance()->GetLength(), false); //Resets idle animation
} //end finalLoadChoice

void APlayerTrophy::resetIdle() { //Resets idle animation after timer is done
	tempSkele->PlayAnimation(tempAnimIdle, true);
	tempSkele = nullptr;
	tempAnimIdle = nullptr;
	GetWorldTimerManager().ClearTimer(AnimDelayTimerHandle);
}

void APlayerTrophy::loadCountess(USkeletalMeshComponent* playerMesh) {
	//Skeleton
	USkeletalMesh* SkeleCountessDefault = Cast<USkeletalMesh>(StaticLoadObject(USkeletalMesh::StaticClass(), NULL,
		TEXT("SkeletalMesh'/Game/ParagonCountess/Characters/Heroes/Countess/Meshes/SM_Countess.SM_Countess'")));
	//Animation Blueprint
	UAnimBlueprint* BP_AnimCountess = Cast<UAnimBlueprint>(StaticLoadObject(UAnimBlueprint::StaticClass(), NULL,
		TEXT("AnimBlueprint'/Game/ParagonCountess/Characters/Heroes/Countess/Countess_AnimBlueprint.Countess_AnimBlueprint'")));
	//Sound
	USoundCue* SoundCountess = Cast<USoundCue>(StaticLoadObject(USoundCue::StaticClass(), NULL,
		TEXT("SoundCue'/Game/ParagonCountess/Characters/Heroes/Countess/Sounds/SoundCues/Countess_Intro_Statement.Countess_Intro_Statement'")));
	//Level Start Animation
	UAnimSequence* AnimLevelStartCountess = Cast<UAnimSequence>(StaticLoadObject(UAnimSequence::StaticClass(), NULL,
		TEXT("AnimSequence'/Game/ParagonCountess/Characters/Heroes/Countess/Animations/LevelStart.LevelStart'")));
	//Idle Animation
	UAnimSequence* AnimIdleCountess = Cast<UAnimSequence>(StaticLoadObject(UAnimSequence::StaticClass(), NULL,
		TEXT("AnimSequence'/Game/ParagonCountess/Characters/Heroes/Countess/Animations/Idle_Relaxed.Idle_Relaxed'")));
	finalLoadChoice(playerMesh, SkeleCountessDefault, BP_AnimCountess, SoundCountess, AnimLevelStartCountess, AnimIdleCountess);
} //end Countess

void APlayerTrophy::loadDekker(USkeletalMeshComponent* playerMesh) {
	//Skeleton
	USkeletalMesh* SkeleDekkerDefault = Cast<USkeletalMesh>(StaticLoadObject(USkeletalMesh::StaticClass(), NULL,
		TEXT("SkeletalMesh'/Game/ParagonDekker/Characters/Heroes/Dekker/Meshes/Dekker.Dekker'")));
	//Animation Blueprint
	UAnimBlueprint* BP_AnimDekker = Cast<UAnimBlueprint>(StaticLoadObject(UAnimBlueprint::StaticClass(), NULL,
		TEXT("AnimBlueprint'/Game/ParagonDekker/Characters/Heroes/Dekker/Dekker_AnimBlueprint.Dekker_AnimBlueprint'")));
	//Sound
	USoundCue* SoundDekker = Cast<USoundCue>(StaticLoadObject(USoundCue::StaticClass(), NULL,
		TEXT("SoundCue'/Game/ParagonDekker/Characters/Heroes/Dekker/Sounds/SoundCues/Dekker_Intro_Statement.Dekker_Intro_Statement'")));
	//Level Start Animation
	UAnimSequence* AnimLevelStartDekker = Cast<UAnimSequence>(StaticLoadObject(UAnimSequence::StaticClass(), NULL,
		TEXT("AnimSequence'/Game/ParagonDekker/Characters/Heroes/Dekker/Animations/LevelStart.LevelStart'")));
	//Idle Animation
	UAnimSequence* AnimIdleDekker = Cast<UAnimSequence>(StaticLoadObject(UAnimSequence::StaticClass(), NULL,
		TEXT("AnimSequence'/Game/ParagonDekker/Characters/Heroes/Dekker/Animations/Idle.Idle'")));
	finalLoadChoice(playerMesh, SkeleDekkerDefault, BP_AnimDekker, SoundDekker, AnimLevelStartDekker, AnimIdleDekker);
} //end Dekker


void APlayerTrophy::loadFengMao(USkeletalMeshComponent* playerMesh) {
	//Skeleton
	USkeletalMesh* SkeleFengMaoDefault = Cast<USkeletalMesh>(StaticLoadObject(USkeletalMesh::StaticClass(), NULL,
		TEXT("SkeletalMesh'/Game/ParagonFengMao/Characters/Heroes/FengMao/Meshes/FengMao_GDC.FengMao_GDC'")));
	//Animation Blueprint
	UAnimBlueprint* BP_AnimFengMao = Cast<UAnimBlueprint>(StaticLoadObject(UAnimBlueprint::StaticClass(), NULL,
		TEXT("AnimBlueprint'/Game/ParagonFengMao/Characters/Heroes/FengMao/FengMao_AnimBlueprint.FengMao_AnimBlueprint'")));
	//Sound
	USoundCue* SoundFengMao = Cast<USoundCue>(StaticLoadObject(USoundCue::StaticClass(), NULL,
		TEXT("SoundCue'/Game/ParagonFengMao/Characters/Heroes/FengMao/Sounds/SoundCues/FengMao_Intro_Statement.FengMao_Intro_Statement'")));
	//Level Start Animation
	UAnimSequence* AnimLevelStartFengMao = Cast<UAnimSequence>(StaticLoadObject(UAnimSequence::StaticClass(), NULL,
		TEXT("AnimSequence'/Game/ParagonFengMao/Characters/Heroes/FengMao/Animations/SelectScreen_Start.SelectScreen_Start'")));
	//Idle Animation
	UAnimSequence* AnimIdleFengMao = Cast<UAnimSequence>(StaticLoadObject(UAnimSequence::StaticClass(), NULL,
		TEXT("AnimSequence'/Game/ParagonFengMao/Characters/Heroes/FengMao/Animations/Idle.Idle'")));
	finalLoadChoice(playerMesh, SkeleFengMaoDefault, BP_AnimFengMao, SoundFengMao, AnimLevelStartFengMao, AnimIdleFengMao);
} //end Feng Mao

void APlayerTrophy::loadGadget(USkeletalMeshComponent* playerMesh) {
	//Skeleton
	USkeletalMesh* SkeleGadgetDefault = Cast<USkeletalMesh>(StaticLoadObject(USkeletalMesh::StaticClass(), NULL,
		TEXT("SkeletalMesh'/Game/ParagonGadget/Characters/Heroes/Gadget/Meshes/Gadget.Gadget'")));
	//Animation Blueprint
	UAnimBlueprint* BP_AnimGadget = Cast<UAnimBlueprint>(StaticLoadObject(UAnimBlueprint::StaticClass(), NULL,
		TEXT("AnimBlueprint'/Game/ParagonGadget/Characters/Heroes/Gadget/Gadget_AnimBlueprint.Gadget_AnimBlueprint'")));
	//Sound
	USoundCue* SoundGadget = Cast<USoundCue>(StaticLoadObject(USoundCue::StaticClass(), NULL,
		TEXT("SoundCue'/Game/ParagonGadget/Characters/Heroes/Gadget/Sounds/Soundcues/Gadget_Intro_Statement.Gadget_Intro_Statement'")));
	//Level Start Animation
	UAnimSequence* AnimLevelStartGadget = Cast<UAnimSequence>(StaticLoadObject(UAnimSequence::StaticClass(), NULL,
		TEXT("AnimSequence'/Game/ParagonGadget/Characters/Heroes/Gadget/Animations/SelectScreen_Start.SelectScreen_Start'")));
	//Idle Animation
	UAnimSequence* AnimIdleGadget = Cast<UAnimSequence>(StaticLoadObject(UAnimSequence::StaticClass(), NULL,
		TEXT("AnimSequence'/Game/ParagonGadget/Characters/Heroes/Gadget/Animations/Idle.Idle'")));
	finalLoadChoice(playerMesh, SkeleGadgetDefault, BP_AnimGadget, SoundGadget, AnimLevelStartGadget, AnimIdleGadget);
} //end Gadget

void APlayerTrophy::loadGrim(USkeletalMeshComponent* playerMesh) {
	//Skeleton
	USkeletalMesh* SkeleGrimDefault = Cast<USkeletalMesh>(StaticLoadObject(USkeletalMesh::StaticClass(), NULL,
		TEXT("SkeletalMesh'/Game/ParagonGRIMexe/Characters/Heroes/GRIM/Meshes/GRIM_GDC.GRIM_GDC'")));
	//Animation Blueprint
	UAnimBlueprint* BP_AnimGrim = Cast<UAnimBlueprint>(StaticLoadObject(UAnimBlueprint::StaticClass(), NULL,
		TEXT("AnimBlueprint'/Game/ParagonGRIMexe/Characters/Heroes/GRIM/Grim_AnimBlueprint.Grim_AnimBlueprint'")));
	//Sound
	USoundCue* SoundGrim = Cast<USoundCue>(StaticLoadObject(USoundCue::StaticClass(), NULL,
		TEXT("SoundCue'/Game/ParagonGRIMexe/Characters/Heroes/GRIM/Sounds/SoundCues/GRIM_Intro_Boast.GRIM_Intro_Boast'")));
	//Level Start Animation
	UAnimSequence* AnimLevelStartGrim = Cast<UAnimSequence>(StaticLoadObject(UAnimSequence::StaticClass(), NULL,
		TEXT("AnimSequence'/Game/ParagonGRIMexe/Characters/Heroes/GRIM/Animations/SelectScreen_Start.SelectScreen_Start'")));
	//Idle Animation
	UAnimSequence* AnimIdleGrim = Cast<UAnimSequence>(StaticLoadObject(UAnimSequence::StaticClass(), NULL,
		TEXT("AnimSequence'/Game/ParagonGRIMexe/Characters/Heroes/GRIM/Animations/Idle.Idle'")));
	finalLoadChoice(playerMesh, SkeleGrimDefault, BP_AnimGrim, SoundGrim, AnimLevelStartGrim, AnimIdleGrim);
} //end Grim

void APlayerTrophy::loadGrux(USkeletalMeshComponent* playerMesh) {
	//Skeleton
	USkeletalMesh* SkeleGruxDefault = Cast<USkeletalMesh>(StaticLoadObject(USkeletalMesh::StaticClass(), NULL,
		TEXT("SkeletalMesh'/Game/ParagonGrux/Characters/Heroes/Grux/Meshes/Grux.Grux'")));
	//Animation Blueprint
	UAnimBlueprint* BP_AnimGrux = Cast<UAnimBlueprint>(StaticLoadObject(UAnimBlueprint::StaticClass(), NULL,
		TEXT("AnimBlueprint'/Game/ParagonGrux/Characters/Heroes/Grux/Grux_AnimBlueprint.Grux_AnimBlueprint'")));
	//Sound
	USoundCue* SoundGrux = Cast<USoundCue>(StaticLoadObject(USoundCue::StaticClass(), NULL,
		TEXT("SoundCue'/Game/ParagonGrux/Characters/Heroes/Grux/Sounds/SoundCues/Grux_Intro_Statement.Grux_Intro_Statement'")));
	//Level Start Animation
	UAnimSequence* AnimLevelStartGrux = Cast<UAnimSequence>(StaticLoadObject(UAnimSequence::StaticClass(), NULL,
		TEXT("AnimSequence'/Game/ParagonGrux/Characters/Heroes/Grux/Animations/LevelStart.LevelStart'")));
	//Idle Animation
	UAnimSequence* AnimIdleGrux = Cast<UAnimSequence>(StaticLoadObject(UAnimSequence::StaticClass(), NULL,
		TEXT("AnimSequence'/Game/ParagonGrux/Characters/Heroes/Grux/Animations/Idle.Idle'")));
	finalLoadChoice(playerMesh, SkeleGruxDefault, BP_AnimGrux, SoundGrux, AnimLevelStartGrux, AnimIdleGrux);
} //end Grux

void APlayerTrophy::loadHowitzer(USkeletalMeshComponent* playerMesh) {
	//Skeleton
	USkeletalMesh* SkeleHowitzerDefault = Cast<USkeletalMesh>(StaticLoadObject(USkeletalMesh::StaticClass(), NULL,
		TEXT("SkeletalMesh'/Game/ParagonHowitzer/Characters/Heroes/Howitzer/Meshes/Howitzer_GDC.Howitzer_GDC'")));
	//Animation Blueprint
	UAnimBlueprint* BP_AnimHowitzer = Cast<UAnimBlueprint>(StaticLoadObject(UAnimBlueprint::StaticClass(), NULL,
		TEXT("AnimBlueprint'/Game/ParagonHowitzer/Characters/Heroes/Howitzer/Howitzer_AnimBlueprint.Howitzer_AnimBlueprint'")));
	//Sound
	USoundCue* SoundHowitzer = Cast<USoundCue>(StaticLoadObject(USoundCue::StaticClass(), NULL,
		TEXT("SoundCue'/Game/ParagonHowitzer/Characters/Heroes/Howitzer/Sounds/SoundCues/Howitzer_Intro_Statement.Howitzer_Intro_Statement'")));
	//Level Start Animation
	UAnimSequence* AnimLevelStartHowitzer = Cast<UAnimSequence>(StaticLoadObject(UAnimSequence::StaticClass(), NULL,
		TEXT("AnimSequence'/Game/ParagonHowitzer/Characters/Heroes/Howitzer/Animations/LevelStart.LevelStart'")));
	//Idle Animation
	UAnimSequence* AnimIdleHowitzer = Cast<UAnimSequence>(StaticLoadObject(UAnimSequence::StaticClass(), NULL,
		TEXT("AnimSequence'/Game/ParagonHowitzer/Characters/Heroes/Howitzer/Animations/Idle.Idle'")));
	finalLoadChoice(playerMesh, SkeleHowitzerDefault, BP_AnimHowitzer, SoundHowitzer, AnimLevelStartHowitzer, AnimIdleHowitzer);
} //end Howitzer

void APlayerTrophy::loadKhaimera(USkeletalMeshComponent* playerMesh) {
	//Skeleton
	USkeletalMesh* SkeleKhaimeraDefault = Cast<USkeletalMesh>(StaticLoadObject(USkeletalMesh::StaticClass(), NULL,
		TEXT("SkeletalMesh'/Game/ParagonKhaimera/Characters/Heroes/Khaimera/Meshes/Khaimera.Khaimera'")));
	//Animation Blueprint
	UAnimBlueprint* BP_AnimKhaimera = Cast<UAnimBlueprint>(StaticLoadObject(UAnimBlueprint::StaticClass(), NULL,
		TEXT("AnimBlueprint'/Game/ParagonKhaimera/Characters/Heroes/Khaimera/Khaimera_AnimBlueprint.Khaimera_AnimBlueprint'")));
	//Sound
	USoundCue* SoundKhaimera = Cast<USoundCue>(StaticLoadObject(USoundCue::StaticClass(), NULL,
		TEXT("SoundCue'/Game/ParagonKhaimera/Characters/Heroes/Khaimera/Sounds/SoundCues/Khaimera_Intro_Statement.Khaimera_Intro_Statement'")));
	//Level Start Animation
	UAnimSequence* AnimLevelStartKhaimera = Cast<UAnimSequence>(StaticLoadObject(UAnimSequence::StaticClass(), NULL,
		TEXT("AnimSequence'/Game/ParagonKhaimera/Characters/Heroes/Khaimera/Animations/LevelStart.LevelStart'")));
	//Idle Animation
	UAnimSequence* AnimIdleKhaimera = Cast<UAnimSequence>(StaticLoadObject(UAnimSequence::StaticClass(), NULL,
		TEXT("AnimSequence'/Game/ParagonKhaimera/Characters/Heroes/Khaimera/Animations/Idle.Idle'")));
	finalLoadChoice(playerMesh, SkeleKhaimeraDefault, BP_AnimKhaimera, SoundKhaimera, AnimLevelStartKhaimera, AnimIdleKhaimera);
} //end Khaimera

void APlayerTrophy::loadKwang(USkeletalMeshComponent* playerMesh) {
	//Skeleton
	USkeletalMesh* SkeleKwangDefault = Cast<USkeletalMesh>(StaticLoadObject(USkeletalMesh::StaticClass(), NULL,
		TEXT("SkeletalMesh'/Game/ParagonKwang/Characters/Heroes/Kwang/Meshes/Kwang_GDC.Kwang_GDC'")));
	//Animation Blueprint
	UAnimBlueprint* BP_AnimKwang = Cast<UAnimBlueprint>(StaticLoadObject(UAnimBlueprint::StaticClass(), NULL,
		TEXT("AnimBlueprint'/Game/ParagonKhaimera/Characters/Heroes/Khaimera/Khaimera_AnimBlueprint.Khaimera_AnimBlueprint'")));
	//Sound
	USoundCue* SoundKwang = Cast<USoundCue>(StaticLoadObject(USoundCue::StaticClass(), NULL,
		TEXT("SoundCue'/Game/ParagonKwang/Characters/Heroes/Kwang/Sounds/SoundCues/Kwang_Intro_Statement.Kwang_Intro_Statement'")));
	//Level Start Animation
	UAnimSequence* AnimLevelStartKwang = Cast<UAnimSequence>(StaticLoadObject(UAnimSequence::StaticClass(), NULL,
		TEXT("AnimSequence'/Game/ParagonKwang/Characters/Heroes/Kwang/Animations/LevelStart.LevelStart'")));
	//Idle Animation
	UAnimSequence* AnimIdleKwang = Cast<UAnimSequence>(StaticLoadObject(UAnimSequence::StaticClass(), NULL,
		TEXT("AnimSequence'/Game/ParagonKwang/Characters/Heroes/Kwang/Animations/Idle.Idle'")));
	finalLoadChoice(playerMesh, SkeleKwangDefault, BP_AnimKwang, SoundKwang, AnimLevelStartKwang, AnimIdleKwang);
} //end Kwang

void APlayerTrophy::loadMurdock(USkeletalMeshComponent* playerMesh) {
	//Skeleton
	USkeletalMesh* SkeleMurdockDefault = Cast<USkeletalMesh>(StaticLoadObject(USkeletalMesh::StaticClass(), NULL,
		TEXT("SkeletalMesh'/Game/ParagonMurdock/Characters/Heroes/Murdock/Meshes/Murdock.Murdock'")));
	//Animation Blueprint
	UAnimBlueprint* BP_AnimMurdock = Cast<UAnimBlueprint>(StaticLoadObject(UAnimBlueprint::StaticClass(), NULL,
		TEXT("AnimBlueprint'/Game/ParagonMurdock/Characters/Heroes/Murdock/Murdock_AnimBlueprint.Murdock_AnimBlueprint'")));
	//Sound
	USoundCue* SoundMurdock = Cast<USoundCue>(StaticLoadObject(USoundCue::StaticClass(), NULL,
		TEXT("SoundCue'/Game/ParagonMurdock/Characters/Heroes/Murdock/Sounds/SoundCues/Murdock_Intro_Statement.Murdock_Intro_Statement'")));
	//Level Start Animation
	UAnimSequence* AnimLevelStartMurdock = Cast<UAnimSequence>(StaticLoadObject(UAnimSequence::StaticClass(), NULL,
		TEXT("AnimSequence'/Game/ParagonMurdock/Characters/Heroes/Murdock/Animations/LevelStart.LevelStart'")));
	//Idle Animation
	UAnimSequence* AnimIdleMurdock = Cast<UAnimSequence>(StaticLoadObject(UAnimSequence::StaticClass(), NULL,
		TEXT("AnimSequence'/Game/ParagonMurdock/Characters/Heroes/Murdock/Animations/Idle.Idle'")));
	finalLoadChoice(playerMesh, SkeleMurdockDefault, BP_AnimMurdock, SoundMurdock, AnimLevelStartMurdock, AnimIdleMurdock);
} //end Murdock

void APlayerTrophy::loadMuriel(USkeletalMeshComponent* playerMesh) {
	//Skeleton
	USkeletalMesh* SkeleMurielDefault = Cast<USkeletalMesh>(StaticLoadObject(USkeletalMesh::StaticClass(), NULL,
		TEXT("SkeletalMesh'/Game/ParagonMuriel/Characters/Heroes/Muriel/Meshes/Muriel_GDC.Muriel_GDC'")));
	//Animation Blueprint
	UAnimBlueprint* BP_AnimMuriel = Cast<UAnimBlueprint>(StaticLoadObject(UAnimBlueprint::StaticClass(), NULL,
		TEXT("AnimBlueprint'/Game/ParagonMuriel/Characters/Heroes/Muriel/Muriel_AnimBlueprint.Muriel_AnimBlueprint'")));
	//Sound
	USoundCue* SoundMuriel = Cast<USoundCue>(StaticLoadObject(USoundCue::StaticClass(), NULL,
		TEXT("SoundCue'/Game/ParagonMuriel/Characters/Heroes/Muriel/Sounds/SoundCues/Muriel_Intro_Statement.Muriel_Intro_Statement'")));
	//Level Start Animation
	UAnimSequence* AnimLevelStartMuriel = Cast<UAnimSequence>(StaticLoadObject(UAnimSequence::StaticClass(), NULL,
		TEXT("AnimSequence'/Game/ParagonMuriel/Characters/Heroes/Muriel/Animations/LevelStart.LevelStart'")));
	//Idle Animation
	UAnimSequence* AnimIdleMuriel = Cast<UAnimSequence>(StaticLoadObject(UAnimSequence::StaticClass(), NULL,
		TEXT("AnimSequence'/Game/ParagonMuriel/Characters/Heroes/Muriel/Animations/Idle.Idle'")));
	finalLoadChoice(playerMesh, SkeleMurielDefault, BP_AnimMuriel, SoundMuriel, AnimLevelStartMuriel, AnimIdleMuriel);
} //end Muriel

void APlayerTrophy::loadPhase(USkeletalMeshComponent* playerMesh) {
	//Skeleton
	USkeletalMesh* SkelePhaseDefault = Cast<USkeletalMesh>(StaticLoadObject(USkeletalMesh::StaticClass(), NULL, 
		TEXT("SkeletalMesh'/Game/ParagonPhase/Characters/Heroes/Phase/Meshes/Phase_GDC.Phase_GDC'")));
	//Animation Blueprint
	UAnimBlueprint* BP_AnimPhase = Cast<UAnimBlueprint>(StaticLoadObject(UAnimBlueprint::StaticClass(), NULL, 
		TEXT("AnimBlueprint'/Game/ParagonPhase/Characters/Heroes/Phase/Phase_AnimBlueprint.Phase_AnimBlueprint'")));
	//Sound
	USoundCue* SoundPhase = Cast<USoundCue>(StaticLoadObject(USoundCue::StaticClass(), NULL,
		TEXT("SoundCue'/Game/ParagonPhase/Characters/Heroes/Phase/Sounds/SoundCues/Phase_Intro_Statement.Phase_Intro_Statement'")));
	//Level Start Animation
	UAnimSequence* AnimLevelStartPhase = Cast<UAnimSequence>(StaticLoadObject(UAnimSequence::StaticClass(), NULL,
		TEXT("AnimSequence'/Game/ParagonPhase/Characters/Heroes/Phase/Animations/LevelStart.LevelStart'")));
	//Idle Animation
	UAnimSequence* AnimIdlePhase = Cast<UAnimSequence>(StaticLoadObject(UAnimSequence::StaticClass(), NULL,
		TEXT("AnimSequence'/Game/ParagonPhase/Characters/Heroes/Phase/Animations/Idle.Idle'")));
	finalLoadChoice(playerMesh, SkelePhaseDefault, BP_AnimPhase, SoundPhase, AnimLevelStartPhase, AnimIdlePhase);
} //end Phase

void APlayerTrophy::loadRampage(USkeletalMeshComponent* playerMesh) {
	//Skeleton
	USkeletalMesh* SkeleRampageDefault = Cast<USkeletalMesh>(StaticLoadObject(USkeletalMesh::StaticClass(), NULL,
		TEXT("SkeletalMesh'/Game/ParagonRampage/Characters/Heroes/Rampage/Meshes/Rampage.Rampage'")));
	//Animation Blueprint
	UAnimBlueprint* BP_AnimRampage = Cast<UAnimBlueprint>(StaticLoadObject(UAnimBlueprint::StaticClass(), NULL,
		TEXT("AnimBlueprint'/Game/ParagonRampage/Characters/Heroes/Rampage/Rampage_AnimBlueprint.Rampage_AnimBlueprint'")));
	//Sound
	USoundCue* SoundRampage = Cast<USoundCue>(StaticLoadObject(USoundCue::StaticClass(), NULL,
		TEXT("SoundCue'/Game/ParagonRampage/Characters/Heroes/Rampage/Sounds/SoundCues/Rampage_Intro_Statement.Rampage_Intro_Statement'")));
	//Level Start Animation
	UAnimSequence* AnimLevelStartRampage = Cast<UAnimSequence>(StaticLoadObject(UAnimSequence::StaticClass(), NULL,
		TEXT("AnimSequence'/Game/ParagonRampage/Characters/Heroes/Rampage/Animations/SelectScreen_Start.SelectScreen_Start'")));
	//Idle Animation
	UAnimSequence* AnimIdleRampage = Cast<UAnimSequence>(StaticLoadObject(UAnimSequence::StaticClass(), NULL,
		TEXT("AnimSequence'/Game/ParagonRampage/Characters/Heroes/Rampage/Animations/Idle.Idle'")));
	finalLoadChoice(playerMesh, SkeleRampageDefault, BP_AnimRampage, SoundRampage, AnimLevelStartRampage, AnimIdleRampage);
} //end Rampage

void APlayerTrophy::loadRiktor(USkeletalMeshComponent* playerMesh) {
	//Skeleton
	USkeletalMesh* SkeleRiktorDefault = Cast<USkeletalMesh>(StaticLoadObject(USkeletalMesh::StaticClass(), NULL,
		TEXT("SkeletalMesh'/Game/ParagonRiktor/Characters/Heroes/Riktor/Meshes/Riktor.Riktor'")));
	//Animation Blueprint
	UAnimBlueprint* BP_AnimRiktor = Cast<UAnimBlueprint>(StaticLoadObject(UAnimBlueprint::StaticClass(), NULL,
		TEXT("AnimBlueprint'/Game/ParagonRiktor/Characters/Heroes/Riktor/Riktor_AnimBlueprint.Riktor_AnimBlueprint'")));
	//Sound
	USoundCue* SoundRiktor = Cast<USoundCue>(StaticLoadObject(USoundCue::StaticClass(), NULL,
		TEXT("SoundCue'/Game/ParagonRiktor/Characters/Heroes/Riktor/Sounds/SoundCues/Riktor_Intro_Statement.Riktor_Intro_Statement'")));
	//Level Start Animation
	UAnimSequence* AnimLevelStartRiktor = Cast<UAnimSequence>(StaticLoadObject(UAnimSequence::StaticClass(), NULL,
		TEXT("AnimSequence'/Game/ParagonRiktor/Characters/Heroes/Riktor/Animations/LevelStart.LevelStart'")));
	//Idle Animation
	UAnimSequence* AnimIdleRiktor = Cast<UAnimSequence>(StaticLoadObject(UAnimSequence::StaticClass(), NULL,
		TEXT("AnimSequence'/Game/ParagonRiktor/Characters/Heroes/Riktor/Animations/Idle.Idle'")));
	finalLoadChoice(playerMesh, SkeleRiktorDefault, BP_AnimRiktor, SoundRiktor, AnimLevelStartRiktor, AnimIdleRiktor);
} //end Riktor

void APlayerTrophy::loadSerath(USkeletalMeshComponent* playerMesh) {
	//Skeleton
	USkeletalMesh* SkeleSerathDefault = Cast<USkeletalMesh>(StaticLoadObject(USkeletalMesh::StaticClass(), NULL,
		TEXT("SkeletalMesh'/Game/ParagonSerath/Characters/Heroes/Serath/Meshes/Serath.Serath'")));
	//Animation Blueprint
	UAnimBlueprint* BP_AnimSerath = Cast<UAnimBlueprint>(StaticLoadObject(UAnimBlueprint::StaticClass(), NULL,
		TEXT("AnimBlueprint'/Game/ParagonSerath/Characters/Heroes/Serath/Serath_AnimBlueprint.Serath_AnimBlueprint'")));
	//Sound
	USoundCue* SoundSerath = Cast<USoundCue>(StaticLoadObject(USoundCue::StaticClass(), NULL,
		TEXT("SoundCue'/Game/ParagonSerath/Characters/Heroes/Serath/Sounds/SoundCues/Serath_Intro_Statement.Serath_Intro_Statement'")));
	//Level Start Animation
	UAnimSequence* AnimLevelStartSerath = Cast<UAnimSequence>(StaticLoadObject(UAnimSequence::StaticClass(), NULL,
		TEXT("AnimSequence'/Game/ParagonSerath/Characters/Heroes/Serath/Animations/Level_Start.Level_Start'")));
	//Idle Animation
	UAnimSequence* AnimIdleSerath = Cast<UAnimSequence>(StaticLoadObject(UAnimSequence::StaticClass(), NULL,
		TEXT("AnimSequence'/Game/ParagonSerath/Characters/Heroes/Serath/Animations/Idle.Idle'")));
	finalLoadChoice(playerMesh, SkeleSerathDefault, BP_AnimSerath, SoundSerath, AnimLevelStartSerath, AnimIdleSerath);
} //end Serath

void APlayerTrophy::loadSevarog(USkeletalMeshComponent* playerMesh) {
	//Skeleton
	USkeletalMesh* SkeleSevarogDefault = Cast<USkeletalMesh>(StaticLoadObject(USkeletalMesh::StaticClass(), NULL,
		TEXT("SkeletalMesh'/Game/ParagonSevarog/Characters/Heroes/Sevarog/Meshes/Sevarog.Sevarog'")));
	//Animation Blueprint
	UAnimBlueprint* BP_AnimSevarog = Cast<UAnimBlueprint>(StaticLoadObject(UAnimBlueprint::StaticClass(), NULL,
		TEXT("AnimBlueprint'/Game/ParagonSevarog/Characters/Heroes/Sevarog/Sevarog_AnimBlueprint.Sevarog_AnimBlueprint'")));
	//Sound
	USoundCue* SoundSevarog = Cast<USoundCue>(StaticLoadObject(USoundCue::StaticClass(), NULL,
		TEXT("SoundCue'/Game/ParagonSevarog/Characters/Heroes/Sevarog/Sounds/SoundCues/Sevarog_Intro_Statement.Sevarog_Intro_Statement'")));
	//Level Start Animation
	UAnimSequence* AnimLevelStartSevarog = Cast<UAnimSequence>(StaticLoadObject(UAnimSequence::StaticClass(), NULL,
		TEXT("AnimSequence'/Game/ParagonSevarog/Characters/Heroes/Sevarog/Animations/LevelStart.LevelStart'")));
	//Idle Animation
	UAnimSequence* AnimIdleSevarog = Cast<UAnimSequence>(StaticLoadObject(UAnimSequence::StaticClass(), NULL,
		TEXT("AnimSequence'/Game/ParagonSevarog/Characters/Heroes/Sevarog/Animations/Idle.Idle'")));
	finalLoadChoice(playerMesh, SkeleSevarogDefault, BP_AnimSevarog, SoundSevarog, AnimLevelStartSevarog, AnimIdleSevarog);
} //end Sevarog

void APlayerTrophy::loadShinbi(USkeletalMeshComponent* playerMesh) {
	//Skeleton
	USkeletalMesh* SkeleShinbiDefault = Cast<USkeletalMesh>(StaticLoadObject(USkeletalMesh::StaticClass(), NULL,
		TEXT("SkeletalMesh'/Game/ParagonShinbi/Characters/Heroes/Shinbi/Meshes/Shinbi.Shinbi'")));
	//Animation Blueprint
	UAnimBlueprint* BP_AnimShinbi = Cast<UAnimBlueprint>(StaticLoadObject(UAnimBlueprint::StaticClass(), NULL,
		TEXT("AnimBlueprint'/Game/ParagonShinbi/Characters/Heroes/Shinbi/Shinbi_AnimBlueprint.Shinbi_AnimBlueprint'")));
	//Sound
	USoundCue* SoundShinbi = Cast<USoundCue>(StaticLoadObject(USoundCue::StaticClass(), NULL,
		TEXT("SoundCue'/Game/ParagonShinbi/Characters/Heroes/Shinbi/Sounds/SoundCues/Shinbi_Intro_Statement.Shinbi_Intro_Statement'")));
	//Level Start Animation
	UAnimSequence* AnimLevelStartShinbi = Cast<UAnimSequence>(StaticLoadObject(UAnimSequence::StaticClass(), NULL,
		TEXT("AnimSequence'/Game/ParagonShinbi/Characters/Heroes/Shinbi/Animations/LevelStart.LevelStart'")));
	//Idle Animation
	UAnimSequence* AnimIdleShinbi = Cast<UAnimSequence>(StaticLoadObject(UAnimSequence::StaticClass(), NULL,
		TEXT("AnimSequence'/Game/ParagonShinbi/Characters/Heroes/Shinbi/Animations/Idle.Idle'")));
	finalLoadChoice(playerMesh, SkeleShinbiDefault, BP_AnimShinbi, SoundShinbi, AnimLevelStartShinbi, AnimIdleShinbi);
} //end Shinbi

void APlayerTrophy::loadTwinblast(USkeletalMeshComponent* playerMesh) {
	//Skeleton
	USkeletalMesh* SkeleTwinblastDefault = Cast<USkeletalMesh>(StaticLoadObject(USkeletalMesh::StaticClass(), NULL,
		TEXT("SkeletalMesh'/Game/ParagonTwinblast/Characters/Heroes/TwinBlast/Meshes/TwinBlast.TwinBlast'")));
	//Animation Blueprint
	UAnimBlueprint* BP_AnimTwinblast = Cast<UAnimBlueprint>(StaticLoadObject(UAnimBlueprint::StaticClass(), NULL,
		TEXT("AnimBlueprint'/Game/ParagonTwinblast/Characters/Heroes/TwinBlast/Twinblast_AnimBlueprint.Twinblast_AnimBlueprint'")));
	//Sound
	USoundCue* SoundTwinblast = Cast<USoundCue>(StaticLoadObject(USoundCue::StaticClass(), NULL,
		TEXT("SoundCue'/Game/ParagonTwinblast/Characters/Heroes/TwinBlast/Sounds/SoundCues/Twinblast_Intro_Statement.Twinblast_Intro_Statement'")));
	//Level Start Animation
	UAnimSequence* AnimLevelStartTwinblast = Cast<UAnimSequence>(StaticLoadObject(UAnimSequence::StaticClass(), NULL,
		TEXT("AnimSequence'/Game/ParagonTwinblast/Characters/Heroes/TwinBlast/Animations/SelectScreen_Start.SelectScreen_Start'")));
	//Idle Animation
	UAnimSequence* AnimIdleTwinblast = Cast<UAnimSequence>(StaticLoadObject(UAnimSequence::StaticClass(), NULL,
		TEXT("AnimSequence'/Game/ParagonTwinblast/Characters/Heroes/TwinBlast/Animations/Idle.Idle'")));
	finalLoadChoice(playerMesh, SkeleTwinblastDefault, BP_AnimTwinblast, SoundTwinblast, AnimLevelStartTwinblast, AnimIdleTwinblast);
} //end Twinblast

USkeletalMeshComponent* APlayerTrophy::getPlayerMesh(int playerNum) {
	switch (playerNum) {
	case 1:
		return PlayerOneMesh;
		break;
	case 2:
		return PlayerTwoMesh;
		break;
	case 3:
		return PlayerThreeMesh;
		break;
	case 4:
		return PlayerFourMesh;
		break;
	default:
		//Something bad happened
		return PlayerOneMesh; //Should never happen, but just in case so the compiler doesn't cry.
		break;
	} //end switch
}

void APlayerTrophy::handleCamera() {
	//If all four 
	bool shortOne = true;
	bool shortTwo = true;
	bool shortThree = true;
	bool shortFour = true;

	//Checks each playerChoice for all 4 characters, if tall is detected then the ifs skip the subsequent if statements
	switch (playerOneChoice) {
	case ESelectedChar::SC_Countess:
		shortOne = true;
		break;
	case ESelectedChar::SC_Dekker:
		shortOne = true;
		break;
	case ESelectedChar::SC_FengMao:
		shortOne = true;
		break;
	case ESelectedChar::SC_Gadget:
		shortOne = true;
		break;
	case ESelectedChar::SC_Grim: //Tall
		shortOne = false;
		break;
	case ESelectedChar::SC_Grux:
		shortOne = true;
		break;
	case ESelectedChar::SC_Howitzer:
		shortOne = true;
		break;
	case ESelectedChar::SC_Khaimera:
		shortOne = true;
		break;
	case ESelectedChar::SC_Kwang:
		shortOne = true;
		break;
	case ESelectedChar::SC_Murdock:
		shortOne = true;
		break;
	case ESelectedChar::SC_Muriel:
		shortOne = true;
		break;
	case ESelectedChar::SC_Phase:
		shortOne = true;
		break;
	case ESelectedChar::SC_Rampage:
		shortOne = true;
		break;
	case ESelectedChar::SC_Riktor: //Tall
		shortOne = false;
		break;
	case ESelectedChar::SC_Serath:
		shortOne = true;
		break;
	case ESelectedChar::SC_Sevarog: //Tall
		shortOne = false;
		break;
	case ESelectedChar::SC_Shinbi:
		shortOne = true;
		break;
	case ESelectedChar::SC_Twinblast:
		shortOne = true;
		break;
	default:
		UE_LOG(LogTemp, Warning, TEXT("Default shortOne reached, DEBUG THIS"));
		break;
	} //end switch

	if (shortOne) {
		switch (playerTwoChoice) {
		case ESelectedChar::SC_Countess:
			shortTwo = true;
			break;
		case ESelectedChar::SC_Dekker:
			shortTwo = true;
			break;
		case ESelectedChar::SC_FengMao:
			shortTwo = true;
			break;
		case ESelectedChar::SC_Gadget:
			shortTwo = true;
			break;
		case ESelectedChar::SC_Grim: //Tall
			shortTwo = false;
			break;
		case ESelectedChar::SC_Grux:
			shortTwo = true;
			break;
		case ESelectedChar::SC_Howitzer:
			shortTwo = true;
			break;
		case ESelectedChar::SC_Khaimera:
			shortTwo = true;
			break;
		case ESelectedChar::SC_Kwang:
			shortTwo = true;
			break;
		case ESelectedChar::SC_Murdock:
			shortTwo = true;
			break;
		case ESelectedChar::SC_Muriel:
			shortTwo = true;
			break;
		case ESelectedChar::SC_Phase:
			shortTwo = true;
			break;
		case ESelectedChar::SC_Rampage:
			shortTwo = true;
			break;
		case ESelectedChar::SC_Riktor: //Tall
			shortTwo = false;
			break;
		case ESelectedChar::SC_Serath:
			shortTwo = true;
			break;
		case ESelectedChar::SC_Sevarog: //Tall
			shortTwo = false;
			break;
		case ESelectedChar::SC_Shinbi:
			shortTwo = true;
			break;
		case ESelectedChar::SC_Twinblast:
			shortTwo = true;
			break;
		default:
			UE_LOG(LogTemp, Warning, TEXT("Default shortTwo reached, DEBUG THIS"));
			break;
		}//end switch
	} //end shortOne if
	
	if (shortOne && shortTwo) {
		switch (playerThreeChoice) {
		case ESelectedChar::SC_Countess:
			shortThree = true;
			break;
		case ESelectedChar::SC_Dekker:
			shortThree = true;
			break;
		case ESelectedChar::SC_FengMao:
			shortThree = true;
			break;
		case ESelectedChar::SC_Gadget:
			shortThree = true;
			break;
		case ESelectedChar::SC_Grim: //Tall
			shortThree = false;
			break;
		case ESelectedChar::SC_Grux:
			shortThree = true;
			break;
		case ESelectedChar::SC_Howitzer:
			shortThree = true;
			break;
		case ESelectedChar::SC_Khaimera:
			shortThree = true;
			break;
		case ESelectedChar::SC_Kwang:
			shortThree = true;
			break;
		case ESelectedChar::SC_Murdock:
			shortThree = true;
			break;
		case ESelectedChar::SC_Muriel:
			shortThree = true;
			break;
		case ESelectedChar::SC_Phase:
			shortThree = true;
			break;
		case ESelectedChar::SC_Rampage:
			shortThree = true;
			break;
		case ESelectedChar::SC_Riktor: //Tall
			shortThree = false;
			break;
		case ESelectedChar::SC_Serath:
			shortThree = true;
			break;
		case ESelectedChar::SC_Sevarog: //Tall
			shortThree = false;
			break;
		case ESelectedChar::SC_Shinbi:
			shortThree = true;
			break;
		case ESelectedChar::SC_Twinblast:
			shortThree = true;
			break;
		default:
			UE_LOG(LogTemp, Warning, TEXT("Default shortThree reached, DEBUG THIS"));
			break;
		}//end switch
	} //end shortOne & shortTwo if

	if (shortOne && shortTwo && shortThree) {
		switch (playerFourChoice) {
		case ESelectedChar::SC_Countess:
			shortFour = true;
			break;
		case ESelectedChar::SC_Dekker:
			shortFour = true;
			break;
		case ESelectedChar::SC_FengMao:
			shortFour = true;
			break;
		case ESelectedChar::SC_Gadget:
			shortFour = true;
			break;
		case ESelectedChar::SC_Grim: //Tall
			shortFour = false;
			break;
		case ESelectedChar::SC_Grux:
			shortFour = true;
			break;
		case ESelectedChar::SC_Howitzer:
			shortFour = true;
			break;
		case ESelectedChar::SC_Khaimera:
			shortFour = true;
			break;
		case ESelectedChar::SC_Kwang:
			shortFour = true;
			break;
		case ESelectedChar::SC_Murdock:
			shortFour = true;
			break;
		case ESelectedChar::SC_Muriel:
			shortFour = true;
			break;
		case ESelectedChar::SC_Phase:
			shortFour = true;
			break;
		case ESelectedChar::SC_Rampage:
			shortFour = true;
			break;
		case ESelectedChar::SC_Riktor: //Tall
			shortFour = false;
			break;
		case ESelectedChar::SC_Serath:
			shortFour = true;
			break;
		case ESelectedChar::SC_Sevarog: //Tall
			shortFour = false;
			break;
		case ESelectedChar::SC_Shinbi:
			shortFour = true;
			break;
		case ESelectedChar::SC_Twinblast:
			shortFour = true;
			break;
		default:
			UE_LOG(LogTemp, Warning, TEXT("Default shortFour reached, DEBUG THIS"));
			break;
		}//end switch
	} //end shortOne & shortTwo & shortThree if

	if (shortOne && shortTwo && shortThree && shortFour) {
		//Switch camera to normal camera in case tall was previously chosen
		TallCamera->SetActive(false);
		Camera->SetActive(true);
	}
	else {
		//Switch camera to tall camera
		Camera->SetActive(false);
		TallCamera->SetActive(true);
	}
}

void APlayerTrophy::removeCharacter(int playerNum) { 
	UE_LOG(LogTemp, Warning, TEXT("Removing character"));
	getPlayerMesh(playerNum)->SetVisibility(false);
}