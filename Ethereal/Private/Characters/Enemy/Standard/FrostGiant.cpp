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
#include "FrostGiant.h"

AFrostGiant::AFrostGiant(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	static ConstructorHelpers::FObjectFinder<USkeletalMesh> EnemyMesh(TEXT("SkeletalMesh'/Game/InfinityBladeAdversaries/Enemy/Enemy_Frost_Giant/SK_Enemy_FrostGiant_Magic.SK_Enemy_FrostGiant_Magic'"));
	static ConstructorHelpers::FObjectFinder<UAnimBlueprint> AnimBP(TEXT("AnimBlueprint'/Game/InfinityBladeAdversaries/Enemy/Enemy_Frost_Giant/Anim_FrostGiant.Anim_FrostGiant'"));
	static ConstructorHelpers::FObjectFinder<USoundCue> AggroAudioObject(TEXT("SoundCue'/Game/Audio/Party/FrostGiant_Aggro_Cue.FrostGiant_Aggro_Cue'"));
	static ConstructorHelpers::FObjectFinder<USoundCue> LobStartAudioObject(TEXT("SoundCue'/Game/Audio/Party/FrostGiant_LobStart_Cue.FrostGiant_LobStart_Cue'"));
	static ConstructorHelpers::FObjectFinder<USoundCue> FirstDropAudioObject(TEXT("SoundCue'/Game/Audio/Party/FrostGiant_Death_FirstDrop_Cue.FrostGiant_Death_FirstDrop_Cue'"));
	static ConstructorHelpers::FObjectFinder<USoundCue> SecondDropAudioObject(TEXT("SoundCue'/Game/Audio/Party/FrostGiant_Death_SecondDrop_Cue.FrostGiant_Death_SecondDrop_Cue'"));
	static ConstructorHelpers::FObjectFinder<USoundCue> DeathAudioObject(TEXT("SoundCue'/Game/Audio/Party/FrostGiant_Death_Cue.FrostGiant_Death_Cue'"));

	// Set Default Objects
	GetMesh()->SkeletalMesh = EnemyMesh.Object;
	GetMesh()->SetAnimInstanceClass(AnimBP.Object->GetAnimBlueprintGeneratedClass());
	S_AggroAudio = AggroAudioObject.Object;
	S_LobStartAudio = LobStartAudioObject.Object;
	S_FirstDropAudio = FirstDropAudioObject.Object;
	S_SecondDropAudio = SecondDropAudioObject.Object;
	S_DeathAudio = DeathAudioObject.Object;


	// Create objects
	AggroAudio = NewObject<UAudioComponent>(this, TEXT("AggroAudio"));
	LobStartAudio = NewObject<UAudioComponent>(this, TEXT("LobStartAudio"));
	FirstDropAudio = NewObject<UAudioComponent>(this, TEXT("FirstDropAudio"));
	SecondDropAudio = NewObject<UAudioComponent>(this, TEXT("SecondDropAudio"));
	DeathAudio = NewObject<UAudioComponent>(this, TEXT("DeathAudio"));

	// Configure Components
	AggroAudio->Sound = S_AggroAudio;
	LobStartAudio->Sound = S_LobStartAudio;
	FirstDropAudio->Sound = S_FirstDropAudio;
	SecondDropAudio->Sound = S_SecondDropAudio;
	DeathAudio->Sound = S_DeathAudio;

	AggroAudio->bAutoActivate = false;
	LobStartAudio->bAutoActivate = false;
	FirstDropAudio->bAutoActivate = false;
	SecondDropAudio->bAutoActivate = false;
	DeathAudio->bAutoActivate = false;

	Name = EEnemyNames::EN_FrostGiant;
	Realm = ERealms::R_Boreal;
	BattleType = EBattleTypes::BT_Standard;
}

// Called when the game starts or when spawned
void AFrostGiant::BeginPlay()
{
	Super::BeginPlay();

	//OnDeath.AddDynamic(this, &ADemonStatue::Death()); // bind the death fuction to the OnDeath event 

}

void AFrostGiant::RunToTarget()
{
	if (!IsDead)
	{
		if (!Target->IsDead)
		{
			// AI run to target, DealDamage(), DoLob = true, delay 0.8, check if dead, play lob start audio, spawn Frost Giant lob drop actor, call DoLob on drop actor, do attack delay, DoLob = false, call again
		}
	}
}

void AFrostGiant::Death()
{
	IsDead = true;
}


