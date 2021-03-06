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
#include "Zhan.generated.h"

UCLASS()
class ETHEREAL_API AZhan : public AEtherealEnemyMaster
{
	GENERATED_BODY()
	
public:

	// Sets default values for this actor's properties
	AZhan(const FObjectInitializer& ObjectInitializer);

	// BeginPlay Override
	virtual void BeginPlay() override;

	// Power Blast collider
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Default)
	UBoxComponent* PowerBlastBox;

	// Spin Atk collider
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Default)
	UBoxComponent* SpinAtkBox;
	
	// Blade Weapon
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Effects)
	USkeletalMeshComponent* Blade;
	USkeletalMesh* SK_Blade;

	// Hit Audio
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Effects)
	UAudioComponent* PowerBlastAudio;
	USoundCue* S_PowerBlastAudio;

	// Swipe Audio
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Effects)
	UAudioComponent* SpinAtkAudio;
	USoundCue* S_SpinAtkAudio;

	// Vomit FX
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Effects)
	UParticleSystemComponent* EyeFX;
	UParticleSystem* P_EyeFX;

	// Vomit FX
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Effects)
	UParticleSystemComponent* BuildUpFX;
	UParticleSystem* P_BuildUpFX;

	// Vomit FX
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Effects)
	UParticleSystemComponent* PowerBlastFX;
	UParticleSystem* P_PowerBlastFX;

	// Vomit FX
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Effects)
	UParticleSystemComponent* SpinAtkFX;
	UParticleSystem* P_SpinAtkFX;

	// Do Sling anim
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Controls)
	bool DoFallAggro;

	// Do Power Blast anim
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Controls)
	bool DoPowerBlast;

	// Do Spin Atk anim
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Controls)
	bool DoSpinAtk;

	// Do Radial Blast anim
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Controls)
	bool DoRadialBlast;

	// Starting Height Offset
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Controls)
	float StartHeightOffset;

	// Death
	UFUNCTION(BlueprintCallable, Category = Default)
	void Death();

	// Run to Target
	UFUNCTION(BlueprintCallable, Category = Default)
	void RunToTarget();

	// Init Aggro - Called by a Realm Boss when it dies
	UFUNCTION(BlueprintCallable, Category = Default)
	void InitAggro();

	// Fall To Aggro - handles effects of Zhan enemy pops
	UFUNCTION(BlueprintCallable, Category = Default)
	void FallToAggro();

	// Power Blast Attack
	UFUNCTION(BlueprintCallable, Category = Default)
	void PowerBlast();

	// Blade Spin Attack
	UFUNCTION(BlueprintCallable, Category = Default)
	void SpinAttack();

	// Radial Blast Attack
	UFUNCTION(BlueprintCallable, Category = Default)
	void RadialBlast();

	// Zhan Escape Realm - called on death
	UFUNCTION(BlueprintCallable, Category = Default)
	void Escape();
};
