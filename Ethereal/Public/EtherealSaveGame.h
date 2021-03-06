// © 2014 - 2016 Soverance Studios
// www.soverance.com

// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at

// http ://www.apache.org/licenses/LICENSE-2.0

// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#pragma once

#include "GameFramework/SaveGame.h"
#include "MasterGearList.h"
#include "EtherealSaveGame.generated.h"

/**
 * 
 */
UCLASS()
class ETHEREAL_API UEtherealSaveGame : public USaveGame
{
	GENERATED_BODY()
	
public:

	UEtherealSaveGame();

	// Save Slot Name
	UPROPERTY(VisibleAnywhere, Category = Basic)
	FString SaveSlotName;

	// MAGIC Tier 1 Slot 1
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Bindings)
	EMasterGearList Save_Magic_Slot1;

	// MAGIC Tier 1 Slot 2
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Bindings)
	EMasterGearList Save_Magic_Slot2;

	// MAGIC Tier 1 Slot 3
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Bindings)
	EMasterGearList Save_Magic_Slot3;

	// MAGIC Tier 2 Slot 1
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Bindings)
	EMasterGearList Save_Magic_Slot4;

	// MAGIC Tier 2 Slot 2
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Bindings)
	EMasterGearList Save_Magic_Slot5;

	// MAGIC Tier 2 Slot 3
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Bindings)
	EMasterGearList Save_Magic_Slot6;

	// Weapon Main
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Bindings)
	EMasterGearList Save_Weapon_Main;

	// Weapon Sub
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Bindings)
	EMasterGearList Save_Weapon_Sub;
	
	// Current Item
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Bindings)
	EMasterGearList Save_Item_Current;

	// Player Level
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stats)
	int Save_PlayerLevel;

	// Current Gold
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stats)
	int Save_CurrentGold;

	// Player Level
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stats)
	int Save_CurrentEXP;

	// Inventory Array
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Inventory)
	TArray<EMasterGearList> Save_Inventory;
	
};
