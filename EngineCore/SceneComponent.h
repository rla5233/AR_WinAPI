#pragma once
#include <EngineBase/Transform.h>
#include "ActorComponent.h"

// 설명 : Actor에 속해있으면서 자신만의 위치까지 가지고 있는 컴포넌트
class USceneComponent : public UActorComponent
{
public:
	// constructor destructor
	USceneComponent();
	~USceneComponent();

	// delete Function
	USceneComponent(const USceneComponent& _Other) = delete;
	USceneComponent(USceneComponent&& _Other) noexcept = delete;
	USceneComponent& operator=(const USceneComponent& _Other) = delete;
	USceneComponent& operator=(USceneComponent&& _Other) noexcept = delete;

	void SetPosition(const FVector& _Value)
	{
		Transform.SetPosition(_Value);
	}

	void SetScale(const FVector& _Value)
	{
		Transform.SetScale(_Value);
	}

	FTransform GetTransform()
	{
		return Transform;
	}

protected:

private:
	FTransform Transform;

};
