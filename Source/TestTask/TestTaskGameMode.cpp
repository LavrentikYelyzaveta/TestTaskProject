// Copyright Epic Games, Inc. All Rights Reserved.

#include "TestTaskGameMode.h"
#include "TestTaskHUD.h"
#include "TestTaskCharacter.h"
#include "Core/Actors/TileActor.h"
#include "Kismet/GameplayStatics.h"
#include "UObject/ConstructorHelpers.h"

ATestTaskGameMode::ATestTaskGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = ATestTaskHUD::StaticClass();
	
	Health=4.0f;
	Score=0.0f;
}

void ATestTaskGameMode::AddFloorTile()
{
	if(ActorToSpawn)
	{
		UWorld* CurrentWorld=GetWorld();
		if(CurrentWorld)
		{
			FActorSpawnParameters SpawnInfo;
			SpawnInfo.Owner=this;
			ATileActor* SpawnedActor = CurrentWorld->SpawnActor<ATileActor>(ActorToSpawn,NextSpawnPoint.GetLocation(),NextSpawnPoint.Rotator(), SpawnInfo);
			NextSpawnPoint = SpawnedActor->GetAttachTransformPoint();
		}
	}
}

void ATestTaskGameMode::BeginPlay()
{
	Super::BeginPlay();
	
}

