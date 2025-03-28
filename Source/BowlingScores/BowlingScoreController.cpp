// Fill out your copyright notice in the Description page of Project Settings.


#include "BowlingScoreController.h"
#include "Blueprint/UserWidget.h"  // Needed to use Widgets subclasses.
#include "UIManager.h" // Needed to pass the widget classes to implement and add to viewport.

void ABowlingScoreController::BeginPlay()
{
	Super::BeginPlay();

	// Make a instance of UIManager class.
	UIManager = NewObject<UUIManager >(this);
	if (UIManager)
	{
		UIManager->ImplementBowlingScoreWidgets(ScoreBoardWidgetClass, ButtonActionWidgetClass, InputScoreWidgetClass, this);
		UIManager->InitializateClassEventBinding();
	}

	// To stay outside of Game Mode.
	SetInputMode(FInputModeUIOnly());
	bShowMouseCursor = true;

}
