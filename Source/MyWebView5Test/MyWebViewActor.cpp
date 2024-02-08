// Fill out your copyright notice in the Description page of Project Settings.

// #include "WebBrowserModule.h"  // Add this include
// #include "WebBrowserWidget.h"
#include "MyWebViewActor.h"

// Sets default values
AMyWebViewActor::AMyWebViewActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
    // WebBrowserWidget = CreateDefaultSubobject<UWebBrowserWidget>(TEXT("WebBrowser"));
    // WebBrowserWidget->SetVisibility(true);
    // RootComponent = WebBrowserWidget;
}

// Called when the game starts or when spawned
void AMyWebViewActor::BeginPlay()
{
	Super::BeginPlay();
	// WebBrowser->LoadURL(TEXT("https://www.goggle.com"));
	// if (WebBrowserWidget)
    // {
    //     WebBrowserWidget->LoadURL("https://www.goggle.com");
    // }
}

// Called every frame
void AMyWebViewActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
// void AMyWebViewActor::OpenWebBrowser(const FString& URL)
// {
//     // Open a web browser with the specified URL
//     FPlatformMisc::LowLevelOutputDebugStringf(TEXT("Opening web browser to %s\n"), *URL);
//     FPlatformProcess::LaunchURL(*URL, nullptr, nullptr);
// }

// void AMyWebViewActor::SomeFunction()
// {
//     // Specify the URL you want to open
//     FString URL = TEXT("https://www.google.com");

//     // Open the web browser
//     OpenWebBrowser(URL);
// }
// void AMyWebViewActor::ClearBrowserCache()
// {
	// IWebBrowserSingleton* WebBrowserSingleton = IWebBrowserModule::Get().GetSingleton();

    // if (WebBrowserSingleton)
    // {
    //     IWebBrowserCookieManager* CookieManager = WebBrowserSingleton->GetCookieManager();

    //     if (CookieManager)
    //     {
    //         CookieManager->DeleteCookies();
    //     }
    // }
// }
