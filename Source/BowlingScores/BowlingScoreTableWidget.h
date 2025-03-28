// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "BowlingScoreTableWidget.generated.h"

/**
 * 
 */
UCLASS()
class BOWLINGSCORES_API UBowlingScoreTableWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	// Recieves a int32 to assign respective score values to try arrays.
	void SetFrameScore(int32 CurrentFrame, FString FirstTry, FString SecondTry, FString FrameScore);

	// Recieves a int32 to assign in to firstTry score values based on Frame value.
	void SetFirstTryScore(int32 CurrentFrame, FString FirstTry);

	// Returns a int32 as first score value based on Frame Value.
	int32 GetFirstTryScore(int32 CurrentFrame);

	// Recieves a int32 to assign in to secondTry score values based on Frame value.
	void SetSecondTryScore(int32 CurrentFrame, FString SecondTry);

	// Returns a int32 as Second score value based on Frame Value.
	int32 GetSecondTryScore(int32 CurrentFrame);

protected:
	void NativeConstruct() override;

private:
	// Holds reference for visual representation of Bowling Score Table.
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UImage* ScoreTableImage;

	// Player Name text block to display score.
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UTextBlock* PlayerName;


	// FRAME 1
	// First try text block to display score.
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UTextBlock* F1_FirstTryScore;

	// Second try text block to display score.
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UTextBlock* F1_SecondTryScore;

	// Total text block to display score.
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UTextBlock* F1_FrameScore;


	// FRAME 2
	// First try text block to display score.
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UTextBlock* F2_FirstTryScore;

	// Second try text block to display score.
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UTextBlock* F2_SecondTryScore;

	// Total text block to display score.
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UTextBlock* F2_FrameScore;


	// FRAME 3
	// First try text block to display score.
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UTextBlock* F3_FirstTryScore;

	// Second try text block to display score.
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UTextBlock* F3_SecondTryScore;

	// Total text block to display score.
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UTextBlock* F3_FrameScore;


	// FRAME 4
	// First try text block to display score.
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UTextBlock* F4_FirstTryScore;

	// Second try text block to display score.
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UTextBlock* F4_SecondTryScore;

	// Total text block to display score.
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UTextBlock* F4_FrameScore;


	// FRAME 5
	// First try text block to display score.
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UTextBlock* F5_FirstTryScore;

	// Second try text block to display score.
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UTextBlock* F5_SecondTryScore;

	// Total text block to display score.
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UTextBlock* F5_FrameScore;


	// FRAME 6
	// First try text block to display score.
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UTextBlock* F6_FirstTryScore;

	// Second try text block to display score.
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UTextBlock* F6_SecondTryScore;

	// Total text block to display score.
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UTextBlock* F6_FrameScore;


	// FRAME 7
	// First try text block to display score.
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UTextBlock* F7_FirstTryScore;

	// Second try text block to display score.
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UTextBlock* F7_SecondTryScore;

	// Total text block to display score.
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UTextBlock* F7_FrameScore;


	// FRAME 8
	// First try text block to display score.
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UTextBlock* F8_FirstTryScore;

	// Second try text block to display score.
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UTextBlock* F8_SecondTryScore;

	// Total text block to display score.
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UTextBlock* F8_FrameScore;


	// FRAME 9
	// First try text block to display score.
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UTextBlock* F9_FirstTryScore;

	// Second try text block to display score.
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UTextBlock* F9_SecondTryScore;

	// Total text block to display score.
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UTextBlock* F9_FrameScore;


	// FRAME 10
	// First try text block to display score.
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UTextBlock* F10_FirstTryScore;

	// Second try text block to display score.
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UTextBlock* F10_SecondTryScore;

	// Total text block to display score.
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UTextBlock* F10_FrameScore;


	// GAME SCORE
	// Total text block to display score.
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UTextBlock* GAME_TotalScore;

	// Because of nullptr problems AllFirstTry, AllSecondTry, AllFrameScores are initialized int NativeConstructor due UTextBlock time creation.
	void ManualArraysInitializations();

	// Holds all the FX (frames) first trys.
	UTextBlock* AllFirstTry[10] = {F1_FirstTryScore, F2_FirstTryScore, F3_FirstTryScore, F4_FirstTryScore, F5_FirstTryScore,
									F6_FirstTryScore, F7_FirstTryScore, F8_FirstTryScore, F9_FirstTryScore, F10_FirstTryScore};

	// Holds all the FX (frames) second trys.
	UTextBlock* AllSecondTry[10] = {F1_SecondTryScore, F2_SecondTryScore, F3_SecondTryScore, F4_SecondTryScore, F5_SecondTryScore,
									F6_SecondTryScore, F7_SecondTryScore, F8_SecondTryScore, F9_SecondTryScore, F10_SecondTryScore};

	// Holds all the FX (frames) scores.
	UTextBlock* AllFrameScores[10] = {F1_FrameScore, F2_FrameScore, F3_FrameScore, F4_FrameScore, F5_FrameScore,
									F6_FrameScore, F7_FrameScore, F8_FrameScore, F9_FrameScore, F10_FrameScore};

};
