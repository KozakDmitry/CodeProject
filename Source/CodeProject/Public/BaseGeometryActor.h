// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "BaseGeometryActor.generated.h"

enum class MovementType
{
	Sin,
	Static
};

UCLASS()
class CODEPROJECT_API ABaseGeometryActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABaseGeometryActor();

	UPROPERTY(VisibleAnyWhere)
	UStaticMeshComponent* BaseMesh;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnyWhere, Category ="Movement")
	float Amplitude = 50.0f;	
	UPROPERTY(EditAnyWhere, Category ="Movement")
	float Frequency = 2.0f;
	UPROPERTY(EditAnyWhere, Category = "Weapon")
	int32 WeaponNum = 4;
	UPROPERTY(EditDefaultsOnly, Category = "Kills")
	int32 KillCount = 15;

	MovementType moveType = MovementType::Static;

	UPROPERTY(EditInstanceOnly, Category = "Health")
	float Health = 125.25f;
	UPROPERTY(EditAnyWhere, Category = "Alive")
	bool IsDead = false;
	UPROPERTY(VisibleAnyWhere)
	bool IsHaveWeapon = true;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	FVector InitialLocation;
	void PrintTypes();
	void PrintStringTypes();
	void PrintTransform();
};
