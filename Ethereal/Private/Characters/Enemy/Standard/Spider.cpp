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
#include "Spider.h"

ASpider::ASpider(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	static ConstructorHelpers::FObjectFinder<USkeletalMesh> EnemyMesh(TEXT("SkeletalMesh'/Game/InfinityBladeAdversaries/Enemy/Enemy_Creature_Spider/SK_EXO_Creature_Spider02.SK_EXO_Creature_Spider02'"));
	static ConstructorHelpers::FObjectFinder<UAnimBlueprint> AnimBP(TEXT("AnimBlueprint'/Game/InfinityBladeAdversaries/Enemy/Enemy_Creature_Spider/Anim_Spider.Anim_Spider'"));
	static ConstructorHelpers::FObjectFinder<USoundCue> DeathAudioObject(TEXT("SoundCue'/Game/Audio/Party/Spider_Death_Cue.Spider_Death_Cue'"));

	// Set Default Objects
	GetMesh()->SkeletalMesh = EnemyMesh.Object;
	GetMesh()->SetAnimInstanceClass(AnimBP.Object->GetAnimBlueprintGeneratedClass());
	S_DeathAudio = DeathAudioObject.Object;

	// Create objects
	DeathAudio = NewObject<UAudioComponent>(this, TEXT("DeathAudio"));

	// Configure Components
	DeathAudio->Sound = S_DeathAudio;

	DeathAudio->bAutoActivate = false;

	Name = EEnemyNames::EN_Spider;
	Realm = ERealms::R_Boreal;
	BattleType = EBattleTypes::BT_Standard;
}

// Called when the game starts or when spawned
void ASpider::BeginPlay()
{
	Super::BeginPlay();

	//OnDeath.AddDynamic(this, &ADemonStatue::Death()); // bind the death fuction to the OnDeath event 

}

void ASpider::RunToTarget()
{
	if (!IsDead)
	{
		if (!Target->IsDead)
		{

		}
	}
}

void ASpider::Death()
{
	IsDead = true;
}

