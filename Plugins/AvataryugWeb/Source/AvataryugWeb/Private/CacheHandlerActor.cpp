// Fill out your copyright notice in the Description page of Project Settings.


#include "CacheHandlerActor.h"

// Sets default values
ACacheHandlerActor::ACacheHandlerActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACacheHandlerActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACacheHandlerActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACacheHandlerActor::DeleteWebCacheFolder()
{
    FString WebCacheFolderPath = FPaths::Combine(FPaths::ProjectSavedDir(), TEXT("webcache_4430"));

    IPlatformFile& PlatformFile = FPlatformFileManager::Get().GetPlatformFile();

    if (PlatformFile.DirectoryExists(*WebCacheFolderPath))
    {
        UE_LOG(LogTemp, Warning, TEXT("Directory does  exist---->>: %s"), *WebCacheFolderPath);
        PlatformFile.DeleteDirectoryRecursively(*WebCacheFolderPath);
    }
}

void ACacheHandlerActor::DeleteDirectory(const FString& DirectoryToDelete)
{
    IPlatformFile& PlatformFile = FPlatformFileManager::Get().GetPlatformFile();

    // Ensure the directory exists before attempting to delete
    if (PlatformFile.DirectoryExists(*DirectoryToDelete))
    {
        // Delete the directory and its contents
        PlatformFile.DeleteDirectoryRecursively(*DirectoryToDelete);
    }
    else
    {
        // Directory does not exist, handle accordingly
        UE_LOG(LogTemp, Warning, TEXT("Directory does not exist: %s"), *DirectoryToDelete);
    }
}

void ACacheHandlerActor::ClearCacher()
{
    UE_LOG(LogTemp, Warning, TEXT("<<------Directory Clear Cache---->>:"));
    FString SavedPath = FPaths::Combine(FPaths::ProjectSavedDir());
    FString WebCacheFolderPath = FPaths::Combine(SavedPath, TEXT("webcache_4430"));
    WebCacheFolderPath.ReplaceInline(TEXT("\\"), TEXT("/"));
    IFileManager::Get().DeleteDirectory(*WebCacheFolderPath, false, true); // Set to false to delete files only
}

void ACacheHandlerActor::ClearWebBrowserCookies()
{
    IWebBrowserSingleton* WebBrowserSingleton = IWebBrowserModule::Get().GetSingleton();
    if (WebBrowserSingleton)
    {
        TSharedPtr<IWebBrowserCookieManager> CookieManager = WebBrowserSingleton->GetCookieManager();
        FString WebCacheFolderPath = FPaths::Combine(FPaths::ProjectSavedDir(), TEXT("webcache_4430"));
        UE_LOG(LogTemp, Warning, TEXT("Web Cache FolderPath exist: %s"), *WebCacheFolderPath);
        WebBrowserSingleton->ClearOldCacheFolders(WebCacheFolderPath, "webcache_4430");
        if (CookieManager.IsValid())
        {
            CookieManager->DeleteCookies();
            UE_LOG(LogTemp, Warning, TEXT("<<-------------------ClearWebBrowserCookies--------------->>"));
        }
    }
}