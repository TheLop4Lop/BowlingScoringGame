// Fill out your copyright notice in the Description page of Project Settings.


#include "BoardActionWidget.h"
#include "Components/Button.h" // Needed to work with UBUtton class.

void UBoardActionWidget::NativeConstruct()
{
	Super::NativeConstruct();

	BindConfirmButtonAction();

}

// Binds all Buttons to their respective function logic.
void UBoardActionWidget::BindConfirmButtonAction()
{
	if (ConfirmScoreButton)
	{
		ConfirmScoreButton->OnReleased.AddDynamic(this, &UBoardActionWidget::SetConfirmButtonLogic);
	}

}

// Binds Button to their respective function logic.
void UBoardActionWidget::BindClearButtonActions()
{
	if (ClearInputButton)
	{
		ClearInputButton->OnReleased.AddDynamic(this, &UBoardActionWidget::SetClearInputButotnLogic);
	}

	if (ClearBoardButton)
	{
		ClearBoardButton->OnReleased.AddDynamic(this, &UBoardActionWidget::SetClearBoardButtonLogic);
	}

}

// Binds Button to their respective function logic.
void UBoardActionWidget::BindExitButtonAction() 
{
	if (ExitButton)
	{
		ExitButton->OnReleased.AddDynamic(this, &UBoardActionWidget::SetExitButtonLogic);
	}

}

// Bind function. Executes Confirm delegate.
void UBoardActionWidget::SetConfirmButtonLogic()
{
	ButtonActionTypeEvent.ExecuteIfBound(EButtonAction::CONFIRM);

}

// Bind function. Executes Clear Input delegate.
void UBoardActionWidget::SetClearInputButotnLogic()
{
	ButtonActionTypeEvent.ExecuteIfBound(EButtonAction::CLEAR_INPUT);

}

// Bind function. Executes Clear Board delegate.
void UBoardActionWidget::SetClearBoardButtonLogic()
{
	ButtonActionTypeEvent.ExecuteIfBound(EButtonAction::CLEAR_SCORE);

}

// Bind function. Executes Exit Game delegate.
void UBoardActionWidget::SetExitButtonLogic()
{
	ButtonActionTypeEvent.ExecuteIfBound(EButtonAction::EXIT_GAME);

}
