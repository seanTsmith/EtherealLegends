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
#include "GaiaTortoise.h"

AGaiaTortoise::AGaiaTortoise(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	static ConstructorHelpers::FObjectFinder<USkeletalMesh> EnemyMesh(TEXT("SkeletalMesh'/Game/EtherealParty/Adamantoise/Adamantoise.Adamantoise'"));
	static ConstructorHelpers::FObjectFinder<UAnimBlueprint> AnimBP(TEXT("AnimBlueprint'/Game/EtherealParty/Adamantoise/Adamantoise_AnimBP.Adamantoise_AnimBP'"));

	// Set Default Objects
	GetMesh()->SkeletalMesh = EnemyMesh.Object;
	GetMesh()->SetAnimInstanceClass(AnimBP.Object->GetAnimBlueprintGeneratedClass());

	Name = EEnemyNames::EN_GaiaTortoise;
	Realm = ERealms::R_Yggdrasil;
	BattleType = EBattleTypes::BT_Boss;
}

// Called when the game starts or when spawned
void AGaiaTortoise::BeginPlay()
{
	Super::BeginPlay();

	//OnDeath.AddDynamic(this, &ADemonStatue::Death()); // bind the death fuction to the OnDeath event 

}

void AGaiaTortoise::RunToTarget()
{
	if (!IsDead)
	{
		if (!Target->IsDead)
		{

		}
	}
}

void AGaiaTortoise::Death()
{
	IsDead = true;
}
