// Fill out your copyright notice in the Description page of Project Settings.


#include "RWTxtFile.h"

#include "HAL/PlatformFileManager.h" //core
#include "Misc/FileHelper.h" //core

FString MULIPLAYERRTS_API URWTxtFile::ReadStringFromFile(FString FilePath, bool& bOutSuccess, FString& OutInfoMessage)
{
	if (!FPlatformFileManager::Get().GetPlatformFile().FileExists(*FilePath))
	{
		bOutSuccess = false;
		OutInfoMessage = FString::Printf(TEXT("Read string from file failed - File Doesn't exits -'%s'"), *FilePath);
		return "";
	}

	FString RetString = "";

	if (!FFileHelper::LoadFileToString(RetString, *FilePath))
	{

		bOutSuccess = false;
		OutInfoMessage = FString::Printf(TEXT("Read string from file failed - Was not able to read file. is this a text file - '%s'"), *FilePath);
		return "";
	}

	bOutSuccess = true;
	OutInfoMessage = FString::Printf(TEXT("Read String from file Succeeded - '%s'"), *FilePath);
	return RetString;
}


void MULIPLAYERRTS_API URWTxtFile::WriteStringToFile(FString FilePath, FString String, bool& bOutSuccess, FString& OutInfoMessage)
{
	if (!FFileHelper::SaveStringToFile(String, *FilePath))
	{
		bOutSuccess = false;
		OutInfoMessage = FString::Printf(TEXT("Write string from file failed - Was not able to write to file. Is your file read only? is the path valid? - '%s'"), *FilePath);
		return;
	}

	bOutSuccess = true;
	OutInfoMessage = FString::Printf(TEXT("Write string from file Succeeded '%s'"), *FilePath);

}