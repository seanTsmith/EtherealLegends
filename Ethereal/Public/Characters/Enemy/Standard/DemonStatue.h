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
#include "Engine/DestructibleMesh.h"
#include "DemonStatue.generated.h"

UCLASS()
class ETHEREAL_API ADemonStatue : public AEtherealEnemyMaster
{
	GENERATED_BODY()
	
public:

	// Sets default values for this actor's properties
	ADemonStatue(const FObjectInitializer& ObjectInitializer);

	// BeginPlay Override
	virtual void BeginPlay() override;

	/** Right Soul Eater spawn location. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Default)
	USceneComponent* SpawnLocR;

	/** Left Soul Eater spawn location. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Default)
	USceneComponent* SpawnLocL;

	/** Stomp Radius Collider. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Default)
	USphereComponent* StompRadius;

	/** Stomp Radius Collider. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Default)
	UDestructibleComponent* DemonDoor;
	UDestructibleMesh* DM_DemonDoor;
	
	/** Statue Right Eye Flare. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Effects)
	UParticleSystemComponent* EyeFlareFX_R;
	UParticleSystem* P_EyeFlareFX_R;

	/** Statue Left Eye Flare. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Effects)
	UParticleSystemComponent* EyeFlareFX_L;
	UParticleSystem* P_EyeFlareFX_L;

	/** Statue Right Eye Idle. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Effects)
	UParticleSystemComponent* EyeIdleFX_R;
	UParticleSystem* P_EyeIdleFX_R;

	/** Statue Left Eye Idle. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Effects)
	UParticleSystemComponent* EyeIdleFX_L;
	UParticleSystem* P_EyeIdleFX_L;
	
	/** Stomp Blast. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Effects)
	UParticleSystemComponent* StompBlast;
	UParticleSystem* P_StompBlast;

	// Statue Jump Audio
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Effects)
	UAudioComponent* JumpAudio;
	USoundCue* S_JumpAudio;

	// Statue Stomp Audio
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Effects)
	UAudioComponent* StompAudio;
	USoundCue* S_StompAudio;

	// Soul Eater Spawn Explosion Audio
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Effects)
	UAudioComponent* ExplosionAudio;
	USoundCue* S_ExplosionAudio;

	// Toggle Eyes
	UFUNCTION(BlueprintCallable, Category = Default)
	void ToggleEyes(bool HideEyes);

	// Spawn Soul Eaters upon aggro
	UFUNCTION(BlueprintCallable, Category = Default)
	void SpawnSoulEaters();

	// Death
	UFUNCTION(BlueprintCallable, Category = Default)
	void Death();

	// Run to Target
	UFUNCTION(BlueprintCallable, Category = Default)
	void RunToTarget();

	// Stomp Attack
	UFUNCTION(BlueprintCallable, Category = Default)
	void StompAttack();
};
