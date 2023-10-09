// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseGeometryActor.h"
#include "Engine/Engine.h"

DEFINE_LOG_CATEGORY_STATIC(LogCodeProject, All, All)
// Sets default values
ABaseGeometryActor::ABaseGeometryActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>("BaseMesh");
	SetRootComponent(BaseMesh);
}

// Called when the game starts or when spawned
void ABaseGeometryActor::BeginPlay()
{
	Super::BeginPlay();
	PrintTypes();
	InitialLocation = GetActorLocation();
	PrintStringTypes();
}

void ABaseGeometryActor::PrintTransform() 
{
	FTransform ftrans = GetActorTransform();
	FVector location = ftrans.GetLocation();
	FRotator rotator = ftrans.Rotator();
	FVector Scale = ftrans.GetScale3D();
	UE_LOG(LogCodeProject, Display, TEXT("Name: % s"), *GetName());
	UE_LOG(LogCodeProject, Display, TEXT("Name: % s"), *ftrans.ToHumanReadableString());
	UE_LOG(LogCodeProject, Display, TEXT("Location: % s"), *location.ToString());
	UE_LOG(LogCodeProject, Display, TEXT("Rotator: % s"), *rotator.ToString());
	UE_LOG(LogCodeProject, Display, TEXT("Scale: % s"), *Scale.ToString());
}

void ABaseGeometryActor::PrintStringTypes()
{
	FString Name = "John Connor";
	UE_LOG(LogCodeProject, Display, TEXT("Name: % s"), *Name);


	FString Combine = "Weapons Num = " + FString::FromInt(WeaponNum);
	FString HealthStr = "Health = " + FString::SanitizeFloat(Health);
	FString IsDeadStr = "IsDead = " + FString(IsDead ? "True" : "False");
	FString Stat = FString::Printf(TEXT("\n All stat: \n %s\n %s\n %s"), *Combine, *HealthStr, *IsDeadStr);
	UE_LOG(LogCodeProject, Display, TEXT("%s"), *Stat);

	GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Black, Name);
	GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Green, Stat, true, FVector2D(1.5f, 1.5f));
}

// Called every frame
void ABaseGeometryActor::Tick(float DeltaTime)
{ 
	Super::Tick(DeltaTime);
	float time = GetWorld()->GetTimeSeconds();
	FVector currLocation = GetActorLocation();
	currLocation.Z = InitialLocation.Z + Amplitude * FMath::Sin(Frequency * time);
	SetActorLocation(currLocation);
	switch (moveType)
	{
	case MovementType::Sin:
		break;
	case MovementType::Static:
		break;
	default:
		break;
	}
}


void ABaseGeometryActor::PrintTypes()
{
	UE_LOG(LogTemp, Warning, TEXT("Actor name %s"), *GetName())
	UE_LOG(LogTemp, Error, TEXT("Weapon Num: %d, Kills Count: %i"), WeaponNum, KillCount);
	UE_LOG(LogTemp, Error, TEXT("Health %.2f"), Health);
	UE_LOG(LogTemp, Error, TEXT("IsDead %d"), IsDead);
	UE_LOG(LogTemp, Error, TEXT("HasWeapon %d"), static_cast<int>(IsHaveWeapon));
}

