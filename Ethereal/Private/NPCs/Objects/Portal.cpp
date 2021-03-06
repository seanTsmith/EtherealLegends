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
#include "Portal.h"

APortal::APortal(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> BaseMesh(TEXT("StaticMesh'/Game/Env/Infil1_City_Decos/Mesh/SM_Infil1_City_Roof_Trim_VarB_ColumnBaseDouble.SM_Infil1_City_Roof_Trim_VarB_ColumnBaseDouble'"));
	static ConstructorHelpers::FObjectFinder<USoundCue> PortalAudioObject(TEXT("SoundCue'/Game/Audio/Impacts/PortalExplosion_Cue.PortalExplosion_Cue'"));
	static ConstructorHelpers::FObjectFinder<UParticleSystem> HolosphereParticle(TEXT("ParticleSystem'/Game/Effects/Holograms/P_Hologram_Sculpture_01.P_Hologram_Sculpture_01'"));
	static ConstructorHelpers::FObjectFinder<UParticleSystem> HolospireParticle(TEXT("ParticleSystem'/Game/Effects/Holograms/HologramSpire.HologramSpire'"));
	static ConstructorHelpers::FObjectFinder<UParticleSystem> BurstParticle(TEXT("ParticleSystem'/Game/InfinityBladeEffects/Effects/FX_Monsters/FX_Monster_Ausar/P_AU_Trap_Impact.P_AU_Trap_Impact'"));

	// Set Default Objects
	SM_Base = BaseMesh.Object;
	S_PortalAudio = PortalAudioObject.Object;
	P_HolosphereFX = HolosphereParticle.Object;
	P_HolospireFX = HolospireParticle.Object;
	P_BurstFX = BurstParticle.Object;

	// Create objects
	Base = NewObject<UStaticMeshComponent>(this, TEXT("Base"));
	Base->StaticMesh = SM_Base;
	PortalAudio = NewObject<UAudioComponent>(this, TEXT("PortalAudio"));
	PortalAudio->Sound = S_PortalAudio;
	PortalAudio->bAutoActivate = false;
	HolosphereFX = NewObject<UParticleSystemComponent>(this, TEXT("HolosphereFX"));
	HolosphereFX->Template = P_HolosphereFX;
	HolosphereFX->bAutoActivate = false;
	HolospireFX = NewObject<UParticleSystemComponent>(this, TEXT("HolospireFX"));
	HolospireFX->Template = P_HolospireFX;
	HolospireFX->bAutoActivate = false;
	BurstFX = NewObject<UParticleSystemComponent>(this, TEXT("BurstFX"));
	BurstFX->Template = P_BurstFX;
	BurstFX->bAutoActivate = false;

	IsUsable = true;
	InteractAnimType = EInteractAnims::IA_Open;
	DoInteract.AddDynamic(this, &APortal::Interact);
}

// Called when the game starts or when spawned
void APortal::BeginPlay()
{
	Super::BeginPlay();
}

// Interact with this NPC
void APortal::Interact()
{
	// TO DO :  Spawn Level Select widget, set it active and add it to viewport. Hide Battle HUD.
	StartInteractAnim();
}

// Do a Burst effect when the portal is activated
void APortal::DoBurstEffect()
{
	HolospireFX->Activate();
	BurstFX->Activate();
	PortalAudio->Play();
}


