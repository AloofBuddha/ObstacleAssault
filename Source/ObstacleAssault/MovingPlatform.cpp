// Fill out your copyright notice in the Description page of Project Settings.

#include "MovingPlatform.h"

// Sets default values
AMovingPlatform::AMovingPlatform()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();

	StartLocation = GetActorLocation();
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	MovePlatform(DeltaTime);
	RotatePlatform(DeltaTime);
}

void AMovingPlatform::MovePlatform(float DeltaTime)
{
	// get location
	FVector PlatformLocation = GetActorLocation();

	// update location by velocity
	PlatformLocation += PlatformVelocity * DeltaTime;

	// set location
	SetActorLocation(PlatformLocation);

	if (ShouldPlatformReturn())
	{
		float OvershotDistance = DistanceMoved - MoveDistance;
		// reverse course
		PlatformVelocity *= -1;
		// reset DistanceMoved
		DistanceMoved = 0;
		// set start location to current point for future calculations of distance
		StartLocation = PlatformLocation;

		UE_LOG(LogTemp, Display, TEXT("%s overshot by: %f"), *GetName(), OvershotDistance);
	}
}

void AMovingPlatform::RotatePlatform(float DeltaTime)
{
	AddActorLocalRotation(RotationalVelocity * DeltaTime);
}

bool AMovingPlatform::ShouldPlatformReturn() const
{
	return GetDistanceMoved() > MoveDistance;
}

float AMovingPlatform::GetDistanceMoved() const
{
	return FVector::Dist(StartLocation, GetActorLocation());
}
