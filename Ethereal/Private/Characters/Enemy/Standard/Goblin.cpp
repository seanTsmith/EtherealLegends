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
#include "Goblin.h"

AGoblin::AGoblin(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	static ConstructorHelpers::FObjectFinder<USkeletalMesh> EnemyMesh(TEXT("SkeletalMesh'/Game/EtherealParty/Goblin/ShortGoblin.ShortGoblin'"));
	static ConstructorHelpers::FObjectFinder<UAnimBlueprint> AnimBP(TEXT("AnimBlueprint'/Game/EtherealParty/Goblin/Goblin_AnimBP.Goblin_AnimBP'"));
	static ConstructorHelpers::FObjectFinder<USoundCue> AttackAudioObject(TEXT("SoundCue'/Game/Audio/Party/Goblin_Atk_Cue.Goblin_Atk_Cue'"));
	static ConstructorHelpers::FObjectFinder<USoundCue> DeathAudioObject(TEXT("SoundCue'/Game/Audio/Party/Goblin_Death_Cue.Goblin_Death_Cue'"));
	static ConstructorHelpers::FObjectFinder<USoundCue> HitAudioObject(TEXT("SoundCue'/Game/Audio/Party/Goblin_hit_Cue.Goblin_hit_Cue'"));

	// Set Default Objects
	GetMesh()->SkeletalMesh = EnemyMesh.Object;
	GetMesh()->SetAnimInstanceClass(AnimBP.Object->GetAnimBlueprintGeneratedClass());
	S_AttackAudio = AttackAudioObject.Object;
	S_DeathAudio = DeathAudioObject.Object;
	S_HitAudio = HitAudioObject.Object;

	// Create objects
	AttackAudio = NewObject<UAudioComponent>(this, TEXT("AttackAudio"));
	DeathAudio = NewObject<UAudioComponent>(this, TEXT("DeathAudio"));
	HitAudio = NewObject<UAudioComponent>(this, TEXT("HitAudio"));

	// Configure Components
	AttackAudio->Sound = S_AttackAudio;
	DeathAudio->Sound = S_DeathAudio;
	HitAudio->Sound = S_HitAudio;

	AttackAudio->bAutoActivate = false;
	DeathAudio->bAutoActivate = false;
	HitAudio->bAutoActivate = false;

	Name = EEnemyNames::EN_Goblin;
	Realm = ERealms::R_Vulcan;
	BattleType = EBattleTypes::BT_Standard;
}

// Called when the game starts or when spawned
void AGoblin::BeginPlay()
{
	Super::BeginPlay();

	//OnDeath.AddDynamic(this, &ADemonStatue::Death()); // bind the death fuction to the OnDeath event 
}

void AGoblin::RunToTarget()
{
	if (!IsDead)
	{
		if (!Target->IsDead)
		{
			// TO DO :  same stuff as the Soul Eater, in general. Check the melee radius and have player take damage
		}
	}
}

void AGoblin::Death()
{
	//FinalDeath(true, false);
}


