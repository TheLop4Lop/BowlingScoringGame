// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "BoardActionWidget.h" // Needed to Interact with buttons events.
#include "UIManager.generated.h"

/**
 * 
 */
UCLASS()
class BOWLINGSCORES_API UUIManager : public UObject
{
	GENERATED_BODY()

public:
	// Implement and adds Widgets on screen.
	void ImplementBowlingScoreWidgets(TSubclassOf<UUserWidget> BoardWidget, TSubclassOf<UUserWidget> ButtonWidget,
										TSubclassOf<UUserWidget> InputWidget, class ABowlingScoreController* Controller);

	// Called to initilizate Bindings from other Widget classes.
	void InitializateClassEventBinding();

private:
	// Holds a UUserWidget intance for ScoreBoardWidgetClass.
	class UBowlingScoreTableWidget* ScoreBoardWidget;

	// Holds a UUserWidget intance for ScoreBoardWidgetClass.
	class UBoardActionWidget* ButtonActionWidget;

	// Holds a UUserWidget intance for ScoreBoardWidgetClass.
	class UScoreInputWidget* InputScoreWidget;

	// Holds reference to Player controller.
	class ABowlingScoreController* PlayerController;

	// Holds the reference to GameMode.
	class ABowlingScoreGameMode* BowlingGameMode;

	// Recieves as a parameter a Enum from BoardActionWidget to determine wich button was pressed.
	void ExecuteActionFromButtonPressed(enum EButtonAction ButtonAction);

	const int32 MaxValue = 10;
	const int32 MinValue = 1;
	
};
