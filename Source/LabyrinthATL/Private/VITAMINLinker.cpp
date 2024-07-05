// Fill out your copyright notice in the Description page of Project Settings.


#include "VITAMINLinker.h"

// Sets default values
AVITAMINLinker::AVITAMINLinker()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}


void AVITAMINLinker::TransposeMap(TMap<FString, uint8> Map, bool Uppercase, TArray<FString>& ByteToLetterMap)
{

    FString albet{ "abcdefghijklmnopqrstuvwxyz" };
    int offset = 0;

    if (Uppercase == true)
        albet = albet.ToUpper();

    TArray<TCHAR> alphabet = albet.GetCharArray();

    for (auto& Elem : Map)
    {   
        FString cString = FString(1, &alphabet[Elem.Value + offset]);

        if (Uppercase == true) //if uppercase is true we are managing the Action Map
        {
            if (Elem.Key.Equals("Idle"))
            {
                ByteToLetterActs.Add("I");
                ByteToLetterMap.Add("I");
                offset = 1;
            }
            else if (!Elem.Key.Equals("0"))
            {
                ByteToLetterActs.Add(cString);
                ByteToLetterMap.Add(cString);
            }
            else
            {
                ByteToLetterActs.Add("0");
                ByteToLetterMap.Add("0");
            }
        }
        else if ((!Elem.Key.Equals("0")) && (!Elem.Key.Equals("true")) && (!Elem.Key.Equals("false"))) //if is false we are managing the Atomic Proposition Map
        {
            ByteToLetterAP.Add(cString);
            ByteToLetterMap.Add(cString);
        }
    }

}

void AVITAMINLinker::LinkVitamin(FString command, FString& result)
{
}

// Called when the game starts or when spawned
void AVITAMINLinker::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AVITAMINLinker::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

