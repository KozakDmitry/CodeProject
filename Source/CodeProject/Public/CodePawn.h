// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "CodePawn.generated.h"

UCLASS()
class CODEPROJECT_API ACodePawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ACodePawn();

	UPROPERTY(VisibleAnyWhere)
	USceneComponent* SceneComponent;

	UPROPERTY(EditAnyWhere)
	float velocity = 300.0f;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
private:
	FVector velocityVector = FVector::ZeroVector;
	void MoveForward(float Amount);
	void MoveSides(float Amount);
};
