// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include <iostream>
#include <cstdio>
#include <memory>
#include <stdexcept>
#include <string>
#include <array>
#include "VITAMINAppLinker.generated.h"

/**
 * 
 */
UCLASS()
class LABYRINTHATL_API UVITAMINAppLinker : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	static void LinkVitamin(FString command, FString& result);

};
