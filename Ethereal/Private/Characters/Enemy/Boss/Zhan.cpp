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
#include "Zhan.h"

AZhan::AZhan(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	static ConstructorHelpers::FObjectFinder<USkeletalMesh> EnemyMesh(TEXT("SkeletalMesh'/Game/MixamoAnimPack/Mixamo_Ganfault/Mesh/Mixamo_Ganfault_Aure.Mixamo_Ganfault_Aure'"));
	static ConstructorHelpers::FObjectFinder<UAnimBlueprint> AnimBP(TEXT("AnimBlueprint'/Game/MixamoAnimPack/Mixamo_Ganfault/Anims/Zhan_Anim.Zhan_Anim'"));
	static ConstructorHelpers::FObjectFinder<USkeletalMesh> BladeMesh(TEXT("SkeletalMesh'/Game/InfinityBladeWeapons/Weapons/Blade/Swords/Blade_HeroSword10/SK_Blade_HeroSword10.SK_Blade_HeroSword10'"));
	static ConstructorHelpers::FObjectFinder<UParticleSystem> EyeParticleObject(TEXT("ParticleSystem'/Game/InfinityBladeEffects/Effects/FX_Monsters/FX_Monster_Chicken/Souleater_Statue_EyeIdle.Souleater_Statue_EyeIdle'"));
	static ConstructorHelpers::FObjectFinder<UParticleSystem> BuildUpParticleObject(TEXT("ParticleSystem'/Game/InfinityBladeEffects/Effects/FX_Monsters/FX_Monster_Elemental/Fire/P_Beam_Laser_Fire_BuildUP.P_Beam_Laser_Fire_BuildUP'"));
	static ConstructorHelpers::FObjectFinder<UParticleSystem> PowerBlastParticleObject(TEXT("ParticleSystem'/Game/InfinityBladeEffects/Effects/FX_Monsters/FX_Monster_Elemental/Fire/P_Beam_Laser_Fire.P_Beam_Laser_Fire'"));
	static ConstructorHelpers::FObjectFinder<UParticleSystem> SpinAtkParticleObject(TEXT("ParticleSystem'/Game/InfinityBladeEffects/Effects/FX_Skill_TeleCharge/Zhan_SpinAtkFX.Zhan_SpinAtkFX'"));
	static ConstructorHelpers::FObjectFinder<USoundCue> PowerBlastAudioObject(TEXT("SoundCue'/Game/Audio/Party/Zhan_PowerBlast_Cue.Zhan_PowerBlast_Cue'"));
	static ConstructorHelpers::FObjectFinder<USoundCue> SpinAtkAudioObject(TEXT("SoundCue'/Game/Audio/Party/Zhan_SpinAtk_Cue.Zhan_SpinAtk_Cue'"));

	// Set Default Objects
	GetMesh()->SkeletalMesh = EnemyMesh.Object;
	GetMesh()->SetAnimInstanceClass(AnimBP.Object->GetAnimBlueprintGeneratedClass());
	SK_Blade = BladeMesh.Object;
	P_EyeFX = EyeParticleObject.Object;
	P_BuildUpFX = BuildUpParticleObject.Object;
	P_PowerBlastFX = PowerBlastParticleObject.Object;
	P_SpinAtkFX = SpinAtkParticleObject.Object;
	S_PowerBlastAudio = PowerBlastAudioObject.Object;
	S_SpinAtkAudio = SpinAtkAudioObject.Object;


	// Create objects
	PowerBlastBox = NewObject<UBoxComponent>(this, TEXT("PowerBlastBox"));
	SpinAtkBox = NewObject<UBoxComponent>(this, TEXT("SpinAtkBox"));
	Blade = NewObject<USkeletalMeshComponent>(this, TEXT("Blade"));
	EyeFX = NewObject<UParticleSystemComponent>(this, TEXT("EyeFX"));
	BuildUpFX = NewObject<UParticleSystemComponent>(this, TEXT("BuildUpFX"));
	PowerBlastFX = NewObject<UParticleSystemComponent>(this, TEXT("PowerBlastFX"));
	SpinAtkFX = NewObject<UParticleSystemComponent>(this, TEXT("SpinAtkFX"));
	PowerBlastAudio = NewObject<UAudioComponent>(this, TEXT("SecondDropAudio"));
	SpinAtkAudio = NewObject<UAudioComponent>(this, TEXT("DeathAudio"));

	// Configure Components
	Blade->SkeletalMesh = SK_Blade;
	EyeFX->Template = P_EyeFX;
	BuildUpFX->Template = P_BuildUpFX;
	PowerBlastFX->Template = P_PowerBlastFX;
	SpinAtkFX->Template = P_SpinAtkFX;
	PowerBlastAudio->Sound = S_PowerBlastAudio;
	SpinAtkAudio->Sound = S_SpinAtkAudio;

	EyeFX->bAutoActivate = false;
	PowerBlastAudio->bAutoActivate = false;
	SpinAtkAudio->bAutoActivate = false;

	PowerBlastBox->SetRelativeLocation(FVector(600, 0, 0));
	PowerBlastBox->SetBoxExtent(FVector(600, 60, 60));

	SpinAtkBox->SetBoxExtent(FVector(300, 80, 80));

	StartHeightOffset = 200.0f;
	this->SetActorLocation(FVector(this->GetActorLocation().X, this->GetActorLocation().Y, (this->GetActorLocation().Z + StartHeightOffset)));  // places Zhan in the air, so he can burst out all awesome during his aggro sequence
	this->GetCharacterMovement()->GravityScale = 0; // turn off Gravity so he stays in the air
	this->GetCapsuleComponent()->SetVisibility(false, true); // hide root object and propagate to all children

	Name = EEnemyNames::EN_Zhan;
	Realm = ERealms::R_Celestial;
	BattleType = EBattleTypes::BT_Boss;

	// TO DO : Attach the Blade to the Mesh in the R_Weapon
	// TO DO : Attach the EyeFX to the Mesh in the EyeSocket
}

// Called when the game starts or when spawned
void AZhan::BeginPlay()
{
	Super::BeginPlay();

	//OnDeath.AddDynamic(this, &ADemonStatue::Death()); // bind the death fuction to the OnDeath event 

}

void AZhan::InitAggro()
{
	Aggro(Target);
	// TO DO :  Spawn Zhan's Aggro Drop at current location - StartHeightOffset on Z
	// DELAY 9.8 seconds
	// Call FirePortal() on Zhan's Aggro Drop
	FallToAggro();
	// DELAY 7 seconds
	AudioManager->Play_Zhan_Battle();
	this->GetCharacterMovement()->GravityScale = 1.0f;
	RunToTarget();
}

void AZhan::FallToAggro()
{
	this->GetCharacterMovement()->GravityScale = 0.1f;
	this->GetCapsuleComponent()->SetVisibility(true, true);
	DoFallAggro = true;

	// TO DO : Play World Camera Shake CS Zhan Spawn 100000 radius
	// TO DO : Client Play Force Feedback FF_ZhanSpawn

	// earlier code sets the reticle visible, be sure to turn it off.
	if (TargetingReticle->IsVisible())
	{
		TargetingReticle->SetVisibility(false);
	}
}

void AZhan::RunToTarget()
{
	if (!IsDead)
	{
		if (!Target->IsDead)
		{
			// AI move to, then random between 0 and 7, picking one of three functions: PowerBlast(), SpinAttack(), or RadialBlast().
		}
	}
}

void AZhan::Death()
{
	IsDead = true;
}

void AZhan::PowerBlast()
{
	DoPowerBlast = true;
	EnemyDealDamage(30);
	PowerBlastAudio->Play();
	// TO DO : Delay 0.5
	// Check power blast collider and have player take damage
	// wait attack delay, then RunToTarget()
}

void AZhan::SpinAttack()
{
	DoSpinAtk = true;
	EnemyDealDamage(25);
	SpinAtkAudio->Play();
	// TO DO : delay 0.5
	// Check SpinAtk collider and have the player take damage
	// wait attack delay and RunToTarget()
}

void AZhan::RadialBlast()
{
	DoRadialBlast = true;
	EnemyDealDamage(40);
	// TO DO : Spawn Zhan Radial Blast Drop
	// TO DO : DELAY 1.5
	// TO DO : Call FireRadialBlast() on the drop, passing Zhan's damage output
	// wait attack delay and call RunToTarget()
}

void AZhan::Escape()
{
	// Spawn the Escape Portal
	static ConstructorHelpers::FObjectFinder<UParticleSystem> EscapePortalObject(TEXT("ParticleSystem'/Game/InfinityBladeEffects/Effects/FX_Monsters/FX_Monster_Ausar/Zhan_EscapePortal.Zhan_EscapePortal'"));
	UParticleSystem* P_EscapePortal = EscapePortalObject.Object;
	UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), P_EscapePortal, this->GetActorLocation(), this->GetActorRotation(), true);  

	// Add the Escape Audio Components
	static ConstructorHelpers::FObjectFinder<USoundCue> PortalExplosionAudioObject(TEXT("SoundCue'/Game/Audio/Impacts/Zhan_PortalExplosion_Cue.Zhan_PortalExplosion_Cue'"));
	static ConstructorHelpers::FObjectFinder<USoundCue> ZhanEscapeAudioObject(TEXT("SoundCue'/Game/Audio/Impacts/Zhan_Escape_Cue.Zhan_Escape_Cue'"));
	USoundCue* S_PortalExplosion = PortalExplosionAudioObject.Object;
	USoundCue* S_ZhanEscape = ZhanEscapeAudioObject.Object;
	UGameplayStatics::PlaySound2D(GetWorld(), S_PortalExplosion);
	UGameplayStatics::PlaySound2D(GetWorld(), S_ZhanEscape);

	// TO DO :  4 second timeline, slowly rising Zhan into the air. Timeline simply adds 0.5 to his Z every update cycle.
	// TO DO :  when timeline is complete, AudioManager->FadeOut(), then spawn ParticleSystem'/Game/InfinityBladeEffects/Effects/FX_Combat_Base/WeaponCombo/P_Cube_Mesh_Test.P_Cube_Mesh_Test'
	this->GetCapsuleComponent()->SetVisibility(false, true); // hide root object and propagate to all children
	// DELAY 1.2 seconds
	// destroy cube mesh particle that was spawned earlier
	// AudioManager->PlayLevelUpFanfare()
	// TO DO : Spawn the Arcadia Return Portal wherever Zhan died
	// DELAY 5 seconds
	// AudioManager->PlayBGM()
}

