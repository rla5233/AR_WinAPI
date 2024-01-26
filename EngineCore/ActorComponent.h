#pragma once
#include "TickObject.h"

class AActor;

// 설명 : Actor에게 속해있다는 컴포넌트 
// (나는 Actor에 속한 기능이다. 라는것을 표현)
class UActorComponent : public UTickObject
{
	friend AActor;
public:
	// constructor destructor
	UActorComponent();
	~UActorComponent();

	// delete Function
	UActorComponent(const UActorComponent& _Other) = delete;
	UActorComponent(UActorComponent&& _Other) noexcept = delete;
	UActorComponent& operator=(const UActorComponent& _Other) = delete;
	UActorComponent& operator=(UActorComponent&& _Other) noexcept = delete;

	AActor* GetOwner()
	{
		return Owner;
	}

protected:

private:
	AActor* Owner = nullptr;

	void SetOwner(AActor* _Owner)
	{
		Owner = _Owner;
	}
};
