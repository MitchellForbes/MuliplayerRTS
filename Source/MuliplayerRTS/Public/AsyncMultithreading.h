// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "AsyncMultithreading.generated.h"
#include "Hal/Runnable.h"

/**
 * 
 */
UCLASS()
class MULIPLAYERRTS_API UAsyncMultithreading : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()
	
};

class ASYNCDEMO_API FRunnableStep1 : FRunnable
{
public:
	FRunnableStep1();
	virutal ~FRunnable1();

private:
	FRunnableThread* Thread;

public:
	virtual void Exit() override;
	virtual bool Init() override;
	virtual uint32 Run() override;
	virtual void Stop() override;
};
