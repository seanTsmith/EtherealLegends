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

#include "Ethereal.h"
#include "EtherealEnemyMaster.h"

// Sets default values
AEtherealEnemyMaster::AEtherealEnemyMaster(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Get Assets, References Obtained Via Right Click in Editor
	static ConstructorHelpers::FObjectFinder<UParticleSystem> HitParticleObject(TEXT("ParticleSystem'/Game/Particles/Emitter/P_blood_splash.P_blood_splash'"));
	static ConstructorHelpers::FObjectFinder<UParticleSystem> DeathParticleObject(TEXT("ParticleSystem'/Game/Particles/Emitter/EnemyDeath.EnemyDeath'"));
	static ConstructorHelpers::FObjectFinder<UParticleSystem> DisappearParticleObject(TEXT("ParticleSystem'/Game/Particles/Emitter/EnemyDisappear.EnemyDisappear'"));
	static ConstructorHelpers::FObjectFinder<USoundCue> DisappearAudioObject(TEXT("SoundCue'/Game/Audio/Party/EnemyDisappear_Cue.EnemyDisappear_Cue'"));
	
	// Set Default Objects
	P_HitFX = HitParticleObject.Object;
	P_DeathFX = DeathParticleObject.Object;
	P_DisappearFX = DisappearParticleObject.Object;
	S_DisappearAudio = DisappearAudioObject.Object;

	// Create
	HitFX = NewObject<UParticleSystemComponent>(this, TEXT("HitFX"));
	DeathFX = NewObject<UParticleSystemComponent>(this, TEXT("DeathFX"));
	DisappearFX = NewObject<UParticleSystemComponent>(this, TEXT("DisappearFX"));
	DisappearAudio = NewObject<UAudioComponent>(this, TEXT("DisappearAudio"));
	
	// Assignment
	HitFX->Template = P_HitFX;
	DeathFX->Template = P_DeathFX;
	DisappearFX->Template = P_DisappearFX;
	DisappearAudio->Sound = S_DisappearAudio;

	HitFX->bAutoActivate = false;
	DeathFX->bAutoActivate = false;
	DisappearFX->bAutoActivate = false;
	DisappearAudio->bAutoActivate = false;

}

// Called when the game starts or when spawned
void AEtherealEnemyMaster::BeginPlay()
{
	// iterate through the world for all Ethereal Audio Managers
	for (TActorIterator<AEtherealAudioManager> ActorItr(GetWorld()); ActorItr; ++ActorItr)
	{
		AudioManager = *ActorItr; // get the instance of the Audio Manager
	}
}

// Called every frame
void AEtherealEnemyMaster::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!IsDead) // if enemy is not dead
	{
		if (InRange)  // if is in range of player
		{
			if (IsAggroed)  // if is aggroed to the player
			{
				if (GetDistanceTo(Target) > PawnSensing->SightRadius)  // if the player gets out of the enemy's sight radius
				{
					// Lost sight of player, disable aggro
					InRange = false;
					Deaggro();
				}
			}
		}
	}
}

// Sets the Enemy's default stats
void AEtherealEnemyMaster::SetBaseStats()
{
	float HPMod = 2000;
	float StatMod = 7.5f;

	if (IsBoss) // Higher stats for bosses
	{
		HPMod = 2000;
		StatMod = 7.5f;
		
	}
	else  // lower stats for regular enemies
	{
		HPMod = 200;
		StatMod = 5.1f;	
	}

	HP_Current = Level * HPMod;
	HP_Max = Level * HPMod;
	ATK = Level * StatMod;
	DEF = Level * StatMod;
	SPD = Level * StatMod;
}

// Force HP Caps keeps the enemy's HP between 0 and Max
bool AEtherealEnemyMaster::ForceHPCaps()
{
	bool Kill = false;

	if (HP_Current > HP_Max)  // if HP is greater than 0
	{
		HP_Current = HP_Max;
	}
	else if (HP_Current < 0)  // if HP is less than 0
	{
		HP_Current = 0;
		Kill = true;
	}

	if (Kill)
	{
		Death(); // Start the Death sequence
	}

	return Kill;
}

// Calculates the damage taken by a player attack
void AEtherealEnemyMaster::EnemyTakeDamage(float DamageTaken)
{
	IsHit = true; // Enemy was hit - setting this to true will trigger a hit animation

	bool iscrit = false;  // set a local crit bool for later use
	float critical = FMath::FRandRange(1.0f, 1.5f);
	float mod1 = 512 - DEF;
	float mod2 = critical * mod1 * DamageTaken;
	float mod3 = mod2 / (16 * 512);  // calculate final damage taken
	HP_Current = HP_Current - mod3;  // Finally remove the damage taken

	if (critical > 1.4f)
	{
		iscrit = true;
	}
	else 
	{
		iscrit = false;
	}

	HitFX->Activate();  // Activate the HitFX particle

	// TO DO :  show combat damage text, passing the 'iscrit' and 'mod3' variables

	bool found = false; // Define a local variable to determine if the enemy is already in the player's aggro list

	// Filter through the player's aggro list, and check if this enemy already exists
	for (AEtherealEnemyMaster* Enemy : Target->AggroList)
	{
		if (Enemy == this)
		{
			found = true; // enemy was found
			break; // stop looping
		}
		else
		{
			found = false; // enemy was not found
		}
	}

	if (!found)
	{
		Aggro(Target); // enemy was not found, call aggro
	}

	ForceHPCaps(); // force HP caps
}

// Calculates the damage dealt by the enemy this turn. Must pass in the base ATK value of the specific attack.
float AEtherealEnemyMaster::EnemyDealDamage(float BaseATK)
{
	float atk1 = (ATK + BaseATK) / 32;
	float atk2 = (ATK * BaseATK) / 32;
	float atk3 = atk1 * atk2;
	float atk4 = (atk3 + ATK) * 40;
	DamageOutput = atk4;

	return DamageOutput;
}

void AEtherealEnemyMaster::Aggro(APawn* Pawn)
{
	if (!IsDead) // make sure this enemy is not dead before doing anything
	{
		AEtherealPlayerMaster* Player = Cast<AEtherealPlayerMaster>(Pawn); // Check if the pawn seen by enemy AI was indeed the player
		if (Player)
		{
			if (!Player->IsDead)  // Make sure the player isn't dead before going further
			{
				Target = Player; // Set the seen player as the new Target	
				Target->AggroList.AddUnique(this); // Add this enemy to the player's aggro list array
				InRange = true; // the enemy is now in range
				IsAggroed = true; // the enemy is now aggroed
				Targetable = true;  // turn on targeting, in case it was previously disabled

				if (BattleType == EBattleTypes::BT_Standard)
				{
					AudioManager->Play_BattleMusic(EBattleTypes::BT_Standard);  // play the standard battle music
				}
				else if (BattleType == EBattleTypes::BT_Boss)
				{
					AudioManager->Play_BattleMusic(EBattleTypes::BT_Boss);  // play the boss battle music
				}
			}
		}
	}
}

void AEtherealEnemyMaster::Deaggro()
{
	bool LocalPlayerHasAggro = true;  // define a local variable, denoting the player as having aggro
	IsAggroed = false;
	Target->AggroList.Remove(this);  // Remove this enemy from the player's aggro list	

	// Check if the player still has aggro
	if (Target->AggroList.Num() > 0)
	{
		LocalPlayerHasAggro = true; // found enemies in aggro list
	}
	else
	{
		LocalPlayerHasAggro = false; // no enemies in aggro list
	}

	if (!LocalPlayerHasAggro)
	{
		AudioManager->Play_BGM(Realm); // found no aggro, so play Background Music
	}
}

void AEtherealEnemyMaster::Death()
{
	OnDeath.Broadcast();  // broadcast the OnDeath event dispatcher, which will run enemy specific death code
	GetMovementComponent()->StopMovementImmediately();  // Stop Movement
	// TO DO :  Completely disable the movement component, as the simple AI method may cause this enemy to continue moving after death
	// TO DO :  Call the Basic Reward function on the Player
	Targetable = false;  // turn off targeting if dead.
}

void AEtherealEnemyMaster::FinalDeath(bool ShouldDestroy, bool SpawnZhan)
{
	DeathFX->Activate();
	// Do the Disappear effect after a short delay
	FTimerHandle DisappearTimer;
	GetWorldTimerManager().SetTimer(DisappearTimer, this, &AEtherealEnemyMaster::Disappear, 1.5f, false);

	if (SpawnZhan)
	{
		// Spawn Zhan after a short delay if this function was called with SpawnZhan set to true
		FTimerHandle ZhanTimer;
		GetWorldTimerManager().SetTimer(ZhanTimer, this, &AEtherealEnemyMaster::SpawnZhan, 2.4f, false);
	}

	if (ShouldDestroy)
	{
		// Destroy the enemy after a short delay if this function was called with ShouldDestroy set to true
		FTimerHandle DestroyTimer;
		GetWorldTimerManager().SetTimer(DestroyTimer, this, &AEtherealEnemyMaster::DestroyEnemy, 5.5f, false);
	}
}

void AEtherealEnemyMaster::Disappear()
{
	DisappearFX->Activate(); // Activate Disappear effect
	DisappearAudio->Play(); // Play Disappear audio
	GetMesh()->SetVisibility(false);  // Hide the enemy mesh
	Deaggro(); // Run Deaggro code
}

void AEtherealEnemyMaster::SpawnZhan()
{
	// TO DO : Get all actors of class Zhan (which should only ever be one) and call InitAggro()
}

void AEtherealEnemyMaster::DestroyEnemy()
{
	this->Destroy(); // Destroy this actor
}