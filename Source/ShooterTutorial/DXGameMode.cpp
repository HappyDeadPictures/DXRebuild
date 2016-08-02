// Fill out your copyright notice in the Description page of Project Settings.

#include "ShooterTutorial.h"
#include "DXGameMode.h"
#include "Engine.h" //for version 4.4+
ADXGameMode::ADXGameMode(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	Super::StartPlay();

	StartMatch();

	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage (-1, 5.f, FColor::Yellow, TEXT("HELLO WORLD"))
	}
}




