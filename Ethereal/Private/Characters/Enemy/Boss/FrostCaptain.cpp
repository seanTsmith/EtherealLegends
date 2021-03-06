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
#include "FrostCaptain.h"

AFrostCaptain::AFrostCaptain(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	static ConstructorHelpers::FObjectFinder<USkeletalMesh> EnemyMesh(TEXT("SkeletalMesh'/Game/InfinityBladeAdversaries/Enemy/Enemy_Frost_Giant/SK_Enemy_FrostGiant_Magic.SK_Enemy_FrostGiant_Magic'"));
	static ConstructorHelpers::FObjectFinder<UAnimBlueprint> AnimBP(TEXT("AnimBlueprint'/Game/InfinityBladeAdversaries/Enemy/Enemy_Frost_Giant/Anim_FrostGiant.Anim_FrostGiant'"));
	static ConstructorHelpers::FObjectFinder<USoundCue> AggroAudioObject(TEXT("SoundCue'/Game/Audio/Party/FrostGiant_Aggro_Cue.FrostGiant_Aggro_Cue'"));
	static ConstructorHelpers::FObjectFinder<USoundCue> HitAudioObject(TEXT("SoundCue'/Game/Audio/Party/FrostGiant_Aggro_Cue.FrostGiant_Aggro_Cue'"));
	static ConstructorHelpers::FObjectFinder<USoundCue> SnortAudioObject(TEXT("SoundCue'/Game/Audio/Party/FrostGiant_LobStart_Cue.FrostGiant_LobStart_Cue'"));
	static ConstructorHelpers::FObjectFinder<USoundCue> StompAudioObject(TEXT("SoundCue'/Game/Audio/Party/FrostGiant_Aggro_Cue.FrostGiant_Aggro_Cue'"));
	static ConstructorHelpers::FObjectFinder<USoundCue> RoarAudioObject(TEXT("SoundCue'/Game/Audio/Party/FrostGiant_Aggro_Cue.FrostGiant_Aggro_Cue'"));
	static ConstructorHelpers::FObjectFinder<USoundCue> FirstDropAudioObject(TEXT("SoundCue'/Game/Audio/Party/FrostGiant_Death_FirstDrop_Cue.FrostGiant_Death_FirstDrop_Cue'"));
	static ConstructorHelpers::FObjectFinder<USoundCue> SecondDropAudioObject(TEXT("SoundCue'/Game/Audio/Party/FrostGiant_Death_SecondDrop_Cue.FrostGiant_Death_SecondDrop_Cue'"));
	static ConstructorHelpers::FObjectFinder<USoundCue> DeathAudioObject(TEXT("SoundCue'/Game/Audio/Party/FrostGiant_Death_Cue.FrostGiant_Death_Cue'"));

	// Set Default Objects
	GetMesh()->SkeletalMesh = EnemyMesh.Object;
	GetMesh()->SetAnimInstanceClass(AnimBP.Object->GetAnimBlueprintGeneratedClass());
	S_AggroAudio = AggroAudioObject.Object;
	S_HitAudio = HitAudioObject.Object;
	S_SnortAudio = SnortAudioObject.Object;
	S_StompAudio = StompAudioObject.Object;
	S_RoarAudio = RoarAudioObject.Object;
	S_FirstDropAudio = FirstDropAudioObject.Object;
	S_SecondDropAudio = SecondDropAudioObject.Object;
	S_DeathAudio = DeathAudioObject.Object;


	// Create objects
	AggroAudio = NewObject<UAudioComponent>(this, TEXT("AggroAudio"));
	HitAudio = NewObject<UAudioComponent>(this, TEXT("HitAudio"));
	SnortAudio = NewObject<UAudioComponent>(this, TEXT("SnortAudio"));
	StompAudio = NewObject<UAudioComponent>(this, TEXT("StompAudio"));
	RoarAudio = NewObject<UAudioComponent>(this, TEXT("RoarAudio"));
	FirstDropAudio = NewObject<UAudioComponent>(this, TEXT("FirstDropAudio"));
	SecondDropAudio = NewObject<UAudioComponent>(this, TEXT("SecondDropAudio"));
	DeathAudio = NewObject<UAudioComponent>(this, TEXT("DeathAudio"));

	// Configure Components
	AggroAudio->Sound = S_AggroAudio;
	HitAudio->Sound = S_HitAudio;
	SnortAudio->Sound = S_SnortAudio;
	StompAudio->Sound = S_StompAudio;
	RoarAudio->Sound = S_RoarAudio;
	FirstDropAudio->Sound = S_FirstDropAudio;
	SecondDropAudio->Sound = S_SecondDropAudio;
	DeathAudio->Sound = S_DeathAudio;

	AggroAudio->bAutoActivate = false;
	HitAudio->bAutoActivate = false;
	SnortAudio->bAutoActivate = false;
	StompAudio->bAutoActivate = false;
	RoarAudio->bAutoActivate = false;
	FirstDropAudio->bAutoActivate = false;
	SecondDropAudio->bAutoActivate = false;
	DeathAudio->bAutoActivate = false;

	Name = EEnemyNames::EN_FrostCaptain;
	Realm = ERealms::R_Boreal;
	BattleType = EBattleTypes::BT_Boss;
}

// Called when the game starts or when spawned
void AFrostCaptain::BeginPlay()
{
	Super::BeginPlay();

	//OnDeath.AddDynamic(this, &ADemonStatue::Death()); // bind the death fuction to the OnDeath event 

	// TO DO : Get placement actor reference

	// TO DO :  Aggro Player, IsAggroed = true, delay 0.5, IsAggroed = false (move that to an anim notify, I guess)
	// delay 7 seconds, then RunToTarget()

}

void AFrostCaptain::RunToTarget()
{
	if (!IsDead)
	{
		if (!Target->IsDead)
		{
			// AI move to, then random between 0 and 7, picking one of three functions: Haymaker(), Stomp(), or Blizzard().
		}
	}
}

void AFrostCaptain::Death()
{
	IsDead = true;
	DeathAudio->Play();
	// TO DO : Deactivate Energy Wall 
}

void AFrostCaptain::Haymaker()
{
	EnemyDealDamage(20);
	DoHaymaker = true;  // should set DoHaymaker to false based on anim notify
	// TO DO :  Spawn haymaker drop
	// delay 1 second, check for player inside Haymaker Drop collider and have the player take damage.
	// wait attack delay and then call ShouldPowerCore()
}

void AFrostCaptain::Stomp()
{
	EnemyDealDamage(20);
	DoStomp = true;
	// TO DO : Spawn Stomp Drop
	// DELAY 2 seconds
	// DoStomp = false;
	// attack delay, then ShouldPowerCore()
}

void AFrostCaptain::Blizzard()
{
	EnemyDealDamage(20);
	DoBlizzard = true;
	AggroAudio->Play();
	// TO DO : Spawn Blizzard Drop and set damage output
	// DELAY 0.2, DoBlizzard = false;
	// DELAY 3 seconds, Destroy Blizzard Drop
	// wait attack delay, then ShouldPowerCore()
}

void AFrostCaptain::ShouldPowerCore()
{
	if (PoweredCoreCount < 2)
	{
		switch (PoweredCoreCount)
		{
		case 0:
			if (HP_Current < (HP_Max * 0.75f))
			{
				PoweredCoreCount = 1;
				PowerCore();
			}
			else
			{
				RunToTarget();
			}
			break;
		case 1:
			if (HP_Current < (HP_Max * 0.30f))
			{
				PoweredCoreCount = 2;
				PowerCore();
			}
			else
			{
				RunToTarget();
			}
			break;
		}
	}
}

void AFrostCaptain::PowerCore()
{
	if (!IsDead)
	{
		Targetable = false;  // cannot target during this phase
		DoLeap = true;  // leap animation

		// TO DO :  Timeline, move to placement's captain burst platform, over 2 seconds.
		// TO DO :  Activate the Core's energy wall
		// TO DO :  IsAggroed = true;

		// DELAY 7 seconds.
		DoLeap = true; // leap animation again
		// TO DO:  Timeline, move to placenemtn's Return Node, over 2 seconds.

		Targetable = true;
		RunToTarget();
		// TO DO :  DELAY 30 seconds and deactivate the energy wall
	}
}

