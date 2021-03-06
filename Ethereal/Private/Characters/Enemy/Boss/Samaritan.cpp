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
#include "Samaritan.h"

ASamaritan::ASamaritan(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	static ConstructorHelpers::FObjectFinder<USkeletalMesh> EnemyMesh(TEXT("SkeletalMesh'/Game/Character/Samaritan_bot/SkeletalMesh/SK_Samaritan_Bot_GDC.SK_Samaritan_Bot_GDC'"));
	static ConstructorHelpers::FObjectFinder<UAnimBlueprint> AnimBP(TEXT("AnimBlueprint'/Game/Character/Samaritan_bot/SkeletalMesh/Anim_Samaritan.Anim_Samaritan'"));

	// Set Default Objects
	GetMesh()->SkeletalMesh = EnemyMesh.Object;
	GetMesh()->SetAnimInstanceClass(AnimBP.Object->GetAnimBlueprintGeneratedClass());

	Name = EEnemyNames::EN_Samaritan;
	Realm = ERealms::R_Empyrean;
	BattleType = EBattleTypes::BT_Boss;
}

// Called when the game starts or when spawned
void ASamaritan::BeginPlay()
{
	Super::BeginPlay();

	//OnDeath.AddDynamic(this, &ADemonStatue::Death()); // bind the death fuction to the OnDeath event 

}

void ASamaritan::RunToTarget()
{
	if (!IsDead)
	{
		if (!Target->IsDead)
		{

		}
	}
}

void ASamaritan::Death()
{
	IsDead = true;
}