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

#pragma once

#include "Characters/EtherealCharacterMaster.h"
#include "Characters/Player/WeaponModes.h"
#include "Gear/Magic/Magic_AnimTypes.h"
#include "EtherealPlayerState.h"
#include "EtherealPlayerMaster.generated.h"

// Forward Declarations
class AEtherealEnemyMaster;

UCLASS()
class ETHEREAL_API AEtherealPlayerMaster : public AEtherealCharacterMaster
{
	GENERATED_BODY()

public:
	
	AEtherealPlayerMaster(const FObjectInitializer& ObjectInitializer);

	// BeginPlay Override
	virtual void BeginPlay() override;

	/** The current Weapon Mode, used for determining animations for the currently bound weapon. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Defaults)
	EWeaponModes WeaponMode;

	/** The Magic Anim Type to play when casting a spell. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Defaults)
	EMagic_AnimTypes ActiveSpellAnimType;

	/** A reference to the Ethereal Player State. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Defaults)
	AEtherealPlayerState* EtherealPlayerState;

	// Enemy Aggro List. Enemies are added to this list as they are aggroed, and removed accordingly.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Default)
	TArray<AEtherealEnemyMaster*> AggroList;
};
