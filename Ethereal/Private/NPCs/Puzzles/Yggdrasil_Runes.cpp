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
#include "Yggdrasil_Runes.h"

AYggdrasil_Runes::AYggdrasil_Runes(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> AlcoveMesh(TEXT("StaticMesh'/Game/InfinityBladeIceLands/Environments/Ice/EX_Env_Ice_1/StaticMesh/SM_Ex_Rune_Stone_1.SM_Ex_Rune_Stone_1'"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh> RotundaMesh(TEXT("StaticMesh'/Game/InfinityBladeIceLands/Environments/Ice/EX_Env_Ice_1/StaticMesh/SM_Ex_Rune_Stone_1.SM_Ex_Rune_Stone_1'"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh> TreetopMesh(TEXT("StaticMesh'/Game/InfinityBladeIceLands/Environments/Ice/EX_Env_Ice_1/StaticMesh/SM_Ex_Rune_Stone_1.SM_Ex_Rune_Stone_1'"));
	static ConstructorHelpers::FObjectFinder<UParticleSystem> AlcoveParticle(TEXT("ParticleSystem'/Game/Vectorfields/Particles/P_YggdrasilRune.P_YggdrasilRune'"));
	static ConstructorHelpers::FObjectFinder<UParticleSystem> RotundaParticle(TEXT("ParticleSystem'/Game/Vectorfields/Particles/P_YggdrasilRune.P_YggdrasilRune'"));
	static ConstructorHelpers::FObjectFinder<UParticleSystem> TreetopParticle(TEXT("ParticleSystem'/Game/Vectorfields/Particles/P_YggdrasilRune.P_YggdrasilRune'"));
	static ConstructorHelpers::FObjectFinder<USoundCue> AlcoveAudioObject(TEXT("SoundCue'/Game/Audio/Party/Yggrasil_RunePower_Cue.Yggrasil_RunePower_Cue'"));
	static ConstructorHelpers::FObjectFinder<USoundCue> RotundaAudioObject(TEXT("SoundCue'/Game/Audio/Party/Yggrasil_RunePower_Cue.Yggrasil_RunePower_Cue'"));
	static ConstructorHelpers::FObjectFinder<USoundCue> TreetopAudioObject(TEXT("SoundCue'/Game/Audio/Party/Yggrasil_RunePower_Cue.Yggrasil_RunePower_Cue'"));
	static ConstructorHelpers::FObjectFinder<UParticleSystem> LeftEyeParticle(TEXT("ParticleSystem'/Game/Vectorfields/Particles/P_YggdrasilRune.P_YggdrasilRune'"));
	static ConstructorHelpers::FObjectFinder<UParticleSystem> RightEyeParticle(TEXT("ParticleSystem'/Game/Vectorfields/Particles/P_YggdrasilRune.P_YggdrasilRune'"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh> TreeTrunkMesh(TEXT("StaticMesh'/Game/KiteDemo/Environments/Trees/Tree_Stump_01/Tree_Stump_01.Tree_Stump_01'"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh> TreeBranchesMesh(TEXT("StaticMesh'/Game/Meshes/EpicTree.EpicTree'"));
	static ConstructorHelpers::FObjectFinder<UDestructibleMesh> TreeHeadMeshObject(TEXT("DestructibleMesh'/Game/Environment/Meshes/RTS_Env_Fire_NordHeed01_DM.RTS_Env_Fire_NordHeed01_DM'"));
	static ConstructorHelpers::FObjectFinder<UParticleSystem> EnergyPillarParticle(TEXT("ParticleSystem'/Game/InfinityBladeEffects/Effects/FX_Mobile/ICE/P_YggdrasilEnergyPillar.P_YggdrasilEnergyPillar'"));
	static ConstructorHelpers::FObjectFinder<UParticleSystem> PillarAuraParticle(TEXT("ParticleSystem'/Game/FXStarStarterKit/Particles/P_Yggdrasil_PillarPreAura.P_Yggdrasil_PillarPreAura'"));
	static ConstructorHelpers::FObjectFinder<UParticleSystem> LiftIndicatorParticle(TEXT("ParticleSystem'/Game/InfinityBladeEffects/Effects/FX_Mobile/combat/P_YggBossLiftIndicator.P_YggBossLiftIndicator'"));
	static ConstructorHelpers::FObjectFinder<USoundCue> HeadExplosionAudioObject(TEXT("SoundCue'/Game/EtherealParty/IceKnight/Audio/IceGiant_RockExplosion_Cue.IceGiant_RockExplosion_Cue'"));
	static ConstructorHelpers::FObjectFinder<USoundCue> EnergyChargeAudioObject(TEXT("SoundCue'/Game/EtherealParty/IceKnight/Audio/IceGiant_Charge_Cue.IceGiant_Charge_Cue'"));
	static ConstructorHelpers::FObjectFinder<USoundCue> AuraAudioObject(TEXT("SoundCue'/Game/EtherealParty/IceKnight/Audio/IceGiant_Breath_Cue.IceGiant_Breath_Cue'"));

	// Set Default Objects
	SM_Rune_Alcove = AlcoveMesh.Object;
	SM_Rune_Rotunda = RotundaMesh.Object;
	SM_Rune_Treetop = TreetopMesh.Object;
	P_AlcoveFX = AlcoveParticle.Object;
	P_RotundaFX = RotundaParticle.Object;
	P_TreetopFX = TreetopParticle.Object;
	S_AlcoveAudio = AlcoveAudioObject.Object;
	S_RotundaAudio = RotundaAudioObject.Object;
	S_TreetopAudio = TreetopAudioObject.Object;
	P_LeftEyeFX = LeftEyeParticle.Object;
	P_RightEyeFX = RightEyeParticle.Object;
	SM_TreeTrunk = TreeTrunkMesh.Object;
	SM_TreeBranches = TreeBranchesMesh.Object;
	DM_TreeHead = TreeHeadMeshObject.Object;
	P_EnergyPillarFX = EnergyPillarParticle.Object;
	P_PillarAuraFX = PillarAuraParticle.Object;
	P_LiftIndicatorFX = LiftIndicatorParticle.Object;
	S_HeadExplosionAudio = HeadExplosionAudioObject.Object;
	S_EnergyChargeAudio = EnergyChargeAudioObject.Object;
	S_AuraAudio = AuraAudioObject.Object;

	// Create objects
	Rune_Alcove = NewObject<UStaticMeshComponent>(this, TEXT("Rune_Alcove"));
	Rune_Alcove->StaticMesh = SM_Rune_Alcove;
	Rune_Rotunda = NewObject<UStaticMeshComponent>(this, TEXT("Rune_Rotunda"));
	Rune_Rotunda->StaticMesh = SM_Rune_Rotunda;
	Rune_Treetop = NewObject<UStaticMeshComponent>(this, TEXT("Rune_Treetop"));
	Rune_Treetop->StaticMesh = SM_Rune_Treetop;
	AlcoveFX = NewObject<UParticleSystemComponent>(this, TEXT("AlcoveFX"));
	AlcoveFX->Template = P_AlcoveFX;
	AlcoveFX->bAutoActivate = false;
	RotundaFX = NewObject<UParticleSystemComponent>(this, TEXT("RotundaFX"));
	RotundaFX->Template = P_RotundaFX;
	RotundaFX->bAutoActivate = false;
	TreetopFX = NewObject<UParticleSystemComponent>(this, TEXT("TreetopFX"));
	TreetopFX->Template = P_TreetopFX;
	TreetopFX->bAutoActivate = false;
	AlcoveAudio = NewObject<UAudioComponent>(this, TEXT("AlcoveAudio"));
	AlcoveAudio->Sound = S_AlcoveAudio;
	AlcoveAudio->bAutoActivate = false;
	RotundaAudio = NewObject<UAudioComponent>(this, TEXT("RotundaAudio"));
	RotundaAudio->Sound = S_RotundaAudio;
	RotundaAudio->bAutoActivate = false;
	TreetopAudio = NewObject<UAudioComponent>(this, TEXT("TreetopAudio"));
	TreetopAudio->Sound = S_TreetopAudio;
	TreetopAudio->bAutoActivate = false;
	LeftEyeFX = NewObject<UParticleSystemComponent>(this, TEXT("LeftEyeFX"));
	LeftEyeFX->Template = P_LeftEyeFX;
	LeftEyeFX->bAutoActivate = false;
	RightEyeFX = NewObject<UParticleSystemComponent>(this, TEXT("RightEyeFX"));
	RightEyeFX->Template = P_RightEyeFX;
	RightEyeFX->bAutoActivate = false;
	TreeTrunk = NewObject<UStaticMeshComponent>(this, TEXT("TreeTrunk"));
	TreeTrunk->StaticMesh = SM_TreeTrunk;
	TreeBranches = NewObject<UStaticMeshComponent>(this, TEXT("TreeBranches"));
	TreeBranches->StaticMesh = SM_TreeBranches;
	TreeHead = NewObject<UDestructibleComponent>(this, TEXT("TreeHead"));
	TreeHead->SetDestructibleMesh(DM_TreeHead);
	EnergyPillarFX = NewObject<UParticleSystemComponent>(this, TEXT("EnergyPillarFX"));
	EnergyPillarFX->Template = P_EnergyPillarFX;
	EnergyPillarFX->bAutoActivate = false;
	PillarAuraFX = NewObject<UParticleSystemComponent>(this, TEXT("PillarAuraFX"));
	PillarAuraFX->Template = P_PillarAuraFX;
	PillarAuraFX->bAutoActivate = false;
	LiftIndicatorFX = NewObject<UParticleSystemComponent>(this, TEXT("LiftIndicatorFX"));
	LiftIndicatorFX->Template = P_LiftIndicatorFX;
	LiftIndicatorFX->bAutoActivate = false;
	HeadExplosionAudio = NewObject<UAudioComponent>(this, TEXT("HeadExplosionAudio"));
	HeadExplosionAudio->Sound = S_HeadExplosionAudio;
	HeadExplosionAudio->bAutoActivate = false;
	EnergyChargeAudio = NewObject<UAudioComponent>(this, TEXT("EnergyChargeAudio"));
	EnergyChargeAudio->Sound = S_EnergyChargeAudio;
	EnergyChargeAudio->bAutoActivate = false;
	AuraAudio = NewObject<UAudioComponent>(this, TEXT("AuraAudio"));
	AuraAudio->Sound = S_AuraAudio;
	AuraAudio->bAutoActivate = false;
	
	IsUsable = true;
	InteractAnimType = EInteractAnims::IA_Open;
	DoInteract.AddDynamic(this, &AYggdrasil_Runes::Interact);

}

// Called when the game starts or when spawned
void AYggdrasil_Runes::BeginPlay()
{
	Super::BeginPlay();
}

// Interact with this NPC
void AYggdrasil_Runes::Interact()
{

}

