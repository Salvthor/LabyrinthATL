// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Runtime/Networking/Public/Networking.h"
#include "VITAMINLinker.generated.h"


UCLASS()
class LABYRINTHATL_API AVITAMINLinker : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AVITAMINLinker();

	UPROPERTY(Category = MapsAndSets, EditAnywhere)
	TArray<FString> ByteToLetterActs;

	UPROPERTY(Category = MapsAndSets, EditAnywhere)
	TArray<FString> ByteToLetterAP;


	UFUNCTION(BlueprintCallable)
	void TransposeMap(TMap<FString, uint8> ActionMap, bool Uppercase, TArray<FString>& ByteToLetterMap);

	UFUNCTION(BlueprintCallable)
	void LinkVitamin(FString command, FString& result);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
