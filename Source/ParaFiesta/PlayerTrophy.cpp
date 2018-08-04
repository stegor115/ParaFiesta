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
//SoundCue goes in the header file for some reason
#include "Runtime/CoreUObject/Public/UObject/ConstructorHelpers.h"


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

	//Order of below: Find skeleton, animation blueprint, sound, level start animation, idle animation, pass into final load function
	switch (playerChoice) {
	case ESelectedChar::SC_Countess:
		loadCountess(playerMesh);
		break;
	case ESelectedChar::SC_Dekker:
		loadDekker(playerMesh);
		break;
	case ESelectedChar::SC_FengMao:
		loadFengMao(playerMesh);
		break;
	case ESelectedChar::SC_Gadget:
		loadGadget(playerMesh);
		break;
	case ESelectedChar::SC_Grim:
		loadGrim(playerMesh);
		break;
	case ESelectedChar::SC_Grux:
		loadGrux(playerMesh);
		break;
	case ESelectedChar::SC_Howitzer:
		loadHowitzer(playerMesh);
		break;
	case ESelectedChar::SC_Khaimera:
		loadKhaimera(playerMesh);
		break;
	case ESelectedChar::SC_Kwang:
		loadKwang(playerMesh);
		break;
	case ESelectedChar::SC_Murdock:
		loadMurdock(playerMesh);
		break;
	case ESelectedChar::SC_Muriel:
		loadMuriel(playerMesh);
		break;
	case ESelectedChar::SC_Phase:
		loadPhase(playerMesh);
		break;
	case ESelectedChar::SC_Rampage:
		loadRampage(playerMesh);
		break;
	case ESelectedChar::SC_Riktor:
		loadRiktor(playerMesh);
		break;
	case ESelectedChar::SC_Serath:
		loadSerath(playerMesh);
		break;
	case ESelectedChar::SC_Sevarog:
		loadSevarog(playerMesh);
		break;
	case ESelectedChar::SC_Shinbi:
		loadShinbi(playerMesh);
		break;
	case ESelectedChar::SC_Twinblast:
		loadTwinblast(playerMesh);
		break;
	default:
		//Something very bad happened if you got here
		break;
	} //end switch
} //end startLoadChoice

void APlayerTrophy::finalLoadChoice(USkeletalMeshComponent* playerMesh, USkeletalMesh* skeleton, UAnimBlueprint* animBlueprint, 
									USoundCue* soundIntro, UAnimSequence* animLevelStart, UAnimSequence* animIdle)
{ //Pass in skeleton, animation blueprint, sound, level start animation, idle animation
	//TO:DO pass all LoadCharacter to this function and set parameters to pass all the found data in to load it all
} //end finalLoadChoice

void APlayerTrophy::loadCountess(USkeletalMeshComponent* playerMesh) {
	//Skeleton
	ConstructorHelpers::FObjectFinder<USkeletalMesh>SkeleCountessDefault(TEXT("SkeletalMesh'/Game/ParagonCountess/Characters/Heroes/Countess/Meshes/SM_Countess.SM_Countess''"));
	//Animation Blueprint
	ConstructorHelpers::FObjectFinder<UAnimBlueprint>BP_AnimCountess(TEXT("AnimBlueprint'/Game/ParagonCountess/Characters/Heroes/Countess/Countess_AnimBlueprint.Countess_AnimBlueprint'"));
	//Sound
	ConstructorHelpers::FObjectFinder<USoundCue>SoundCountess(TEXT("SoundCue'/Game/ParagonCountess/Characters/Heroes/Countess/Sounds/SoundCues/Countess_Intro_Statement.Countess_Intro_Statement'"));
	//Level Start Animation
	ConstructorHelpers::FObjectFinder<UAnimSequence>AnimLevelStartCountess(TEXT("AnimSequence'/Game/ParagonCountess/Characters/Heroes/Countess/Animations/LevelStart.LevelStart'"));
	//Idle Animation
	ConstructorHelpers::FObjectFinder<UAnimSequence>AnimIdleCountess(TEXT("AnimSequence'/Game/ParagonCountess/Characters/Heroes/Countess/Animations/Idle_Relaxed.Idle_Relaxed'"));
	finalLoadChoice(playerMesh, SkeleCountessDefault.Object, BP_AnimCountess.Object, SoundCountess.Object, AnimLevelStartCountess.Object, AnimIdleCountess.Object); //TO-DO: Copy this to all other characters
} //end Countess

void APlayerTrophy::loadDekker(USkeletalMeshComponent* playerMesh) {
	//Skeleton
	ConstructorHelpers::FObjectFinder<USkeletalMesh>SkeleDekkerDefault(TEXT("SkeletalMesh'/Game/ParagonDekker/Characters/Heroes/Dekker/Meshes/Dekker.Dekker'"));
	//Animation Blueprint
	ConstructorHelpers::FObjectFinder<UAnimBlueprint>BP_AnimDekker(TEXT("AnimBlueprint'/Game/ParagonDekker/Characters/Heroes/Dekker/Dekker_AnimBlueprint.Dekker_AnimBlueprint'"));
	//Sound
	ConstructorHelpers::FObjectFinder<USoundCue>SoundDekker(TEXT("SoundCue'/Game/ParagonDekker/Characters/Heroes/Dekker/Sounds/SoundCues/Dekker_Intro_Statement.Dekker_Intro_Statement'"));
	//Level Start Animation
	ConstructorHelpers::FObjectFinder<UAnimSequence>AnimLevelStartDekker(TEXT("AnimSequence'/Game/ParagonDekker/Characters/Heroes/Dekker/Animations/LevelStart.LevelStart'"));
	//Idle Animation
	ConstructorHelpers::FObjectFinder<UAnimSequence>AnimIdleDekker(TEXT("AnimSequence'/Game/ParagonDekker/Characters/Heroes/Dekker/Animations/Idle.Idle'"));
} //end Dekker


void APlayerTrophy::loadFengMao(USkeletalMeshComponent* playerMesh) {
	//Skeleton
	ConstructorHelpers::FObjectFinder<USkeletalMesh>SkeleFengMaoDefault(TEXT("SkeletalMesh'/Game/ParagonFengMao/Characters/Heroes/FengMao/Meshes/FengMao_GDC.FengMao_GDC'"));
	//Animation Blueprint
	ConstructorHelpers::FObjectFinder<UAnimBlueprint>BP_AnimFengMao(TEXT("AnimBlueprint'/Game/ParagonFengMao/Characters/Heroes/FengMao/FengMao_AnimBlueprint.FengMao_AnimBlueprint'"));
	//Sound
	ConstructorHelpers::FObjectFinder<USoundCue>SoundFengMao(TEXT("SoundCue'/Game/ParagonFengMao/Characters/Heroes/FengMao/Sounds/SoundCues/FengMao_Intro_Statement.FengMao_Intro_Statement'"));
	//Level Start Animation
	ConstructorHelpers::FObjectFinder<UAnimSequence>AnimLevelStartFengMao(TEXT("AnimSequence'/Game/ParagonFengMao/Characters/Heroes/FengMao/Animations/SelectScreen_Start.SelectScreen_Start'"));
	//Idle Animation
	ConstructorHelpers::FObjectFinder<UAnimSequence>AnimIdleFengMao(TEXT("AnimSequence'/Game/ParagonFengMao/Characters/Heroes/FengMao/Animations/Idle.Idle'"));
} //end Feng Mao

void APlayerTrophy::loadGadget(USkeletalMeshComponent* playerMesh) {
	//Skeleton
	ConstructorHelpers::FObjectFinder<USkeletalMesh>SkeleGadgetDefault(TEXT("SkeletalMesh'/Game/ParagonGadget/Characters/Heroes/Gadget/Meshes/Gadget.Gadget'"));
	//Animation Blueprint
	ConstructorHelpers::FObjectFinder<UAnimBlueprint>BP_AnimGadget(TEXT("AnimBlueprint'/Game/ParagonGadget/Characters/Heroes/Gadget/Gadget_AnimBlueprint.Gadget_AnimBlueprint'"));
	//Sound
	ConstructorHelpers::FObjectFinder<USoundCue>SoundGadget(TEXT("SoundCue'/Game/ParagonGadget/Characters/Heroes/Gadget/Sounds/Soundcues/Gadget_Intro_Statement.Gadget_Intro_Statement'"));
	//Level Start Animation
	ConstructorHelpers::FObjectFinder<UAnimSequence>AnimLevelStartGadget(TEXT("AnimSequence'/Game/ParagonGadget/Characters/Heroes/Gadget/Animations/SelectScreen_Start.SelectScreen_Start'"));
	//Idle Animation
	ConstructorHelpers::FObjectFinder<UAnimSequence>AnimIdleGadget(TEXT("AnimSequence'/Game/ParagonGadget/Characters/Heroes/Gadget/Animations/Idle.Idle'"));
} //end Gadget

void APlayerTrophy::loadGrim(USkeletalMeshComponent* playerMesh) {
	//Skeleton
	ConstructorHelpers::FObjectFinder<USkeletalMesh>SkeleGrimDefault(TEXT("SkeletalMesh'/Game/ParagonGRIMexe/Characters/Heroes/GRIM/Meshes/GRIM_GDC.GRIM_GDC'"));
	//Animation Blueprint
	ConstructorHelpers::FObjectFinder<UAnimBlueprint>BP_AnimGrim(TEXT("AnimBlueprint'/Game/ParagonGRIMexe/Characters/Heroes/GRIM/Grim_AnimBlueprint.Grim_AnimBlueprint'"));
	//Sound
	ConstructorHelpers::FObjectFinder<USoundCue>SoundGrim(TEXT("SoundCue'/Game/ParagonGRIMexe/Characters/Heroes/GRIM/Sounds/SoundCues/GRIM_Intro_Boast.GRIM_Intro_Boast'"));
	//Level Start Animation
	ConstructorHelpers::FObjectFinder<UAnimSequence>AnimLevelStartGrim(TEXT("AnimSequence'/Game/ParagonGRIMexe/Characters/Heroes/GRIM/Animations/SelectScreen_Start.SelectScreen_Start'"));
	//Idle Animation
	ConstructorHelpers::FObjectFinder<UAnimSequence>AnimIdleGrim(TEXT("AnimSequence'/Game/ParagonGRIMexe/Characters/Heroes/GRIM/Animations/Idle.Idle'"));
} //end Grim

void APlayerTrophy::loadGrux(USkeletalMeshComponent* playerMesh) {
	//Skeleton
	ConstructorHelpers::FObjectFinder<USkeletalMesh>SkeleGruxDefault(TEXT("SkeletalMesh'/Game/ParagonGrux/Characters/Heroes/Grux/Meshes/Grux.Grux'"));
	//Animation Blueprint
	ConstructorHelpers::FObjectFinder<UAnimBlueprint>BP_AnimGrux(TEXT("AnimBlueprint'/Game/ParagonGrux/Characters/Heroes/Grux/Grux_AnimBlueprint.Grux_AnimBlueprint'"));
	//Sound
	ConstructorHelpers::FObjectFinder<USoundCue>SoundGrux(TEXT("SoundCue'/Game/ParagonGrux/Characters/Heroes/Grux/Sounds/SoundCues/Grux_Intro_Statement.Grux_Intro_Statement'"));
	//Level Start Animation
	ConstructorHelpers::FObjectFinder<UAnimSequence>AnimLevelStartGrux(TEXT("AnimSequence'/Game/ParagonGrux/Characters/Heroes/Grux/Animations/LevelStart.LevelStart'"));
	//Idle Animation
	ConstructorHelpers::FObjectFinder<UAnimSequence>AnimIdleGrux(TEXT("AnimSequence'/Game/ParagonGrux/Characters/Heroes/Grux/Animations/Idle.Idle'"));
} //end Grux

void APlayerTrophy::loadHowitzer(USkeletalMeshComponent* playerMesh) {
	//Skeleton
	ConstructorHelpers::FObjectFinder<USkeletalMesh>SkeleHowlitzerDefault(TEXT("SkeletalMesh'/Game/ParagonHowitzer/Characters/Heroes/Howitzer/Meshes/Howitzer_GDC.Howitzer_GDC'"));
	//Animation Blueprint
	ConstructorHelpers::FObjectFinder<UAnimBlueprint>BP_AnimHowitzer(TEXT("AnimBlueprint'/Game/ParagonHowitzer/Characters/Heroes/Howitzer/Howitzer_AnimBlueprint.Howitzer_AnimBlueprint'"));
	//Sound
	ConstructorHelpers::FObjectFinder<USoundCue>SoundHowitzer(TEXT("SoundCue'/Game/ParagonHowitzer/Characters/Heroes/Howitzer/Sounds/SoundCues/Howitzer_Intro_Statement.Howitzer_Intro_Statement'"));
	//Level Start Animation
	ConstructorHelpers::FObjectFinder<UAnimSequence>AnimLevelStartHowitzer(TEXT("AnimSequence'/Game/ParagonHowitzer/Characters/Heroes/Howitzer/Animations/LevelStart.LevelStart'"));
	//Idle Animation
	ConstructorHelpers::FObjectFinder<UAnimSequence>AnimIdleHowitzer(TEXT("AnimSequence'/Game/ParagonHowitzer/Characters/Heroes/Howitzer/Animations/Idle.Idle'"));
} //end Howitzer

void APlayerTrophy::loadKhaimera(USkeletalMeshComponent* playerMesh) {
	//Skeleton
	ConstructorHelpers::FObjectFinder<USkeletalMesh>SkeleKhaimeraDefault(TEXT("SkeletalMesh'/Game/ParagonKhaimera/Characters/Heroes/Khaimera/Meshes/Khaimera.Khaimera'"));
	//Animation Blueprint
	ConstructorHelpers::FObjectFinder<UAnimBlueprint>BP_AnimKhaimera(TEXT("AnimBlueprint'/Game/ParagonKhaimera/Characters/Heroes/Khaimera/Khaimera_AnimBlueprint.Khaimera_AnimBlueprint'"));
	//Sound
	ConstructorHelpers::FObjectFinder<USoundCue>SoundKhaimera(TEXT("SoundCue'/Game/ParagonKhaimera/Characters/Heroes/Khaimera/Sounds/SoundCues/Khaimera_Intro_Statement.Khaimera_Intro_Statement'"));
	//Level Start Animation
	ConstructorHelpers::FObjectFinder<UAnimSequence>AnimLevelStartKhaimera(TEXT("AnimSequence'/Game/ParagonKhaimera/Characters/Heroes/Khaimera/Animations/LevelStart.LevelStart'"));
	//Idle Animation
	ConstructorHelpers::FObjectFinder<UAnimSequence>AnimIdleKhaimera(TEXT("AnimSequence'/Game/ParagonKhaimera/Characters/Heroes/Khaimera/Animations/Idle.Idle'"));
} //end Khaimera

void APlayerTrophy::loadKwang(USkeletalMeshComponent* playerMesh) {
	//Skeleton
	ConstructorHelpers::FObjectFinder<USkeletalMesh>SkeleKwangDefault(TEXT("SkeletalMesh'/Game/ParagonKwang/Characters/Heroes/Kwang/Meshes/Kwang_GDC.Kwang_GDC'"));
	//Animation Blueprint
	ConstructorHelpers::FObjectFinder<UAnimBlueprint>BP_AnimKwang(TEXT("AnimBlueprint'/Game/ParagonKhaimera/Characters/Heroes/Khaimera/Khaimera_AnimBlueprint.Khaimera_AnimBlueprint'"));
	//Sound
	ConstructorHelpers::FObjectFinder<USoundCue>SoundKwang(TEXT("SoundCue'/Game/ParagonKwang/Characters/Heroes/Kwang/Sounds/SoundCues/Kwang_Intro_Statement.Kwang_Intro_Statement'"));
	//Level Start Animation
	ConstructorHelpers::FObjectFinder<UAnimSequence>AnimLevelStartKwang(TEXT("AnimSequence'/Game/ParagonKwang/Characters/Heroes/Kwang/Animations/LevelStart.LevelStart'"));
	//Idle Animation
	ConstructorHelpers::FObjectFinder<UAnimSequence>AnimIdleKwang(TEXT("AnimSequence'/Game/ParagonKwang/Characters/Heroes/Kwang/Animations/Idle.Idle'"));
} //end Kwang

void APlayerTrophy::loadMurdock(USkeletalMeshComponent* playerMesh) {
	//Skeleton
	ConstructorHelpers::FObjectFinder<USkeletalMesh>SkeleMurdockDefault(TEXT("SkeletalMesh'/Game/ParagonMurdock/Characters/Heroes/Murdock/Meshes/Murdock.Murdock'"));
	//Animation Blueprint
	ConstructorHelpers::FObjectFinder<UAnimBlueprint>BP_AnimMurdock(TEXT("AnimBlueprint'/Game/ParagonMurdock/Characters/Heroes/Murdock/Murdock_AnimBlueprint.Murdock_AnimBlueprint'"));
	//Sound
	ConstructorHelpers::FObjectFinder<USoundCue>SoundMurdock(TEXT("SoundCue'/Game/ParagonMurdock/Characters/Heroes/Murdock/Sounds/SoundCues/Murdock_Intro_Statement.Murdock_Intro_Statement'"));
	//Level Start Animation
	ConstructorHelpers::FObjectFinder<UAnimSequence>AnimLevelStartKwang(TEXT("AnimSequence'/Game/ParagonMurdock/Characters/Heroes/Murdock/Animations/LevelStart.LevelStart'"));
	//Idle Animation
	ConstructorHelpers::FObjectFinder<UAnimSequence>AnimIdleMurdock(TEXT("AnimSequence'/Game/ParagonMurdock/Characters/Heroes/Murdock/Animations/Idle.Idle'"));
} //end Murdock

void APlayerTrophy::loadMuriel(USkeletalMeshComponent* playerMesh) {
	//Skeleton
	ConstructorHelpers::FObjectFinder<USkeletalMesh>SkeleMurielDefault(TEXT("SkeletalMesh'/Game/ParagonMuriel/Characters/Heroes/Muriel/Meshes/Muriel_GDC.Muriel_GDC'"));
	//Animation Blueprint
	ConstructorHelpers::FObjectFinder<UAnimBlueprint>BP_AnimMuriel(TEXT("AnimBlueprint'/Game/ParagonMuriel/Characters/Heroes/Muriel/Muriel_AnimBlueprint.Muriel_AnimBlueprint'"));
	//Sound
	ConstructorHelpers::FObjectFinder<USoundCue>SoundMuriel(TEXT("SoundCue'/Game/ParagonMuriel/Characters/Heroes/Muriel/Sounds/SoundCues/Muriel_Intro_Statement.Muriel_Intro_Statement'"));
	//Level Start Animation
	ConstructorHelpers::FObjectFinder<UAnimSequence>AnimLevelStartMuriel(TEXT("AnimSequence'/Game/ParagonMuriel/Characters/Heroes/Muriel/Animations/LevelStart.LevelStart'"));
	//Idle Animation
	ConstructorHelpers::FObjectFinder<UAnimSequence>AnimIdleMuriel(TEXT("AnimSequence'/Game/ParagonMuriel/Characters/Heroes/Muriel/Animations/Idle.Idle'"));
} //end Muriel

void APlayerTrophy::loadPhase(USkeletalMeshComponent* playerMesh) {
	//Skeleton
	ConstructorHelpers::FObjectFinder<USkeletalMesh>SkelePhaseDefault(TEXT("SkeletalMesh'/Game/ParagonPhase/Characters/Heroes/Phase/Meshes/Phase_GDC.Phase_GDC'"));
	//Animation Blueprint
	ConstructorHelpers::FObjectFinder<UAnimBlueprint>BP_AnimPhase(TEXT("AnimBlueprint'/Game/ParagonPhase/Characters/Heroes/Phase/Phase_AnimBlueprint.Phase_AnimBlueprint'"));
	//Sound
	ConstructorHelpers::FObjectFinder<USoundCue>SoundPhase(TEXT("SoundCue'/Game/ParagonPhase/Characters/Heroes/Phase/Sounds/SoundCues/Phase_Intro_Statement.Phase_Intro_Statement'"));
	//Level Start Animation
	ConstructorHelpers::FObjectFinder<UAnimSequence>AnimLevelStartPhase(TEXT("AnimSequence'/Game/ParagonPhase/Characters/Heroes/Phase/Animations/LevelStart.LevelStart'"));
	//Idle Animation
	ConstructorHelpers::FObjectFinder<UAnimSequence>AnimIdlePhase(TEXT("AnimSequence'/Game/ParagonPhase/Characters/Heroes/Phase/Animations/Idle.Idle'"));
} //end Phase

void APlayerTrophy::loadRampage(USkeletalMeshComponent* playerMesh) {
	//Skeleton
	ConstructorHelpers::FObjectFinder<USkeletalMesh>SkeleRampageDefault(TEXT("SkeletalMesh'/Game/ParagonRampage/Characters/Heroes/Rampage/Meshes/Rampage.Rampage'"));
	//Animation Blueprint
	ConstructorHelpers::FObjectFinder<UAnimBlueprint>BP_AnimRampage(TEXT("AnimBlueprint'/Game/ParagonRampage/Characters/Heroes/Rampage/Rampage_AnimBlueprint.Rampage_AnimBlueprint'"));
	//Sound
	ConstructorHelpers::FObjectFinder<USoundCue>SoundRampage(TEXT("SoundCue'/Game/ParagonRampage/Characters/Heroes/Rampage/Sounds/SoundCues/Rampage_Intro_Statement.Rampage_Intro_Statement'"));
	//Level Start Animation
	ConstructorHelpers::FObjectFinder<UAnimSequence>AnimLevelStartRampage(TEXT("AnimSequence'/Game/ParagonRampage/Characters/Heroes/Rampage/Animations/SelectScreen_Start.SelectScreen_Start'"));
	//Idle Animation
	ConstructorHelpers::FObjectFinder<UAnimSequence>AnimIdleRampage(TEXT("AnimSequence'/Game/ParagonRampage/Characters/Heroes/Rampage/Animations/Idle.Idle'"));
} //end Rampage

void APlayerTrophy::loadRiktor(USkeletalMeshComponent* playerMesh) {
	//Skeleton
	ConstructorHelpers::FObjectFinder<USkeletalMesh>SkeleRiktorDefault(TEXT("SkeletalMesh'/Game/ParagonRiktor/Characters/Heroes/Riktor/Meshes/Riktor.Riktor'"));
	//Animation Blueprint
	ConstructorHelpers::FObjectFinder<UAnimBlueprint>BP_AnimRiktor(TEXT("AnimBlueprint'/Game/ParagonRiktor/Characters/Heroes/Riktor/Riktor_AnimBlueprint.Riktor_AnimBlueprint'"));
	//Sound
	ConstructorHelpers::FObjectFinder<USoundCue>SoundRiktor(TEXT("SoundCue'/Game/ParagonRiktor/Characters/Heroes/Riktor/Sounds/SoundCues/Riktor_Intro_Statement.Riktor_Intro_Statement'"));
	//Level Start Animation
	ConstructorHelpers::FObjectFinder<UAnimSequence>AnimLevelStartRiktor(TEXT("AnimSequence'/Game/ParagonRiktor/Characters/Heroes/Riktor/Animations/LevelStart.LevelStart'"));
	//Idle Animation
	ConstructorHelpers::FObjectFinder<UAnimSequence>AnimIdleRiktor(TEXT("AnimSequence'/Game/ParagonRiktor/Characters/Heroes/Riktor/Animations/Idle.Idle'"));
} //end Riktor

void APlayerTrophy::loadSerath(USkeletalMeshComponent* playerMesh) {
	//Skeleton
	ConstructorHelpers::FObjectFinder<USkeletalMesh>SkeleSerathDefault(TEXT("SkeletalMesh'/Game/ParagonSerath/Characters/Heroes/Serath/Meshes/Serath.Serath'"));
	//Animation Blueprint
	ConstructorHelpers::FObjectFinder<UAnimBlueprint>BP_AnimSerath(TEXT("AnimBlueprint'/Game/ParagonSerath/Characters/Heroes/Serath/Serath_AnimBlueprint.Serath_AnimBlueprint'"));
	//Sound
	ConstructorHelpers::FObjectFinder<USoundCue>SoundSerath(TEXT("SoundCue'/Game/ParagonSerath/Characters/Heroes/Serath/Sounds/SoundCues/Serath_Intro_Statement.Serath_Intro_Statement'"));
	//Level Start Animation
	ConstructorHelpers::FObjectFinder<UAnimSequence>AnimLevelStartSerath(TEXT("AnimSequence'/Game/ParagonSerath/Characters/Heroes/Serath/Animations/Level_Start.Level_Start'"));
	//Idle Animation
	ConstructorHelpers::FObjectFinder<UAnimSequence>AnimIdleSerath(TEXT("AnimSequence'/Game/ParagonSerath/Characters/Heroes/Serath/Animations/Idle.Idle'"));
} //end Serath

void APlayerTrophy::loadSevarog(USkeletalMeshComponent* playerMesh) {
	//Skeleton
	ConstructorHelpers::FObjectFinder<USkeletalMesh>SkeleSevarogDefault(TEXT("SkeletalMesh'/Game/ParagonSevarog/Characters/Heroes/Sevarog/Meshes/Sevarog.Sevarog'"));
	//Animation Blueprint
	ConstructorHelpers::FObjectFinder<UAnimBlueprint>BP_AnimSevarog(TEXT("AnimBlueprint'/Game/ParagonSevarog/Characters/Heroes/Sevarog/Sevarog_AnimBlueprint.Sevarog_AnimBlueprint'"));
	//Sound
	ConstructorHelpers::FObjectFinder<USoundCue>SoundSevarog(TEXT("SoundCue'/Game/ParagonSevarog/Characters/Heroes/Sevarog/Sounds/SoundCues/Sevarog_Intro_Statement.Sevarog_Intro_Statement'"));
	//Level Start Animation
	ConstructorHelpers::FObjectFinder<UAnimSequence>AnimLevelStartSevarog(TEXT("AnimSequence'/Game/ParagonSevarog/Characters/Heroes/Sevarog/Animations/LevelStart.LevelStart'"));
	//Idle Animation
	ConstructorHelpers::FObjectFinder<UAnimSequence>AnimIdleSevarog(TEXT("AnimSequence'/Game/ParagonSevarog/Characters/Heroes/Sevarog/Animations/Idle.Idle'"));
} //end Sevarog

void APlayerTrophy::loadShinbi(USkeletalMeshComponent* playerMesh) {
	//Skeleton
	ConstructorHelpers::FObjectFinder<USkeletalMesh>SkeleShinbiDefault(TEXT("SkeletalMesh'/Game/ParagonShinbi/Characters/Heroes/Shinbi/Meshes/Shinbi.Shinbi''"));
	//Animation Blueprint
	ConstructorHelpers::FObjectFinder<UAnimBlueprint>BP_AnimShinbi(TEXT("AnimBlueprint'/Game/ParagonShinbi/Characters/Heroes/Shinbi/Shinbi_AnimBlueprint.Shinbi_AnimBlueprint'"));
	//Sound
	ConstructorHelpers::FObjectFinder<USoundCue>SoundShinbi(TEXT("SoundCue'/Game/ParagonShinbi/Characters/Heroes/Shinbi/Sounds/SoundCues/Shinbi_Intro_Statement.Shinbi_Intro_Statement'"));
	//Level Start Animation
	ConstructorHelpers::FObjectFinder<UAnimSequence>AnimLevelStartShinbi(TEXT("AnimSequence'/Game/ParagonShinbi/Characters/Heroes/Shinbi/Animations/LevelStart.LevelStart'"));
	//Idle Animation
	ConstructorHelpers::FObjectFinder<UAnimSequence>AnimIdleShinbi(TEXT("AnimSequence'/Game/ParagonShinbi/Characters/Heroes/Shinbi/Shinbi_Wolf/Animations/Idle.Idle'"));
} //end Shinbi

void APlayerTrophy::loadTwinblast(USkeletalMeshComponent* playerMesh) {
	//Skeleton
	ConstructorHelpers::FObjectFinder<USkeletalMesh>SkeleTwinblastDefault(TEXT("SkeletalMesh'/Game/ParagonTwinblast/Characters/Heroes/TwinBlast/Meshes/TwinBlast.TwinBlast''"));
	//Animation Blueprint
	ConstructorHelpers::FObjectFinder<UAnimBlueprint>BP_AnimTwinblast(TEXT("AnimBlueprint'/Game/ParagonTwinblast/Characters/Heroes/TwinBlast/Twinblast_AnimBlueprint.Twinblast_AnimBlueprint'"));
	//Sound
	ConstructorHelpers::FObjectFinder<USoundCue>SoundTwinblast(TEXT("SoundCue'/Game/ParagonTwinblast/Characters/Heroes/TwinBlast/Sounds/SoundCues/Twinblast_Intro_Statement.Twinblast_Intro_Statement'"));
	//Level Start Animation
	ConstructorHelpers::FObjectFinder<UAnimSequence>AnimLevelStartTwinblast(TEXT("AnimSequence'/Game/ParagonTwinblast/Characters/Heroes/TwinBlast/Animations/SelectScreen_Start.SelectScreen_Start'"));
	//Idle Animation
	ConstructorHelpers::FObjectFinder<UAnimSequence>AnimIdleTwinblast(TEXT("AnimSequence'/Game/ParagonTwinblast/Characters/Heroes/TwinBlast/Animations/Idle.Idle'"));
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