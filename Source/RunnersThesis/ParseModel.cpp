// Fill out your copyright notice in the Description page of Project Settings.


#include "ParseModel.h"

void UParseModel::ReadFile(FString Directory, bool& Success, FString& OutInfoMessage, TArray<FString>& MStateActs, int& StateNumber, int& InitialState, int& AgentNum, TArray<FString>& AtomicProp, TArray<FString>& MLabelling)
{

	TArray<FString> RetString, TmpStringArray;
	FString Line, CurrentSection;

	if (!FPlatformFileManager::Get().GetPlatformFile().FileExists(*Directory))
	{
		Success = false;
		OutInfoMessage = FString::Printf(TEXT("Error: File not Found - '%s'"), *Directory);
		return;
	}

	if (!FFileHelper::LoadFileToStringArray(RetString, *Directory))
	{
		Success = false;
		OutInfoMessage = FString::Printf(TEXT("Error: Was not able to read file - '%s'"), *Directory);
		return;
	}

	for (int32 i = 0; i != RetString.Num(); i++)
	{
		Line = *RetString[i].TrimStartAndEnd();

		if (Line == "Transition")
			CurrentSection = "Transition";
		else if (Line == "Unkown_Transition_by")
			CurrentSection = "Unknown_Transition_by";
		else if (Line == "Name_State")
			CurrentSection = "Name_State";
		else if (Line == "Initial_State")
			CurrentSection = "Initial_State";
		else if (Line == "Atomic_propositions")
			CurrentSection = "Atomic_propositions";
		else if (Line == "Labelling")
			CurrentSection = "Labelling";
		else if (Line == "Number_of_agents")
			CurrentSection = "Number_of_agents";
		else if (CurrentSection == "Transition")
		{
			Line.ParseIntoArrayWS(TmpStringArray);
			MStateActs.Append(TmpStringArray);
		}
		//else if (CurrentSection == "Unknown_Transition_by")
		//	unknown_transition_content += Line + "\n"
		else if (CurrentSection == "Name_State")
		{
			Line.ParseIntoArrayWS(TmpStringArray);
			StateNumber = TmpStringArray.Num();
		}
		else if (CurrentSection == "Initial_State")
			InitialState = FCString::Atoi(*(Line.RightChop(1)));
		else if (CurrentSection == "Atomic_propositions")
			Line.ParseIntoArrayWS(AtomicProp);
		else if (CurrentSection == "Labelling")
		{
			Line.RemoveSpacesInline();
			MLabelling.Add(*Line);
		}
		else if (CurrentSection == "Number_of_agents")
			AgentNum = FCString::Atoi(*Line);

		//UE_LOG(LogTemp, Warning, TEXT("'%s'"), *RetString[i]);
	}

	Success = true;
	OutInfoMessage = FString::Printf(TEXT("Completed: File successfully parsed - '%s'"), *Directory);
	return;
}

void UParseModel::ReadNextActions(FString Directory, bool& bSuccess, FString& OutInfoMessage, TMap<FString, int> ActToIntCombination, TMap<int, FActionSeq>& ActSequence)
{

	TArray<FString> RetString, TmpStringArray;
	FString Line, SuccessString = "File Successfully Read";
	float delay = 0.05f;


	if (!FPlatformFileManager::Get().GetPlatformFile().FileExists(*Directory))
	{
		bSuccess = false;
		OutInfoMessage = FString::Printf(TEXT("Error: File not Found - '%s'"), *Directory);
		return;
	}

	if (!FFileHelper::LoadFileToStringArray(RetString, *Directory))
	{
		bSuccess = false;
		OutInfoMessage = FString::Printf(TEXT("Error: Was not able to read file - '%s'"), *Directory);
		return;
	}

	while (RetString[0].StartsWith("<") || RetString[0].StartsWith("!"))
	{
		FFileHelper::LoadFileToStringArray(TmpStringArray, *Directory);
		if (!TmpStringArray.IsEmpty())
			RetString = TmpStringArray;
	}

	for (int32 i = 0; i != RetString.Num(); i++)
	{
		Line = *RetString[i].TrimStartAndEnd();
		Line.ParseIntoArrayWS(TmpStringArray);

		FActionSeq actS;
		actS.TargetState = FCString::Atoi(*TmpStringArray[1]);
		actS.ActCombination = *ActToIntCombination.Find(*TmpStringArray[2]);

		ActSequence.Add(FCString::Atoi(*TmpStringArray[0]), actS);
	}

	if (!FFileHelper::SaveStringToFile(SuccessString, *Directory))
	{
		bSuccess = false;
		OutInfoMessage = FString::Printf(TEXT("Error: Could not Write To File - '%s'"), *Directory);
		return;
	}

	bSuccess = true;
	return;
}

void UParseModel::WriteFile(FString Directory, bool& bSuccess, FString& OutInfoMessage, TArray<FString> MStateActs, int StateNumber, int InitialState, int ActionNum, int AgentNum, TArray<FString> AtomicProp, TArray<FString> MLabelling)
{
	FString currentString = "WritingTest";
	TArray <FString> writeToFile;
	int CState = 0, CAction = 0, i = 0;

	if (!FFileHelper::SaveStringToFile(currentString, *Directory))
	{
		bSuccess = false;
		OutInfoMessage = FString::Printf(TEXT("Error: Could not Write To File - '%s'"), *Directory);
		return;
	}


	writeToFile.Add("Transition");
	
	currentString = "";
	for (FString action : MStateActs)
	{
		while (action.Find("-") >= 0)
			action.RemoveAt(action.Find("-"));

		if((ActionNum > 1) && (CAction < ActionNum - 1))
			action = action.Append(",");

		currentString = currentString.Append(action);
		CAction++;

		if (CAction == ActionNum)
		{
			CAction = 0;
			CState++;
			if (CState == StateNumber)
			{
				CState = 0;
				writeToFile.Add(currentString);
				currentString = "";
			}
			else
				currentString = currentString.Append(" ");
		}
	}

	writeToFile.Add("Name_State");
	
	currentString = "";
	for (i = 0; i < StateNumber; i++)
	{
		currentString = currentString.Append("s" + FString::FromInt(i));
		if (i < (StateNumber - 1))
			currentString = currentString.Append(" ");
	}

	writeToFile.Add(currentString);


	writeToFile.Add("Initial_State");
	writeToFile.Add("s" + FString::FromInt(InitialState));


	writeToFile.Add("Atomic_propositions");

	currentString = "";
	for (i = 0; i < AtomicProp.Num(); i++)
	{
		if (AtomicProp[i] != "\0")
		{
			currentString = currentString.Append(AtomicProp[i]);
			if (i < (AtomicProp.Num() - 1))
				currentString = currentString.Append(" ");

		}
	}

	writeToFile.Add(currentString);


	writeToFile.Add("Labelling");

	for (i = 0; i < MLabelling.Num(); i++)
	{
		currentString = "";
		for (TCHAR c : MLabelling[i].GetCharArray())
		{
			currentString = currentString.AppendChar(c);
			currentString = currentString.Append(" ");
		}
		currentString = currentString.TrimEnd();
		writeToFile.Add(currentString);
	}

	writeToFile.Add("Number_of_agents");
	writeToFile.Add(FString::FromInt(AgentNum));


	FFileHelper::SaveStringArrayToFile(writeToFile, *Directory);

	bSuccess = true;
	OutInfoMessage = FString::Printf(TEXT("Completed: File successfully written - '%s'"), *Directory);
	return;
}

void UParseModel::ReadFormula(FString Directory, bool& Success, FString& OutInfoMessage, FString& FormulaString)
{
	TArray<FString> RetString;

	if (!FPlatformFileManager::Get().GetPlatformFile().FileExists(*Directory))
	{
		Success = false;
		OutInfoMessage = FString::Printf(TEXT("Error: File not Found - '%s'"), *Directory);
		return;
	}

	if (!FFileHelper::LoadFileToStringArray(RetString, *Directory))
	{
		Success = false;
		OutInfoMessage = FString::Printf(TEXT("Error: Was not able to read file - '%s'"), *Directory);
		return;
	}

	Success = true;
	OutInfoMessage = FString::Printf(TEXT("Completed: File successfully parsed - '%s'"), *Directory);
	FormulaString = *RetString[0];
	return;
}

void UParseModel::WriteFormula(FString Directory, bool& bSuccess, FString& OutInfoMessage, FString FormulaString)
{

	if (!FFileHelper::SaveStringToFile(FormulaString, *Directory))
	{
		bSuccess = false;
		OutInfoMessage = FString::Printf(TEXT("Error: Could not Write To File - '%s'"), *Directory);
		return;
	}

	bSuccess = true;
	OutInfoMessage = FString::Printf(TEXT("Completed: File successfully written - '%s'"), *Directory);
	return;
}


