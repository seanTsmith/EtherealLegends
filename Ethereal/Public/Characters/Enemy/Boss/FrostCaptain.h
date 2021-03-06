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
#include "FrostCaptain.generated.h"

UCLASS()
class ETHEREAL_API AFrostCaptain : public AEtherealEnemyMaster
{
	GENERATED_BODY()

public:
	
	// Sets default values for this actor's properties
	AFrostCaptain(const FObjectInitializer& ObjectInitializer);

	// BeginPlay Override
	virtual void BeginPlay() override;

	// Aggro Audio
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Effects)
	UAudioComponent* AggroAudio;
	USoundCue* S_AggroAudio;

	// Hit Audio
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Effects)
	UAudioComponent* HitAudio;
	USoundCue* S_HitAudio;

	// Snort Audio
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Effects)
	UAudioComponent* SnortAudio;
	USoundCue* S_SnortAudio;

	// Stomp Audio
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Effects)
	UAudioComponent* StompAudio;
	USoundCue* S_StompAudio;

	// Roar Audio
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Effects)
	UAudioComponent* RoarAudio;
	USoundCue* S_RoarAudio;

	// First Drop Audio
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Effects)
	UAudioComponent* FirstDropAudio;
	USoundCue* S_FirstDropAudio;

	// Second Drop Audio
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Effects)
	UAudioComponent* SecondDropAudio;
	USoundCue* S_SecondDropAudio;

	// Death Audio
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Effects)
	UAudioComponent* DeathAudio;
	USoundCue* S_DeathAudio;

	// Do haymaker anim
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Controls)
	bool DoHaymaker;

	// Haymaker attack
	UFUNCTION(BlueprintCallable, Category = Default)
	void Haymaker();

	// Do stomp anim
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Controls)
	bool DoStomp;

	// Stomp Attack
	UFUNCTION(BlueprintCallable, Category = Default)
	void Stomp();

	// Do blizzard anim
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Controls)
	bool DoBlizzard;

	// Blizzard attack
	UFUNCTION(BlueprintCallable, Category = Default)
	void Blizzard();

	// Do leap anim
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Controls)
	bool DoLeap;

	// Death
	UFUNCTION(BlueprintCallable, Category = Default)
	void Death();

	// Run to Target
	UFUNCTION(BlueprintCallable, Category = Default)
	void RunToTarget();	

	// Keep track of how many times the core has been powered. Max is twice.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Controls)
	int PoweredCoreCount;

	// Check if the core should become powered
	UFUNCTION(BlueprintCallable, Category = Default)
	void ShouldPowerCore();

	// Power the Core
	UFUNCTION(BlueprintCallable, Category = Default)
	void PowerCore();
};
