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

#include "GameFramework/Character.h"
#include "EtherealCharacterMaster.generated.h"

UCLASS()
class ETHEREAL_API AEtherealCharacterMaster : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AEtherealCharacterMaster(const FObjectInitializer& ObjectInitializer);

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	// Whether or not this character is dead
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Controls)
	bool IsDead;

	// Whether or not this character is targetable
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Targeting)
	bool Targetable;

	// Default Capsule Component
	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Default)
	//UCapsuleComponent* Capsule;

	// Targeting Notification Audio
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Targeting)
	UAudioComponent* TargetingAudio;
	USoundCue* S_TargetingAudio;

	// Targeting Reticle Mesh.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Targeting)
	UStaticMeshComponent* TargetingReticle;
	UStaticMesh* SM_TargetingReticle;

	/** Sets Mesh visibility based on Weapon Type. */
	UFUNCTION(BlueprintCallable, Category = Targeting)
	void ToggleReticle(bool Visible);

	FORCEINLINE void SetupSMComponentsWithCollision(UStaticMeshComponent* Comp)
	{
		if (!Comp) return;

		Comp->bOwnerNoSee = false;
		Comp->bCastDynamicShadow = true;
		Comp->CastShadow = true;
		Comp->BodyInstance.SetObjectType(ECC_WorldDynamic);
		Comp->BodyInstance.SetCollisionEnabled(ECollisionEnabled::NoCollision);
		Comp->BodyInstance.SetResponseToAllChannels(ECR_Ignore);
		Comp->SetHiddenInGame(false);
	}
	
};
