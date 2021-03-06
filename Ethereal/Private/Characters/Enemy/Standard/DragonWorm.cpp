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
#include "Kismet/KismetMathLibrary.h"
#include "DragonWorm.h"

ADragonWorm::ADragonWorm(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	static ConstructorHelpers::FObjectFinder<USkeletalMesh> EnemyMesh(TEXT("SkeletalMesh'/Game/EtherealParty/DragonWorm/DragonWorm.DragonWorm'"));
	static ConstructorHelpers::FObjectFinder<UAnimBlueprint> AnimBP(TEXT("AnimBlueprint'/Game/EtherealParty/DragonWorm/Worm_Anim.Worm_Anim'"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh> RockBaseMesh(TEXT("StaticMesh'/Game/SenzaPeso/MASTERALL/StaticMeshes/SK_LavaPillar_03.SK_LavaPillar_03'"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh> LavaBlobMesh(TEXT("StaticMesh'/Game/SenzaPeso/MASTERALL/StaticMeshes/SM_LavaBlob_01.SM_LavaBlob_01'"));
	static ConstructorHelpers::FObjectFinder<UParticleSystem> AggroFlareParticle(TEXT("ParticleSystem'/Game/Elemental/Effects/Fx_Magic/Effects/DragonWorm_AggroFlare.DragonWorm_AggroFlare'"));
	static ConstructorHelpers::FObjectFinder<USoundCue> AggroAudioObject(TEXT("SoundCue'/Game/Audio/Party/DragonWorm_Aggro_Cue.DragonWorm_Aggro_Cue'"));
	static ConstructorHelpers::FObjectFinder<USoundCue> SpitAudioObject(TEXT("SoundCue'/Game/Audio/Party/DragonWorm_Spit_Cue.DragonWorm_Spit_Cue'"));
	static ConstructorHelpers::FObjectFinder<USoundCue> DeathAudioObject(TEXT("SoundCue'/Game/Audio/Party/DragonWorm_Death_Cue.DragonWorm_Death_Cue'"));
	static ConstructorHelpers::FObjectFinder<USoundCue> HitAudioObject(TEXT("SoundCue'/Game/Audio/Party/DragonWorm_Hit_Cue.DragonWorm_Hit_Cue'"));

	// Set Default Objects
	GetMesh()->SkeletalMesh = EnemyMesh.Object;
	GetMesh()->SetAnimInstanceClass(AnimBP.Object->GetAnimBlueprintGeneratedClass());
	SM_RockBase = RockBaseMesh.Object;
	SM_LavaBlob = LavaBlobMesh.Object;
	P_AggroFlare = AggroFlareParticle.Object;
	S_AggroAudio = AggroAudioObject.Object;
	S_SpitAudio = SpitAudioObject.Object;
	S_DeathAudio = DeathAudioObject.Object;
	S_HitAudio = HitAudioObject.Object;

	// Create objects
	RockBase = NewObject<UStaticMeshComponent>(this, TEXT("RockBase"));
	LavaBlob = NewObject<UStaticMeshComponent>(this, TEXT("LavaBlob"));
	AggroFlare = NewObject<UParticleSystemComponent>(this, TEXT("AggroFlare"));
	AggroAudio = NewObject<UAudioComponent>(this, TEXT("AggroAudio"));
	SpitAudio = NewObject<UAudioComponent>(this, TEXT("SpitAudio"));
	DeathAudio = NewObject<UAudioComponent>(this, TEXT("DeathAudio"));
	HitAudio = NewObject<UAudioComponent>(this, TEXT("HitAudio"));

	// Configure Components
	RockBase->StaticMesh = SM_RockBase;
	LavaBlob->StaticMesh = SM_LavaBlob;
	AggroFlare->Template = P_AggroFlare;
	AggroAudio->Sound = S_AggroAudio;
	SpitAudio->Sound = S_SpitAudio;
	DeathAudio->Sound = S_DeathAudio;
	HitAudio->Sound = S_HitAudio;

	AggroFlare->bAutoActivate = false;
	AggroAudio->bAutoActivate = false;
	SpitAudio->bAutoActivate = false;
	DeathAudio->bAutoActivate = false;
	HitAudio->bAutoActivate = false;

	Name = EEnemyNames::EN_DragonWorm;
	Realm = ERealms::R_Vulcan;
	BattleType = EBattleTypes::BT_Standard;
}

// Called when the game starts or when spawned
void ADragonWorm::BeginPlay()
{
	Super::BeginPlay();

	//OnDeath.AddDynamic(this, &ADemonStatue::Death()); // bind the death fuction to the OnDeath event 

}

void ADragonWorm::RunToTarget()
{
	if (!IsDead)
	{
		if (!Target->IsDead)
		{
			// TO DO :  same stuff as the Soul Eater, in general. However, when Attack is set to true and his Spit animation plays, 
			// there is an anim notify that will spawn the Worm Spit Drop
			// Additionally, this enemy should call LookAtTarget() while aggroed, so that he is always facing the player
		}
	}
}

void ADragonWorm::Death()
{
	//FinalDeath(true, false);
	IsDead = true;
	LavaBlob->SetVisibility(false);
}

// Worm Aggro. Makes the worm appear from beneath the rock base
void ADragonWorm::WormAggro()
{
	IsAggroed = true;
	AggroFlare->Activate();
	LavaBlob->SetVisibility(true);
}

// Deaggro worm.  Makes the worm disappear back underneath the rock base.
void ADragonWorm::WormDeaggro()
{
	IsAggroed = false;
	AggroFlare->Deactivate();
	LavaBlob->SetVisibility(false);
}

// Called during tick while aggroed, forces the worm to always look at the player.
void ADragonWorm::LookAtTarget()
{
	FVector WormLocation = this->GetActorLocation(); // Get worm rotation
	FVector PlayerLocation = Target->GetActorLocation();  // get player location
	FRotator LookAtRot = UKismetMathLibrary::FindLookAtRotation(WormLocation, PlayerLocation);  // find look at rotation
	FRotator CorrectedRot = FRotator(LookAtRot.Pitch, LookAtRot.Yaw - 90, LookAtRot.Roll);  // correct rotation
	this->SetActorRotation(CorrectedRot); // set rotation to the corrected rotation
}