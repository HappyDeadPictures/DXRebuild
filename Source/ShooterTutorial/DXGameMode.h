// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/GameMode.h"
#include "DXGameMode.generated.h"

/**
 * 
 */
UCLASS()
class SHOOTERTUTORIAL_API ADXGameMode : public AGameMode
{
	GENERATED_BODY()
		virtual void Startplay() override;
	ADXGameMode(const FObjectInitializer& ObjectInitializer);
	
	
	
	
};
