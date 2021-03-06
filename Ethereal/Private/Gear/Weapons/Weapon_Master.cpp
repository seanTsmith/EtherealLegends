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
#include "Weapon_Master.h"

AWeapon_Master::AWeapon_Master(const FObjectInitializer& ObjectInitializer)
{
	// Asset, Reference Obtained Via Right Click in Editor
	static ConstructorHelpers::FObjectFinder<USkeletalMesh> SkeletalMeshObject(TEXT("SkeletalMesh'/Game/VFX/sphere_skeletal.sphere_skeletal'"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh> StaticMeshObject(TEXT("StaticMesh'/Game/VFX/sphere.sphere'"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh> OffhandMeshObject(TEXT("StaticMesh'/Game/VFX/sphere.sphere'"));

	// Set Default Objects
	SK_WeaponSkeletalMesh = SkeletalMeshObject.Object;
	SM_WeaponStaticMesh = StaticMeshObject.Object;
	SM_WeaponOffhandMesh = StaticMeshObject.Object;

	// Create
	WeaponSkeletalMesh = NewObject<USkeletalMeshComponent>(this, TEXT("Weapon Skeletal Mesh"));
	WeaponStaticMesh = NewObject<UStaticMeshComponent>(this, TEXT("Weapon Static Mesh"));
	WeaponOffhandMesh = NewObject<UStaticMeshComponent>(this, TEXT("Weapon Offhand Mesh"));

	// Set Mesh
	WeaponSkeletalMesh->SetSkeletalMesh(SK_WeaponSkeletalMesh);
	WeaponStaticMesh->SetStaticMesh(SM_WeaponStaticMesh);
	WeaponOffhandMesh->SetStaticMesh(SM_WeaponOffhandMesh);

	// Configure Mesh
	SetupSKComponentsWithCollision(WeaponSkeletalMesh);
	SetupSMComponentsWithCollision(WeaponStaticMesh);
	SetupSMComponentsWithCollision(WeaponOffhandMesh);
}

// Called when the game starts or when spawned
void AWeapon_Master::BeginPlay()
{
	Super::BeginPlay();

	// Attachment
	//WeaponSkeletalMesh->AttachToComponent(GetRootComponent(), FAttachmentTransformRules::SnapToTargetIncludingScale);
	//WeaponStaticMesh->AttachToComponent(GetRootComponent(), FAttachmentTransformRules::SnapToTargetIncludingScale);
	//WeaponOffhandMesh->AttachToComponent(GetRootComponent(), FAttachmentTransformRules::SnapToTargetIncludingScale);
}


// SetVisible
void AWeapon_Master::SetVisible()
{
	if (IsVisible == true)
	{
		switch (Type)
		{
			case EMasterGearTypes::GT_None:
				break;
			case EMasterGearTypes::GT_OneHanded:
				WeaponSkeletalMesh->SetVisibility(true);
				WeaponStaticMesh->SetVisibility(true);
				WeaponOffhandMesh->SetVisibility(false);
				break;
			case EMasterGearTypes::GT_TwoHanded:
				WeaponSkeletalMesh->SetVisibility(true);
				WeaponStaticMesh->SetVisibility(true);
				WeaponOffhandMesh->SetVisibility(false);
				break;
			case EMasterGearTypes::GT_Ranged:
				WeaponSkeletalMesh->SetVisibility(true);
				WeaponStaticMesh->SetVisibility(true);
				WeaponOffhandMesh->SetVisibility(false);
				break;
			case EMasterGearTypes::GT_Casting:
				WeaponSkeletalMesh->SetVisibility(false);
				WeaponStaticMesh->SetVisibility(true);
				WeaponOffhandMesh->SetVisibility(true);
				break;
			case EMasterGearTypes::GT_White:
				break;
			case EMasterGearTypes::GT_Black:
				break;
			case EMasterGearTypes::GT_Support:
				break;
			case EMasterGearTypes::GT_Ancient:
				break;
			case EMasterGearTypes::GT_Shield:
				WeaponSkeletalMesh->SetVisibility(true);
				WeaponStaticMesh->SetVisibility(true);
				break;
			case EMasterGearTypes::GT_Ammo:
				break;
			case EMasterGearTypes::GT_Head:
				break;
			case EMasterGearTypes::GT_Cape:
				break;
			case EMasterGearTypes::GT_Body:
				break;
			case EMasterGearTypes::GT_Hands:
				break;
			case EMasterGearTypes::GT_Legs:
				break;
			case EMasterGearTypes::GT_Feet:
				break;
			case EMasterGearTypes::GT_Consumable:
				break;
			case EMasterGearTypes::GT_KeyItem:
				break;
			default:
				break;
		}
	}	
}

void AWeapon_Master::OnHit(UObject* CharacterMaster)
{
	if (IsVisible)
	{

	}
}







