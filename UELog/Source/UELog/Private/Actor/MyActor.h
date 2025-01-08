// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor.generated.h"

UCLASS()
class AMyActor : public AActor
{
	GENERATED_BODY()
	
public:
	AMyActor() : Count(0), CurrentPos({ 0,0 }), PrevPos({0,0}), TotalDist(0), EventCount(0){ PrimaryActorTick.bCanEverTick = true; }

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;
	void move();
	int32 step();
	void randomEvent();
	float distance(FVector2D first, FVector2D second);
	void PrintLog();

private:
	int Count;
	int EventCount;
	float TotalDist;
	FVector2D CurrentPos;
	FVector2D PrevPos;
};
