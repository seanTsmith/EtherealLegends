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
#include "Vulcan_Lava.generated.h"

UCLASS()
class ETHEREAL_API AVulcan_Lava : public AEtherealNPCMaster
{
	GENERATED_BODY()
	
public:

	// Sets default values for this actor's properties
	AVulcan_Lava(const FObjectInitializer& ObjectInitializer);

	// BeginPlay Override
	virtual void BeginPlay() override;

	// Interact with this NPC
	UFUNCTION(BlueprintCallable, Category = Default)
	void Interact();
	
	// Lava Pit 1
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Default)
	UStaticMeshComponent* LavaMesh1;
	UStaticMesh* SM_LavaMesh1;

	// Lava Pit 2
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Default)
	UStaticMeshComponent* LavaMesh2;
	UStaticMesh* SM_LavaMesh2;

	// Lava Pit 3
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Default)
	UStaticMeshComponent* LavaMesh3;
	UStaticMesh* SM_LavaMesh3;

	// Fire Head
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Default)
	UStaticMeshComponent* FireHead;
	UStaticMesh* SM_FireHead;

	// Head Pouring Lava
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Default)
	UStaticMeshComponent* HeadLava;
	UStaticMesh* SM_HeadLava;

	// Rock
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Default)
	UStaticMeshComponent* Rock;
	UStaticMesh* SM_Rock;

	// Kick Rock
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Default)
	UStaticMeshComponent* KickRock;
	UStaticMesh* SM_KickRock;

	// Avalanche Audio
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Effects)
	UAudioComponent* AvalancheAudio;
	USoundCue* S_AvalancheAudio;

	// Explosion Audio
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Effects)
	UAudioComponent* ExplosionAudio;
	USoundCue* S_ExplosionAudio;

	// Final Scream Audio
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Effects)
	UAudioComponent* FinalScreamAudio;
	USoundCue* S_FinalScreamAudio;
};
