// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "LOM_Attribute_Component.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class LIFEONMARS_API ULOM_Attribute_Component : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	ULOM_Attribute_Component();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	void SetDefaultHealth(float DefaultHealth);
	void SetDefaultOxy(float DefaultOxy);

	UPROPERTY(ReplicatedUsing = OnRep_Health, BlueprintReadWrite, Category = "Health Component")
		float Health;



	UFUNCTION()
		void OnRep_Health(float NewHealth);

	UPROPERTY(ReplicatedUsing = OnRep_Oxy, BlueprintReadWrite, Category = "Health Component")
		float Oxy;

	//UPROPERTY(Replicated, EditAnywhere, BlueprintReadWrite, Category = "Health Component")
	//	float DefaultHealth;

	//UPROPERTY(Replicated, EditAnywhere, BlueprintReadWrite, Category = "Health Component")
	//	float DefaultOxy;

	UFUNCTION(BlueprintCallable, meta = (Category, OverrideNativeName = "OnRep_Oxy"))
		void OnRep_Oxy(float OldOxy);
		
};
