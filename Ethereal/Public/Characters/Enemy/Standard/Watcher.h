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

#include "Characters/Enemy/EtherealEnemyMaster.h"
#include "Watcher.generated.h"

UCLASS()
class ETHEREAL_API AWatcher : public AEtherealEnemyMaster
{
	GENERATED_BODY()
	
public:

	// Sets default values for this actor's properties
	AWatcher(const FObjectInitializer& ObjectInitializer);

	// BeginPlay Override
	virtual void BeginPlay() override;

	// Beam Blast Audio
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Effects)
	UAudioComponent* BeamAudio;
	USoundCue* S_BeamAudio;

	// Beam Blast Audio
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Effects)
	UAudioComponent* PreAtkAudio;
	USoundCue* S_PreAtkAudio;

	// Beam Blast Audio
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Effects)
	UAudioComponent* DeathAudio;
	USoundCue* S_DeathAudio;

	// Beam Blast Audio
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Effects)
	UAudioComponent* FlapAudio;
	USoundCue* S_FlapAudio;

	/** Eye Blast Particle */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Effects)
	UParticleSystemComponent* EyeBeamBlast;
	UParticleSystem* P_EyeBeamBlast;
	
	// Do the Eye Blast attack
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Controls)
	bool Attack;

	// Denotes that the Watcher is currently firing his eye blast, and cannot move
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Controls)
	bool Blasting;

	// Death
	UFUNCTION(BlueprintCallable, Category = Default)
	void Death();

	// Run to Target
	UFUNCTION(BlueprintCallable, Category = Default)
	void RunToTarget();
};
