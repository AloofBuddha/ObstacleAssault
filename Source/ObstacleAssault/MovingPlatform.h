// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingPlatform.generated.h"

UCLASS()
class OBSTACLEASSAULT_API AMovingPlatform : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AMovingPlatform();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	void MovePlatform(float DeltaTime);
	void RotatePlatform(float DeltaTime);
	bool ShouldPlatformReturn() const;
	float GetDistanceMoved() const;

private:
	UPROPERTY(EditAnywhere, Category = "Moving")
	FVector PlatformVelocity = FVector(200, 0, -90);

	UPROPERTY(EditAnywhere, Category = "Moving")
	float MoveDistance = 100;

	UPROPERTY(EditAnywhere, Category = "Rotating")
	FRotator RotationalVelocity = FRotator(0, 0, 90);

	UPROPERTY(VisibleAnywhere)
	float DistanceMoved = 0;

	FVector StartLocation;
};
