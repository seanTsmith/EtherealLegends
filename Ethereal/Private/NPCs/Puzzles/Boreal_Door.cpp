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
#include "Boreal_Door.h"

ABoreal_Door::ABoreal_Door(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> DoorLeftMesh(TEXT("StaticMesh'/Game/Environment/Meshes/SM_Cave_Statue_01.SM_Cave_Statue_01'"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh> DoorRightMesh(TEXT("StaticMesh'/Game/Environment/Meshes/SM_Cave_Statue_01.SM_Cave_Statue_01'"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh> Satellite1Mesh(TEXT("StaticMesh'/Game/Environment/Meshes/SM_Cave_Statue_01.SM_Cave_Statue_01'"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh> Satellite2Mesh(TEXT("StaticMesh'/Game/Environment/Meshes/SM_Cave_Statue_01.SM_Cave_Statue_01'"));
	static ConstructorHelpers::FObjectFinder<UParticleSystem> AuraLeftDoorParticle(TEXT("ParticleSystem'/Game/ExampleContent/Effects/ParticleSystems/P_Sov_StatueAura.P_Sov_StatueAura'"));
	static ConstructorHelpers::FObjectFinder<UParticleSystem> AuraRightDoorParticle(TEXT("ParticleSystem'/Game/ExampleContent/Effects/ParticleSystems/P_Sov_StatueAura.P_Sov_StatueAura'"));
	static ConstructorHelpers::FObjectFinder<UParticleSystem> AuraSatellite1Particle(TEXT("ParticleSystem'/Game/ExampleContent/Effects/ParticleSystems/P_Sov_StatueAura.P_Sov_StatueAura'"));
	static ConstructorHelpers::FObjectFinder<UParticleSystem> AuraSatellite2Particle(TEXT("ParticleSystem'/Game/ExampleContent/Effects/ParticleSystems/P_Sov_StatueAura.P_Sov_StatueAura'"));
	static ConstructorHelpers::FObjectFinder<UParticleSystem> FlareLeftDoorParticle(TEXT("ParticleSystem'/Game/Effects/Particles/Eth_DemonStatuePower.Eth_DemonStatuePower'"));
	static ConstructorHelpers::FObjectFinder<UParticleSystem> FlareRightDoorParticle(TEXT("ParticleSystem'/Game/Effects/Particles/Eth_DemonStatuePower.Eth_DemonStatuePower'"));
	static ConstructorHelpers::FObjectFinder<UParticleSystem> FlareSatellite1Particle(TEXT("ParticleSystem'/Game/Effects/Particles/Eth_DemonStatuePower.Eth_DemonStatuePower'"));
	static ConstructorHelpers::FObjectFinder<UParticleSystem> FlareSatellite2Particle(TEXT("ParticleSystem'/Game/Effects/Particles/Eth_DemonStatuePower.Eth_DemonStatuePower'"));
	static ConstructorHelpers::FObjectFinder<USoundCue> LeftDoorAudioObject(TEXT("SoundCue'/Game/Audio/Cave/Statue_Burst_Cue.Statue_Burst_Cue'"));
	static ConstructorHelpers::FObjectFinder<USoundCue> RightDoorAudioObject(TEXT("SoundCue'/Game/Audio/Cave/Statue_Burst_Cue.Statue_Burst_Cue'"));
	static ConstructorHelpers::FObjectFinder<USoundCue> Satellite1AudioObject(TEXT("SoundCue'/Game/Audio/Cave/Statue_Burst_Cue.Statue_Burst_Cue'"));
	static ConstructorHelpers::FObjectFinder<USoundCue> Satellite2AudioObject(TEXT("SoundCue'/Game/Audio/Cave/Statue_Burst_Cue.Statue_Burst_Cue'"));
	static ConstructorHelpers::FObjectFinder<USkeletalMesh> DoorsMesh(TEXT("SkeletalMesh'/Game/Elemental/Animation/Skeletal_Meshes/lava_knight_proxy/Throne_Doors.Throne_Doors'"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh> DoorsArchMesh(TEXT("StaticMesh'/Game/Elemental/Environment/Throne_Exterior/Mesh/SM_Throne_Exterior_DoorArch.SM_Throne_Exterior_DoorArch'"));
	static ConstructorHelpers::FObjectFinder<USoundCue> DoorOpenAudioObject(TEXT("SoundCue'/Game/Elemental/Sound/Cinematic/DoorOpening.DoorOpening'"));

	// Set Default Objects
	SM_Statue_LeftDoor = DoorLeftMesh.Object;
	SM_Statue_RightDoor = DoorRightMesh.Object;
	SM_Statue_Satellite1 = Satellite1Mesh.Object;
	SM_Statue_Satellite2 = Satellite2Mesh.Object;
	P_AuraFX_LeftDoor = AuraLeftDoorParticle.Object;
	P_AuraFX_RightDoor = AuraRightDoorParticle.Object;
	P_AuraFX_Satellite1 = AuraSatellite1Particle.Object;
	P_AuraFX_Satellite2 = AuraSatellite2Particle.Object;
	P_FlareFX_LeftDoor = FlareLeftDoorParticle.Object;
	P_FlareFX_RightDoor = FlareRightDoorParticle.Object;
	P_FlareFX_Satellite1 = FlareSatellite1Particle.Object;
	P_FlareFX_Satellite2 = FlareSatellite2Particle.Object;
	S_FlareAudio_LeftDoor = LeftDoorAudioObject.Object;
	S_FlareAudio_RightDoor = RightDoorAudioObject.Object;
	S_FlareAudio_Satellite1 = Satellite1AudioObject.Object;
	S_FlareAudio_Satellite2 = Satellite2AudioObject.Object;
	SK_Doors = DoorsMesh.Object;
	SM_DoorsArch = DoorsArchMesh.Object;
	S_DoorOpenAudio = DoorOpenAudioObject.Object;

	// Create objects
	Statue_LeftDoor = NewObject<UStaticMeshComponent>(this, TEXT("Statue_LeftDoor"));
	Statue_LeftDoor->StaticMesh = SM_Statue_LeftDoor;
	Statue_RightDoor = NewObject<UStaticMeshComponent>(this, TEXT("Statue_RightDoor"));
	Statue_RightDoor->StaticMesh = SM_Statue_RightDoor;
	Statue_Satellite1 = NewObject<UStaticMeshComponent>(this, TEXT("Statue_Satellite1"));
	Statue_Satellite1->StaticMesh = SM_Statue_Satellite1;
	Statue_Satellite2 = NewObject<UStaticMeshComponent>(this, TEXT("Statue_Satellite2"));
	Statue_Satellite2->StaticMesh = SM_Statue_Satellite2;
	AuraFX_LeftDoor = NewObject<UParticleSystemComponent>(this, TEXT("AuraFX_LeftDoor"));
	AuraFX_LeftDoor->Template = P_AuraFX_LeftDoor;
	AuraFX_LeftDoor->bAutoActivate = false;
	AuraFX_RightDoor = NewObject<UParticleSystemComponent>(this, TEXT("AuraFX_RightDoor"));
	AuraFX_RightDoor->Template = P_AuraFX_RightDoor;
	AuraFX_RightDoor->bAutoActivate = false;
	AuraFX_Satellite1 = NewObject<UParticleSystemComponent>(this, TEXT("AuraFX_Satellite1"));
	AuraFX_Satellite1->Template = P_AuraFX_Satellite1;
	AuraFX_Satellite1->bAutoActivate = false;
	AuraFX_Satellite2 = NewObject<UParticleSystemComponent>(this, TEXT("AuraFX_Satellite2"));
	AuraFX_Satellite2->Template = P_AuraFX_Satellite2;
	AuraFX_Satellite2->bAutoActivate = false;
	FlareFX_LeftDoor = NewObject<UParticleSystemComponent>(this, TEXT("FlareFX_LeftDoor"));
	FlareFX_LeftDoor->Template = P_FlareFX_LeftDoor;
	FlareFX_LeftDoor->bAutoActivate = false;
	FlareFX_RightDoor = NewObject<UParticleSystemComponent>(this, TEXT("FlareFX_RightDoor"));
	FlareFX_RightDoor->Template = P_FlareFX_RightDoor;
	FlareFX_RightDoor->bAutoActivate = false;
	FlareFX_Satellite1 = NewObject<UParticleSystemComponent>(this, TEXT("FlareFX_Satellite1"));
	FlareFX_Satellite1->Template = P_FlareFX_Satellite1;
	FlareFX_Satellite1->bAutoActivate = false;
	FlareFX_Satellite2 = NewObject<UParticleSystemComponent>(this, TEXT("FlareFX_Satellite2"));
	FlareFX_Satellite2->Template = P_FlareFX_Satellite2;
	FlareFX_Satellite2->bAutoActivate = false;
	FlareAudio_LeftDoor = NewObject<UAudioComponent>(this, TEXT("FlareAudio_LeftDoor"));
	FlareAudio_LeftDoor->Sound = S_FlareAudio_LeftDoor;
	FlareAudio_LeftDoor->bAutoActivate = false;
	FlareAudio_RightDoor = NewObject<UAudioComponent>(this, TEXT("FlareAudio_RightDoor"));
	FlareAudio_RightDoor->Sound = S_FlareAudio_RightDoor;
	FlareAudio_RightDoor->bAutoActivate = false;
	FlareAudio_Satellite1 = NewObject<UAudioComponent>(this, TEXT("FlareAudio_Satellite1"));
	FlareAudio_Satellite1->Sound = S_FlareAudio_Satellite1;
	FlareAudio_Satellite1->bAutoActivate = false;
	FlareAudio_Satellite2 = NewObject<UAudioComponent>(this, TEXT("FlareAudio_Satellite2"));
	FlareAudio_Satellite2->Sound = S_FlareAudio_Satellite2;
	FlareAudio_Satellite2->bAutoActivate = false;
	Doors = NewObject<USkeletalMeshComponent>(this, TEXT("Doors"));
	Doors->SkeletalMesh = SK_Doors;
	//Doors->AnimationMode = Use Animation Asset
	//Doors->AnimToPlay = AnimSequence'/Game/Elemental/Animation/LavaKnight_Animations/Anims/Anim_Shot_0003_Throne_Doors.Anim_Shot_0003_Throne_Doors'
	DoorsArch = NewObject<UStaticMeshComponent>(this, TEXT("DoorsArch"));
	DoorsArch->StaticMesh = SM_DoorsArch;
	DoorOpenAudio = NewObject<UAudioComponent>(this, TEXT("DoorOpenAudio"));
	DoorOpenAudio->Sound = S_DoorOpenAudio;
	DoorOpenAudio->bAutoActivate = false;

	//// LEFT DOOR STATUE
	//AuraFX_LeftDoor->SetupAttachment(Statue_LeftDoor);
	//FlareFX_LeftDoor->SetupAttachment(Statue_LeftDoor);
	//FlareAudio_LeftDoor->SetupAttachment(Statue_LeftDoor);
	//InteractBox_LeftDoor->SetupAttachment(Statue_LeftDoor);
	//PointLight_LeftDoor->SetupAttachment(PointLight_LeftDoor);

	//// RIGHT DOOR STATUE
	//AuraFX_RightDoor->SetupAttachment(Statue_RightDoor);
	//FlareFX_RightDoor->SetupAttachment(Statue_RightDoor);
	//FlareAudio_RightDoor->SetupAttachment(Statue_RightDoor);
	//InteractBox_RightDoor->SetupAttachment(Statue_RightDoor);
	//PointLight_RightDoor->SetupAttachment(PointLight_RightDoor);

	//// SATELLITE STATUE 1
	//AuraFX_Satellite1->SetupAttachment(Statue_Satellite1);
	//FlareFX_Satellite1->SetupAttachment(Statue_Satellite1);
	//FlareAudio_Satellite1->SetupAttachment(Statue_Satellite1);
	//InteractBox_Satellite1->SetupAttachment(Statue_Satellite1);
	//PointLight_Satellite1->SetupAttachment(PointLight_Satellite1);

	//// SATELLITE STATUE 2
	//AuraFX_Satellite2->SetupAttachment(Statue_Satellite2);
	//FlareFX_Satellite2->SetupAttachment(Statue_Satellite2);
	//FlareAudio_Satellite2->SetupAttachment(Statue_Satellite2);
	//InteractBox_Satellite2->SetupAttachment(Statue_Satellite2);
	//PointLight_Satellite2->SetupAttachment(PointLight_Satellite2);

	//Doors->SetupAttachment(DoorsArch);
	//DoorOpenAudio->SetupAttachment(DoorsArch);

	IsUsable = true;
	InteractAnimType = EInteractAnims::IA_Open;
	DoInteract.AddDynamic(this, &ABoreal_Door::Interact);

	Color_Active = FLinearColor(1, 0.11f, 0, 1); // orange/red
	Color_Inactive = FLinearColor(0, 0.21f, 1, 1);  // blue
	Solved = false;
}

// Called when the game starts or when spawned
void ABoreal_Door::BeginPlay()
{
	Super::BeginPlay();
}

// Interact with this NPC
void ABoreal_Door::Interact()
{
	StartInteractAnim(); // do interact animation

	switch (CurrentStatue) // switch on CurrentStatue
	{
	case ECurrentStatue::CS_None: // if None, do nothing
		break;
	case ECurrentStatue::CS_LeftDoor: // LEFT DOOR
		if (Active_LeftDoor) // if Left Door is active
		{
			if (!IsCarryingDrop) // if player is not carrying a drop
			{
				Active_LeftDoor = false; // left door inactive
				FlareAudio_LeftDoor->Play(); // play flare audio
				FlareFX_LeftDoor->Activate(); // activate flare fx
				AuraFX_LeftDoor->Deactivate(); // deactivate aura
				// TO DO : Spawn Door Drop, attach it to player
				// TO DO : Run timeline that lerps color of light at this door from ACTIVE to INACTIVE, reset interaction for statues when finished
			}
			else
			{
				// InteractingPlayer->AudioManager->SFXError->Play(); // ERROR - the statue cannot be used because status is active and player is carrying a drop
			}
		}
		else // if the Left Door statue is inactive
		{
			if (IsCarryingDrop) // if player is carring a statue drop
			{
				Active_LeftDoor = true; // activate this statue
				FlareAudio_LeftDoor->Play();  // play flare audio
				FlareFX_LeftDoor->Activate();  // activate flare fx
				AuraFX_LeftDoor->Activate();  // activate aura fx
				// TO DO : Remove door drop
				// TO DO : Run timeline that lerps color of light at this door from INACTIVE to ACTIVE, reset interaction for statues when finished.
				// TO DO : Check for puzzle success
			}
			else
			{
				// InteractingPlayer->AudioManager->SFXError->Play(); // ERROR statue cannot be used because player is not carrying drop to activate the statue with
			}
		}
		break;
	case ECurrentStatue::CS_RightDoor:
		if (Active_RightDoor) // if statue is active
		{
			if (!IsCarryingDrop) // if player is not carrying a drop
			{
				Active_RightDoor = false; // left door inactive
				FlareAudio_RightDoor->Play(); // play flare audio
				FlareFX_RightDoor->Activate(); // activate flare fx
				AuraFX_RightDoor->Deactivate(); // deactivate aura
				// TO DO : Spawn Door Drop, attach it to player
				// TO DO : Run timeline that lerps color of light at this door from ACTIVE to INACTIVE, reset interaction for statues when finished
			}
			else
			{
				// InteractingPlayer->AudioManager->SFXError->Play(); // ERROR - the statue cannot be used because status is active and player is carrying a drop
			}
		}
		else // if the Left Door statue is inactive
		{
			if (IsCarryingDrop) // if player is carring a statue drop
			{
				Active_RightDoor = true; // activate this statue
				FlareAudio_RightDoor->Play();  // play flare audio
				FlareFX_RightDoor->Activate();  // activate flare fx
				AuraFX_RightDoor->Activate();  // activate aura fx
				// TO DO : Remove door drop
				// TO DO : Run timeline that lerps color of light at this door from INACTIVE to ACTIVE, reset interaction for statues when finished.
				// TO DO : Check for puzzle success
			}
			else
			{
				// InteractingPlayer->AudioManager->SFXError->Play(); // ERROR statue cannot be used because player is not carrying drop to activate the statue with
			}
		}
		break;
	case ECurrentStatue::CS_Satellite1:
		if (Active_Satellite1) // if statue is active
		{
			if (!IsCarryingDrop) // if player is not carrying a drop
			{
				Active_Satellite1 = false; // left door inactive
				FlareAudio_Satellite1->Play(); // play flare audio
				FlareFX_Satellite1->Activate(); // activate flare fx
				AuraFX_Satellite1->Deactivate(); // deactivate aura
				// TO DO : Spawn Door Drop, attach it to player
				// TO DO : Run timeline that lerps color of light at this door from ACTIVE to INACTIVE, reset interaction for statues when finished
			}
			else
			{
				// InteractingPlayer->AudioManager->SFXError->Play(); // ERROR - the statue cannot be used because status is active and player is carrying a drop
			}
		}
		else // if the Left Door statue is inactive
		{
			if (IsCarryingDrop) // if player is carring a statue drop
			{
				Active_Satellite1 = true; // activate this statue
				FlareAudio_Satellite1->Play();  // play flare audio
				FlareFX_Satellite1->Activate();  // activate flare fx
				AuraFX_Satellite1->Activate();  // activate aura fx
				// TO DO : Remove door drop
				// TO DO : Run timeline that lerps color of light at this door from INACTIVE to ACTIVE, reset interaction for statues when finished.
				// TO DO : Check for puzzle success
			}
			else
			{
				// InteractingPlayer->AudioManager->SFXError->Play(); // ERROR statue cannot be used because player is not carrying drop to activate the statue with
			}
		}
		break;
	case ECurrentStatue::CS_Satellite2:
		if (Active_Satellite2) // if statue is active
		{
			if (!IsCarryingDrop) // if player is not carrying a drop
			{
				Active_Satellite2 = false; // left door inactive
				FlareAudio_Satellite2->Play(); // play flare audio
				FlareFX_Satellite2->Activate(); // activate flare fx
				AuraFX_Satellite2->Deactivate(); // deactivate aura
				// TO DO : Spawn Door Drop, attach it to player
				// TO DO : Run timeline that lerps color of light at this door from ACTIVE to INACTIVE, reset interaction for statues when finished
			}
			else
			{
				// InteractingPlayer->AudioManager->SFXError->Play(); // ERROR - the statue cannot be used because status is active and player is carrying a drop
			}
		}
		else // if the Left Door statue is inactive
		{
			if (IsCarryingDrop) // if player is carring a statue drop
			{
				Active_Satellite2 = true; // activate this statue
				FlareAudio_Satellite2->Play();  // play flare audio
				FlareFX_Satellite2->Activate();  // activate flare fx
				AuraFX_Satellite2->Activate();  // activate aura fx
				// TO DO : Remove door drop
				// TO DO : Run timeline that lerps color of light at this door from INACTIVE to ACTIVE, reset interaction for statues when finished.
				// TO DO : Check for puzzle success
			}
			else
			{
				// InteractingPlayer->AudioManager->SFXError->Play(); // ERROR statue cannot be used because player is not carrying drop to activate the statue with
			}
		}
		break;
	}
}

// Checks if this puzzle has been solved
void ABoreal_Door::CheckForSuccess()
{
	if (Active_LeftDoor && Active_RightDoor)
	{
		DoorOpenAudio->Play();
		// TO DO : Play door open animation.
		Solved = true;
	}
}