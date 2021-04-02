// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/Actors/CoinActor.h"


#include "TestTask/TestTaskCharacter.h"
#include "TestTask/TestTaskGameMode.h"
#include "Windows/LiveCoding/Private/External/LC_ClientStartupThread.h"

// Sets default values
ACoinActor::ACoinActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
    ScoreAmount=1;

	RootComp=CreateDefaultSubobject<USceneComponent>(TEXT("Scene Component"));
	RootComponent=RootComp;
	
	CoinBody=CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Coin Body"));
	CoinBody->SetupAttachment(RootComponent);
	
	TriggerBox=CreateDefaultSubobject<USphereComponent>(TEXT("Trigger Component"));
	TriggerBox->SetupAttachment(RootComponent);
	
	TriggerBox->OnComponentBeginOverlap.AddDynamic(this,&ACoinActor::OnCompOverlap);
}

void ACoinActor::OnCompOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
    UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult){
    
	ATestTaskGameMode* GameMode=Cast<ATestTaskGameMode>(GetWorld()->GetAuthGameMode());
	if(OtherActor->ActorHasTag("Player"))
	{
		Destroy();
		GameMode->Score+=ScoreAmount;
	}
}

// Called when the game starts or when spawned
void ACoinActor::BeginPlay()
{
	Super::BeginPlay();
	
}

void ACoinActor::BeginDestroy()
{
	Super::BeginDestroy();
}

// Called every frame
void ACoinActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

