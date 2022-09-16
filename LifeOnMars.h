// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "Modules/ModuleInterface.h"
#include "UObject/NoExportTypes.h"
#include "LifeOnMars.generated.h"

#define SURFACE_SAND SurfaceType1
#define SURFACE_CONCRETE SurfaceType2
#define SURFACE_METAL SurfaceType3
#define SURFACE_BRICK SurfaceType4
#define SURFACE_ROCK SurfaceType5
#define SURFACE_BODY SurfaceType6
#define SURFACE_GRAVEL SurfaceType7
#define SURFACE_PEBBLE SurfaceType8
#define SURFACE_HEAD SurfaceType9
#define SURFACE_CLAY SurfaceType10
#define SURFACE_WATER SurfaceType11
#define SURFACE_WOOD SurfaceType12
#define SURFACE_ELECTRONIC SurfaceType13
#define SURFACE_DIRT SurfaceType14
#define SURFACE_GLASS SurfaceType15
#define SURFACE_GRASS SurfaceType16
#define SURFACE_SHEETROCK SurfaceType17
#define SURFACE_TILE SurfaceType18
#define SURFACE_ASPHALT SurfaceType19
#define SURFACE_CARDBOARD SurfaceType20
#define SURFACE_CARPET SurfaceType21
#define SURFACE_LEAVES SurfaceType22
#define SURFACE_PLASTER SurfaceType23
#define SURFACE_PLASTIC SurfaceType24
#define SURFACE_CLOTH SurfaceType25
#define SURFACE_SNOW SurfaceType26
#define SURFACE_ICE SurfaceType27
#define SURFACE_THINMETAL SurfaceType28
#define SURFACE_SOLIDMETAL SurfaceType29

UENUM(BlueprintType)
enum class ECharacterActivity : uint8 {
	EIdle = 0	UMETA(DisplayName = "Idle"),
	EWalk = 1	UMETA(DisplayName = "Walk"),
	ERun = 2	UMETA(DisplayName = "Run"),
	EJump = 3	UMETA(DisplayName = "Jump"),
	ECrouch = 4	UMETA(DisplayName = "Crouch"),
	EProne = 5	UMETA(DisplayName = "Prone"),
	ESlowWalk = 6	UMETA(DisplayName = "SlowWalk"),
	EFlying = 7	UMETA(DisplayName = "Fly")
};

USTRUCT(BlueprintType)
struct FNftUserProfile {
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, Category = "NFT")
		FString Description;

	UPROPERTY(BlueprintReadWrite, Category = "NFT")
		FString ImageURL;

	UPROPERTY(BlueprintReadWrite, Category = "NFT")
		FString Name;

	FNftUserProfile() {
		Description = "";
		ImageURL = "";
		Name = "";
	}
};

UENUM(BlueprintType)
enum class EWeather : uint8 {
	EIdle = 0	UMETA(DisplayName = "Idle"),
	ERain = 1	UMETA(DisplayName = "Rain"),
	ESpring = 2	UMETA(DisplayName = "Spring"),
	ESummer = 3	UMETA(DisplayName = "Summer"),
	EFall = 4	UMETA(DisplayName = "Fall"),
	EWinter = 5	UMETA(DisplayName = "Winter"),
};


UENUM(BlueprintType)
enum class EItem_Category : uint8 {
	Resources 	UMETA(DisplayName = "Resources"),
	Melee		UMETA(DisplayName = "Weapons"),
	Bow			UMETA(DisplayName = "Bow"),
	Weapons		UMETA(DisplayName = "Weapons"),
	Construction 	UMETA(DisplayName = "Construction"),
	Armor 		UMETA(DisplayName = "Armor"),
	Tools 		UMETA(DisplayName = "Tools"),
	Medical 	UMETA(DisplayName = "Medical"),
	Food 		UMETA(DisplayName = "Food"),
	Water 		UMETA(DisplayName = "Water"),
	Ammo 		UMETA(DisplayName = "Ammo"),
	Traps 		UMETA(DisplayName = "Traps"),
	Misc 		UMETA(DisplayName = "Misc"),
	Electrical 	UMETA(DisplayName = "Electrical"),
	Fun 		UMETA(DisplayName = "Fun"),
};

UENUM(BlueprintType)
enum class EActivity : uint8 {
	Sit  	    UMETA(DisplayName = "Sit"),
	Bow  	    UMETA(DisplayName = "Bow"),
	Melee  	    UMETA(DisplayName = "Melee"),
	OneHand_Right  	    UMETA(DisplayName = "OneHand_Right"),
	OneHand_Left  	    UMETA(DisplayName = "OneHand_Left"),
};
