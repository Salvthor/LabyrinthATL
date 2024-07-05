// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ActionSeq.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct FActionSeq
{
    GENERATED_BODY()

    UPROPERTY(BlueprintReadWrite)
    TArray<int32> TargetState;

    UPROPERTY(BlueprintReadWrite)
    TArray<int32> ActCombination;


    FActionSeq() = default;

    FActionSeq(const int tState, const int ActComb){
        TargetState.Add(tState);
        ActCombination.Add(ActComb);
    }
};
