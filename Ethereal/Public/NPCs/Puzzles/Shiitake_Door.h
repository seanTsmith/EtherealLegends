// © 2014 - 2016 Soverance Studios
// www.soverance.com

// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at

// http://www.apache.org/licenses/LICENSE-2.0

// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#pragma once

#include "NPCs/EtherealNPCMaster.h"
#include "Shiitake_Door.generated.h"

UCLASS()
class ETHEREAL_API AShiitake_Door : public AEtherealNPCMaster
{
	GENERATED_BODY()

public:
	
	// Sets default values for this actor's properties
	AShiitake_Door(const FObjectInitializer& ObjectInitializer);

	// BeginPlay Override
	virtual void BeginPlay() override;
	
	// Interact with this NPC
	UFUNCTION(BlueprintCallable, Category = Default)
	void Interact();

	// Gear Mesh.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Default)
	UStaticMeshComponent* GearFront;
	UStaticMesh* SM_GearFront;

	// Gear Offside Mesh.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Default)
	UStaticMeshComponent* GearBack;
	UStaticMesh* SM_GearBack;

	// Gate Audio
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Effects)
	UAudioComponent* GateAudio;
	USoundCue* S_GateAudio;

	// Column Left Mesh.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Default)
	UStaticMeshComponent* ColumnLeft;
	UStaticMesh* SM_ColumnLeft;

	// Column Right Mesh.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Default)
	UStaticMeshComponent* ColumnRight;
	UStaticMesh* SM_ColumnRight;

	// Gate Mesh.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Default)
	UStaticMeshComponent* Gate;
	UStaticMesh* SM_Gate;

	// Rotating Movement Component
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Collision)
	URotatingMovementComponent* RotatingMovement = CreateDefaultSubobject<URotatingMovementComponent>(TEXT("RotatingMovement"));

	// Determines whether or not the Gate is open
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Controls)
	bool GateIsOpen;

	// The starting location of the gate
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Controls)
	FVector GateStartLoc;

	// The ending location of the gate, when it is fully open
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Controls)
	FVector GateEndLoc;
};
