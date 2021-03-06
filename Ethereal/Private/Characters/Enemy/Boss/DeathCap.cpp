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
#include "DeathCap.h"

ADeathCap::ADeathCap(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	static ConstructorHelpers::FObjectFinder<USkeletalMesh> EnemyMesh(TEXT("SkeletalMesh'/Game/EtherealParty/GiantMushroom/GiantMushroomMesh.GiantMushroomMesh'"));
	static ConstructorHelpers::FObjectFinder<UAnimBlueprint> AnimBP(TEXT("AnimBlueprint'/Game/EtherealParty/GiantMushroom/Anim_GiantMushroom.Anim_GiantMushroom'"));
	static ConstructorHelpers::FObjectFinder<UParticleSystem> UpheavalParticleObject(TEXT("ParticleSystem'/Game/InfinityBladeEffects/Effects/FX_Monsters/FX_Monster_Elemental/Fire/Watcher_EyeBlast.Watcher_EyeBlast'"));
	static ConstructorHelpers::FObjectFinder<USoundCue> AggroAudioObject(TEXT("SoundCue'/Game/EtherealParty/Watcher/Audio/Watcher_Beam_Cue.Watcher_Beam_Cue'"));
	static ConstructorHelpers::FObjectFinder<USoundCue> SpitAudioObject(TEXT("SoundCue'/Game/EtherealParty/Watcher/Audio/Watcher-PreAtk_Cue.Watcher-PreAtk_Cue'"));

	// Set Default Objects
	GetMesh()->SkeletalMesh = EnemyMesh.Object;
	GetMesh()->SetAnimInstanceClass(AnimBP.Object->GetAnimBlueprintGeneratedClass());
	P_UpheavalFX = UpheavalParticleObject.Object;
	S_AggroAudio = AggroAudioObject.Object;
	S_SpitAudio = SpitAudioObject.Object;

	// Create objects
	UpheavalFX = NewObject<UParticleSystemComponent>(this, TEXT("UpheavalFX"));
	AggroAudio = NewObject<UAudioComponent>(this, TEXT("AggroAudio"));
	SpitAudio = NewObject<UAudioComponent>(this, TEXT("SpitAudio"));

	// Configure Components
	UpheavalFX->Template = P_UpheavalFX;
	AggroAudio->Sound = S_AggroAudio;
	SpitAudio->Sound = S_SpitAudio;

	UpheavalFX->bAutoActivate = false;
	AggroAudio->bAutoActivate = false;
	SpitAudio->bAutoActivate = false;

	Name = EEnemyNames::EN_DeathCap;
	Realm = ERealms::R_Shiitake;
	BattleType = EBattleTypes::BT_Boss;
}

// Called when the game starts or when spawned
void ADeathCap::BeginPlay()
{
	Super::BeginPlay();

	//OnDeath.AddDynamic(this, &ADemonStatue::Death()); // bind the death fuction to the OnDeath event 
}

// TO DO:  create and call an aggro function, which sets Hiding true and plays the aggro sound cue

void ADeathCap::RunToTarget()
{
	if (!IsDead)
	{
		if (!Target->IsDead)
		{
			// TO DO :  random in range, and pick one of the two poison attacks to perform
		}
	}
}

void ADeathCap::Death()
{
	//FinalDeath(true, false);
}

void ADeathCap::PoisonLob()
{
	EnemyDealDamage(30); // get damage output
	Spit = true;  // do the spit animation
	// TO DO :  spawn the mushroom poison lob drop
	// TO DO :  call the "DoLob" function inside the lob drop, passing the damage output of this actor
	// TO DO :  wait the attack delay, and call the RunToTarget() function
}

void ADeathCap::PoisonUpheaval()
{
	Roar = true;  // do the roar animation
	// TO DO :  set the Upheaval decal to visible, which has not yet been added to the constructor, so you need to do that too.
	// Delay one second
	UpheavalFX->Activate();

	// TO DO :  needs a specific collider, which will then check if a player is inside, and if so, have that player take damage
	// TO DO :  call the poison status function on the player
	// TO DO :  wait the attack delay, and call the RunToTarget() function
}


