// Fill out your copyright notice in the Description page of Project Settings.


#include "LOM_Attribute_Component.h"
#include <Runtime/Engine/Public/Net/UnrealNetwork.h>

// Sets default values for this component's properties
ULOM_Attribute_Component::ULOM_Attribute_Component()
{
	PrimaryComponentTick.bCanEverTick = false;
	SetIsReplicated(true);
}


// Called when the game starts
void ULOM_Attribute_Component::BeginPlay()
{
	Super::BeginPlay();
	
	
}


void ULOM_Attribute_Component::SetDefaultHealth(float DefaultHealth)
{

}

void ULOM_Attribute_Component::SetDefaultOxy(float DefaultOxy)
{

}

void ULOM_Attribute_Component::OnRep_Health(float NewHealth)
{

}

void ULOM_Attribute_Component::OnRep_Oxy(float OldOxy)
{

}

void ULOM_Attribute_Component::GetLifetimeReplicatedProps(TArray< FLifetimeProperty >& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(ULOM_Attribute_Component, Health);
	DOREPLIFETIME(ULOM_Attribute_Component, Oxy);
}