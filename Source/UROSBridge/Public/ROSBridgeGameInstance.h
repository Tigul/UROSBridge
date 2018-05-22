// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "ROSBRidgeHandler.h"

#include "ROSBridgeGameInstance.generated.h"

/**
 * Base class for an example GameInstance that holds an instance of FROSBridgeHandler.
 * The class is tickable and will call FROSBridgeHandler::Process() on every Tick.
 * To use this class, create a derived blueprint from it, configure 
 * ROSBridgeServerHost and ROSBridgeServerPort if necessary and set 
 * this Blueprint as the Game Instance for your project. This can be done 
 * in the UE4Editor -> Project Settings -> Maps & Modes.
 */
UCLASS()
class UROSBRIDGE_API UROSBridgeGameInstance : public UGameInstance, public FTickableGameObject
{
	GENERATED_BODY()

	void OnStart() override;
	
	virtual void Tick(float DeltaTime) override;
	virtual bool IsTickable() const override;
	virtual TStatId GetStatId() const override;
	
	virtual void Shutdown() override;

public:
	TSharedPtr<FROSBridgeHandler> ROSHandler;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "ROS")
	FString ROSBridgeServerHost = "127.0.0.1";

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "ROS")
	int32 ROSBridgeServerPort = 9090;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "ROS")
	bool bConnectToROS = true;
};