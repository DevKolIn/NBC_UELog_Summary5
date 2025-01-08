// Fill out your copyright notice in the Description page of Project Settings.


#include "Actor/MyActor.h"

void AMyActor::BeginPlay()
{
	Super::BeginPlay();

	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, FString::Printf(TEXT("Spwan Actor!")));
	UE_LOG(LogTemp, Warning, TEXT("Spwan Actor!"));
}

void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (Count < 10)
	{
		move();
		randomEvent();
		PrintLog();
		PrevPos = CurrentPos;
		++Count;
	}
	if (Count == 10)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, FString::Printf(TEXT("TotalDist (%f)"), TotalDist));
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, FString::Printf(TEXT("TotalEventCount (%d)"), EventCount));
		UE_LOG(LogTemp, Warning, TEXT("TotalDist (%f)"), TotalDist);
		UE_LOG(LogTemp, Warning, TEXT("TotalEventCount (%d)"), EventCount);
		++Count;
	}
}

void AMyActor::move()
{
	FVector2D Offset(step(), step());
	CurrentPos += Offset;
	TotalDist += distance(PrevPos, CurrentPos);
}

int32 AMyActor::step()
{
	return FMath::RandRange(0, 1);
}

void AMyActor::randomEvent()
{
	if (FMath::RandRange(0, 1) == 0)
	{
		++EventCount;
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, FString::Printf(TEXT("Event Trigger!")));
	}
}

float AMyActor::distance(FVector2D first, FVector2D second)
{
	float X = first.X - second.X;
	float Y = first.Y - second.Y;
	return FMath::Sqrt(X * X + Y * Y);
}

void AMyActor::PrintLog()
{
	float dist = distance(PrevPos, CurrentPos);
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, FString::Printf(TEXT("Actor CurretnPos (%lf, %lf), distance (%f)"), CurrentPos.X, CurrentPos.Y, dist));
	UE_LOG(LogTemp, Warning, TEXT("Actor CurretnPos (%lf, %lf)"), CurrentPos.X, CurrentPos.Y, dist);
}
