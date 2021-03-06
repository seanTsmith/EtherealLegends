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
#include "Shiitake_Door.h"

AShiitake_Door::AShiitake_Door(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> GearFrontMesh(TEXT("StaticMesh'/Game/InfinityBladeFireLands/Environments/Fire/Env_Fire_FlameDungeon/StaticMesh/Background/SM_Background_Gear01.SM_Background_Gear01'"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh> GearBackMesh(TEXT("StaticMesh'/Game/InfinityBladeFireLands/Environments/Fire/Env_Fire_FlameDungeon/StaticMesh/Background/SM_Background_Gear01.SM_Background_Gear01'"));
	static ConstructorHelpers::FObjectFinder<USoundCue> GateAudioObject(TEXT("SoundCue'/Game/Audio/Party/Shiitake_Gate_Cue.Shiitake_Gate_Cue'"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ColumnLeftMesh(TEXT("StaticMesh'/Game/InfinityBladeIceLands/Environments/Ice/Ice_Fortress/StaticMesh/SM_Ice_Fort_Pillar_2.SM_Ice_Fort_Pillar_2'"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ColumnRightMesh(TEXT("StaticMesh'/Game/InfinityBladeIceLands/Environments/Ice/Ice_Fortress/StaticMesh/SM_Ice_Fort_Pillar_2.SM_Ice_Fort_Pillar_2'"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh> GateMesh(TEXT("StaticMesh'/Game/InfinityBladeIceLands/Environments/Ice/Ice_Fortress/StaticMesh/SM_Ice_Fort_Gate_1.SM_Ice_Fort_Gate_1'"));

	// Set Default Objects
	SM_GearFront = GearFrontMesh.Object;
	SM_GearBack = GearBackMesh.Object;
	S_GateAudio = GateAudioObject.Object;
	SM_ColumnLeft = ColumnLeftMesh.Object;
	SM_ColumnRight = ColumnRightMesh.Object;
	SM_Gate = GateMesh.Object;

	// Create objects
	GearFront = NewObject<UStaticMeshComponent>(this, TEXT("GearFront"));
	GearFront->StaticMesh = SM_GearFront;
	GearBack = NewObject<UStaticMeshComponent>(this, TEXT("GearBack"));
	GearBack->StaticMesh = SM_GearBack;
	GearBack->SetupAttachment(GearFront);
	GateAudio = NewObject<UAudioComponent>(this, TEXT("GateAudio"));
	GateAudio->Sound = S_GateAudio;
	GateAudio->bAutoActivate = false;
	ColumnLeft = NewObject<UStaticMeshComponent>(this, TEXT("ColumnLeft"));
	ColumnLeft->StaticMesh = SM_ColumnLeft;
	ColumnLeft->SetupAttachment(GateAudio);
	ColumnRight = NewObject<UStaticMeshComponent>(this, TEXT("ColumnRight"));
	ColumnRight->StaticMesh = SM_ColumnRight;
	ColumnRight->SetupAttachment(GateAudio);
	Gate = NewObject<UStaticMeshComponent>(this, TEXT("Gate"));
	Gate->StaticMesh = SM_Gate;
	Gate->SetupAttachment(GateAudio);

	IsUsable = true;
	InteractAnimType = EInteractAnims::IA_Open;
	DoInteract.AddDynamic(this, &AShiitake_Door::Interact);
}

// Called when the game starts or when spawned
void AShiitake_Door::BeginPlay()
{
	Super::BeginPlay();

	GateStartLoc = Gate->GetComponentLocation();
	GateEndLoc = FVector(Gate->GetComponentLocation().X, Gate->GetComponentLocation().Y, (Gate->GetComponentLocation().X - 500.0f));
	RotatingMovement->RotationRate = FRotator(0, 0, 0);
}

// Interact with this NPC
void AShiitake_Door::Interact()
{
	if (!GateIsOpen)
	{
		StartInteractAnim();
		GateAudio->Play();
		RotatingMovement->SetUpdatedComponent(GearFront);
		RotatingMovement->RotationRate = FRotator(0, 0, 90);
		// TO DO :  do a timeline that lowers the gate, from startloc to endloc. when finished, set GateIsOpen to true, and gear rotation rate to 0
	}
}


