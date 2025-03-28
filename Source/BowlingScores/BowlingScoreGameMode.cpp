// Fill out your copyright notice in the Description page of Project Settings.


#include "BowlingScoreGameMode.h"

// Returns the Current frame the player is setting the score.
int32 ABowlingScoreGameMode::GetCurrentFrame()
{
	return CurrentFrame;

}

// Change to the next Frame.
void ABowlingScoreGameMode::ChangeToTheNextFrame()
{
    if (CurrentFrame < MaxFrames)
    {
        CurrentFrame++;
    }
    else
    {
        // Add Something to let know the end.
    }

}

// Returns number of tried by the player.
int32 ABowlingScoreGameMode::GetCurrentTry()
{
	return CurrentThrowTry;

}

// Add a try to the Throw try quantity.
void ABowlingScoreGameMode::AddNextTry()
{
    if (CurrentThrowTry == MaxThrowTry)
    {
        CurrentThrowTry = 1;
    }
    else
    {
        CurrentThrowTry++;
    }

}
