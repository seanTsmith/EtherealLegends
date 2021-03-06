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
#include "GiantSpider.h"

AGiantSpider::AGiantSpider(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	static ConstructorHelpers::FObjectFinder<USkeletalMesh> EnemyMesh(TEXT("SkeletalMesh'/Game/InfinityBladeAdversaries/Enemy/Enemy_Creature_Spider/SK_EXO_Creature_Spider02.SK_EXO_Creature_Spider02'"));
	static ConstructorHelpers::FObjectFinder<UAnimBlueprint> AnimBP(TEXT("AnimBlueprint'/Game/InfinityBladeAdversaries/Enemy/Enemy_Creature_Spider/Anim_Spider.Anim_Spider'"));
	static ConstructorHelpers::FObjectFinder<UParticleSystem> SpiderVomitParticle(TEXT("ParticleSystem'/Game/Elemental/Effects/Fx_Magic/Effects/DragonWorm_AggroFlare.DragonWorm_AggroFlare'"));
	static ConstructorHelpers::FObjectFinder<USoundCue> DeathAudioObject(TEXT("SoundCue'/Game/Audio/Party/Spider_Death_Cue.Spider_Death_Cue'"));

	// Set Default Objects
	GetMesh()->SkeletalMesh = EnemyMesh.Object;
	GetMesh()->SetAnimInstanceClass(AnimBP.Object->GetAnimBlueprintGeneratedClass());
	P_SpiderVomit = SpiderVomitParticle.Object;
	S_DeathAudio = DeathAudioObject.Object;

	// Create objects
	SpiderVomit = NewObject<UParticleSystemComponent>(this, TEXT("SpiderVomit"));
	DeathAudio = NewObject<UAudioComponent>(this, TEXT("DeathAudio"));

	// Configure Components
	SpiderVomit->Template = P_SpiderVomit;
	DeathAudio->Sound = S_DeathAudio;

	SpiderVomit->bAutoActivate = false;
	DeathAudio->bAutoActivate = false;

	Name = EEnemyNames::EN_Spider;
	Realm = ERealms::R_Boreal;
	BattleType = EBattleTypes::BT_Standard;
}

// Called when the game starts or when spawned
void AGiantSpider::BeginPlay()
{
	Super::BeginPlay();

	//OnDeath.AddDynamic(this, &ADemonStatue::Death()); // bind the death fuction to the OnDeath event 

}

void AGiantSpider::RunToTarget()
{
	if (!IsDead)
	{
		if (!Target->IsDead)
		{
			// AI move to, DealDamage(), set AoE decal visible, delay 1 second, check if dead, activate spider vomit fx, check inside collider for player, have him take damage, set aoe decal hidden, do attack delay and then run this function again.
		}
	}
}

void AGiantSpider::Death()
{
	IsDead = true;
}



