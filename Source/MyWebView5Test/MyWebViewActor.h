// Fill out your copyright notice in the Description page of Project Settings.


// #include "../Source/Runtime/WebBrowser/Private/.h"

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
// #include "Components/Button.h"

#include "MyWebViewActor.generated.h"


UCLASS()
class MYWEBVIEW5TEST_API AMyWebViewActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyWebViewActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
    // void OpenWebBrowser(const FString &URL);
	
    // void SomeFunction();

private:
    // TSharedPtr<IWebBrowserWindow> BrowserWindow;
    // UPROPERTY(EditAnywhere)
    // UWebBrowser* WebBrowser;
    // UPROPERTY(EditAnywhere)
    // UWebBrowserWidget* BrowserWidget;


};
