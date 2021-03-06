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
#include "Watcher.h"

AWatcher::AWatcher(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	static ConstructorHelpers::FObjectFinder<USkeletalMesh> EnemyMesh(TEXT("SkeletalMesh'/Game/EtherealParty/Watcher/Watcher.Watcher'"));
	static ConstructorHelpers::FObjectFinder<UAnimBlueprint> AnimBP(TEXT("AnimBlueprint'/Game/EtherealParty/Watcher/Anim_Watcher.Anim_Watcher'"));
	static ConstructorHelpers::FObjectFinder<UParticleSystem> EyeBlastParticleObject(TEXT("ParticleSystem'/Game/InfinityBladeEffects/Effects/FX_Monsters/FX_Monster_Elemental/Fire/Watcher_EyeBlast.Watcher_EyeBlast'"));
	static ConstructorHelpers::FObjectFinder<USoundCue> BeamAudioObject(TEXT("SoundCue'/Game/EtherealParty/Watcher/Audio/Watcher_Beam_Cue.Watcher_Beam_Cue'"));
	static ConstructorHelpers::FObjectFinder<USoundCue> PreAtkAudioObject(TEXT("SoundCue'/Game/EtherealParty/Watcher/Audio/Watcher-PreAtk_Cue.Watcher-PreAtk_Cue'"));
	static ConstructorHelpers::FObjectFinder<USoundCue> DeathAudioObject(TEXT("SoundCue'/Game/EtherealParty/Watcher/Audio/Watcher_Death_Cue.Watcher_Death_Cue'"));
	static ConstructorHelpers::FObjectFinder<USoundCue> FlapAudioObject(TEXT("SoundCue'/Game/EtherealParty/Watcher/Audio/Watcher_Flap_Cue.Watcher_Flap_Cue'"));

	// Set Default Objects
	GetMesh()->SkeletalMesh = EnemyMesh.Object;
	GetMesh()->SetAnimInstanceClass(AnimBP.Object->GetAnimBlueprintGeneratedClass());
	P_EyeBeamBlast = EyeBlastParticleObject.Object;
	S_BeamAudio = BeamAudioObject.Object;
	S_PreAtkAudio = PreAtkAudioObject.Object;
	S_DeathAudio = DeathAudioObject.Object;
	S_FlapAudio = FlapAudioObject.Object;

	// Create objects
	EyeBeamBlast = NewObject<UParticleSystemComponent>(this, TEXT("EyeBeamBlast"));
	BeamAudio = NewObject<UAudioComponent>(this, TEXT("BeamAudio"));
	PreAtkAudio = NewObject<UAudioComponent>(this, TEXT("PreAtkAudio"));
	DeathAudio = NewObject<UAudioComponent>(this, TEXT("DeathAudio"));
	FlapAudio = NewObject<UAudioComponent>(this, TEXT("FlapAudio"));

	// Configure Components
	EyeBeamBlast->Template = P_EyeBeamBlast;
	BeamAudio->Sound = S_BeamAudio;
	PreAtkAudio->Sound = S_PreAtkAudio;
	DeathAudio->Sound = S_DeathAudio;
	FlapAudio->Sound = S_FlapAudio;

	EyeBeamBlast->bAutoActivate = false;
	BeamAudio->bAutoActivate = false;
	PreAtkAudio->bAutoActivate = false;
	DeathAudio->bAutoActivate = false;
	FlapAudio->bAutoActivate = false;

	Name = EEnemyNames::EN_Watcher;
	Realm = ERealms::R_Shiitake;
	BattleType = EBattleTypes::BT_Standard;
}

// Called when the game starts or when spawned
void AWatcher::BeginPlay()
{
	Super::BeginPlay();

	//OnDeath.AddDynamic(this, &ADemonStatue::Death()); // bind the death fuction to the OnDeath event 
}

void AWatcher::RunToTarget()
{
	if (!IsDead)
	{
		if (!Target->IsDead)
		{
			Attack = true; // this triggers the watcher's attack animation
			// TO DO:  Run to target. This function is currently in Blueprints.
			// When the enemy gets within melee range of the player, do an Eye Blast attack.
			// stop the Watcher's movement
			PreAtkAudio->Play();
			// Spawn the Watcher Beam Drop, and set the target and caster variables.
			// delay by 2.4 seconds
			EyeBeamBlast->Activate();  // activate the beam blast
			Blasting = true;
			BeamAudio->Play();
			// Get overlapping actors from the Beam Drop, and if those actors include the player, make him take damage and call "Burn" status on the player
			// Delay by 1 second
			// Destroy the Beam Drop actor
			EyeBeamBlast->Deactivate();
			Blasting = false;
			// delay by this enemy's attack duration
			// Run this function again
		}
	}
}

void AWatcher::Death()
{
	DeathAudio->Play();
	//FinalDeath(true, false);
}
