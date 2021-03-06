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
#include "Flytrap.h"

AFlytrap::AFlytrap(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	static ConstructorHelpers::FObjectFinder<USkeletalMesh> EnemyMesh(TEXT("SkeletalMesh'/Game/EtherealParty/Elongata/Elongata.Elongata'"));
	static ConstructorHelpers::FObjectFinder<UAnimBlueprint> AnimBP(TEXT("AnimBlueprint'/Game/EtherealParty/Elongata/Flytrap_AnimBP.Flytrap_AnimBP'"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh> FernBaseMesh(TEXT("StaticMesh'/Game/KiteDemo/Environments/Foliage/Ferns/SM_Fern_01.SM_Fern_01'"));
	static ConstructorHelpers::FObjectFinder<USoundCue> AggroAudioObject(TEXT("SoundCue'/Game/Audio/Party/Flytrap_Aggro_Cue.Flytrap_Aggro_Cue'"));
	static ConstructorHelpers::FObjectFinder<USoundCue> HitAudioObject(TEXT("SoundCue'/Game/Audio/Party/Flytrap_Hit_Cue.Flytrap_Hit_Cue'"));
	static ConstructorHelpers::FObjectFinder<USoundCue> BiteAudioObject(TEXT("SoundCue'/Game/Audio/Party/Flytrap_Bite_Cue.Flytrap_Bite_Cue'"));
	static ConstructorHelpers::FObjectFinder<USoundCue> SpitAudioObject(TEXT("SoundCue'/Game/Audio/Party/Flytrap_Spit_Cue.Flytrap_Spit_Cue'"));
	static ConstructorHelpers::FObjectFinder<USoundCue> DeathAudioObject(TEXT("SoundCue'/Game/Audio/Party/Flytrap_Death_Cue.Flytrap_Death_Cue'"));

	// Set Default Objects
	GetMesh()->SkeletalMesh = EnemyMesh.Object;
	GetMesh()->SetAnimInstanceClass(AnimBP.Object->GetAnimBlueprintGeneratedClass());
	SM_FernBase = FernBaseMesh.Object;
	S_AggroAudio = AggroAudioObject.Object;
	S_HitAudio = HitAudioObject.Object;
	S_BiteAudio = BiteAudioObject.Object;
	S_SpitAudio = SpitAudioObject.Object;
	S_DeathAudio = DeathAudioObject.Object;


	// Create objects
	FernBase = NewObject<UStaticMeshComponent>(this, TEXT("FernBase"));
	AggroAudio = NewObject<UAudioComponent>(this, TEXT("AggroAudio"));
	HitAudio = NewObject<UAudioComponent>(this, TEXT("HitAudio"));
	BiteAudio = NewObject<UAudioComponent>(this, TEXT("BiteAudio"));
	SpitAudio = NewObject<UAudioComponent>(this, TEXT("SpitAudio"));
	DeathAudio = NewObject<UAudioComponent>(this, TEXT("DeathAudio"));

	// Configure Components
	FernBase->StaticMesh = SM_FernBase;
	AggroAudio->Sound = S_AggroAudio;
	HitAudio->Sound = S_HitAudio;
	BiteAudio->Sound = S_BiteAudio;
	SpitAudio->Sound = S_SpitAudio;
	DeathAudio->Sound = S_DeathAudio;

	AggroAudio->bAutoActivate = false;
	HitAudio->bAutoActivate = false;
	BiteAudio->bAutoActivate = false;
	SpitAudio->bAutoActivate = false;
	DeathAudio->bAutoActivate = false;

	this->GetCharacterMovement()->MaxAcceleration = 0; // prevent this actor from moving, because it's a damn plant.

	Name = EEnemyNames::EN_Flytrap;
	Realm = ERealms::R_Yggdrasil;
	BattleType = EBattleTypes::BT_Standard;
}

// Called when the game starts or when spawned
void AFlytrap::BeginPlay()
{
	Super::BeginPlay();

	//OnDeath.AddDynamic(this, &ADemonStatue::Death()); // bind the death fuction to the OnDeath event 

}

void AFlytrap::RunToTarget()
{
	if (!IsDead)
	{
		if (!Target->IsDead)
		{
			// TO DO : AI move to, if player is in melee radius, 
			// EnemyDealDamage(35) Bite = true
			// else
			// EnemyDealDamage(25) Spit = true
			// wait attack delay, then RunToTarget()
		}
	}
}

void AFlytrap::Death()
{
	IsDead = true;
	DeathAudio->Play();
}


void AFlytrap::LookAtTarget()
{
	FVector FlytrapLocation = this->GetActorLocation(); // GetFlytrap rotation
	FVector PlayerLocation = Target->GetActorLocation();  // get player location
	FRotator LookAtRot = UKismetMathLibrary::FindLookAtRotation(FlytrapLocation, PlayerLocation);  // find look at rotation
	FRotator CorrectedRot = FRotator(LookAtRot.Pitch, LookAtRot.Yaw - 90, LookAtRot.Roll);  // correct rotation
	this->SetActorRotation(CorrectedRot); // set rotation to the corrected rotation
}

