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
#include "Armor_Master.h"

AArmor_Master::AArmor_Master(const FObjectInitializer& ObjectInitializer)
{
	// Asset, Reference Obtained Via Right Click in Editor
	static ConstructorHelpers::FObjectFinder<USkeletalMesh> SkeletalMeshObject(TEXT("SkeletalMesh'/Game/VFX/sphere_skeletal.sphere_skeletal'"));

	// Creates a scene component and sets it as the root
	Root = NewObject<USceneComponent>(this, TEXT("Root"));
	RootComponent = Root;

	// Set Default Objects
	SK_HeadArmorSkeletalMesh = SkeletalMeshObject.Object;

	// Create
	HeadArmorSkeletalMesh = NewObject<USkeletalMeshComponent>(this, TEXT("Head Armor"));

	// Set Mesh
	HeadArmorSkeletalMesh->SetSkeletalMesh(SK_HeadArmorSkeletalMesh);

	// Configure Mesh
	SetupSKComponentsWithCollision(HeadArmorSkeletalMesh);
}

// Called when the game starts or when spawned
void AArmor_Master::BeginPlay()
{
	Super::BeginPlay();

	// Attachment
	//HeadArmorSkeletalMesh->AttachToComponent(GetRootComponent(), FAttachmentTransformRules::SnapToTargetIncludingScale);
}


