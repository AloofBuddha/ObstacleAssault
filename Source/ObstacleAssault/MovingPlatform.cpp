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
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// get location
	FVector PlatformLocation = GetActorLocation();

	// switch velocity if at either bounds
	if (PlatformLocation.X < LowerBoundX || PlatformLocation.X > UpperBoundX)
	{
		MovingVelocity *= -1;
	}

	// update location
	PlatformLocation += MovingVelocity;
	// set location
	SetActorLocation(PlatformLocation);
}
