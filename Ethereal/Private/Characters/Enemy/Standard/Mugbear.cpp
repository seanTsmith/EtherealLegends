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
#include "Mugbear.h"

AMugbear::AMugbear(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	static ConstructorHelpers::FObjectFinder<USkeletalMesh> EnemyMesh(TEXT("SkeletalMesh'/Game/InfinityBladeAdversaries/Enemy/Enemy_Bear/Enemy_Bear.Enemy_Bear'"));
	static ConstructorHelpers::FObjectFinder<UAnimBlueprint> AnimBP(TEXT("AnimBlueprint'/Game/InfinityBladeAdversaries/Enemy/Enemy_Bear/Anim_Bear.Anim_Bear'"));
	static ConstructorHelpers::FObjectFinder<USoundCue> SlamAudioObject(TEXT("SoundCue'/Game/Audio/Party/Mugbear_SlamAtk_Cue.Mugbear_SlamAtk_Cue'"));
	static ConstructorHelpers::FObjectFinder<USoundCue> RoarAudioObject(TEXT("SoundCue'/Game/Audio/Party/FrostCaptain_StompRoar_Cue.FrostCaptain_StompRoar_Cue'"));
	static ConstructorHelpers::FObjectFinder<USoundCue> DeathAudioObject(TEXT("SoundCue'/Game/Audio/Party/Mugbear_Death_Cue.Mugbear_Death_Cue'"));

	// Set Default Objects
	GetMesh()->SkeletalMesh = EnemyMesh.Object;
	GetMesh()->SetAnimInstanceClass(AnimBP.Object->GetAnimBlueprintGeneratedClass());
	S_SlamAudio = SlamAudioObject.Object;
	S_RoarAudio = RoarAudioObject.Object;
	S_DeathAudio = DeathAudioObject.Object;


	// Create objects
	SlamAudio = NewObject<UAudioComponent>(this, TEXT("BiteAudio"));
	RoarAudio = NewObject<UAudioComponent>(this, TEXT("SpitAudio"));
	DeathAudio = NewObject<UAudioComponent>(this, TEXT("DeathAudio"));

	// Configure Components
	SlamAudio->Sound = S_SlamAudio;
	RoarAudio->Sound = S_RoarAudio;
	DeathAudio->Sound = S_DeathAudio;

	SlamAudio->bAutoActivate = false;
	RoarAudio->bAutoActivate = false;
	DeathAudio->bAutoActivate = false;

	// reshape the capsule collider for this enemy
	this->GetCapsuleComponent()->SetCapsuleHalfHeight(100);
	this->GetCapsuleComponent()->SetCapsuleRadius(100);

	Name = EEnemyNames::EN_Mugbear;
	Realm = ERealms::R_Yggdrasil;
	BattleType = EBattleTypes::BT_Standard;
}

// Called when the game starts or when spawned
void AMugbear::BeginPlay()
{
	Super::BeginPlay();

	//OnDeath.AddDynamic(this, &ADemonStatue::Death()); // bind the death fuction to the OnDeath event 

}

void AMugbear::RunToTarget()
{
	if (!IsDead)
	{
		if (!Target->IsDead)
		{
			// TO DO : AI move to, if player is in melee radius, 
			// EnemyDealDamage(35), get a random bool, and either DoSwingLeft or DoSwingRight
			// else
			// EnemyDealDamage(25), and DoThrow
			// wait attack delay, then RunToTarget()
		}
	}
}

void AMugbear::Death()
{
	IsDead = true;
	DeathAudio->Play();
}



