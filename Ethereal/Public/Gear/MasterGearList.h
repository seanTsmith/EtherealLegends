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
#include "MasterGearList.generated.h"
/**
 * 
 */

 UENUM(BlueprintType)
 enum class EMasterGearList : uint8
 {
	// NONE
 	GL_None UMETA(DisplayName = "NONE"),
	// MAGIC
 	GL_Cure UMETA(DisplayName = "Cure"),
 	GL_Cure2 UMETA(DisplayName = "Cure II"),
 	GL_Raise UMETA(DisplayName = "Raise"),
 	GL_Regen UMETA(DisplayName = "Regen"),
 	GL_Refresh UMETA(DisplayName = "Refresh"),
 	GL_Esuna UMETA(DisplayName = "Esuna"),
 	GL_Comet UMETA(DisplayName = "Comet"),
 	GL_Blizzard UMETA(DisplayName = "Blizzard"),
 	GL_Thunder UMETA(DisplayName = "Thunder"),
 	GL_Fire UMETA(DisplayName = "Fire"),
 	GL_Poison UMETA(DisplayName = "Poison"),
 	GL_Sleep UMETA(DisplayName = "Sleep"),
 	GL_Berserk UMETA(DisplayName = "Berserk"),
 	GL_Barrier UMETA(DisplayName = "Barrier"),
 	GL_Haste UMETA(DisplayName = "Haste"),
 	GL_Slow UMETA(DisplayName = "Slow"),
 	GL_Counter UMETA(DisplayName = "Counter"),
 	GL_Stun UMETA(DisplayName = "Stun"),
 	GL_Dash UMETA(DisplayName = "Dash"),
 	GL_Gravity UMETA(DisplayName = "Gravity"),
	// WEAPONS
 	GL_IronSword UMETA(DisplayName = "Iron Sword"),
 	GL_Hauteclaire UMETA(DisplayName = "Hauteclaire"),
 	GL_SpartanShield UMETA(DisplayName = "Spartan Shield"),
 	GL_Annihilator UMETA(DisplayName = "Annihilator"),
 	GL_Excalibur UMETA(DisplayName = "Excalibur"),
 	GL_Joyeuse UMETA(DisplayName = "Joyeuse"),
 	GL_WarAspis UMETA(DisplayName = "War Aspis"),
 	GL_Marauder UMETA(DisplayName = "Marauder"),
 	GL_Temperance UMETA(DisplayName = "Temperance"),
 	GL_EurytosBow UMETA(DisplayName = "Eurytos' Bow"),
 	GL_Juggernaut UMETA(DisplayName = "Juggernaut"),
 	GL_ShortBow UMETA(DisplayName = "ShortBow"),
 	GL_EagleEye UMETA(DisplayName = "EagleEye"),
 	GL_MagicOrbs UMETA(DisplayName = "Magic Orbs"),
 	GL_Claymore UMETA(DisplayName = "Claymore"),
	// CONSUMABLE ITEMS
 	GL_Reraise UMETA(DisplayName = "Reraise"),
 	GL_Potion UMETA(DisplayName = "Potion"),
 	GL_HiPotion UMETA(DisplayName = "Hi-Potion"),
 	GL_Ether UMETA(DisplayName = "Ether"),
 	GL_HiEther UMETA(DisplayName = "Hi-Ether"),
 	GL_Adrenaline UMETA(DisplayName = "Adrenaline"),
 	GL_SentinelBrew UMETA(DisplayName = "Sentinel Brew"),
 	GL_Elixer UMETA(DisplayName = "Elixer"),
	// AMMUNITION
 	GL_DemonArrow UMETA(DisplayName = "Demon Arrow"),
 	GL_FlameArrow UMETA(DisplayName = "Flame Arrow"),
 	GL_IronArrow UMETA(DisplayName = "Iron Arrow"),
 	GL_WoodenArrow UMETA(DisplayName = "Wooden Arrow"),
 };
