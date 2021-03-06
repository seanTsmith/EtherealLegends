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

#include "EnemyNames.h"
#include "Perception/PawnSensingComponent.h"
#include "Characters/EtherealCharacterMaster.h"
#include "Characters/Player/EtherealPlayerMaster.h"
#include "Management/BattleTypes.h"
#include "Management/Realms.h"
#include "Management/EtherealAudioManager.h"
#include "EtherealEnemyMaster.generated.h"

// Event Dispatcher for Death
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDeath);

UCLASS()
class ETHEREAL_API AEtherealEnemyMaster : public AEtherealCharacterMaster
{
	GENERATED_BODY()
	
public:

	AEtherealEnemyMaster(const FObjectInitializer& ObjectInitializer);

	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaSeconds) override;

	// Event Dispatcher OnDeath
	UPROPERTY(BlueprintAssignable, Category = "Dispatcher")
	FDeath OnDeath;

	// DEFAULTS

	// The name of this enemy
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Default)
	EEnemyNames Name;

	// The Realm associated with this enemy (i.e. what map does he spawn in).
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Default)
	ERealms Realm;

	// What type of battle this enemy initiates
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Default)
	EBattleTypes BattleType;

	// Enemy's current target. will always be the player
	// Change this to an Ethereal Player Master soon
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Default)
	AEtherealPlayerMaster* Target;

	// Reference to the instance of EtherealAudioMaster
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Default)
	AEtherealAudioManager* AudioManager;

	// CONTROL STATES
	
	// Whether or not the enemy is in range of the player
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Controls)
	bool InRange;

	// Whether or not the enemy is currently moving
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Controls)
	bool IsMoving;

	// Whether or not the enemy was hit by the player
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Controls)
	bool IsHit;

	// Whether or not the enemy is a boss enemy
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Controls)
	bool IsBoss;

	// Whether or not the enemy has been aggroed by the player
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Controls)
	bool IsAggroed;

	// BASE STATS

	// Enemy Level
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stats)
	int Level;

	// Enemy ATK value
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stats)
	float ATK;

	// Enemy DEF value
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stats)
	float DEF;

	// Enemy SPD value
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stats)
	float SPD;

	// Enemy Current HP value
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stats)
	float HP_Current;

	// Enemy Max HP value
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stats)
	float HP_Max;

	// The time this enemy will wait between taking turns
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stats)
	float AttackDelay;

	// The damage output of this enemy. Used to calculate final damage taken by the player.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stats)
	float DamageOutput;

	// COMPONENTS

	/** This emitter is active when the enemy is hit. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Effects)
	UParticleSystemComponent* HitFX;
	UParticleSystem* P_HitFX;

	/** This emitter is active when this enemy dies. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Effects)
	UParticleSystemComponent* DeathFX;
	UParticleSystem* P_DeathFX;

	/** Effect played when enemy vanishes after dying. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Effects)
	UParticleSystemComponent* DisappearFX;
	UParticleSystem* P_DisappearFX;

	// Disappear Audio
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Effects)
	UAudioComponent* DisappearAudio;
	USoundCue* S_DisappearAudio;

	// Melee Radius Collider
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Collision)
	USphereComponent* MeleeRadius = CreateDefaultSubobject<USphereComponent>(TEXT("MeleeRadius"));

	// Pawn Sensing Component
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Collision)
	UPawnSensingComponent* PawnSensing = CreateDefaultSubobject<UPawnSensingComponent>(TEXT("PawnSensing"));

	// FUNCTIONS

	// Sets the initial stats of the player, based on his level
	UFUNCTION(BlueprintCallable, Category = Stats)
	void SetBaseStats();

	// Sets the initial stats of the player, based on his level
	UFUNCTION(BlueprintCallable, Category = Stats)
	bool ForceHPCaps();

	// Sets the initial stats of the player, based on his level
	UFUNCTION(BlueprintCallable, Category = Combat)
	void EnemyTakeDamage(float DamageTaken);

	// Sets the initial stats of the player, based on his level
	UFUNCTION(BlueprintCallable, Category = Combat)
	float EnemyDealDamage(float BaseATK);

	// Aggro the player. This function is called in Blueprint by the AI OnSeePawn event
	UFUNCTION(BlueprintCallable, Category = Combat)
	void Aggro(APawn* Pawn);

	// Deaggro the player. 
	UFUNCTION(BlueprintCallable, Category = Combat)
	void Deaggro();

	// Activate the Death sequence of this enemy
	UFUNCTION(BlueprintCallable, Category = Combat)
	void Death();

	// Activate the Final Death sequence of this enemy, destroying it. Boss enemies will spawn Zhan after this cycle.
	// This function is called at the end of an enemy's Death animation, and must be bound to an AnimNotify in editor
	UFUNCTION(BlueprintCallable, Category = Combat)
	void FinalDeath(bool ShouldDestroy, bool SpawnZhan);

	// Activate the Disappear sequence of this enemy
	UFUNCTION(BlueprintCallable, Category = Combat)
	void Disappear();

	// Spawns Zhan after a Boss dies. Should not be called by regular enemies.
	UFUNCTION(BlueprintCallable, Category = Combat)
	void SpawnZhan();

	// Destroys this enemy
	UFUNCTION(BlueprintCallable, Category = Combat)
	void DestroyEnemy();
};
