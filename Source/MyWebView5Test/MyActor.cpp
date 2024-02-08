// Fill out your copyright notice in the Description page of Project Settings.
#include "MyActor.h"
#include "IWebBrowserCookieManager.h"
#include "IWebBrowserSingleton.h"
#include "WebBrowserModule.h"



// Sets default values
AMyActor::AMyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
void AMyActor::DeleteWebCacheFolder()
{
    FString WebCacheFolderPath = FPaths::Combine(FPaths::ProjectSavedDir(), TEXT("webcache_4430"));

    IPlatformFile& PlatformFile = FPlatformFileManager::Get().GetPlatformFile();

    if (PlatformFile.DirectoryExists(*WebCacheFolderPath))
    {
		 UE_LOG(LogTemp, Warning, TEXT("Directory does  exist---->>: %s"), *WebCacheFolderPath);
        PlatformFile.DeleteDirectoryRecursively(*WebCacheFolderPath);
    }
}
void AMyActor::DeleteDirectory(const FString& DirectoryToDelete)
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

/*void AMyActor::ClearBrowserCache()
{
     IWebBrowserSingleton* WebBrowserSingletons = IWebBrowserModule::Get().GetSingleton();

    if (WebBrowserSingletons)
    {
        IWebBrowserCookieManager* CookieManager = WebBrowserSingletons->GetCookieManager();

        if (CookieManager)
        {
            CookieManager->DeleteCookies();
			UE_LOG(LogTemp, Warning, TEXT(“DeleteCookies”));
        }
    }
   
} */

void AMyActor::ClearCacher()
{
     UE_LOG(LogTemp, Warning, TEXT("<<------Directory Clear Cache---->>:"));
    // Specify the paths to the cache folders you want to delete
//     FString IntermediatePath = FPaths::Combine(FPaths::ProjectIntermediateDir());
    FString SavedPath = FPaths::Combine(FPaths::ProjectSavedDir());
//   FString WebCacheFolderPath = FPaths::Combine(FPaths::ProjectSavedDir(), TEXT("webcache_4430"));
//     // Delete the folders
//     IFileManager::Get().DeleteDirectory(*IntermediatePath, false, true);
//     IFileManager::Get().DeleteDirectory(*SavedPath, false, true);


    FString WebCacheFolderPath = FPaths::Combine(SavedPath, TEXT("webcache_4430"));
    WebCacheFolderPath.ReplaceInline(TEXT("\\"), TEXT("/"));
    IFileManager::Get().DeleteDirectory(*WebCacheFolderPath, false, true); // Set to false to delete files only
}

void AMyActor::ClearWebBrowserCookies()
{
    // Get the Web Browser singleton
        
    IWebBrowserSingleton* WebBrowserSingleton = IWebBrowserModule::Get().GetSingleton();
        
    if (WebBrowserSingleton)
    {
        // WebBrowserSingleton->GetBrowser()->ClearCache(true);
        // WebBrowserSingleton->GetCookieManager().Get()->DeleteCookies();
        // Get the cookie manager proxy
        TSharedPtr<IWebBrowserCookieManager> CookieManager = WebBrowserSingleton->GetCookieManager();
        // FString WebCacheFolderPath = FPaths::ProjectSavedDir();
        FString WebCacheFolderPath = FPaths::Combine(FPaths::ProjectSavedDir(), TEXT("webcache_4430"));
        UE_LOG(LogTemp, Warning, TEXT("Web Cache FolderPath exist: %s"), *WebCacheFolderPath);
        WebBrowserSingleton->ClearOldCacheFolders(WebCacheFolderPath,"webcache_4430");

        if (CookieManager.IsValid())
        {
            CookieManager->DeleteCookies();
            UE_LOG(LogTemp, Warning, TEXT("<<-------------------ClearWebBrowserCookies--------------->>")); 
        }
          
    }
    
}