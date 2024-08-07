// Fill out your copyright notice in the Description page of Project Settings.


#include "MultiThreading.h"



UMultiThreading* UMultiThreading::MultiThreadedNode()
{
	UMultiThreading* Node = NewObject<UMultiThreading>();
	return Node;
}


void UMultiThreading::Activate()
{
	(new FAutoDeleteAsyncTask<BP_NonAbandonableTask>(this))->StartBackgroundTask();
}

//===========================================================================


BP_NonAbandonableTask::BP_NonAbandonableTask(UMultiThreading* BP_TaskInstance)
{
	CallingObject = BP_TaskInstance;
}

BP_NonAbandonableTask::~BP_NonAbandonableTask()
{
	CallingObject->FinishedWork.Broadcast();
	CallingObject->SetReadyToDestroy();
}

void BP_NonAbandonableTask::DoWork()
{
	CallingObject->MultiThreadedWork.Broadcast();
}
