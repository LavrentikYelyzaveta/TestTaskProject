// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/Actors/DamageActor.h"


#include "TestTask/TestTaskCharacter.h"
#include "TestTask/TestTaskGameMode.h"
#include "TestTask/TestTaskProjectile.h"

// Sets default values
ADamageActor::ADamageActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	RootComp=CreateDefaultSubobject<USceneComponent>(TEXT("Scene Component"));
	RootComponent=RootComp;
	
	DamageActorBody=CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Coin Body"));
	DamageActorBody->SetupAttachment(RootComponent);
	
	TriggerBox=CreateDefaultSubobject<UBoxComponent>(TEXT("Trigger Box Component"));
	TriggerBox->SetupAttachment(RootComponent);
	
	TriggerBox->OnComponentHit.AddDynamic(this,&ADamageActor::OnCompHit);
}

void ADamageActor::OnCompHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	FVector NormalImpulse, const FHitResult& Hit)
{
	if(OtherActor->ActorHasTag("Projectile"))
	{
			Destroy();
	}
	
	ATestTaskGameMode* GameMode=Cast<ATestTaskGameMode>(GetWorld()->GetAuthGameMode());
	if(OtherActor->ActorHasTag("Player"))
	{
		GameMode->Health--;
		Destroy();
	}
}

// Called when the game starts or when spawned
void ADamageActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADamageActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

