// Fill out your copyright notice in the Description page of Project Settings.

#include "PlayerTrophy.h"
#include "Components/SkeletalMeshComponent.h"
#include "Components/SceneComponent.h"
#include "Camera/CameraComponent.h"
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
	/*
	//Find ALL Skeletons here.
	//Skins will be added later.
	ConstructorHelpers::FObjectFinder<USkeletalMesh>SkeleCountessDefault(TEXT("SkeletalMesh'/Game/ParagonCountess/Characters/Heroes/Countess/Meshes/SM_Countess.SM_Countess''")); //Countess
	//Crunch will not be a playable character, FAR too big.
	ConstructorHelpers::FObjectFinder<USkeletalMesh>SkeleDekkerDefault(TEXT("SkeletalMesh'/Game/ParagonDekker/Characters/Heroes/Dekker/Meshes/Dekker.Dekker'")); //Dekker
	ConstructorHelpers::FObjectFinder<USkeletalMesh>SkeleFengMaoDefault(TEXT("SkeletalMesh'/Game/ParagonFengMao/Characters/Heroes/FengMao/Meshes/FengMao_GDC.FengMao_GDC'")); //Feng Mao
	ConstructorHelpers::FObjectFinder<USkeletalMesh>SkeleGadgetDefault(TEXT("SkeletalMesh'/Game/ParagonGadget/Characters/Heroes/Gadget/Meshes/Gadget.Gadget'")); //Gadget
	ConstructorHelpers::FObjectFinder<USkeletalMesh>SkeleGrimDefault(TEXT("SkeletalMesh'/Game/ParagonGRIMexe/Characters/Heroes/GRIM/Meshes/GRIM_GDC.GRIM_GDC'")); //GRIM
	ConstructorHelpers::FObjectFinder<USkeletalMesh>SkeleGruxDefault(TEXT("SkeletalMesh'/Game/ParagonGrux/Characters/Heroes/Grux/Meshes/Grux.Grux'")); //Grux
	ConstructorHelpers::FObjectFinder<USkeletalMesh>SkeleHowlitzerDefault(TEXT("SkeletalMesh'/Game/ParagonHowitzer/Characters/Heroes/Howitzer/Meshes/Howitzer_GDC.Howitzer_GDC'")); //Howitzer
	ConstructorHelpers::FObjectFinder<USkeletalMesh>SkeleKhaimeraDefault(TEXT("SkeletalMesh'/Game/ParagonKhaimera/Characters/Heroes/Khaimera/Meshes/Khaimera.Khaimera'")); //Khaimera
	ConstructorHelpers::FObjectFinder<USkeletalMesh>SkeleKwangDefault(TEXT("SkeletalMesh'/Game/ParagonKwang/Characters/Heroes/Kwang/Meshes/Kwang_GDC.Kwang_GDC'")); //Kwang
	ConstructorHelpers::FObjectFinder<USkeletalMesh>SkeleMurdockDefault(TEXT("SkeletalMesh'/Game/ParagonMurdock/Characters/Heroes/Murdock/Meshes/Murdock.Murdock'")); //Murdock
	ConstructorHelpers::FObjectFinder<USkeletalMesh>SkeleMurielDefault(TEXT("SkeletalMesh'/Game/ParagonMuriel/Characters/Heroes/Muriel/Meshes/Muriel_GDC.Muriel_GDC'")); //Muriel
	ConstructorHelpers::FObjectFinder<USkeletalMesh>SkelePhaseDefault(TEXT("SkeletalMesh'/Game/ParagonPhase/Characters/Heroes/Phase/Meshes/Phase_GDC.Phase_GDC'")); //Phase
	*/

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

void load(int playerNum) {
	//MAKE A SWITCH CASE SO ALL OF THESE DON'T HAPPEN!!!!!!!!! SIMPLY USE THE MESS BELOW FOR EASY COPY PASTE
	//Skins will be added later.
	ConstructorHelpers::FObjectFinder<USkeletalMesh>SkeleCountessDefault(TEXT("SkeletalMesh'/Game/ParagonCountess/Characters/Heroes/Countess/Meshes/SM_Countess.SM_Countess''")); //Countess
	//Crunch will not be a playable character, FAR too big.
	ConstructorHelpers::FObjectFinder<USkeletalMesh>SkeleDekkerDefault(TEXT("SkeletalMesh'/Game/ParagonDekker/Characters/Heroes/Dekker/Meshes/Dekker.Dekker'")); //Dekker
	ConstructorHelpers::FObjectFinder<USkeletalMesh>SkeleFengMaoDefault(TEXT("SkeletalMesh'/Game/ParagonFengMao/Characters/Heroes/FengMao/Meshes/FengMao_GDC.FengMao_GDC'")); //Feng Mao
	ConstructorHelpers::FObjectFinder<USkeletalMesh>SkeleGadgetDefault(TEXT("SkeletalMesh'/Game/ParagonGadget/Characters/Heroes/Gadget/Meshes/Gadget.Gadget'")); //Gadget
	ConstructorHelpers::FObjectFinder<USkeletalMesh>SkeleGrimDefault(TEXT("SkeletalMesh'/Game/ParagonGRIMexe/Characters/Heroes/GRIM/Meshes/GRIM_GDC.GRIM_GDC'")); //GRIM
	ConstructorHelpers::FObjectFinder<USkeletalMesh>SkeleGruxDefault(TEXT("SkeletalMesh'/Game/ParagonGrux/Characters/Heroes/Grux/Meshes/Grux.Grux'")); //Grux
	ConstructorHelpers::FObjectFinder<USkeletalMesh>SkeleHowlitzerDefault(TEXT("SkeletalMesh'/Game/ParagonHowitzer/Characters/Heroes/Howitzer/Meshes/Howitzer_GDC.Howitzer_GDC'")); //Howitzer
	ConstructorHelpers::FObjectFinder<USkeletalMesh>SkeleKhaimeraDefault(TEXT("SkeletalMesh'/Game/ParagonKhaimera/Characters/Heroes/Khaimera/Meshes/Khaimera.Khaimera'")); //Khaimera
	ConstructorHelpers::FObjectFinder<USkeletalMesh>SkeleKwangDefault(TEXT("SkeletalMesh'/Game/ParagonKwang/Characters/Heroes/Kwang/Meshes/Kwang_GDC.Kwang_GDC'")); //Kwang
	ConstructorHelpers::FObjectFinder<USkeletalMesh>SkeleMurdockDefault(TEXT("SkeletalMesh'/Game/ParagonMurdock/Characters/Heroes/Murdock/Meshes/Murdock.Murdock'")); //Murdock
	ConstructorHelpers::FObjectFinder<USkeletalMesh>SkeleMurielDefault(TEXT("SkeletalMesh'/Game/ParagonMuriel/Characters/Heroes/Muriel/Meshes/Muriel_GDC.Muriel_GDC'")); //Muriel
	ConstructorHelpers::FObjectFinder<USkeletalMesh>SkelePhaseDefault(TEXT("SkeletalMesh'/Game/ParagonPhase/Characters/Heroes/Phase/Meshes/Phase_GDC.Phase_GDC'")); //Phase
	ConstructorHelpers::FObjectFinder<USkeletalMesh>SkeleRampageDefault(TEXT("SkeletalMesh'/Game/ParagonRampage/Characters/Heroes/Rampage/Meshes/Rampage.Rampage'")); //Rampage
	ConstructorHelpers::FObjectFinder<USkeletalMesh>SkeleRiktorDefault(TEXT("SkeletalMesh'/Game/ParagonRiktor/Characters/Heroes/Riktor/Meshes/Riktor.Riktor'")); //Riktor
	ConstructorHelpers::FObjectFinder<USkeletalMesh>SkeleSerathDefault(TEXT("SkeletalMesh'/Game/ParagonSerath/Characters/Heroes/Serath/Meshes/Serath.Serath'")); //Serath
	ConstructorHelpers::FObjectFinder<USkeletalMesh>SkeleSevarogDefault(TEXT("SkeletalMesh'/Game/ParagonSevarog/Characters/Heroes/Sevarog/Meshes/Sevarog.Sevarog'")); //Sevarog
	ConstructorHelpers::FObjectFinder<USkeletalMesh>SkeleShinbiDefault(TEXT("SkeletalMesh'/Game/ParagonShinbi/Characters/Heroes/Shinbi/Meshes/Shinbi.Shinbi''")); //Shinbi
	ConstructorHelpers::FObjectFinder<USkeletalMesh>SkeleTwinblastDefault(TEXT("SkeletalMesh'/Game/ParagonTwinblast/Characters/Heroes/TwinBlast/Meshes/TwinBlast.TwinBlast''")); //Twinblast
}
