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

#include "EnemyNames.generated.h"

UENUM(BlueprintType)
enum class EEnemyNames : uint8
{
	EN_None UMETA(DisplayName = "NONE"),

	// Shiitake Temple
	EN_SoulEater UMETA(DisplayName = "Soul Eater"),
	EN_DemonStatue UMETA(DisplayName = "Demon Statue"),
	EN_Watcher UMETA(DisplayName = "Watcher"),
	EN_DeathCap UMETA(DisplayName = "Death Cap"),

	// Vulcan Shrine
	EN_Gruntling UMETA(DisplayName = "Gruntling"),
	EN_Goblin UMETA(DisplayName = "Goblin"),
	EN_DragonWorm UMETA(DisplayName = "Dragon Worm"),
	EN_RedDragon UMETA(DisplayName = "Red Dragon"),

	// Boreal Core
	EN_Spider UMETA(DisplayName = "Spider"),
	EN_GiantSpider UMETA(DisplayName = "Giant Spider"),
	EN_FrostGiant UMETA(DisplayName = "Frost Giant"),
	EN_FrostCaptain UMETA(DisplayName = "Frost Captain"),

	// Yggdrasil
	EN_Flytrap UMETA(DisplayName = "Flytrap"),
	EN_Mugbear UMETA(DisplayName = "Mugbear"),
	EN_EarthTroll UMETA(DisplayName = "Earth Troll"),
	EN_GaiaTortoise UMETA(DisplayName = "Gaia Tortoise"),

	// Empyrean Gardens
	EN_Golem UMETA(DisplayName = "Golem"),
	EN_PowerDrone UMETA(DisplayName = "Power Drone"),
	EN_RoboGolem UMETA(DisplayName = "Robo-Golem"),
	EN_Samaritan UMETA(DisplayName = "Samaritan"),

	// Celestial Nexus
	EN_Spacetrooper UMETA(DisplayName = "Spacetrooper"),
	EN_Nightshade UMETA(DisplayName = "Nightshade"),
	EN_Eternal UMETA(DisplayName = "The Eternal"),
	EN_Zhan UMETA(DisplayName = "Zhan"),
};
