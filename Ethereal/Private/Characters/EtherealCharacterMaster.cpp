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
#include "EtherealCharacterMaster.h"


// Sets default values
AEtherealCharacterMaster::AEtherealCharacterMaster(const FObjectInitializer& ObjectInitializer)
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Add Capsule Component as Root Component
	//Capsule = GetCapsuleComponent();
	
	// Get Assets, References Obtained Via Right Click in Editor
	static ConstructorHelpers::FObjectFinder<UStaticMesh> StaticMeshObject(TEXT("StaticMesh'/Game/Shapes/SM_TargetingReticle.SM_TargetingReticle'"));
	static ConstructorHelpers::FObjectFinder<USoundCue> AudioObject(TEXT("SoundCue'/Game/Audio/Eth_Menu/Ethereal_MenuCursor_Cue.Ethereal_MenuCursor_Cue'"));
	// Set Default Objects
	SM_TargetingReticle = StaticMeshObject.Object;
	S_TargetingAudio = AudioObject.Object;
	// Create
	TargetingReticle = ObjectInitializer.CreateDefaultSubobject<UStaticMeshComponent>(this, TEXT("Targeting Reticle"));
	TargetingAudio = ObjectInitializer.CreateDefaultSubobject<UAudioComponent>(this, TEXT("Targeting Audio"));
	// Set Mesh
	TargetingReticle->SetStaticMesh(SM_TargetingReticle);
	// Configure Mesh
	SetupSMComponentsWithCollision(TargetingReticle);

	TargetingAudio->Sound = S_TargetingAudio;
	TargetingAudio->bAutoActivate = false;
}

// Called when the game starts or when spawned
void AEtherealCharacterMaster::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AEtherealCharacterMaster::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
}

// Called to bind functionality to input
void AEtherealCharacterMaster::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);
}

// Activate the Targeting Reticle when Locked On (only used by the player)
void AEtherealCharacterMaster::ToggleReticle(bool Visible)
{
	if (Visible)
	{
		TargetingReticle->SetVisibility(true);
		TargetingAudio->Play();
	}
	else
	{
		TargetingReticle->SetVisibility(false);
	}
}

