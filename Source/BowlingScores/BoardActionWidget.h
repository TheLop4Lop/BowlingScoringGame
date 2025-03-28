// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "BoardActionWidget.generated.h"

// Enum to pass as a parameter in Delegate event.
enum EButtonAction
{
	CONFIRM,
	CLEAR_INPUT,
	CLEAR_SCORE,
	EXIT_GAME

};

// Delegate with One Parameter to excecute ActionButton logic, depends on the button pressed.
DECLARE_DELEGATE_OneParam(FButtonActionDelegate, EButtonAction)

/**
 * 
 */
UCLASS()
class BOWLINGSCORES_API UBoardActionWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	// Declare instance that store a function reference to trigger a specific Button Action event.
	FButtonActionDelegate ButtonActionTypeEvent;

protected:
	virtual void NativeConstruct() override;

private:
	// UButton to confirm the entered score. Executes a event to send number to Score handler.
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UButton* ConfirmScoreButton;

	// UButton to clear single number input. Execute a event to clean score input.
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UButton* ClearInputButton;

	// UButton to clear all the enterd data in Bowling Score Board. Excecutes a event to clean all data.
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UButton* ClearBoardButton;

	// Exit game.
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UButton* ExitButton;

	// Binds Button to their respective function logic.
	void BindConfirmButtonAction();

	// Binds Button to their respective function logic.
	void BindClearButtonActions();

	// Binds Button to their respective function logic.
	void BindExitButtonAction();

	// Bind function. Executes Confirm delegate.
	UFUNCTION()
	void SetConfirmButtonLogic();

	// Bind function. Executes Clear Input delegate.
	UFUNCTION()
	void SetClearInputButotnLogic();

	// Bind function. Executes Clear Board delegate.
	UFUNCTION()
	void SetClearBoardButtonLogic();

	// Bind function. Executes Exit Game delegate.
	UFUNCTION()
	void SetExitButtonLogic();

};
