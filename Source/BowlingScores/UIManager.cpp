// Fill out your copyright notice in the Description page of Project Settings.


#include "UIManager.h"
#include "BowlingScoreController.h" // Needed to assigns reference of PlayerController to create Widgets.
#include "Blueprint/UserWidget.h" // Needed to create Widgets and adding them to viewport.

#include "GameFramework/GameModeBase.h" // To Get Game Mode.
#include "BowlingScoreGameMode.h" // Needed to interact with frames and player tries rules.

#include "BowlingScoreTableWidget.h" // Needed to pass information after calculation.
#include "ScoreInputWidget.h" // Needed to recieve score information.

// Implement and adds Widgets on screen.
void UUIManager::ImplementBowlingScoreWidgets(TSubclassOf<UUserWidget> BoardWidget,	TSubclassOf<UUserWidget> ButtonWidget,
									TSubclassOf<UUserWidget> InputWidget, ABowlingScoreController* Controller)
{
	PlayerController = Controller;
	if (PlayerController)
	{
		ScoreBoardWidget = Cast<UBowlingScoreTableWidget>(CreateWidget<UUserWidget>(PlayerController, BoardWidget));
		if (ScoreBoardWidget)
		{
			ScoreBoardWidget->AddToViewport();
		}

		ButtonActionWidget = Cast<UBoardActionWidget>(CreateWidget<UUserWidget>(PlayerController, ButtonWidget));
		if (ButtonActionWidget)
		{
			ButtonActionWidget->AddToViewport();
		}

		InputScoreWidget = Cast<UScoreInputWidget>(CreateWidget<UUserWidget>(PlayerController, InputWidget));
		if (InputScoreWidget)
		{
			InputScoreWidget->AddToViewport();
		}
	}

}

// Called to initilizate Bindings from other Widget classes.
void UUIManager::InitializateClassEventBinding()
{
	if (ButtonActionWidget)
	{
		// Bind Delegate event to function that recieves enum.
		ButtonActionWidget->ButtonActionTypeEvent.BindUObject(this, &UUIManager::ExecuteActionFromButtonPressed);
	}

	if (PlayerController)
	{
		// Get GameMode to interact with Frames and tries by player.
		BowlingGameMode = PlayerController->GetWorld()->GetAuthGameMode<ABowlingScoreGameMode>();
	}

}

// Recieves as a parameter a Enum from BoardActionWidget to determine wich button was pressed.
void UUIManager::ExecuteActionFromButtonPressed(EButtonAction ButtonAction)
{
	switch (ButtonAction)
	{
	case CONFIRM:
		if (BowlingGameMode && InputScoreWidget && ScoreBoardWidget)
		{
			int32 CurrentFrame = BowlingGameMode->GetCurrentFrame() - 1;
			int32 PlayerThrowTry = BowlingGameMode->GetCurrentTry();

			int32 ScoreEntered = InputScoreWidget->GetScoreFromEditableTextBlock();

			if (ScoreEntered >= MinValue && ScoreEntered <= MaxValue)
			{
				// Clear the Score in InputWidget.
				InputScoreWidget->CleanEditabletextBlock();

				ManageAttemptsByThePlayerInput(CurrentFrame, PlayerThrowTry, ScoreEntered);

				ManagePointsCalculations(CurrentFrame);
			}
			else
			{
				UE_LOG(LogTemp, Warning, TEXT("Out of parameter value, ScoreEntered: %i"), ScoreEntered);
			}
		}
		break;
	case CLEAR_INPUT:
		InputScoreWidget->CleanEditabletextBlock();
		break;
	case CLEAR_SCORE:

		break;
	case EXIT_GAME:
		UE_LOG(LogTemp, Warning, TEXT("EXIT GAME FROM EDITOR"));
		break;
	default:
		break;
	}

}

void UUIManager::ManageAttemptsByThePlayerInput(int32 Frame, int32 Attempts, int32 Score)
{
	// First try.
	if (Attempts == 1)
	{
		if (Score < MaxValue)
		{
			// Set First try Score.
			ScoreBoardWidget->SetFirstTryScore(Frame, FString::FromInt(Score));
		}
		else
		{
			// Set Strike.
			ScoreBoardWidget->SetFirstTryScore(Frame, FString::FromInt(MinValue - 1));
			ScoreBoardWidget->SetSecondTryScore(Frame, FString::FromInt(MaxValue));

			// Move to next try immediately.
			BowlingGameMode->ChangeToTheNextFrame();

			return; // Exit here, because after a strike, no second try is needed.
		}

		BowlingGameMode->AddNextTry();
	}
	// Second Try
	else
	{
		int32 FirstTryScore = ScoreBoardWidget->GetFirstTryScore(Frame);

		// Check for a Spare.
		if (Score + FirstTryScore == MaxValue or Score + FirstTryScore < MaxValue)
		{
			ScoreBoardWidget->SetSecondTryScore(Frame, FString::FromInt(Score));
			BowlingGameMode->AddNextTry();
			BowlingGameMode->ChangeToTheNextFrame();
		}
	}

}

void UUIManager::ManagePointsCalculations(int32 Frame)
{
	if (Frame == MinValue - 1)
	{
		// Simply sum the two attempts of the last frame.
		ScoreBoardWidget->SetFrameScore(Frame, FString::FromInt(ScoreBoardWidget->GetFirstTryScore(Frame) + ScoreBoardWidget->GetSecondTryScore(Frame)));
	}
	else if (Frame > MinValue - 1) // If it's not the last frame, evaluate based on previous frames
	{
		// Sum the score of the two attempts in the current frame plus the accumulated score from previous frames.
		int32 TotalPreviousFramesScore = ScoreBoardWidget->GetFrameScore(Frame - 1);
		ScoreBoardWidget->SetFrameScore(Frame, FString::FromInt(ScoreBoardWidget->GetFirstTryScore(Frame) + ScoreBoardWidget->GetSecondTryScore(Frame) + TotalPreviousFramesScore));

		// Check if the previous frame was a Strike
		if (ScoreBoardWidget->GetFirstTryScore(Frame - 1) == MinValue - 1 && ScoreBoardWidget->GetSecondTryScore(Frame - 1) == 0) // Checks if it was a Strike
		{
			// If it was a Strike, add the full score of the current frame (both attempts).
			ScoreBoardWidget->SetFrameScore(Frame - 1, FString::FromInt(MaxValue + ScoreBoardWidget->GetFirstTryScore(Frame) + ScoreBoardWidget->GetSecondTryScore(Frame) + TotalPreviousFramesScore));
		}
		// Check if the previous frame was a Spare
		else if ((ScoreBoardWidget->GetFirstTryScore(Frame - 1) + ScoreBoardWidget->GetSecondTryScore(Frame - 1)) == MaxValue) // Checks if it was a Spare
		{
			// If it was a Spare, add only the first attempt of the current frame.
			ScoreBoardWidget->SetFrameScore(Frame - 1, FString::FromInt(MaxValue + ScoreBoardWidget->GetFirstTryScore(Frame) + TotalPreviousFramesScore));
		}
	}

}
