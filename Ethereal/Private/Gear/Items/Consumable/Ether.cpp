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
#include "Ether.h"

// Sets default values
AEther::AEther(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	// Get Assets, References Obtained Via Right Click in Editor
	ConstructorHelpers::FObjectFinder<USoundCue> AudioObject(TEXT("SoundCue'/Game/Audio/Party/Ethereal_Elixer_Cue.Ethereal_Elixer_Cue'"));
	ConstructorHelpers::FObjectFinder<UParticleSystem> ParticleObject(TEXT("ParticleSystem'/Game/EtherealParty/OldWizard/Effects/Item_UsePotion.Item_UsePotion'"));
	ConstructorHelpers::FObjectFinder<UTexture2D> LargeIconObject(TEXT("Texture2D'/Game/Blueprints/Widgets/UI-Images/Icons_Gear/ItemIcon_Ether.ItemIcon_Ether'"));
	ConstructorHelpers::FObjectFinder<UTexture2D> SmallIconObject(TEXT("Texture2D'/Game/Blueprints/Widgets/UI-Images/Icons_Gear/ItemIcon_Ether-small.ItemIcon_Ether-small'"));

	// Set Default Objects

	Name = EMasterGearList::GL_Ether;
	Type = EMasterGearTypes::GT_Consumable;
	Effect = "+ 35% of Max MP.";
	Description = "Restores a small amount of MP.";
	LargeIcon = LargeIconObject.Object;
	SmallIcon = SmallIconObject.Object;
	S_ItemAudio = AudioObject.Object;
	P_ItemFX = ParticleObject.Object;

}

// Called when the game starts or when spawned
void AEther::BeginPlay()
{
	Super::BeginPlay();

	// Bind the Use function to the event dispatcher for Item Use
	OnItemUse.AddDynamic(this, &AEther::Use);

	ItemFX->Template = P_ItemFX;
	ItemFX->bAutoActivate = false;
	ItemAudio->Sound = S_ItemAudio;
	ItemAudio->bAutoActivate = false;
}

void AEther::Use()
{
	GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Red, "An Item Was Used.");

	// Activate ItemFX
	// Play ItemAudio
	// Player State Reference
	// MP_Current = MP_Current + (MP_Max * 0.35)
	// Force MP Caps
	// Show Combat Text MP Restore
}


