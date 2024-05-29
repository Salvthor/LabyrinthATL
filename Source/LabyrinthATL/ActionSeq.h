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
    int TargetState = -1;

    UPROPERTY(BlueprintReadWrite)
    int ActCombination = -1;

    FActionSeq() :
        TargetState(-1), ActCombination(-1)
    {}

    FActionSeq(const int tState, const int ActComb): 
        TargetState(tState), ActCombination(ActComb)
    {}
};
