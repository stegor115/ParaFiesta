// Fill out your copyright notice in the Description page of Project Settings.

#include "PlayerAvatar.h"
#include "Engine/World.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"
#include "GameFramework/SpringArmComponent.h"
#include "Components/InputComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Camera/CameraComponent.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"

// Sets default values
APlayerAvatar::APlayerAvatar()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Character Movement (Taken from ThirdPersonProject Starter Code)
	GetCharacterMovement()->bOrientRotationToMovement = true; // Character moves in the direction of input...	
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 540.0f, 0.0f); // ...at this rotation rate
	GetCharacterMovement()->JumpZVelocity = 600.f;
	GetCharacterMovement()->AirControl = 0.2f;

	//Camera Boom (Big stick that keeps camera away)
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 800.0f; //Length of the "stick"
	CameraBoom->bUsePawnControlRotation = false; //Stops stick from moving for top down view
	CameraBoom->SetRelativeRotation(FRotator(-45.0f, -90.0f, 0.0f));
	CameraBoom->SetRelativeLocation(FVector(0.0f, 0.0f, 60.0f));

	//Camera
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("PlayerCamera"));
	Camera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName); //Attach camera to the end of the stick of the boom
	Camera->bUsePawnControlRotation = false; //Prevents camera itself from rotating.

}

// Called when the game starts or when spawned
void APlayerAvatar::BeginPlay()
{
	Super::BeginPlay();
	StartMove();
}

// Called every frame
void APlayerAvatar::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APlayerAvatar::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	//Actions
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("TestMoveOne", IE_Pressed, this, &APlayerAvatar::TestMoveOne);
	//Camera Handling
	PlayerInputComponent->BindAction("ZoomOut", IE_Pressed, this, &APlayerAvatar::ZoomOut);
	PlayerInputComponent->BindAction("ZoomIn", IE_Pressed, this, &APlayerAvatar::ZoomIn);
	//Basic Movement
	//PlayerInputComponent->BindAxis("MoveForward", this, &APlayerAvatar::MoveForward);
	//PlayerInputComponent->BindAxis("MoveBackward", this, &APlayerAvatar::MoveBackward);
	//PlayerInputComponent->BindAxis("MoveLeft", this, &APlayerAvatar::MoveLeft);
	//PlayerInputComponent->BindAxis("MoveRight", this, &APlayerAvatar::MoveRight);
	//Proper Movement
}

//Camera Handling--------------------------------------------------------------
void APlayerAvatar::ZoomOut()
{
	if (CameraBoom->TargetArmLength < MAX_CAMERA_DISTANCE) {
		CameraBoom->TargetArmLength += 10.0f;
	} //end if
}
void APlayerAvatar::ZoomIn()
{
	if (CameraBoom->TargetArmLength > MIN_CAMERA_DISTANCE) {
		CameraBoom->TargetArmLength -= 10.0f;
	} //end if

}
//Movement---------------------------------------------------------------------
/*
void APlayerAvatar::MoveForward(float value)
{
	if (Controller && value) {
		//Finds which way is forward
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);
		//Get forward vector
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, 5);
	} //end if
}

void APlayerAvatar::MoveBackward(float value)
{
	if (Controller && value) {
		//Finds which way is backward
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);
		//Gets "forward" vector (negative direction)
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, value);
	} //end if
}

void APlayerAvatar::MoveLeft(float value)
{
	if (Controller && value) {
		//Finds which way is left
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);
		//Gets "right" vector (negative direction)
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		AddMovementInput(Direction, value);
	} //end if
}

void APlayerAvatar::MoveRight(float value)
{
	if (Controller && value) {
		//Finds which way is right
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);
		//Gets right vector
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		AddMovementInput(Direction, value);
	} //end if
}
*/

void APlayerAvatar::StartMove()
{
	if (moves != 0) {
		TArray<AActor*> foundActors;
		UGameplayStatics::GetAllActorsOfClass(GetWorld(), ABoardSpot::StaticClass(), foundActors);

		for (int i = 0; i != foundActors.Num(); ++i) { //Iterate through the array of found actors
			ABoardSpot* mySpot = Cast<ABoardSpot>(foundActors[i]);
			if (mySpot->GetOverlap()) {
				mySpot->MoreToMove(this);
				break;
			} //end if
			//UE_LOG(LogTemp, Warning, TEXT("Test"));
		}//end for

	} //end if
}

void APlayerAvatar::TestMoveOne() {
	UE_LOG(LogTemp, Warning, TEXT("Test"));
	moves = 1;
	StartMove();
}

void APlayerAvatar::Move(EDirection direction)
{
	FVector newLocation; //Used to modify positions
	FRotator newRotation; //Used to modify rotation
	switch (direction) { //Figure out what direction to move in
	case EDirection::E_Up:
		newLocation = this->GetActorLocation() - FVector(0.0f, 200.0f, 0.0f);
		newRotation = FRotator(0.0f, 180.0f, 0.0f);
		this->TeleportTo(newLocation, newRotation);
		break;
	case EDirection::E_Down:
		newLocation = this->GetActorLocation() + FVector(0.0f, 200.0f, 0.0f);
		newRotation = FRotator(0.0f, 0.0f, 0.0f);
		this->TeleportTo(newLocation, newRotation);
		break;
	case EDirection::E_Right:
		newLocation = this->GetActorLocation() + FVector(200.0f, 0.0f, 0.0f);
		newRotation = FRotator(0.0f, 270.0f, 0.0f);
		this->TeleportTo(newLocation, newRotation);
		break;
	case EDirection::E_Left:
		newLocation = this->GetActorLocation() - FVector(200.0f, 0.0f, 0.0f);
		newRotation = FRotator(0.0f, 90.0f, 0.0f);
		this->TeleportTo(newLocation, newRotation);
		break;
	case EDirection::E_Pause: //Pause as in Pause to choose direction
		//Not implemented
		break;
	default:
		//Never should happen
		break;
	} //end switch

	moves--;

	if (moves != 0) {
		TArray<AActor*> overlapActors;
		GetOverlappingActors(overlapActors, ABoardSpot::StaticClass());
		for (int i = 0; i != overlapActors.Num(); ++i) {
			ABoardSpot* mySpot = Cast<ABoardSpot>(overlapActors[i]);
			mySpot->MoreToMove(this);
		} //end for
	} //end if
} //end Move