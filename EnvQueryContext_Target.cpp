// Copyright Epic Games, Inc. All Rights Reserved.

#include "Variant_Shooter/AI/EnvQueryContext_Target.h"
#include "EnvironmentQuery/Items/EnvQueryItemType_Actor.h"
#include "EnvironmentQuery/EnvQueryTypes.h"
#include "ShooterAIController.h"

void UEnvQueryContext_Target::ProvideContext(FEnvQueryInstance& QueryInstance, FEnvQueryContextData& ContextData) const
{
	// ============ 获取AI控制器 ============
	if (AShooterAIController* Controller = Cast<AShooterAIController>(QueryInstance.Owner))
	{
		// 优先使用当前锁定的目标
		if (IsValid(Controller->GetCurrentTarget()))
		{
			UEnvQueryItemType_Actor::SetContextHelper(ContextData, Controller->GetCurrentTarget());
		}
		else
		{
			// 无目标时默认使用控制器本身
			UEnvQueryItemType_Actor::SetContextHelper(ContextData, Controller);
		}
	}
}
