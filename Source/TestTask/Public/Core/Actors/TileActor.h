// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"


#include "CoinActor.h"
#include "DamageActor.h"
#include "Components/ArrowComponent.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"

#include "TileActor.generated.h"

UCLASS()
class TESTTASK_API ATileActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATileActor();

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Tile")
	USceneComponent* RootComp;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Tile")
	UStaticMeshComponent* TileBody;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Tile")
	UStaticMeshComponent* LeftSide;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Tile")
    UStaticMeshComponent* RightSide;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Tile")
	UBoxComponent* TriggerBox;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Tile")
	UArrowComponent* SpawnDirection;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Tile")
	UArrowComponent* SpawnObstaclePoint;

	
	//get point to spawn next tile
	UFUNCTION(BlueprintCallable)
	FTransform GetAttachTransformPoint();

	//get point to spawn obstacle
	UFUNCTION(BlueprintCallable)
    FTransform GetSpawnObstaclePoint();

	UFUNCTION(BlueprintCallable)
	void TriggerEnabled(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
    UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);
	
	//Timer for tile destruction
	FTimerHandle TriggerDestroyTile;

	void TriggerDestroy();
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
