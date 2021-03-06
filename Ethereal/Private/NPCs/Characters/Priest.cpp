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
#include "Blueprint/UserWidget.h"
#include "Priest.h"

APriest::APriest(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	static ConstructorHelpers::FObjectFinder<USkeletalMesh> NPCMesh(TEXT("SkeletalMesh'/Game/EtherealParty/OldWizard/OldWizard.OldWizard'"));
	static ConstructorHelpers::FObjectFinder<UAnimBlueprint> AnimBP(TEXT("AnimBlueprint'/Game/EtherealParty/OldWizard/Anim_OldWizard.Anim_OldWizard'"));

	// Set Default Objects
	SM_Mesh = NPCMesh.Object;

	// Create objects
	Mesh = NewObject<USkeletalMeshComponent>(this, TEXT("Mesh"));
	Mesh->SetAnimInstanceClass(AnimBP.Object->GetAnimBlueprintGeneratedClass());
	Mesh->SkeletalMesh = SM_Mesh;

	IsUsable = true;
	InteractAnimType = EInteractAnims::IA_Talk;
	DoInteract.AddDynamic(this, &APriest::Interact);
}

// Called when the game starts or when spawned
void APriest::BeginPlay()
{
	Super::BeginPlay();
}

// Interact with this NPC
void APriest::Interact()
{
	StartInteractAnim();
	// Add widget to viewport and hide battle hud. 
}