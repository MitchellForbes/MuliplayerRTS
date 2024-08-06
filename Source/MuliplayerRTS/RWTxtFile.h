// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Misc/FileHelper.h"
#include "RWTxtFile.generated.h"

/**
 * 
 */
UCLASS()
class MULIPLAYERRTS_API URWTxtFile : public UBlueprintFunctionLibrary
{
	GENERATED_BODY() 

	UFUNCTION(BlueprintCallable, Category = "WriteTextFile")
		static FString ReadStringFromFile(FString FilePath, bool& bOutSuccess, FString& OutInfoMessage);

	UFUNCTION(BlueprintCallable, Category = "WriteTextFile")
		static void WriteStringToFile(FString FilePath,FString String, bool& bOutSuccess, FString& OutInfoMessage);
	
};
