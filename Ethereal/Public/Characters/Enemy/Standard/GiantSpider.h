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

#include "Characters/Enemy/EtherealEnemyMaster.h"
#include "GiantSpider.generated.h"

UCLASS()
class ETHEREAL_API AGiantSpider : public AEtherealEnemyMaster
{
	GENERATED_BODY()

public:
	
	// Sets default values for this actor's properties
	AGiantSpider(const FObjectInitializer& ObjectInitializer);

	// BeginPlay Override
	virtual void BeginPlay() override;

	// Spider Vomit FX
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Effects)
	UParticleSystemComponent* SpiderVomit;
	UParticleSystem* P_SpiderVomit;

	// Death Audio
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Effects)
	UAudioComponent* DeathAudio;
	USoundCue* S_DeathAudio;

	// Do an attack animation
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Controls)
	bool DoSpit;

	// Do the drop from ceiling animation
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Controls)
	bool DoDrop;

	// Death
	UFUNCTION(BlueprintCallable, Category = Default)
	void Death();

	// Run to Target
	UFUNCTION(BlueprintCallable, Category = Default)
	void RunToTarget();	
};
