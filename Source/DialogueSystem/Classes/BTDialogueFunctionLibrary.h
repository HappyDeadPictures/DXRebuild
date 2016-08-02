// Copyright 2015 Mavrin Artem. All Rights Reserved.

#pragma once
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Components/SlateWrapperTypes.h"

#include "DialogueSettings.h"
#include "BTDialogueFunctionLibrary.generated.h"

class UBlackboardComponent;
struct FBlackboardKeySelector;

//UCLASS(meta = (RestrictedToClasses = "BTNode"))
UCLASS()
class DIALOGUESYSTEM_API UBTDialogueFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "DialogueSystem|Dialogue", Meta = (HidePin = "NodeOwner", DefaultToSelf = "NodeOwner"))
		static void SetQuestionVisibility(UBTNode* NodeOwner, FString QuestionNodeName, bool NewVisibility);

	UFUNCTION(BlueprintCallable, Category = "DialogueSystem|Dialogue", Meta = (DefaultToSelf = "EventListener"))
		static void SkipCurrentPhrase(UDialogueEventListener* EventListener);

	UFUNCTION(BlueprintCallable, Category = "DialogueSystem|Dialogue", Meta = (DefaultToSelf = "DialogueSettings"))
		static ADialogueSettings* GenerateSettings(TSubclassOf<ADialogueSettings> DialogueSettings, APlayerController* PlayerController);
	
};