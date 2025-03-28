// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "BowlingScoreGameMode.generated.h"

/**
 * 
 */
UCLASS()
class BOWLINGSCORES_API ABowlingScoreGameMode : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	// Returns the Current frame the player is setting the score.
	int32 GetCurrentFrame();
	// Change to the next Frame.
	void ChangeToTheNextFrame();

	// Returns number of tried by the player.
	int32 GetCurrentTry();
	// Add a try to the Throw try quantity.
	void AddNextTry();

private:
	int32 CurrentFrame = 1;
	const int32 MaxFrames = 10;

	int32 CurrentThrowTry = 1;
	const int MaxThrowTry = 2;
	
};
