// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/Actors/TileActor.h"

#include "Core/Actors/CoinActor.h"
#include "TestTask/TestTaskCharacter.h"
#include "TestTask/TestTaskGameMode.h"

// Sets default values
ATileActor::ATileActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComp=CreateDefaultSubobject<USceneComponent>(TEXT("Scene Component"));
	RootComponent=RootComp;
	
	TileBody=CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Tile Body"));
	TileBody->SetupAttachment(RootComponent);

	LeftSide=CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Left Side of the Tile"));
	LeftSide->SetupAttachment(RootComponent);

	RightSide=CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Right Side of the Tile"));
	RightSide->SetupAttachment(RootComponent);

	TriggerBox=CreateDefaultSubobject<UBoxComponent>(TEXT("Trigger Box Component"));
	TriggerBox->SetupAttachment(RootComponent);
	TriggerBox->OnComponentBeginOverlap.AddDynamic(this,&ATileActor::TriggerEnabled);

	SpawnDirection=CreateDefaultSubobject<UArrowComponent>(TEXT("Tile Spawn Direction "));
	SpawnDirection->SetupAttachment(RootComponent);
	
	SpawnObstaclePoint=CreateDefaultSubobject<UArrowComponent>(TEXT("Spawn Point"));
	SpawnObstaclePoint->SetupAttachment(RootComponent);
}


FTransform ATileActor::GetAttachTransformPoint()
{
	FTransform AttachPoint=SpawnDirection->GetComponentTransform();
	return AttachPoint;
}

FTransform ATileActor::GetSpawnObstaclePoint()
{
	FTransform SpawnPoint=SpawnObstaclePoint->GetComponentTransform();
	return SpawnPoint;
}

void ATileActor::TriggerEnabled(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
                                UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	ATestTaskCharacter* BaseCharacter=Cast<ATestTaskCharacter>(OtherActor);
	
	if(BaseCharacter){
		ATestTaskGameMode* BaseGameMode=Cast<ATestTaskGameMode>(GetWorld()->GetAuthGameMode());
		BaseGameMode->AddFloorTile();
		GetWorld()->GetTimerManager().SetTimer(TriggerDestroyTile,this,&ATileActor::TriggerDestroy,5.0f,true);
	}
}

void ATileActor::TriggerDestroy()
{
	Destroy();
}

// Called when the game starts or when spawned
void ATileActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATileActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

