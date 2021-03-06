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
#include "EarthTroll.h"

AEarthTroll::AEarthTroll(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	static ConstructorHelpers::FObjectFinder<USkeletalMesh> EnemyMesh(TEXT("SkeletalMesh'/Game/InfinityBladeAdversaries/Enemy/Enemy_Troll/SK_Troll_Poison.SK_Troll_Poison'"));
	static ConstructorHelpers::FObjectFinder<UAnimBlueprint> AnimBP(TEXT("AnimBlueprint'/Game/InfinityBladeAdversaries/Enemy/Enemy_Troll/Anim_Troll.Anim_Troll'"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh> HammerMesh(TEXT("StaticMesh'/Game/InfinityBladeAdversaries/Enemy/Enemy_Troll/Meshes/SM_Troll_hammer.SM_Troll_hammer'"));
	static ConstructorHelpers::FObjectFinder<UParticleSystem> VomitParticleObject(TEXT("ParticleSystem'/Game/InfinityBladeEffects/Effects/FX_Monsters/FX_Monster_Troll/Poison/P_Troll_Poison_Vomit_01.P_Troll_Poison_Vomit_01'"));
	static ConstructorHelpers::FObjectFinder<USoundCue> AggroAudioObject(TEXT("SoundCue'/Game/Audio/Party/FrostGiant_Aggro_Cue.FrostGiant_Aggro_Cue'"));
	static ConstructorHelpers::FObjectFinder<USoundCue> HitAudioObject(TEXT("SoundCue'/Game/EtherealParty/IceKnight/Audio/Avatar_IceKnight_Hit_Cue.Avatar_IceKnight_Hit_Cue'"));
	static ConstructorHelpers::FObjectFinder<USoundCue> SwipeAudioObject(TEXT("SoundCue'/Game/Sounds/FoleyBodyMoves/Stereo/FoleyBody_HandSwipe_Stereo_Cue.FoleyBody_HandSwipe_Stereo_Cue'"));
	static ConstructorHelpers::FObjectFinder<USoundCue> SpitAudioObject(TEXT("SoundCue'/Game/Audio/Party/GiantSpider_AtkSpit_Cue.GiantSpider_AtkSpit_Cue'"));
	static ConstructorHelpers::FObjectFinder<USoundCue> RoarAudioObject(TEXT("SoundCue'/Game/Audio/Party/FrostCaptain_StompRoar_Cue.FrostCaptain_StompRoar_Cue'"));
	static ConstructorHelpers::FObjectFinder<USoundCue> FirstDropAudioObject(TEXT("SoundCue'/Game/Audio/Party/FrostGiant_Death_FirstDrop_Cue.FrostGiant_Death_FirstDrop_Cue'"));
	static ConstructorHelpers::FObjectFinder<USoundCue> SecondDropAudioObject(TEXT("SoundCue'/Game/Audio/Party/FrostGiant_Death_SecondDrop_Cue.FrostGiant_Death_SecondDrop_Cue'"));
	static ConstructorHelpers::FObjectFinder<USoundCue> DeathAudioObject(TEXT("SoundCue'/Game/Audio/Party/FrostGiant_Death_Cue.FrostGiant_Death_Cue'"));

	// Set Default Objects
	GetMesh()->SkeletalMesh = EnemyMesh.Object;
	GetMesh()->SetAnimInstanceClass(AnimBP.Object->GetAnimBlueprintGeneratedClass());
	SM_Hammer = HammerMesh.Object;
	P_VomitFX = VomitParticleObject.Object;
	S_AggroAudio = AggroAudioObject.Object;
	S_HitAudio = HitAudioObject.Object;
	S_SwipeAudio = SwipeAudioObject.Object;
	S_SpitAudio = SpitAudioObject.Object;
	S_RoarAudio = RoarAudioObject.Object;
	S_FirstDropAudio = FirstDropAudioObject.Object;
	S_SecondDropAudio = SecondDropAudioObject.Object;
	S_DeathAudio = DeathAudioObject.Object;


	// Create objects
	SpitBox = NewObject<UBoxComponent>(this, TEXT("SpitBox"));
	Hammer = NewObject<UStaticMeshComponent>(this, TEXT("Hammer"));
	VomitFX = NewObject<UParticleSystemComponent>(this, TEXT("VomitFX"));
	AggroAudio = NewObject<UAudioComponent>(this, TEXT("AggroAudio"));
	HitAudio = NewObject<UAudioComponent>(this, TEXT("HitAudio"));
	SwipeAudio = NewObject<UAudioComponent>(this, TEXT("SwipeAudio"));
	SpitAudio = NewObject<UAudioComponent>(this, TEXT("SpitAudio"));
	RoarAudio = NewObject<UAudioComponent>(this, TEXT("RoarAudio"));
	FirstDropAudio = NewObject<UAudioComponent>(this, TEXT("FirstDropAudio"));
	SecondDropAudio = NewObject<UAudioComponent>(this, TEXT("SecondDropAudio"));
	DeathAudio = NewObject<UAudioComponent>(this, TEXT("DeathAudio"));

	// Configure Components
	Hammer->StaticMesh = SM_Hammer;
	VomitFX->Template = P_VomitFX;
	AggroAudio->Sound = S_AggroAudio;
	HitAudio->Sound = S_HitAudio;
	SwipeAudio->Sound = S_SwipeAudio;
	SpitAudio->Sound = S_SpitAudio;
	RoarAudio->Sound = S_RoarAudio;
	FirstDropAudio->Sound = S_FirstDropAudio;
	SecondDropAudio->Sound = S_SecondDropAudio;
	DeathAudio->Sound = S_DeathAudio;

	VomitFX->bAutoActivate = false;
	AggroAudio->bAutoActivate = false;
	HitAudio->bAutoActivate = false;
	SwipeAudio->bAutoActivate = false;
	SpitAudio->bAutoActivate = false;
	RoarAudio->bAutoActivate = false;
	FirstDropAudio->bAutoActivate = false;
	SecondDropAudio->bAutoActivate = false;
	DeathAudio->bAutoActivate = false;

	SpitBox->SetRelativeLocation(FVector(0, 350, 90));
	SpitBox->SetBoxExtent(FVector(100, 400, 150));

	Name = EEnemyNames::EN_EarthTroll;
	Realm = ERealms::R_Yggdrasil;
	BattleType = EBattleTypes::BT_Standard;

	// TO DO : Attach the Hammer to the Mesh in the WeaponSocket
	// TO DO : Attach the VomitFX to the Mesh in the VomitSocket
}

// Called when the game starts or when spawned
void AEarthTroll::BeginPlay()
{
	Super::BeginPlay();

	//OnDeath.AddDynamic(this, &ADemonStatue::Death()); // bind the death fuction to the OnDeath event 

}

void AEarthTroll::RunToTarget()
{
	if (!IsDead)
	{
		if (!Target->IsDead)
		{
			// AI move to, then random between 0 and 7, picking one of three functions: Sling(), Swipe(), or Spit().
		}
	}
}

void AEarthTroll::Death()
{
	IsDead = true;
	DeathAudio->Play();
}

void AEarthTroll::Sling()
{
	EnemyDealDamage(45);
	DoSling = true;
	// TO DO :  Spawn the Troll Sling Drop, pass it the target and damage output
	// Wait attack delay, then call RunToTarget()
}

void AEarthTroll::Swipe()
{
	EnemyDealDamage(40);
	DoSwipe = true;
	// TO DO : Set AoE Cone visible
	// Wait attack delay, then call RunToTarget()
}

void AEarthTroll::Spit()
{
	EnemyDealDamage(50);
	DoSpit = true;
	// Wait attack delay, then call RunToTarget()
}


