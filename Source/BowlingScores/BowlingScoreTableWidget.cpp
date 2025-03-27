// Fill out your copyright notice in the Description page of Project Settings.


#include "BowlingScoreTableWidget.h"
#include "Components/TextBlock.h" // Needed to display score information.
#include "Components/Image.h" // Needed to display image.

// Recieves a int32 to assign respective score values to try arrays.
void UBowlingScoreTableWidget::SetFrameScore(int32 CurrentFrame, FString FirstTry, FString SecondTry, FString FrameScore)
{
	AllFirstTry[CurrentFrame]->SetText(FText::FromString(FirstTry));
	AllSecondTry[CurrentFrame]->SetText(FText::FromString(SecondTry));
	AllFrameScores[CurrentFrame]->SetText(FText::FromString(FrameScore));

}
