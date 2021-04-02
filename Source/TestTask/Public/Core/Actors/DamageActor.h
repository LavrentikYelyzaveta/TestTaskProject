// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "Components/BoxComponent.h"
#include "GameFramework/Actor.h"
#include "DamageActor.generated.h"

UCLASS()
class TESTTASK_API ADamageActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADamageActor();
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Tile")
	USceneComponent* RootComp;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Tile")
	UStaticMeshComponent* DamageActorBody;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Tile")
	UBoxComponent* TriggerBox;

	UFUNCTION()
	void OnCompHit(UPrimitiveComponent* HitComponent, AActor* OtherActor,
		UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
