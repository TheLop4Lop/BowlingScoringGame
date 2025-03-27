// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "BowlingScoreController.generated.h"

/**
 * 
 */
UCLASS()
class BOWLINGSCORES_API ABowlingScoreController : public APlayerController
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;

	virtual void SetupInputComponent() override;

private:
	
};
