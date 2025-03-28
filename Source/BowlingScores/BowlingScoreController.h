// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "BowlingScoreController.generated.h"

/**
 * 
 */
UCLASS()
class BOWLINGSCORES_API ABowlingScoreController : public APlayerController
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;

	//virtual void SetupInputComponent() override;

private:
	// Store reference instance class for Score Table Widget Class 
	UPROPERTY(EditAnywhere, Category = "UI", meta = (AllowPrivateAccess))
	TSubclassOf<UUserWidget> ScoreBoardWidgetClass;

	// Store reference instance class for Board Action Widget Class
	UPROPERTY(EditAnywhere, Category = "UI", meta = (AllowPrivateAccess))
	TSubclassOf<UUserWidget> ButtonActionWidgetClass;

	// Store reference instance class for Score Input Widget Class.
	UPROPERTY(EditAnywhere, Category = "UI", meta = (AllowPrivateAccess))
	TSubclassOf<UUserWidget> InputScoreWidgetClass;

	// Holds value for UIManager intance.
	class UUIManager* UIManager;

};
