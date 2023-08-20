// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/BaseCharacter.h"
#include "EnemyCharacter.generated.h"

/**
 * 
 */
UCLASS()
class ABONTHELOOSE_API AEnemyCharacter : public ABaseCharacter
{
	GENERATED_BODY()
	
public:

protected:
	//Attack related functions
	virtual void Attack() override;
	virtual void CanAttack() override;

private:


};
