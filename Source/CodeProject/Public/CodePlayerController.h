// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "CodePlayerController.generated.h"

/**
 * 
 */
UCLASS()
class CODEPROJECT_API ACodePlayerController : public APlayerController
{
	GENERATED_BODY()
protected:
	virtual void SetupInputComponent();
	virtual void BeginPlay();
private:
	void ChangePawn();
	UPROPERTY()
	TArray<AActor*> Pawns;
	int32 CurrentPawnIndex = 0;
};
