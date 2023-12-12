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

	// get location
	FVector PlatformLocation = GetActorLocation();

	// update location by velocity
	PlatformLocation += PlatformVelocity * DeltaTime;

	// set location
	SetActorLocation(PlatformLocation);

	// Calculate Distance Travelled for reverse
	DistanceMoved = FVector::Dist(StartLocation, PlatformLocation);

	if (DistanceMoved > MoveDistance)
	{
		// reverse course
		PlatformVelocity *= -1;
		// reset DistanceMoved
		DistanceMoved = 0;
		// set start location to current point for future calculations of distance
		StartLocation = PlatformLocation;
	}
}
