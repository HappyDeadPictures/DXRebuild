// Copyright 2015 Mavrin Artem. All Rights Reserved.

#include "DialogueSystemPrivatePCH.h"
#include "BTComposite_QuestionGroup.h"
#include "BTDialogueFunctionLibrary.h"

void UBTDialogueFunctionLibrary::SetQuestionVisibility(UBTNode* NodeOwner, FString QuestionNodeName, bool NewVisibility)
{
	check(NodeOwner != NULL);
	UBTComposite_QuestionGroup* QuestionGroup;

	QuestionGroup = Cast<UBTComposite_QuestionGroup>(NodeOwner);
	if (!QuestionGroup)
	{
		QuestionGroup = Cast<UBTComposite_QuestionGroup>(NodeOwner->GetParentNode());
	}
	if (QuestionGroup)
	{
		for (auto& Child : QuestionGroup->Children)
		{
			UBTComposite_Question* Question = Cast<UBTComposite_Question>(Child.ChildComposite);
			if (Question && Question->GetNodeName() == QuestionNodeName)
			{
				Question->bVisible = NewVisibility;
			}
		}
	}
}

void UBTDialogueFunctionLibrary::SkipCurrentPhrase(UDialogueEventListener* EventListener)
{
	if (EventListener != nullptr)
	{
		UBTTask_ShowPhrases* Node = EventListener->ShowPhrasesNode;
		if (Node != nullptr)
		{
			Node->OwnerActor->GetWorldTimerManager().ClearTimer(Node->TimerHandle);
			Node->ShowNewDialoguePhrase(true);
		}
	}
}

ADialogueSettings* UBTDialogueFunctionLibrary::GenerateSettings(TSubclassOf<ADialogueSettings> DialogueSettings, APlayerController* PlayerController)
{
	ADialogueSettings* DS = PlayerController->GetWorld()->SpawnActor<ADialogueSettings>((UClass*)DialogueSettings);
	DS->PlayerController = PlayerController;
	return DS;
}