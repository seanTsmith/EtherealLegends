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
#include "Characters/Player/EtherealPlayerMaster.h"
#include "Haste.h"

// Sets default values
AHaste::AHaste(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	// Get Assets, References Obtained Via Right Click in Editor
	ConstructorHelpers::FObjectFinder<USoundCue> AudioObject(TEXT("SoundCue'/Game/EtherealParty/OldWizard/Audio/Absolut_Haste_Cue.Absolut_Haste_Cue'"));
	ConstructorHelpers::FObjectFinder<UParticleSystem> CastParticleObject(TEXT("ParticleSystem'/Game/Blueprints/Gear/Magic/SpellEffects/Particles/Spell_Haste.Spell_Haste'"));
	ConstructorHelpers::FObjectFinder<UParticleSystem> ChargeParticleObject(TEXT("ParticleSystem'/Game/Blueprints/Gear/Magic/SpellEffects/Particles/ChargeFX/ChargeParticle.ChargeParticle'"));
	ConstructorHelpers::FObjectFinder<UTexture2D> LargeIconObject(TEXT("Texture2D'/Game/Blueprints/Widgets/UI-Images/Icons_Magic/haste.haste'"));
	ConstructorHelpers::FObjectFinder<UTexture2D> SmallIconObject(TEXT("Texture2D'/Game/Blueprints/Widgets/UI-Images/Icons_Magic/haste-small.haste-small'"));

	// Set Default Values
	Name = EMasterGearList::GL_Haste;
	Type = EMasterGearTypes::GT_Support;
	Description = "Temporarily increase SPD, improving cast time and movement speed by 20%.";
	MPCost = 60;
	ATK = 0;
	DEF = 0;
	SPD = 20;
	HP = -240;
	MP = -40;
	Duration = 60;
	CastTime = 40;
	CritMultiplier = 0;
	HasteMultiplier = 0.20f;
	DefenseMultiplier = 0;
	TargetType = EMagic_TargetTypes::TT_Player;
	AnimType = EMagic_AnimTypes::AT_Standard;

	// Set Default Objects
	S_CastAudio = AudioObject.Object;
	P_CastFX = CastParticleObject.Object;
	P_ChargeFX = ChargeParticleObject.Object;
	LargeIcon = LargeIconObject.Object;
	SmallIcon = SmallIconObject.Object;

	CastAudio->Sound = S_CastAudio;
	CastFX->Template = P_CastFX;
	ChargeFX->Template = P_ChargeFX;
}

// Called when the game starts or when spawned
void AHaste::BeginPlay()
{
	Super::BeginPlay();

	// Bind the Use function to the event dispatcher for Item Use
	QuitCharging.AddDynamic(this, &AHaste::Cancel);
}

void AHaste::Cancel()
{
	GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Red, "Haste casting was cancelled.");
}


void AHaste::ChargeHaste()
{
	IsCharging = true; // Set Charging State True
	ChargeFX->SetColorParameter("Color", FLinearColor(1, 0.33f, 0, 1));  // Set Charge Particle Color
	ChargeFX->Activate();  // Activate the charge particle
	 // Get player mesh and attach this object
	Root->AttachToComponent(OwnerReference->GetMesh(), FAttachmentTransformRules::SnapToTargetIncludingScale, "PowerSocket");
}

void AHaste::CastHaste()
{
	// TO DO:  Get Player Controller and set Haste Status on BattleHUD
	// TO DO:  Create Dynamic Material Instances and set the Scalar Parameter Value "HasteAlpha" in order to fade in/out the particle effect using a timeline

	IsCharging = false;
	IsCasting = true;
	ChargeFX->Deactivate(); // Deactivate Charge particle
	CastAudio->Play(); // Play Cast Audio
	CastFX->Activate(); // Activate Cast FX particle

	IncreaseSPD();

	// Remove the SPD Boost after the spell's Duration is complete
	FTimerHandle CastTimer;
	GetWorldTimerManager().SetTimer(CastTimer, this, &AHaste::DecreaseSPD, Duration, false);
}

void AHaste::IncreaseSPD()
{
	StoredSPDBoost = OwnerReference->EtherealPlayerState->SPD * HasteMultiplier;  // Define the SPD Boost amount
	OwnerReference->EtherealPlayerState->SPD = OwnerReference->EtherealPlayerState->SPD + StoredSPDBoost;  // Add the SPD Boost to the player's current SPD
	OwnerReference->GetCharacterMovement()->MaxWalkSpeed = 150;  // Set Player's Max Walk Speed to 150
}

void AHaste::DecreaseSPD()
{
	OwnerReference->EtherealPlayerState->SPD = OwnerReference->EtherealPlayerState->SPD - StoredSPDBoost;  // Remove the SPD Boost from the player's current SPD
	// Set the player's Max Walk Speed back to normal
	//if (OwnerReference->IsRunning)
	//{
	//	OwnerReference->GetCharacterMovement()->MaxWalkSpeed = 100;  // Set Player's Max Walk Speed to 100 if running is toggled on
	//}
	//else
	//{
	//	OwnerReference->GetCharacterMovement()->MaxWalkSpeed = 50;  // Set Player's Max Walk Speed to 50 if running is toggled off
	//}

}

