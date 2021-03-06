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
#include "SoulEater.h"

// Sets default values
ASoulEater::ASoulEater(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	static ConstructorHelpers::FObjectFinder<USkeletalMesh> EnemyMesh(TEXT("SkeletalMesh'/Game/EtherealParty/SoulEater/SoulEater.SoulEater'"));
	static ConstructorHelpers::FObjectFinder<UAnimBlueprint> AnimBP(TEXT("AnimBlueprint'/Game/EtherealParty/SoulEater/Anim_SoulEater.Anim_SoulEater'"));
	static ConstructorHelpers::FObjectFinder<USoundCue> DeathAudioObject(TEXT("SoundCue'/Game/Audio/Party/SoulEater_Death_Cue.SoulEater_Death_Cue'"));

	S_DeathAudio = DeathAudioObject.Object;

	DeathAudio = NewObject<UAudioComponent>(this, TEXT("DeathAudio"));

	GetMesh()->SkeletalMesh = EnemyMesh.Object;
	GetMesh()->SetAnimInstanceClass(AnimBP.Object->GetAnimBlueprintGeneratedClass());
	DeathAudio->Sound = S_DeathAudio;

	DeathAudio->bAutoActivate = false;

	Name = EEnemyNames::EN_SoulEater;
	Realm = ERealms::R_Shiitake;
	BattleType = EBattleTypes::BT_Standard;
}

// Called when the game starts or when spawned
void ASoulEater::BeginPlay()
{
	//OnDeath.AddDynamic(this, &ASoulEater::Death()); // bind the death fuction to the OnDeath event 
}

void ASoulEater::RunToTarget()
{
	if (!IsDead)
	{
		if (!Target->IsDead)
		{
			// TO DO:  Run to target. This function is currently in Blueprints.
			// When the enemy gets within melee range of the player, do a melee attack.
			// after the attack delay, run this function again
		}
	}
}

void ASoulEater::Death()
{
	DeathAudio->Play();  // Play death audio
}

