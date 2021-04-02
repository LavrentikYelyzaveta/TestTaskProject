// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "Components/BoxComponent.h"
#include "Components/SphereComponent.h"
#include "GameFramework/Actor.h"
#include "CoinActor.generated.h"

UCLASS()
class TESTTASK_API ACoinActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACoinActor();

	UPROPERTY(EditAnywhere)
	int32 ScoreAmount;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Tile")
	USceneComponent* RootComp;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Tile")
	UStaticMeshComponent* CoinBody;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Tile")
	USphereComponent* TriggerBox;

	UFUNCTION()
	void OnCompOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
    UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void BeginDestroy() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
