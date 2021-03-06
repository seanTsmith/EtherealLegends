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
#include "Nightshade.h"

ANightshade::ANightshade(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	static ConstructorHelpers::FObjectFinder<USkeletalMesh> EnemyMesh(TEXT("SkeletalMesh'/Game/MixamoAnimPack/Mixamo_Nightshade/Nightshade_J_Friedrich.Nightshade_J_Friedrich'"));
	static ConstructorHelpers::FObjectFinder<UAnimBlueprint> AnimBP(TEXT("AnimBlueprint'/Game/MixamoAnimPack/Mixamo_Nightshade/Anim_Nightshade.Anim_Nightshade'"));

	// Set Default Objects
	GetMesh()->SkeletalMesh = EnemyMesh.Object;
	GetMesh()->SetAnimInstanceClass(AnimBP.Object->GetAnimBlueprintGeneratedClass());

	Name = EEnemyNames::EN_Nightshade;
	Realm = ERealms::R_Empyrean;
	BattleType = EBattleTypes::BT_Standard;
}

// Called when the game starts or when spawned
void ANightshade::BeginPlay()
{
	Super::BeginPlay();

	//OnDeath.AddDynamic(this, &ADemonStatue::Death()); // bind the death fuction to the OnDeath event 

}

void ANightshade::RunToTarget()
{
	if (!IsDead)
	{
		if (!Target->IsDead)
		{

		}
	}
}

void ANightshade::Death()
{
	IsDead = true;
}


