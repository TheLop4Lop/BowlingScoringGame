// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ScoreInputWidget.generated.h"

/**
 * 
 */
UCLASS()
class BOWLINGSCORES_API UScoreInputWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	// Get the content from ScoreText when Confirm Button is pressed.
	int32 GetScoreFromEditableTextBlock();

	// Clean the content of ScoreText.
	void CleanEditabletextBlock();

private:
	// Holds reference for visual representation of Input Table.
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UImage* ScoreImage;

	// Text block to display score.
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UTextBlock* Score;

	// Text block to display score.
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UEditableText* ScoreText;
	
};
