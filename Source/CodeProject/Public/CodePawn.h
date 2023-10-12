// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "CodePawn.generated.h"

class UCameraComponent;

UCLASS()
class CODEPROJECT_API ACodePawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ACodePawn();

	UPROPERTY(VisibleAnyWhere)
	USceneComponent* SceneComponent;

	UPROPERTY(VisibleAnyWhere)
	UStaticMeshComponent* StaticMeshComponent;
	UPROPERTY(VisibleAnyWhere)
	UCameraComponent* CameraComponent;

	UPROPERTY(EditAnyWhere)
	float Velocity = 300.0f;
	
	virtual void PossessedBy(AController* NewController) override;
	virtual void UnPossessed() override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
private:
	FVector VelocityVector = FVector::ZeroVector;
	void MoveForward(float Amount);
	void MoveSides(float Amount);
};
