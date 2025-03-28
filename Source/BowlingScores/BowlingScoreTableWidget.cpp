// Fill out your copyright notice in the Description page of Project Settings.


#include "BowlingScoreTableWidget.h"
#include "Components/TextBlock.h" // Needed to display score information.
#include "Components/Image.h" // Needed to display image.

void UBowlingScoreTableWidget::NativeConstruct()
{
    Super::NativeConstruct();

    ManualArraysInitializations();

}

// Recieves a int32 to assign in to firstTry score values based on Frame value.
void UBowlingScoreTableWidget::SetFirstTryScore(int32 CurrentFrame, FString FirstTry)
{
	if (!AllFirstTry[CurrentFrame])
	{
		UE_LOG(LogTemp, Error, TEXT("SetFirstTryScore: AllFirstTry[%d] es nullptr"), CurrentFrame);
		return;
	}

	AllFirstTry[CurrentFrame]->SetText(FText::FromString(FirstTry));

}

// Returns a int32 as first score value based on Frame Value.
int32 UBowlingScoreTableWidget::GetFirstTryScore(int32 CurrentFrame)
{
	if (!AllFirstTry[CurrentFrame])
	{
        UE_LOG(LogTemp, Error, TEXT("GetFirstTryScore[%d]: es nullptr"), CurrentFrame);
        return 0;
	}

    FString ScoreString = AllFirstTry[CurrentFrame]->GetText().ToString();
    return FCString::Atoi(*ScoreString);

}

// Recieves a int32 to assign in to secondTry score values based on Frame value.
void UBowlingScoreTableWidget::SetSecondTryScore(int32 CurrentFrame, FString SecondTry)
{
	if (!AllSecondTry[CurrentFrame])
	{
		UE_LOG(LogTemp, Error, TEXT("SetSecondTryScore: AllFirstTry[%d] es nullptr"), CurrentFrame);
		return;
	}

	AllSecondTry[CurrentFrame]->SetText(FText::FromString(SecondTry));

}

// Returns a int32 as Second score value based on Frame Value.
int32 UBowlingScoreTableWidget::GetSecondTryScore(int32 CurrentFrame)
{
	if (!AllSecondTry[CurrentFrame])
	{
        UE_LOG(LogTemp, Error, TEXT("GetSecondTryScore[%d]: es nullptr"), CurrentFrame);
        return 0;
	}

    FString ScoreString = AllSecondTry[CurrentFrame]->GetText().ToString();
    return FCString::Atoi(*ScoreString);

}

// Recieves a int32 to assign in to AllFrameScores score values based on Frame.
void UBowlingScoreTableWidget::SetFrameScore(int32 CurrentFrame, FString FrameScore)
{
    if (!AllFrameScores[CurrentFrame])
    {
        UE_LOG(LogTemp, Error, TEXT("AllFrameScores: AllFirstTry[%d] es nullptr"), CurrentFrame);
        return;
    }

    AllFrameScores[CurrentFrame]->SetText(FText::FromString(FrameScore));

}

// Returns a int32 as Frame score value based on Frame.
int32 UBowlingScoreTableWidget::GetFrameScore(int32 CurrentFrame)
{
    if (!AllFrameScores[CurrentFrame])
    {
        UE_LOG(LogTemp, Error, TEXT("GetFrameScore[%d]: es nullptr"), CurrentFrame);
        return 0;
    }

    FString ScoreString = AllFrameScores[CurrentFrame]->GetText().ToString();
    return FCString::Atoi(*ScoreString);

}

// Because of nullptr problems AllFirstTry, AllSecondTry, AllFrameScores are initialized int NativeConstructor due UTextBlock time creation.
void UBowlingScoreTableWidget::ManualArraysInitializations()
{
    AllFirstTry[0] = F1_FirstTryScore;
    AllFirstTry[1] = F2_FirstTryScore;
    AllFirstTry[2] = F3_FirstTryScore;
    AllFirstTry[3] = F4_FirstTryScore;
    AllFirstTry[4] = F5_FirstTryScore;
    AllFirstTry[5] = F6_FirstTryScore;
    AllFirstTry[6] = F7_FirstTryScore;
    AllFirstTry[7] = F8_FirstTryScore;
    AllFirstTry[8] = F9_FirstTryScore;
    AllFirstTry[9] = F10_FirstTryScore;

    AllSecondTry[0] = F1_SecondTryScore;
    AllSecondTry[1] = F2_SecondTryScore;
    AllSecondTry[2] = F3_SecondTryScore;
    AllSecondTry[3] = F4_SecondTryScore;
    AllSecondTry[4] = F5_SecondTryScore;
    AllSecondTry[5] = F6_SecondTryScore;
    AllSecondTry[6] = F7_SecondTryScore;
    AllSecondTry[7] = F8_SecondTryScore;
    AllSecondTry[8] = F9_SecondTryScore;
    AllSecondTry[9] = F10_SecondTryScore;

    AllFrameScores[0] = F1_FrameScore;
    AllFrameScores[1] = F2_FrameScore;
    AllFrameScores[2] = F3_FrameScore;
    AllFrameScores[3] = F4_FrameScore;
    AllFrameScores[4] = F5_FrameScore;
    AllFrameScores[5] = F6_FrameScore;
    AllFrameScores[6] = F7_FrameScore;
    AllFrameScores[7] = F8_FrameScore;
    AllFrameScores[8] = F9_FrameScore;
    AllFrameScores[9] = F10_FrameScore;

}
