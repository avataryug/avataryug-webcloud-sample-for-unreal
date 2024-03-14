// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "IWebBrowserCookieManager.h"
#include "IWebBrowserSingleton.h"
#include "WebBrowserModule.h"
#include "CacheHandlerActor.generated.h"

UCLASS()
class AVATARYUGWEB_API ACacheHandlerActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACacheHandlerActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, Category = "WebCache")
	void DeleteWebCacheFolder();

	UFUNCTION(BlueprintCallable, Category = "WebCache")
	void DeleteDirectory(const FString& DirectoryToDelete);

	UFUNCTION(BlueprintCallable, Category = "WebCache")
	void ClearCacher();

	UFUNCTION(BlueprintCallable, Category = "WebCache")
	void ClearWebBrowserCookies();
};
