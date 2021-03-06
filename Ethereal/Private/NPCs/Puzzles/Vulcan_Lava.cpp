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
#include "Vulcan_Lava.h"

AVulcan_Lava::AVulcan_Lava(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> Lava1Mesh(TEXT("StaticMesh'/Game/InfinityBladeFireLands/Environments/Fire/Env_Fire_Magma/StaticMesh/WeaponSmithsLava.WeaponSmithsLava'"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh> Lava2Mesh(TEXT("StaticMesh'/Game/InfinityBladeFireLands/Environments/Fire/Env_Fire_Magma/StaticMesh/WeaponSmithsLava.WeaponSmithsLava'"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh> Lava3Mesh(TEXT("StaticMesh'/Game/InfinityBladeFireLands/Environments/Fire/Env_Fire_Magma/StaticMesh/WeaponSmithsLava.WeaponSmithsLava'"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh> FireHeadMesh(TEXT("StaticMesh'/Game/InfinityBladeFireLands/Environments/Fire/Fire_Fortress/SM/Env_Fire_NordHeed02.Env_Fire_NordHeed02'"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh> HeadLavaMesh(TEXT("StaticMesh'/Game/InfinityBladeFireLands/Environments/Fire/Env_Fire_FlameDungeon/StaticMesh/Pipes/SM_Dungeon_Pipes_Lava01.SM_Dungeon_Pipes_Lava01'"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh> RockMesh(TEXT("StaticMesh'/Game/Elemental/Environment/Throne_Interior/Mesh/SM_Rock_01.SM_Rock_01'"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh> KickRockMesh(TEXT("StaticMesh'/Game/Elemental/Environment/Throne_Interior/Mesh/SM_Rock_01.SM_Rock_01'"));
	static ConstructorHelpers::FObjectFinder<USoundCue> AvalancheAudioObject(TEXT("SoundCue'/Game/Audio/Party/Shiitake_Gate_Cue.Shiitake_Gate_Cue'"));
	static ConstructorHelpers::FObjectFinder<USoundCue> ExplosionAudioObject(TEXT("SoundCue'/Game/Audio/Party/Shiitake_Gate_Cue.Shiitake_Gate_Cue'"));
	static ConstructorHelpers::FObjectFinder<USoundCue> FinalScreamAudioObject(TEXT("SoundCue'/Game/Audio/Party/Shiitake_Gate_Cue.Shiitake_Gate_Cue'"));

	// Set Default Objects
	SM_LavaMesh1 = Lava1Mesh.Object;
	SM_LavaMesh2 = Lava2Mesh.Object;
	SM_LavaMesh3 = Lava3Mesh.Object;
	SM_FireHead = FireHeadMesh.Object;
	SM_HeadLava = HeadLavaMesh.Object;
	SM_Rock = RockMesh.Object;
	SM_KickRock = KickRockMesh.Object;
	S_AvalancheAudio = AvalancheAudioObject.Object;
	S_ExplosionAudio = ExplosionAudioObject.Object;
	S_FinalScreamAudio = FinalScreamAudioObject.Object;

	// Create objects
	LavaMesh1 = NewObject<UStaticMeshComponent>(this, TEXT("LavaMesh1"));
	LavaMesh1->StaticMesh = SM_LavaMesh1;
	LavaMesh2 = NewObject<UStaticMeshComponent>(this, TEXT("LavaMesh2"));
	LavaMesh2->StaticMesh = SM_LavaMesh2;
	LavaMesh3 = NewObject<UStaticMeshComponent>(this, TEXT("LavaMesh3"));
	LavaMesh3->StaticMesh = SM_LavaMesh3;
	FireHead = NewObject<UStaticMeshComponent>(this, TEXT("FireHead"));
	FireHead->StaticMesh = SM_FireHead;
	HeadLava = NewObject<UStaticMeshComponent>(this, TEXT("HeadLava"));
	HeadLava->StaticMesh = SM_HeadLava;
	Rock = NewObject<UStaticMeshComponent>(this, TEXT("Rock"));
	Rock->StaticMesh = SM_Rock;
	KickRock = NewObject<UStaticMeshComponent>(this, TEXT("KickRock"));
	KickRock->StaticMesh = SM_KickRock;
	AvalancheAudio = NewObject<UAudioComponent>(this, TEXT("AvalancheAudio"));
	AvalancheAudio->Sound = S_AvalancheAudio;
	ExplosionAudio = NewObject<UAudioComponent>(this, TEXT("ExplosionAudio"));
	ExplosionAudio->Sound = S_ExplosionAudio;
	FinalScreamAudio = NewObject<UAudioComponent>(this, TEXT("FinalScreamAudio"));
	FinalScreamAudio->Sound = S_FinalScreamAudio;

	IsUsable = true;
	InteractAnimType = EInteractAnims::IA_Open;
	DoInteract.AddDynamic(this, &AVulcan_Lava::Interact);
}

// Called when the game starts or when spawned
void AVulcan_Lava::BeginPlay()
{
	Super::BeginPlay();

}

// Interact with this NPC
void AVulcan_Lava::Interact()
{
	IsUsable = false;
	StartInteractAnim();
	// TO DO : Play World Camera Shak CS Open Chest (for kicking the rock)
	// TO DO : DELAY 0.8
	// Play avalanche audio
	// TO DO : Play world camera shake CS Vulcan Rock Slide
	// TO DO : Spawn emitter at location, ParticleSystem'/Game/Elemental/Effects/Fx_DustAndDebris/ParticleSystems/P_Burnin_Sigil_RockDebris.P_Burnin_Sigil_RockDebris'
	// TO DO : Spawn emitter at location, ParticleSystem'/Game/Elemental/Effects/Fx_DustAndDebris/ParticleSystems/P_BreakAway_BackDebris.P_BreakAway_BackDebris'
	// TO DO : Move kick rock towards large rock with timeline
	// TO DO : Impact large rock, spawn emitter ParticleSystem'/Game/Elemental/Effects/Fx_Fire/ParticleSystems/P_ShatterRock_Blast2.P_ShatterRock_Blast2'
	// TO DO : Play Rock Explosion Audio (this was removed from the BP, too much audio at once. probably not going to put it back in)
	// TO DO : Play SFX Final Scream Audio
	// TO DO : SPawn emitter at Rock, ParticleSystem'/Game/Elemental/Effects/FX_HammerHit/ParticleSystems/P_Crack_03_BurstRock.P_Crack_03_BurstRock'
	// TO DO : move the Rock and the KickRock into their final positions
	// TO DO : move the lava down, so that the player can now traverse the area
}


