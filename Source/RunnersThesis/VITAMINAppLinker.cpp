// Fill out your copyright notice in the Description page of Project Settings.



#include "VITAMINAppLinker.h"

void UVITAMINAppLinker::LinkVitamin(FString command, FString& result)
{
    UE_LOG(LogTemp, Warning, TEXT("Hello"));
    char buffer[512];
    auto pipe = _popen(TCHAR_TO_ANSI(*command), "r");
    

    if (!pipe) throw std::runtime_error("popen() failed!");

    while (!feof(pipe))
    {
        if (fgets(buffer, 512, pipe) != nullptr)
        {
            UE_LOG(LogTemp, Warning, TEXT("%s"), buffer);
            result += buffer;
        }
        else
            UE_LOG(LogTemp, Warning, TEXT("ITS NULL MAN :(("));
    }

    auto rc = _pclose(pipe);

    if (rc == EXIT_SUCCESS)
    {
        std::cout << "SUCCESS\n";
    }
    else
    {
        std::cout << "FAILED\n";
    }

    return;
}
