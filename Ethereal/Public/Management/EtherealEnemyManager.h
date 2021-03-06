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

#include "GameFramework/Actor.h"
#include "Management/EnemyNode.h"
#include "EtherealEnemyManager.generated.h"

UCLASS()
class ETHEREAL_API AEtherealEnemyManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEtherealEnemyManager();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Enemy Node Array
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Default)
	TArray<AEnemyNode*> EnemyNodes;

	// Searches the world for EnemyNode instances, and spawns the enemies associated with them.
	UFUNCTION(BlueprintCallable, Category = Default)
	void SpawnAllNodes();	

	// Spawns the enemy at a specific node.
	UFUNCTION(BlueprintCallable, Category = Default)
	void SpawnNode(AEnemyNode* Node);
};
