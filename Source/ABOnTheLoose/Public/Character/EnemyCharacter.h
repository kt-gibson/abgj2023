// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/BaseCharacter.h"
#include "EnemyCharacter.generated.h"

class UAnimMontage;

/**
 *	AEnemyCharacter
 * 
 *	This class represents the enemy character and contains relevant functionality for movement, attacking, anim montages, etc
 */
UCLASS()
class ABONTHELOOSE_API AEnemyCharacter : public ABaseCharacter
{
	GENERATED_BODY()
	
public:
	AEnemyCharacter();

protected:
	virtual void Tick(float DeltaTime) override;
	//Attack related functions
	virtual void Attack() override;
	virtual void CanAttack() override;

	UPROPERTY(BlueprintReadWrite)
	AActor* AttackTarget;

private:
	UPROPERTY(EditAnywhere)
	float AttackRadius = 100.f;
	UPROPERTY(EditAnywhere)
	UAnimMontage* AttackMontage;

	bool bIsAttacking = false;
	bool bIsGrabbed = false;

};
