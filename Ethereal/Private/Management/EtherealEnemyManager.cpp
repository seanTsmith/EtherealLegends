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
#include "EtherealEnemyManager.h"


// Sets default values
AEtherealEnemyManager::AEtherealEnemyManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

// Called when the game starts or when spawned
void AEtherealEnemyManager::BeginPlay()
{
	Super::BeginPlay();
	
	// Commented out because this must change, now that we're using a different level streaming configuration
	//FTimerHandle InitSpawn;
	//GetWorldTimerManager().SetTimer(InitSpawn, this, &AEtherealEnemyMaster::SpawnAllNodes, 0.5f, false);
}

void AEtherealEnemyManager::SpawnAllNodes()
{
	// iterate through the world for all Enemy Nodes
	for (TActorIterator<AEnemyNode> ActorItr(GetWorld()); ActorItr; ++ActorItr)
	{
		AEnemyNode* Node = *ActorItr; // get the instance of the node

		SpawnNode(Node); // Spawn the enemy related to this node instance
	}
}

void AEtherealEnemyManager::SpawnNode(AEnemyNode* Node)
{
	FTransform transform = Node->GetActorTransform();
	int level = Node->EnemyLevel;

	// TO DO : Spawn AI from class based on name, set it's level based on Node, and then call SetDefaultStats() on the enemy
	switch (Node->EnemyName)
	{
		case EEnemyNames::EN_None:
			
			break;

		// SHIITAKE TEMPLE

		case EEnemyNames::EN_SoulEater:
			
			break;
		case EEnemyNames::EN_DemonStatue:

			break;
		case EEnemyNames::EN_Watcher:

			break;
		case EEnemyNames::EN_DeathCap:

			break;

		// VULCAN SHRINE

		case EEnemyNames::EN_Gruntling:

			break;
		case EEnemyNames::EN_Goblin:

			break;
		case EEnemyNames::EN_DragonWorm:

			break;
		case EEnemyNames::EN_RedDragon:

			break;

		// BOREAL CORE

		case EEnemyNames::EN_Spider:

			break;
		case EEnemyNames::EN_GiantSpider:

			break;
		case EEnemyNames::EN_FrostGiant:

			break;
		case EEnemyNames::EN_FrostCaptain:

			break;

		// YGGDRASIL

		case EEnemyNames::EN_Flytrap:

			break;
		case EEnemyNames::EN_Mugbear:

			break;
		case EEnemyNames::EN_EarthTroll:

			break;
		case EEnemyNames::EN_GaiaTortoise:

			break;

		// EMPYREAN GARDENS

		case EEnemyNames::EN_Golem:

			break;
		case EEnemyNames::EN_PowerDrone:

			break;
		case EEnemyNames::EN_RoboGolem:

			break;
		case EEnemyNames::EN_Samaritan:

			break;

		// CELESTIAL NEXUS

		case EEnemyNames::EN_Spacetrooper:

			break;
		case EEnemyNames::EN_Nightshade:

			break;
		case EEnemyNames::EN_Eternal:

			break;
		case EEnemyNames::EN_Zhan:

			break;
	}
}
