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
#include "Gruntling.h"

AGruntling::AGruntling(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	static ConstructorHelpers::FObjectFinder<USkeletalMesh> EnemyMesh(TEXT("SkeletalMesh'/Game/InfinityBladeAdversaries/Enemy/Enemy_Gruntling/SK_Exodus_Gruntling.SK_Exodus_Gruntling'"));
	static ConstructorHelpers::FObjectFinder<UAnimBlueprint> AnimBP(TEXT("AnimBlueprint'/Game/InfinityBladeAdversaries/Enemy/Enemy_Gruntling/Anim_EggGrunt.Anim_EggGrunt'"));
	static ConstructorHelpers::FObjectFinder<USoundCue> AppearAudioObject(TEXT("SoundCue'/Game/Audio/Gruntling/Gruntling_Appear_Cue.Gruntling_Appear_Cue'"));
	static ConstructorHelpers::FObjectFinder<USoundCue> CastAudioObject(TEXT("SoundCue'/Game/Audio/Gruntling/Gruntling_Cast_Cue.Gruntling_Cast_Cue'"));
	static ConstructorHelpers::FObjectFinder<USoundCue> DeathAudioObject(TEXT("SoundCue'/Game/Audio/Gruntling/Gruntling_Death_Cue.Gruntling_Death_Cue'"));
	static ConstructorHelpers::FObjectFinder<USoundCue> HitAudioObject(TEXT("SoundCue'/Game/Audio/Gruntling/Gruntling_Hit_Cue.Gruntling_Hit_Cue'"));

	// Set Default Objects
	GetMesh()->SkeletalMesh = EnemyMesh.Object;
	GetMesh()->SetAnimInstanceClass(AnimBP.Object->GetAnimBlueprintGeneratedClass());
	S_AppearAudio = AppearAudioObject.Object;
	S_CastAudio = CastAudioObject.Object;
	S_DeathAudio = DeathAudioObject.Object;
	S_HitAudio = HitAudioObject.Object;

	// Create objects
	AppearAudio = NewObject<UAudioComponent>(this, TEXT("AppearAudio"));
	CastAudio = NewObject<UAudioComponent>(this, TEXT("CastAudio"));
	DeathAudio = NewObject<UAudioComponent>(this, TEXT("DeathAudio"));
	HitAudio = NewObject<UAudioComponent>(this, TEXT("HitAudio"));

	// Configure Components
	AppearAudio->Sound = S_AppearAudio;
	CastAudio->Sound = S_CastAudio;
	DeathAudio->Sound = S_DeathAudio;
	HitAudio->Sound = S_HitAudio;

	AppearAudio->bAutoActivate = false;
	CastAudio->bAutoActivate = false;
	DeathAudio->bAutoActivate = false;
	HitAudio->bAutoActivate = false;

	Name = EEnemyNames::EN_Gruntling;
	Realm = ERealms::R_Vulcan;
	BattleType = EBattleTypes::BT_Standard;
}

// Called when the game starts or when spawned
void AGruntling::BeginPlay()
{
	Super::BeginPlay();

	//OnDeath.AddDynamic(this, &ADemonStatue::Death()); // bind the death fuction to the OnDeath event 

	// TO DO : The Gruntling was prototyped to spawn from an egg, which is unfortunately held as an external BP actor.
	// The Gruntling must be refactored to include the egg within this class, so that the enemy is more self-contained

	// The egg will be a placement object, and when the player is in range, the egg shakes and the gruntling hops out of it
	// The egg should then disappear, and the gruntling can then go into it's AI attack mode
	// in the prototype, the Gruntling spawns with automatic aggro, immediately running toward the player
}

void AGruntling::RunToTarget()
{
	if (!IsDead)
	{
		if (!Target->IsDead)
		{
			// TO DO :  same stuff as the Soul Eater, in general. Check the melee radius, but instead of melee damage he'll spawn the Gruntling Drop.
			// Wait the attack delay and call this function again
		}
	}
}

void AGruntling::Death()
{
	//FinalDeath(true, false);
}



