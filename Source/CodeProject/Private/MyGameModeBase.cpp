// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameModeBase.h"
#include "CodePawn.h"

AMyGameModeBase::AMyGameModeBase()
{
	DefaultPawnClass = ACodePawn::StaticClass();
}


