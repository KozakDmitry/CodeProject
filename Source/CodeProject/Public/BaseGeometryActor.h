// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "BaseGeometryActor.generated.h"

UENUM(BlueprintType)
enum class EMovementType : uint8
{
	Sin,
	Static
};

USTRUCT(BlueprintType)
struct FGeometryData 
{
	GENERATED_USTRUCT_BODY()
	UPROPERTY(EditAnyWhere, Category = "Movement")
	float Amplitude = 50.0f;
	UPROPERTY(EditAnyWhere, Category = "Movement")
	float Frequency = 2.0f;
	UPROPERTY(EditAnyWhere, Category = "Movement")
	EMovementType MoveType = EMovementType::Static;
	UPROPERTY(EditAnyWhere, Category = "Design")
	FLinearColor Color = FLinearColor::Black;
	UPROPERTY(EditAnyWhere, Category = "Design")
	float TimerRate = 3.0f;
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
	void SetGeometryData(const FGeometryData& Data) { MoveData = Data; }

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnyWhere, Category = "Geometry Data")
	FGeometryData MoveData;

	UPROPERTY(EditAnyWhere, Category = "Weapon")
	int32 WeaponNum = 4;
	UPROPERTY(EditDefaultsOnly, Category = "Kills")
	int32 KillCount = 15;

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
	FTimerHandle TimerHandle;

	const int32 MaxTimerCount = 5;
	int32 TimerCount = 0;
	void PrintTypes();
	void PrintStringTypes();
	void PrintTransform();
	void HandleMovement();
	void SetColor(const FLinearColor& Color);
	void OnTimerFired();
};