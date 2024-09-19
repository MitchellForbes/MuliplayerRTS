// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "MultiThreading.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FTaskOutput);

/**
 * 
 */
UCLASS()
class MULIPLAYERRTS_API UMultiThreading : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()
	
	public:

	UPROPERTY(BlueprintAssignable)
		FTaskOutput MultiThreadedWork;

	UPROPERTY(BlueprintAssignable)
		FTaskOutput FinishedWork;

	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"))
		static UMultiThreading* MultiThreadedNode();

	virtual void Activate() override;
};

//============================================================================

class BP_NonAbandonableTask : public FNonAbandonableTask
{

public:
	
	BP_NonAbandonableTask(UMultiThreading* BP_TaskInstance);

	~BP_NonAbandonableTask();


	FORCEINLINE TStatId GetStatId() const
	{
		RETURN_QUICK_DECLARE_CYCLE_STAT(BP_NonAbandonableTask, STATGROUP_ThreadPoolAsyncTasks);
	};

	UMultiThreading* CallingObject = nullptr;

	void DoWork();
};
