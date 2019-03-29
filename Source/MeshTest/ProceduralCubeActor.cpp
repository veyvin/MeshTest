// Fill out your copyright notice in the Description page of Project Settings.


#include "ProceduralCubeActor.h"

// Sets default values
AProceduralCubeActor::AProceduralCubeActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	mesh = CreateDefaultSubobject<UProceduralMeshComponent>(TEXT("GeneratedMesh"));
	RootComponent = mesh;
	// New in UE 4.17, multi-threaded PhysX cooking.
	mesh->bUseAsyncCooking = true;
}

// Called when the game starts or when spawned
void AProceduralCubeActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AProceduralCubeActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AProceduralCubeActor::PostActorCreated()
{
	Super::PostActorCreated();
	CreateTriangle();
}

// This is called when actor is already in level and map is opened
void AProceduralCubeActor::PostLoad()
{
	Super::PostLoad();
	CreateTriangle();
}

void AProceduralCubeActor::CreateTriangle()
{
	TArray<FVector> vertices;
	vertices.Add(FVector(0, 0, 0));//0
	vertices.Add(FVector(0, 100, 0));//1
	vertices.Add(FVector(0, 0, 100));//2
	vertices.Add(FVector(0, 100, 100));//3
	vertices.Add(FVector(100, 0, 0));;//4
	vertices.Add(FVector(100, 100, 0));//5
	vertices.Add(FVector(100, 0, 100));;//6
	vertices.Add(FVector(100, 100, 100));;//6

	TArray<int32> Triangles;
	Triangles.Add(0);
	Triangles.Add(1);
	Triangles.Add(2);

	Triangles.Add(1);
	Triangles.Add(3);
	Triangles.Add(2);

	Triangles.Add(1);
	Triangles.Add(5);
	Triangles.Add(3);

	Triangles.Add(5);
	Triangles.Add(7);
	Triangles.Add(3);

	Triangles.Add(5);
	Triangles.Add(4);
	Triangles.Add(6);

	Triangles.Add(6);
	Triangles.Add(7);
	Triangles.Add(5);

	Triangles.Add(4);
	Triangles.Add(0);
	Triangles.Add(2);

	Triangles.Add(2);
	Triangles.Add(6);
	Triangles.Add(4);

	Triangles.Add(2);
	Triangles.Add(3);
	Triangles.Add(7);


	Triangles.Add(2);
	Triangles.Add(7);
	Triangles.Add(6);


	Triangles.Add(4);
	Triangles.Add(5);
	Triangles.Add(1);

	Triangles.Add(0);
	Triangles.Add(4);
	Triangles.Add(1);

	TArray<FVector> normals;
	normals.Add(FVector(1, 0, 0));
	normals.Add(FVector(1, 0, 0));
	normals.Add(FVector(0, 1, 0));
	normals.Add(FVector(0, 1, 0));
	normals.Add(FVector(-1, 0, 0));
	normals.Add(FVector(-1, 0, 0));
	normals.Add(FVector(0, -1, 0));
	normals.Add(FVector(0, -1, 0));
	normals.Add(FVector(0, 0, 1));
	normals.Add(FVector(0, 0, 1));
	normals.Add(FVector(0, 0, -1));
	normals.Add(FVector(0, 0, -1));

	TArray<FVector2D> UV0;


	TArray<FProcMeshTangent> tangents;


	TArray<FLinearColor> vertexColors;
	vertexColors.Add(FLinearColor(0.75, 0.75, 0.75, 1.0));
	vertexColors.Add(FLinearColor(0.75, 0.75, 0.75, 1.0));
	vertexColors.Add(FLinearColor(0.75, 0.75, 0.75, 1.0));
	vertexColors.Add(FLinearColor(0.75, 0.75, 0.75, 1.0));
	vertexColors.Add(FLinearColor(0.75, 0.75, 0.75, 1.0));
	vertexColors.Add(FLinearColor(0.75, 0.75, 0.75, 1.0));
	vertexColors.Add(FLinearColor(0.75, 0.75, 0.75, 1.0));
	vertexColors.Add(FLinearColor(0.75, 0.75, 0.75, 1.0));


	
	mesh->CreateMeshSection_LinearColor(0, vertices, Triangles, normals, UV0, vertexColors, tangents, true);

	// Enable collision data
	mesh->ContainsPhysicsTriMeshData(true);
}