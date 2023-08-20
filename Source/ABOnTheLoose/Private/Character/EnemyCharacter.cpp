// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/EnemyCharacter.h"

AEnemyCharacter::AEnemyCharacter()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AEnemyCharacter::Tick(float DeltaTime)
{
	if (AttackTarget)
		CanAttack();
}

void AEnemyCharacter::Attack()
{
	//Play the anim montage
	checkf(AttackMontage, TEXT("Attack Montage has not been set")); //This not being set is a developer error - just crash the program.
	UAnimInstance* AnimInstance = GetMesh()->GetAnimInstance();
	//UE_LOG(LogTemp, Warning, TEXT("Trying to attack"));
	if (AnimInstance)
	{
		//const float Val = AnimInstance->Montage_Play(AttackMontage);
		//UE_LOG(LogTemp, Warning, TEXT("Trying to play montage - Ret val: %f"), Val);
		AnimInstance->Montage_Play(AttackMontage);
		//AnimInstance->Montage_JumpToSection(FName(TEXT("Attack")), AttackMontage);
		bIsAttacking = false;
	}
}

//This function will check to see if AI is in an appropriate range to initiate the attack montage - The montage will contain notifies to inflict damage
void AEnemyCharacter::CanAttack()
{
	//checkf(AttackTarget, TEXT("Attack Target has not been set")); //This not being set is a developer error - just crash the program.
	if (!bIsAttacking && !bIsGrabbed)
	{
		//Get the distance between the target actor and enemy. If inside attack radius perform the attack
		const double DistanceToTarget = (AttackTarget->GetActorLocation() - GetActorLocation()).Size();
		//UE_LOG(LogTemp, Warning, TEXT("Trying to attack - DistanceToTarget: %f"), DistanceToTarget);
		if (DistanceToTarget <= AttackRadius)
		{
			bIsAttacking = true;
			Attack();
		}
	}
}
