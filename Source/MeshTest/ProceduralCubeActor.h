// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ProceduralMeshComponent.h"
#include "ProceduralCubeActor.generated.h"

UCLASS()
class MESHTEST_API AProceduralCubeActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProceduralCubeActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void PostActorCreated();
	void PostLoad();
	void CreateTriangle();

	UPROPERTY(EditAnywhere)
	UProceduralMeshComponent * mesh;
};
