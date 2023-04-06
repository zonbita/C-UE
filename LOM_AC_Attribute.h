// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Net/UnrealNetwork.h"
#include "Components/ActorComponent.h"
#include "LOM_FunctionLibrary.h"
#include "Engine/DataTable.h"
#include "LOM_AC_Attribute.generated.h"


UCLASS(Blueprintable, BlueprintType, ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class LIFEONMARS_API ULOM_AC_Attribute : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	ULOM_AC_Attribute();

	/** Please add a function description */
	UFUNCTION(BlueprintCallable, Category = "Default")
		void Calculator_HP(double Damage);

	/** Please add a function description */
	UFUNCTION(BlueprintCallable, Category = "Default")
		void Calculator_Location();

	/** Please add a function description */
	UFUNCTION(BlueprintCallable, meta = (Category, OverrideNativeName = "OnRep_Level"))
		virtual void OnRep_Level();

	UFUNCTION(BlueprintImplementableEvent)
		void After_OnRepLevel();


	/** Please add a function description */
	UFUNCTION()
		virtual void OnRep_HP();

	/** Please add a function description */
	UFUNCTION()
		virtual void OnRep_Stamina();

	/** Please add a function description */
	UFUNCTION()
		virtual void OnRep_Oxygen();

	/** Please add a function description */
	UFUNCTION(BlueprintCallable, Category = "Default")
		void Loop_Cal_Stamina();


	UFUNCTION(BlueprintImplementableEvent)
		void After_Cal_Distance();

	UFUNCTION(BlueprintCallable)
		void Sub_Oxy(float value);
		
	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Level", ReplicatedUsing = "OnRep_Level")
		int32 Level;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Level")
		int32 XP;

	/** Please add a variable description */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attribute", ReplicatedUsing = "OnRep_HP", meta = (MultiLine = "true"))
		double HP;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Attribute", meta = (MultiLine = "true"))
		double Max_HP;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Attribute", ReplicatedUsing = "OnRep_Stamina")
		double Stamina;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Attribute")
		double Max_Stamina;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Attribute", ReplicatedUsing = "OnRep_Oxygen")
		double Oxygen;

	/** Please add a variable description */
	//UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Default")
	//	TObjectPtr<ACharacter> Metahuman;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Default")
		FVector Old_Location;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Attribute")
		double Move_Distance_KM;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Attribute")
		double StaminaRegen;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Attribute")
		double TimetoRegen;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Level")
		int32 XP_NeedToUp;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Attribute")
		double Oxygen_consumption;

	/** Please add a variable description */
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FED_HP, double, value);
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, BlueprintAssignable, BlueprintCallable, meta = (DisplayName = "ED HP", Category = "Default", MultiLine = "true", OverrideNativeName = "ED_HP"))
		FED_HP ED_HP;

	/** Please add a variable description */
	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FED_ChangeHP);
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, BlueprintAssignable, BlueprintCallable, meta = (DisplayName = "ED_ChangeHP", Category = "Default", MultiLine = "true", OverrideNativeName = "ED_ChangeHP"))
		FED_ChangeHP ED_ChangeHP;

	/** Please add a variable description */
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FED_Stamina, double, Stamina);
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, BlueprintAssignable, BlueprintCallable, meta = (DisplayName = "ED_Stamina", Category = "Default", MultiLine = "true", OverrideNativeName = "ED_Stamina"))
		FED_Stamina ED_Stamina;

	/** Please add a variable description */
	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FED_ChangeStamina);
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, BlueprintAssignable, BlueprintCallable, meta = (DisplayName = "ED_ChangeStamina", Category = "Default", MultiLine = "true", OverrideNativeName = "ED_ChangeStamina"))
		FED_ChangeStamina ED_ChangeStamina;

	/** Please add a variable description */
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FED_Oxygen, double, Value);
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, BlueprintAssignable, BlueprintCallable, meta = (DisplayName = "ED_Oxygen", Category = "Default", MultiLine = "true", OverrideNativeName = "ED_Oxygen"))
		FED_Oxygen ED_Oxygen;

	/** Please add a variable description */
	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FED_ChangeOxygen);
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, BlueprintAssignable, BlueprintCallable, meta = (DisplayName = "ED_ChangeOxygen", Category = "Default", MultiLine = "true", OverrideNativeName = "ED_ChangeOxygen"))
		FED_ChangeOxygen ED_ChangeOxygen;



protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const;

		
};
