// Fill out your copyright notice in the Description page of Project Settings.


#include "CodeHubActor.h"
#include "Engine/World.h"
// Sets default values
ACodeHubActor::ACodeHubActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACodeHubActor::BeginPlay()
{
	Super::BeginPlay();
	UWorld* World = GetWorld();
	if (World) 
	{
		for (int32 i = 0; i < 32; i++)
		{
			const FTransform GeometryTransform = FTransform(FRotator::ZeroRotator, FVector(0.0f, 300.0f*i, 300.0f));
			ABaseGeometryActor* GeometryActor = World->SpawnActor<ABaseGeometryActor>(CodeClass, GeometryTransform);
			if (GeometryActor) 
			{
				FGeometryData Data;
				Data.MoveType = FMath::RandBool() ? EMovementType::Static : EMovementType::Sin;
				GeometryActor->SetGeometryData(Data);

			}
		
		}

		for (int32 i = 0; i < 32; i++)
		{
			const FTransform GeometryTransform = FTransform(FRotator::ZeroRotator, FVector(0.0f, 300.0f * i, 700.0f));
			ABaseGeometryActor* GeometryActor = World->SpawnActorDeferred<ABaseGeometryActor>(CodeClass, GeometryTransform);

			if (GeometryActor)
			{
				FGeometryData Data;
				Data.Color = FLinearColor::MakeRandomColor();
				//Data.MoveType = FMath::RandBool() ? EMovementType::Static : EMovementType::Sin;
				GeometryActor->SetGeometryData(Data);
				GeometryActor->FinishSpawning(GeometryTransform);
			}

		}
		for (const FGeometryPayload Payload : GeometryPayloads) 
		{
			ABaseGeometryActor* Geometry = World->SpawnActorDeferred<ABaseGeometryActor>(Payload.CodeClass, Payload.InitialTransform);
			if(Geometry)
			{
				Geometry->SetGeometryData(Payload.Data);
				Geometry->FinishSpawning(Payload.InitialTransform);
			}
		}
	}
}

// Called every frame
void ACodeHubActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

