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
#include "Management/BattleTypes.h"
#include "Management/Realms.h"
#include "EtherealAudioManager.generated.h"

UCLASS()
class ETHEREAL_API AEtherealAudioManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEtherealAudioManager();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// The root component for this actor.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Default)
	USceneComponent* Root;

	// CurrentAudio, which is simply a container used for referencing the currently playing audio track. Used during transitions between tracks.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Default)
	UAudioComponent* CurrentAudio;

	// BATTLE MUSIC  ---------------------------------

	// Play the Battle Music, based on type selection.
	UFUNCTION(BlueprintCallable, Category = BattleMusic)
	void Play_BattleMusic(EBattleTypes Selection);
	
	// Standard Battle Music
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = BattleMusic)
	UAudioComponent* Battle_Standard;
	USoundCue* S_Battle_Standard;

	// Play Standard Battle Music
	UFUNCTION(BlueprintCallable, Category = BattleMusic)
	void Play_Battle_Standard();

	// Boss Battle Music
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = BattleMusic)
	UAudioComponent* Battle_Boss;
	USoundCue* S_Battle_Boss;

	// Play Boss Battle Music
	UFUNCTION(BlueprintCallable, Category = BattleMusic)
	void Play_Battle_Boss();

	// Zhan Intro Music
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = BattleMusic)
	UAudioComponent* Zhan_Intro;
	USoundCue* S_Zhan_Intro;

	// Play Zhan Intro Music
	UFUNCTION(BlueprintCallable, Category = BattleMusic)
	void Play_Zhan_Intro();

	// Zhan Battle Music
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = BattleMusic)
	UAudioComponent* Zhan_Battle;
	USoundCue* S_Zhan_Battle;

	// Play Zhan Battle Music
	UFUNCTION(BlueprintCallable, Category = BattleMusic)
	void Play_Zhan_Battle();

	// BACKGROUND MUSIC  -------------------------------------

	// Play Background Music
	UFUNCTION(BlueprintCallable, Category = BackgroundMusic)
	void Play_BGM(ERealms Level);

	// Main Menu Background Music
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = BackgroundMusic)
	UAudioComponent* BGM_MainMenu;
	USoundCue* S_BGM_MainMenu;

	// Play Main Menu Background Music
	UFUNCTION(BlueprintCallable, Category = BackgroundMusic)
	void Play_BGM_MainMenu();

	// Arcadia Background Music
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = BackgroundMusic)
	UAudioComponent* BGM_Arcadia;
	USoundCue* S_BGM_Arcadia;

	// Play Shiitake Temple Background Music
	UFUNCTION(BlueprintCallable, Category = BackgroundMusic)
	void Play_BGM_Arcadia();

	// Shiitake Temple Background Music
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = BackgroundMusic)
	UAudioComponent* BGM_Shiitake;
	USoundCue* S_BGM_Shiitake;

	// Play Shiitake Temple Background Music
	UFUNCTION(BlueprintCallable, Category = BackgroundMusic)
	void Play_BGM_Shiitake();

	// Vulcan Shrine Background Music
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = BackgroundMusic)
	UAudioComponent* BGM_Vulcan;
	USoundCue* S_BGM_Vulcan;

	// Play Vulcan Shrine Background Music
	UFUNCTION(BlueprintCallable, Category = BackgroundMusic)
	void Play_BGM_Vulcan();

	// Boreal Core Background Music
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = BackgroundMusic)
	UAudioComponent* BGM_Boreal;
	USoundCue* S_BGM_Boreal;

	// Play Boreal Core Background Music
	UFUNCTION(BlueprintCallable, Category = BackgroundMusic)
	void Play_BGM_Boreal();

	// Yggdrasil Background Music
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = BackgroundMusic)
	UAudioComponent* BGM_Yggdrasil;
	USoundCue* S_BGM_Yggdrasil;

	// Play Yggdrasil Background Music
	UFUNCTION(BlueprintCallable, Category = BackgroundMusic)
	void Play_BGM_Yggdrasil();

	// Empyrean Gardens Background Music
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = BackgroundMusic)
	UAudioComponent* BGM_Empyrean;
	USoundCue* S_BGM_Empyrean;

	// Play Empyrean Gardens Background Music
	UFUNCTION(BlueprintCallable, Category = BackgroundMusic)
	void Play_BGM_Empyrean();

	// Celestial Nexus Background Music
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = BackgroundMusic)
	UAudioComponent* BGM_Celestial;
	USoundCue* S_BGM_Celestial;

	// Play Celestial Nexus Background Music
	UFUNCTION(BlueprintCallable, Category = BackgroundMusic)
	void Play_BGM_Celestial();

	// SOUND EFFECTS  -----------------------------------------

	// Level Up Fanfare Music
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SoundEffects)
	UAudioComponent* SFX_LevelUp;
	USoundCue* S_SFX_LevelUp;	

	// Play Level Up Sound Effect. It's only in here so that it can fade out the battle music so that your level up is more pronounced.
	UFUNCTION(BlueprintCallable, Category = SoundEffects)
	void Play_SFX_LevelUp();

	// Menu Start Game SFX
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SoundEffects)
	UAudioComponent* SFX_StartGame;
	USoundCue* S_SFX_StartGame;

	// Play Start Game SFX
	UFUNCTION(BlueprintCallable, Category = SoundEffects)
	void Play_SFX_StartGame();

	// Menu Select SFX
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SoundEffects)
	UAudioComponent* SFX_Select;
	USoundCue* S_SFX_Select;

	// Play Select SFX
	UFUNCTION(BlueprintCallable, Category = SoundEffects)
	void Play_SFX_Select();

	// Menu Switch SFX
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SoundEffects)
	UAudioComponent* SFX_Switch;
	USoundCue* S_SFX_Switch;

	// Play Switch SFX
	UFUNCTION(BlueprintCallable, Category = SoundEffects)
	void Play_SFX_Switch();

	// Menu Cursor SFX
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SoundEffects)
	UAudioComponent* SFX_Cursor;
	USoundCue* S_SFX_Cursor;

	// Play Cursor SFX
	UFUNCTION(BlueprintCallable, Category = SoundEffects)
	void Play_SFX_Cursor();

	// Menu Cancel SFX
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SoundEffects)
	UAudioComponent* SFX_Cancel;
	USoundCue* S_SFX_Cancel;

	// Play Cancel SFX
	UFUNCTION(BlueprintCallable, Category = SoundEffects)
	void Play_SFX_Cancel();

	// Menu Binding Attach SFX
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SoundEffects)
	UAudioComponent* SFX_BindingAttach;
	USoundCue* S_SFX_BindingAttach;

	// Play Binding Attach SFX
	UFUNCTION(BlueprintCallable, Category = SoundEffects)
	void Play_SFX_BindingAttach();

	// Menu Error SFX
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SoundEffects)
	UAudioComponent* SFX_Error;
	USoundCue* S_SFX_Error;

	// Play Error SFX
	UFUNCTION(BlueprintCallable, Category = SoundEffects)
	void Play_SFX_Error();
};
