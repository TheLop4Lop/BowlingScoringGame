// Fill out your copyright notice in the Description page of Project Settings.


#include "ScoreInputWidget.h"
#include "Components/EditableText.h" // Needed to interact with class and get scores.

// Get the content from ScoreText when Confirm Button is pressed.
int32 UScoreInputWidget::GetScoreFromEditableTextBlock()
{
	FText InputText = ScoreText->GetText();

	FString InputString = InputText.ToString();
	int32 ScoreInput = FCString::Atoi(*InputString);

	return ScoreInput;

}

// Clean the content of ScoreText.
void UScoreInputWidget::CleanEditabletextBlock()
{
	ScoreText->SetText(FText::FromString(""));

}
