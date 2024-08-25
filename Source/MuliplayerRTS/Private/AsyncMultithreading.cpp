// Fill out your copyright notice in the Description page of Project Settings.


#include "AsyncMultithreading.h"

FRunnableStep1::FRunnableSTEP1()
{
	Thread = FRunnableThread::Create(this, TEXT("Step 1"));
}
FRunnableStep1:: ~FRunnableStep1()
{
	if (Thread)
	{
		Thread->Kill();
		delete Thread;
	}
}
void FRunnable1::Exit()
{
	// Called in the context of the aggregrating thread to perfrom any cleanup
}
void FRunnable1::Init()
{
	return true;
}
void FRunnable1::Run()
{
	while (true)
	{
		UE_LOG(Logtemp, Display, TEXT("Step 1: This code is running asynchronously!!"))
			FPlatformProcess::Sleep(1.0f);
	}

}
void FRunnable1::Stop()
{
	//Gets called by Thread -> Kill()
}