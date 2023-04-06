// Fill out your copyright notice in the Description page of Project Settings.


#include "LOM_AC_Attribute.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Net/UnrealNetwork.h"
#include "Delegates/DelegateSignatureImpl.inl"
#include "LifeOnMars.h"
#include <Kismet/KismetSystemLibrary.h>

// Sets default values for this component's properties
ULOM_AC_Attribute::ULOM_AC_Attribute()
{
	SetIsReplicated(true);

}
void ULOM_AC_Attribute::BeginPlay()
{
	Super::BeginPlay();

	//if (GetOwner()->HasAuthority())
	//{
	//	FTimerHandle Timer;
	//	GetWorld()->GetTimerManager().SetTimer(Timer, this, &ULOM_AC_Attribute::Loop_Cal_Distance, 5, true);
	//	Old_Location = GetOwner()->GetActorLocation();
	//}
}

void ULOM_AC_Attribute::Calculator_HP(double Damage)
{
	HP = FMath::Clamp(HP - Damage, 0.f, 100.f);
}

void ULOM_AC_Attribute::Calculator_Location()
{
	After_Cal_Distance();

}

void ULOM_AC_Attribute::OnRep_Level()
{
	int out;
	ULOM_FunctionLibrary::Calculator_XP(Level, 600, out, XP_NeedToUp);
	After_OnRepLevel();
}

void ULOM_AC_Attribute::OnRep_HP()
{
	ED_ChangeHP.Broadcast();
}

void ULOM_AC_Attribute::OnRep_Stamina()
{
	ED_ChangeStamina.Broadcast();
}

void ULOM_AC_Attribute::OnRep_Oxygen()
{
	ED_ChangeOxygen.Broadcast();
}

void ULOM_AC_Attribute::Loop_Cal_Stamina()
{
	
	Stamina = FMath::Clamp(Stamina + StaminaRegen, 0, Max_Stamina) ;
	OnRep_Stamina();
}

void ULOM_AC_Attribute::Sub_Oxy(float value)
{
	ED_Oxygen.Broadcast(Oxygen - (value - (Oxygen_consumption/100)));
}


void ULOM_AC_Attribute::GetLifetimeReplicatedProps(TArray< FLifetimeProperty >& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME_CONDITION(ULOM_AC_Attribute, Stamina, COND_OwnerOnly);
	DOREPLIFETIME_CONDITION(ULOM_AC_Attribute, Oxygen, COND_OwnerOnly);
	DOREPLIFETIME_CONDITION(ULOM_AC_Attribute, HP, COND_OwnerOnly);

	DOREPLIFETIME_CONDITION(ULOM_AC_Attribute, Level, COND_OwnerOnly);
}
