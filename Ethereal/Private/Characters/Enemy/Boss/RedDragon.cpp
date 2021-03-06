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
#include "RedDragon.h"

ARedDragon::ARedDragon(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	static ConstructorHelpers::FObjectFinder<USkeletalMesh> EnemyMesh(TEXT("SkeletalMesh'/Game/EtherealParty/Dragon/dragon_skin.dragon_skin'"));
	static ConstructorHelpers::FObjectFinder<UAnimBlueprint> AnimBP(TEXT("AnimBlueprint'/Game/EtherealParty/Dragon/Anim_RedDragon.Anim_RedDragon'"));
	static ConstructorHelpers::FObjectFinder<USoundCue> BreathAudioObject(TEXT("SoundCue'/Game/EtherealParty/Dragon/Audio/Dragon_FireBreath_Cue.Dragon_FireBreath_Cue'"));
	static ConstructorHelpers::FObjectFinder<USoundCue> TailWhipAudioObject(TEXT("SoundCue'/Game/EtherealParty/Dragon/Audio/Dragon_TailWhip_Cue.Dragon_TailWhip_Cue'"));
	static ConstructorHelpers::FObjectFinder<USoundCue> FlapAudioObject(TEXT("SoundCue'/Game/EtherealParty/Dragon/Audio/Dragon_Flap_Cue.Dragon_Flap_Cue'"));

	// Set Default Objects
	GetMesh()->SkeletalMesh = EnemyMesh.Object;
	GetMesh()->SetAnimInstanceClass(AnimBP.Object->GetAnimBlueprintGeneratedClass());
	S_BreathAudio = BreathAudioObject.Object;
	S_TailWhipAudio = TailWhipAudioObject.Object;
	S_FlapAudio = FlapAudioObject.Object;

	// Create objects
	HitBox = NewObject<UBoxComponent>(this, TEXT("HitBox"));
	MeleeRadius_Tail = NewObject<UBoxComponent>(this, TEXT("MeleeRadius_Tail"));
	MeleeRadius_Breath = NewObject<UBoxComponent>(this, TEXT("MeleeRadius_Breath"));
	BreathAudio = NewObject<UAudioComponent>(this, TEXT("BreathAudio"));
	TailWhipAudio = NewObject<UAudioComponent>(this, TEXT("TailWhipAudio"));
	FlapAudio = NewObject<UAudioComponent>(this, TEXT("FlapAudio"));

	// Configure Components
	BreathAudio->Sound = S_BreathAudio;
	TailWhipAudio->Sound = S_TailWhipAudio;
	FlapAudio->Sound = S_FlapAudio;

	BreathAudio->bAutoActivate = false;
	TailWhipAudio->bAutoActivate = false;
	FlapAudio->bAutoActivate = false;

	Name = EEnemyNames::EN_RedDragon;
	Realm = ERealms::R_Vulcan;
	BattleType = EBattleTypes::BT_Boss;
}

// Called when the game starts or when spawned
void ARedDragon::BeginPlay()
{
	Super::BeginPlay();

	//OnDeath.AddDynamic(this, &ADemonStatue::Death()); // bind the death fuction to the OnDeath event 

	// TO DO :  Get the placement actor, so this enemy has a reference to the flight spline
}

void ARedDragon::RunToTarget()
{
	if (!IsDead)
	{
		if (!Target->IsDead)
		{
			// TO DO : if player is overlapping MeleeRadius_Breath, do Breath()
			// TO DO : if player is overlapping MeleeRadius_Tail, do TailSwipe()
			// TO DO : if overlapping neither, ResetAnims() and then DetermineFlight()
		}
	}
}

void ARedDragon::Death()
{
	//FinalDeath(true, false);
	IsDead = true;
}

void ARedDragon::ResetAnims()
{
	IsHit = false;
	DoBreath = false;
	DoSwipe = false;
}

void ARedDragon::DetermineFlight()
{
	if (FlightCount < 2)
	{
		if (InFlight == false)
		{
			switch (FlightCount)
			{
				case 0:
					if (HP_Current < (HP_Max * 0.75f))
					{
						FlightCount = 1;
						TakeFlight();
					}
					break;
				case 1:
					if (HP_Current < (HP_Max * 0.50f))
					{
						FlightCount = 2;
						TakeFlight();
					}
					break;
				case 2:
					if (HP_Current < (HP_Max * 0.25f))
					{
						FlightCount = 3;
						TakeFlight();
					}
					break;
			}
		}
	}
}

void ARedDragon::TakeFlight()
{
	ResetAnims();
	Targetable = false;
	
	if (!IsDead)
	{
		// TO DO : AI MOVE TO the placement's Take Off Point reference component.
		EnemyDealDamage(40);
		FastFlap = true;
		// TO DO : Spawn Boss Worms
	}
}

void ARedDragon::FireBreath()
{
	DoBreath = true;
	this->GetCharacterMovement()->StopMovementImmediately();
	this->GetCharacterMovement()->SetMovementMode(EMovementMode::MOVE_None);
	EnemyDealDamage(30);
	// delay two seconds, then check if player is overlapping MeleeRadius_Breath, and if so, Deal Damage to player
	// after the attack delay, set movement mode to walking, ResetAnims(), check if dead, and if not, DetermineFlight()
}

void ARedDragon::TailSwipe()
{
	DoSwipe = true;
	this->GetCharacterMovement()->StopMovementImmediately();
	this->GetCharacterMovement()->SetMovementMode(EMovementMode::MOVE_None);
	// delay 0.5 seconds, then check if player is overlapping MeleeRadius_Tail, and if so, Deal Damage to the player
	// after the attack delay, set movement mode to walking, ResetAnims(), check if dead, and if not, DetermineFlight()
}

void ARedDragon::FollowSplineInFlight()
{
	if (InFlight)
	{
		DistanceOnSpline = DistanceOnSpline + 12;
		// TO DO :  Get distance along spline, world space coordinates, and set the actor location accordingly
		// TO DO :  Get rotation at distance along spline, world coordinate space, and set actor rotation accordingly

		// TO DO : DECAL TRIGGERS and BREATH IN FLIGHT and END FLIGHT / LAND
	}
}

