// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

#include "Core/Actors/TileActor.h"
#include "GameFramework/GameModeBase.h"
#include "TestTaskGameMode.generated.h"

UCLASS(minimalapi)
class ATestTaskGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ATestTaskGameMode();
	
	UPROPERTY(EditAnywhere)
	TSubclassOf<ATileActor> ActorToSpawn;

	UFUNCTION(BlueprintCallable)
	void AddFloorTile();
	
	UPROPERTY(BlueprintReadWrite)
	FTransform NextSpawnPoint;

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	float Health;

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	int32 Score;

	virtual void BeginPlay() override;

};



