// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameModeBase.h"
#include "CodePawn.h"
#include "CodePlayerController.h"

AMyGameModeBase::AMyGameModeBase()
{
	DefaultPawnClass = ACodePawn::StaticClass();
	PlayerControllerClass = ACodePlayerController::StaticClass();
}


