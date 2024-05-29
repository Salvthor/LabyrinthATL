// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "Kismet/BlueprintFunctionLibrary.h"
#include "CoreMinimal.h"
#include "Misc/FileHelper.h"
#include "Misc/Paths.h"
#include "HAL/PlatformFileManager.h"
#include "Internationalization/Regex.h"
#include "ActionSeq.h"

#include "ParseModel.generated.h"

/**
 *
 */
UCLASS()
class LABYRINTHATL_API UParseModel : public UBlueprintFunctionLibrary
{

	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable)
	static void ReadFormula(FString Directory, bool& bSuccess, FString& OutInfoMessage, FString& FormulaString);

	UFUNCTION(BlueprintCallable)
	static void WriteFormula(FString Directory, bool& bSuccess, FString& OutInfoMessage, FString FormulaString);
	
	UFUNCTION(BlueprintCallable)
	static void ReadFile(FString Directory, bool& bSuccess, FString& OutInfoMessage, TArray<FString>& MStateActs, int& StateNumber, int& InitialState, int& AgentNum, TArray<FString>& AtomicProp, TArray<FString>& MLabelling);

	UFUNCTION(BlueprintCallable)
	static void WriteFile(FString Directory, bool& bSuccess, FString& OutInfoMessage, TArray<FString> MStateActs, int StateNumber, int InitialState, int ActionNum, int AgentNum, TArray<FString> AtomicProp, TArray<FString> MLabelling);

	UFUNCTION(BlueprintCallable)
	static void ReadNextActions(FString Directory, bool& bSuccess, FString& OutInfoMessage, TMap<FString, int> ActToIntCombination, TMap<int, FActionSeq>& ActSequence);


};
