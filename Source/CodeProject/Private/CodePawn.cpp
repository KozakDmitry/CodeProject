// Fill out your copyright notice in the Description page of Project Settings.


#include "CodePawn.h"
#include "Components/InputComponent.h"

DEFINE_LOG_CATEGORY_STATIC(LogCodePawn, All, All)
// Sets default values
ACodePawn::ACodePawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SceneComponent = CreateDefaultSubobject<USceneComponent>("SceneComponent");
	SetRootComponent(SceneComponent);
}

// Called when the game starts or when spawned
void ACodePawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACodePawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}	

// Called to bind functionality to input
void ACodePawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis("MoveForward", this, ACodePawn::MoveForward);
	PlayerInputComponent->BindAxis("MoveSides", this, ACodePawn::MoveSides);


}
void ACodePawn::MoveForward(float Amount)
{
	UE_LOG(LogCodePawn, Display, TEXT("Move Forward %f"), Amount);
}

void ACodePawn::MoveSides(float Amount)
{
	UE_LOG(LogCodePawn, Display, TEXT("Move Sides %f"), Amount);

}
