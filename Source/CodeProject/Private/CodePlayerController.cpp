// Fill out your copyright notice in the Description page of Project Settings.

#include "CodePlayerController.h"
#include "CodePawn.h"
#include "Components/InputComponent.h"
#include "Kismet/GameplayStatics.h"

DEFINE_LOG_CATEGORY_STATIC(LogCodePlayerController, All, All)

void ACodePlayerController::SetupInputComponent()
{
    Super::SetupInputComponent();
    if (InputComponent)
    {
        InputComponent->BindAction("ChangePawn", IE_Pressed, this, &ACodePlayerController::ChangePawn);
    }
}

void ACodePlayerController::BeginPlay()
{
    Super::BeginPlay();
    UGameplayStatics::GetAllActorsOfClass(GetWorld(), ACodePawn::StaticClass(), Pawns);
}

void ACodePlayerController::ChangePawn()
{
    if (Pawns.Num() <= 1)
    {
        return;
    }
    ACodePawn *CurrentPawn = Cast<ACodePawn>(Pawns[CurrentPawnIndex]);
    CurrentPawnIndex = (CurrentPawnIndex + 1) % Pawns.Num();
    if (!CurrentPawn)
    {
        return;
    }
    Possess(CurrentPawn);
    UE_LOG(LogCodePlayerController, Display, TEXT("Changed game pawn"));
}
