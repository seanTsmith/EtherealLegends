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
#include "DemonStatue.h"

ADemonStatue::ADemonStatue(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	// Asset, Reference Obtained Via Right Click in Editor
	static ConstructorHelpers::FObjectFinder<UDestructibleMesh> DestructibleMeshObject(TEXT("DestructibleMesh'/Game/InfinityBladeGrassLands/Environments/Plains/Env_Plains_Statues/StaticMesh/SM_Plains_Castle_DemonDoor_01_DM.SM_Plains_Castle_DemonDoor_01_DM'"));
	static ConstructorHelpers::FObjectFinder<UParticleSystem> FlareRParticleObject(TEXT("ParticleSystem'/Game/InfinityBladeEffects/Effects/FX_Monsters/FX_Monster_Elemental/ICE/Souleater_Statue_EyeFlare.Souleater_Statue_EyeFlare'"));
	static ConstructorHelpers::FObjectFinder<UParticleSystem> FlareLParticleObject(TEXT("ParticleSystem'/Game/InfinityBladeEffects/Effects/FX_Monsters/FX_Monster_Elemental/ICE/Souleater_Statue_EyeFlare.Souleater_Statue_EyeFlare'"));
	static ConstructorHelpers::FObjectFinder<UParticleSystem> IdleRParticleObject(TEXT("ParticleSystem'/Game/InfinityBladeEffects/Effects/FX_Monsters/FX_Monster_Chicken/Souleater_Statue_EyeIdle.Souleater_Statue_EyeIdle'"));
	static ConstructorHelpers::FObjectFinder<UParticleSystem> IdleLParticleObject(TEXT("ParticleSystem'/Game/InfinityBladeEffects/Effects/FX_Monsters/FX_Monster_Chicken/Souleater_Statue_EyeIdle.Souleater_Statue_EyeIdle'"));
	static ConstructorHelpers::FObjectFinder<UParticleSystem> StompBlastParticleObject(TEXT("ParticleSystem'/Game/InfinityBladeEffects/Effects/FX_Mobile/combat/SoulEater-Statue-StompBlast.SoulEater-Statue-StompBlast'"));
	static ConstructorHelpers::FObjectFinder<USoundCue> JumpAudioObject(TEXT("SoundCue'/Game/Audio/Rocks/SoulEater_Statue_Jump_Cue.SoulEater_Statue_Jump_Cue'"));
	static ConstructorHelpers::FObjectFinder<USoundCue> StompAudioObject(TEXT("SoundCue'/Game/Audio/Rocks/SoulEater_Statue_Stomp_Cue.SoulEater_Statue_Stomp_Cue'"));
	static ConstructorHelpers::FObjectFinder<USoundCue> ExplosionAudioObject(TEXT("SoundCue'/Game/Audio/Impacts/Rock_Explo_Slowed02_L_Cue.Rock_Explo_Slowed02_L_Cue'"));

	// Set Default Objects
	DM_DemonDoor = DestructibleMeshObject.Object;
	P_EyeFlareFX_R = FlareRParticleObject.Object;
	P_EyeFlareFX_L = FlareLParticleObject.Object;
	P_EyeIdleFX_R = IdleRParticleObject.Object;
	P_EyeIdleFX_L = IdleRParticleObject.Object;
	P_StompBlast = StompBlastParticleObject.Object;
	S_JumpAudio = JumpAudioObject.Object;
	S_StompAudio = StompAudioObject.Object;
	S_ExplosionAudio = ExplosionAudioObject.Object;

	// Creates scene components for knowing where to spawn Soul Eaters upon aggro
	SpawnLocR = NewObject<USceneComponent>(this, TEXT("SpawnLocR"));
	SpawnLocL = NewObject<USceneComponent>(this, TEXT("SpawnLocL"));
	StompRadius = NewObject<USphereComponent>(this, TEXT("StompRadius"));

	DemonDoor = NewObject<UDestructibleComponent>(this, TEXT("DemonDoor"));
	EyeFlareFX_R = NewObject<UParticleSystemComponent>(this, TEXT("EyeFlareFX_R"));
	EyeFlareFX_L = NewObject<UParticleSystemComponent>(this, TEXT("EyeFlareFX_L"));
	EyeIdleFX_R = NewObject<UParticleSystemComponent>(this, TEXT("EyeIdleFX_R"));
	EyeIdleFX_L = NewObject<UParticleSystemComponent>(this, TEXT("EyeIdleFX_L"));
	StompBlast = NewObject<UParticleSystemComponent>(this, TEXT("StompBlast"));
	JumpAudio = NewObject<UAudioComponent>(this, TEXT("JumpAudio"));
	StompAudio = NewObject<UAudioComponent>(this, TEXT("StompAudio"));
	ExplosionAudio = NewObject<UAudioComponent>(this, TEXT("ExplosionAudio"));

	// Configure Components
	DemonDoor->SetDestructibleMesh(DM_DemonDoor);
	EyeFlareFX_R->Template = P_EyeFlareFX_R;
	EyeFlareFX_L->Template = P_EyeFlareFX_L;
	EyeIdleFX_R->Template = P_EyeIdleFX_R;
	EyeIdleFX_L->Template = P_EyeIdleFX_L;
	StompBlast->Template = P_StompBlast;
	JumpAudio->Sound = S_JumpAudio;
	StompAudio->Sound = S_StompAudio;
	ExplosionAudio->Sound = S_ExplosionAudio;
	StompRadius->SetSphereRadius(300.0f);

	Name = EEnemyNames::EN_DemonStatue;
	Realm = ERealms::R_Shiitake;
	BattleType = EBattleTypes::BT_Standard;
}

// Called when the game starts or when spawned
void ADemonStatue::BeginPlay()
{
	Super::BeginPlay();

	//OnDeath.AddDynamic(this, &ADemonStatue::Death()); // bind the death fuction to the OnDeath event 
}

void ADemonStatue::ToggleEyes(bool HideEyes)
{
	if (HideEyes)
	{
		EyeFlareFX_R->Deactivate();
		EyeFlareFX_L->Deactivate();
		EyeIdleFX_R->Deactivate();
		EyeIdleFX_R->Deactivate();
	}
	else
	{
		EyeFlareFX_R->Activate();
		EyeFlareFX_L->Activate();
		EyeIdleFX_R->Activate();
		EyeIdleFX_R->Activate();
	}
}

void ADemonStatue::RunToTarget()
{
	if (!IsDead)
	{
		if (!Target->IsDead)
		{
			// TO DO:  Run to target. This function is currently in Blueprints.
			// When the enemy gets within melee range of the player, do a melee attack.
			// after the attack delay, run this function again
		}
	}
}

void ADemonStatue::Death()
{
	DemonDoor->ApplyRadiusDamage(100, this->GetActorLocation(), 100, 100, true);  // Destroy the door
	ToggleEyes(false);
	FinalDeath(true, false);
	// TO DO :  destroy the AoE decal
}

void ADemonStatue::SpawnSoulEaters()
{
	ExplosionAudio->Play();
	// TO DO :  Spawn AI from Soul Eater class at SpawnLocR
	// TO DO :  Spawn AI from Soul Eater class at SpawnLocL
	// TO DO :  Spawn emitter at both locations  -  ParticleSystem'/Game/InfinityBladeEffects/Effects/FX_Mobile/Fire/combat/SoulEaterSpawn.SoulEaterSpawn'
}

void ADemonStatue::StompAttack()
{
	JumpAudio->Play();
	FVector JumpStartLocation = this->GetActorLocation();
	// TO DO :  Run a timeline that lerps this actor into the air to simulate a jump
	// use JumpStartLocation as the start, and JumpStartLocation + 60 on Z as the End
	// Timeline has a two second curve, 0.75 second to go up to 1, 0.5 second delay, and another 0.75 seconds down to 0.
	// An event occurs at 0.75 spawns the AoE decal
	// When the timeline ends, destroy the AoE decal, then continue with the rest of the code
	StompBlast->Activate();
	StompAudio->Play();

	TArray<AActor*> Overlapping;  // define a local array to store hits
	StompRadius->GetOverlappingActors(Overlapping, AEtherealPlayerMaster::StaticClass()); // check for overlapping players within the stomp radius

	for (AActor* Actor : Overlapping) // for each actor found overlapping
	{
		AEtherealPlayerMaster* Player = Cast<AEtherealPlayerMaster>(Actor);  // cast to Player Master

		if (Player) // if succeeded
		{
			// TO DO :  Make the player take damage
		}
	}

	// TO DO :  call this function again after the attack delay
}

