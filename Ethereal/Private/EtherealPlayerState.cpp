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
#include "EtherealPlayerState.h"


AEtherealPlayerState::AEtherealPlayerState(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	// Set Default Stats
	PlayerLevel = 5;
	HP_Current = 0;
	HP_Max = 0;
	MP_Current = 0;
	MP_Max = 0;
	TP_Current = 0;
	TP_Max = 0;
	ATK = 0;
	DEF = 0;
	SPD = 0;
	RefreshRate = 0;
	RegenRate = 0;
	Gold_Current = 0;

	Binding_Magic_Slot1 = EMasterGearList::GL_None;
	Binding_Magic_Slot2 = EMasterGearList::GL_None;
	Binding_Magic_Slot3 = EMasterGearList::GL_None;
	Binding_Magic_Slot4 = EMasterGearList::GL_None;
	Binding_Magic_Slot5 = EMasterGearList::GL_None;
	Binding_Magic_Slot6 = EMasterGearList::GL_None;

	Binding_Weapon_Main = EMasterGearList::GL_None;
	Binding_Weapon_Sub = EMasterGearList::GL_None;

	Binding_Item_Current = EMasterGearList::GL_None;
}

// Called when the game starts or when spawned
void AEtherealPlayerState::BeginPlay()
{
	Super::BeginPlay();

}

// SET BASE STATS
void AEtherealPlayerState::SetBaseStats()
{
	int BaseHP = PlayerLevel * 200;
	int BaseMP = PlayerLevel * 20;
	float BaseStats = PlayerLevel * 5.1f;

	HP_Current = BaseHP;
	HP_Max = BaseHP;
	MP_Current = BaseMP;
	MP_Max = BaseMP;
	ATK = BaseStats;
	DEF = BaseStats;
	SPD = BaseStats;
}

// Completely Refill HP & MP 
void AEtherealPlayerState::RestoreAll()
{
	HP_Current = HP_Max;
	MP_Current = MP_Max;
}

// Force HP Caps
bool AEtherealPlayerState::ForceHPCaps()
{
	bool Kill = false;

	// If HP is greater than Max, set HP to Max
	if (HP_Current > HP_Max)
	{
		HP_Current = HP_Max;
	}
	// If HP is less than Zero, set HP to Zero
	if (HP_Current < 0)
	{
		HP_Current = 0;
		Kill = true;
	}

	return Kill;
}

// Force MP Caps
void AEtherealPlayerState::ForceMPCaps()
{
	// If MP is greater than Max, set MP to Max
	if (MP_Current > MP_Max)
	{
		MP_Current = MP_Max;
	}
	// if MP is less than Zero, set MP to Zero
	if (MP_Current < 0)
	{
		MP_Current = 0;
	}
}

// SET TNL
void AEtherealPlayerState::SetTNL()
{
	switch (PlayerLevel)
	{
		case 1:
			EXP_ToNextLevel = 1250;
			break;
		case 2:
			EXP_ToNextLevel = 2250;
			break;
		case 3:
			EXP_ToNextLevel = 3500;
			break;
		case 4:
			EXP_ToNextLevel = 5000;
			break;
		case 5:
			EXP_ToNextLevel = 6750;
			break;
		case 6:
			EXP_ToNextLevel = 8750;
			break;
		case 7:
			EXP_ToNextLevel = 10950;
			break;
		case 8:
			EXP_ToNextLevel = 13350;
			break;
		case 9:
			EXP_ToNextLevel = 15950;
			break;
		case 10:
			EXP_ToNextLevel = 13350;
			break;
		case 11:
			EXP_ToNextLevel = 15950;
			break;
		case 12:
			EXP_ToNextLevel = 18750;
			break;
		case 13:
			EXP_ToNextLevel = 21750;
			break;
		case 14:
			EXP_ToNextLevel = 24950;
			break;
		case 15:
			EXP_ToNextLevel = 28350;
			break;
		case 16:
			EXP_ToNextLevel = 31950;
			break;
		case 17:
			EXP_ToNextLevel = 35750;
			break;
		case 18:
			EXP_ToNextLevel = 39750;
			break;
		case 19:
			EXP_ToNextLevel = 43950;
			break;
		case 20:
			EXP_ToNextLevel = 48350;
			break;
		case 21:
			EXP_ToNextLevel = 52950;
			break;
		case 22:
			EXP_ToNextLevel = 57750;
			break;
		case 23:
			EXP_ToNextLevel = 62750;
			break;
		case 24:
			EXP_ToNextLevel = 67850;
			break;
		case 25:
			EXP_ToNextLevel = 73050;
			break;
		case 26:
			EXP_ToNextLevel = 78350;
			break;
		case 27:
			EXP_ToNextLevel = 83750;
			break;
		case 28:
			EXP_ToNextLevel = 89250;
			break;
		case 29:
			EXP_ToNextLevel = 94850;
			break;
		case 30:
			EXP_ToNextLevel = 100550;
			break;
		case 31:
			EXP_ToNextLevel = 106350;
			break;
		case 32:
			EXP_ToNextLevel = 112250;
			break;
		case 33:
			EXP_ToNextLevel = 118250;
			break;
		case 34:
			EXP_ToNextLevel = 124350;
			break;
		case 35:
			EXP_ToNextLevel = 130550;
			break;
		case 36:
			EXP_ToNextLevel = 136850;
			break;
		case 37:
			EXP_ToNextLevel = 143250;
			break;
		case 38:
			EXP_ToNextLevel = 149750;
			break;
		case 39:
			EXP_ToNextLevel = 156350;
			break;
		case 40:
			EXP_ToNextLevel = 163050;
			break;
		case 41:
			EXP_ToNextLevel = 169850;
			break;
		case 42:
			EXP_ToNextLevel = 176750;
			break;
		case 43:
			EXP_ToNextLevel = 183750;
			break;
		case 44:
			EXP_ToNextLevel = 190850;
			break;
		case 45:
			EXP_ToNextLevel = 198050;
			break;
		case 46:
			EXP_ToNextLevel = 205350;
			break;
		case 47:
			EXP_ToNextLevel = 212750;
			break;
		case 48:
			EXP_ToNextLevel = 220250;
			break;
		case 49:
			EXP_ToNextLevel = 227850;
			break;
		case 50:
			EXP_ToNextLevel = 235550;
			break;
	}
}

// Level Up
void AEtherealPlayerState::LevelUp()
{
	if (EXP_Current >= EXP_ToNextLevel)
	{
		PlayerLevel = PlayerLevel + 1;
		RestoreAll();
	}
}

// Regen Tick
void AEtherealPlayerState::Regen()
{
	HP_Current = HP_Current + RegenRate;
	ForceHPCaps();
}

// Refresh Tick
void AEtherealPlayerState::Refresh()
{
	MP_Current = MP_Current + RefreshRate;
	ForceMPCaps();
}

// Get Inventory Item
AEtherealGearMaster* AEtherealPlayerState::GetInventoryItem(EMasterGearList ItemToGet)
{
	AEtherealGearMaster* Item = nullptr;

	for (AEtherealGearMaster* GearItem : Inventory)
	{
		if (GearItem->Name == ItemToGet)
		{
			Item = GearItem;
		}
		else
		{
			Item = nullptr;
		}
	}

	return Item;
}

// Add Inventory Item
void AEtherealPlayerState::AddInventoryItem(EMasterGearList ItemToAdd)
{
	/*switch (ItemToAdd)
	{
		case EMasterGearList::GL_Adrenaline:
			AEtherealGearMaster* NewItem = GetWorld()->SpawnActor<AEtherealGearMaster>(AAdrenaline);
			break;
		default:
			break;
	}*/
		
}

// ADD GEAR STATS
void AEtherealPlayerState::AddGearStats(EMasterGearList WeaponName)
{
	// Get the inventory item
	AEtherealGearMaster* Gear = GetInventoryItem(WeaponName);

	// Add stats from gear to the player's stats
	ATK = (ATK + Gear->ATK);
	DEF = (DEF + Gear->DEF);
	SPD = (SPD + Gear->SPD);
	HP_Max = (HP_Max + Gear->HP);
	MP_Max = (MP_Max + Gear->MP);

	//AEtherealGearMaster* Weapon = dynamic_cast<AWeapon_Master*>(Gear);
}

// REMOVE GEAR STATS
void AEtherealPlayerState::RemoveGearStats(EMasterGearList WeaponName)
{
	// Get the inventory item
	AEtherealGearMaster* Gear = GetInventoryItem(WeaponName);

	// Add stats from gear to the player's stats
	ATK = (ATK - Gear->ATK);
	DEF = (DEF - Gear->DEF);
	SPD = (SPD - Gear->SPD);
	HP_Max = (HP_Max - Gear->HP);
	MP_Max = (MP_Max - Gear->MP);

}