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
			UE_LOG(LogTemp, Warning, TEXT("TOP, CurrentFrame: %i, PlayerThrowTry: %i, ScoreEntered: %i"), CurrentFrame + 1, PlayerThrowTry, ScoreEntered);

			// Clear the Score in InputWidget.
			InputScoreWidget->CleanEditabletextBlock();

			// First try.
			if (PlayerThrowTry == 1)
			{
				if (ScoreEntered < MaxValue)
				{
					// Set First try Score.
					ScoreBoardWidget->SetFirstTryScore(CurrentFrame, FString::FromInt(ScoreEntered));
				}
				else
				{
					// Set Strike (No second try needed).
					ScoreBoardWidget->SetFirstTryScore(CurrentFrame, FString::FromInt(MinValue - 1));
					ScoreBoardWidget->SetSecondTryScore(CurrentFrame, FString::FromInt(MaxValue));

					// Move to next try immediately.
					BowlingGameMode->AddNextTry();
					BowlingGameMode->ChangeToTheNextFrame();

					return; // Exit here, because after a strike, no second try is needed.
				}

				BowlingGameMode->AddNextTry();
			}
			// Second Try
			else
			{
				int32 FirstTryScore = ScoreBoardWidget->GetFirstTryScore(CurrentFrame);

				// Check for a Spare.
				if (ScoreEntered + FirstTryScore == MaxValue)
				{
					ScoreBoardWidget->SetSecondTryScore(CurrentFrame, FString::FromInt(ScoreEntered));
					BowlingGameMode->AddNextTry();
					BowlingGameMode->ChangeToTheNextFrame();
				}
			}
			UE_LOG(LogTemp, Warning, TEXT("Down, CurrentFrame: %i, PlayerThrowTry: %i, ScoreEntered: %i"), CurrentFrame + 1, PlayerThrowTry, ScoreEntered);
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
