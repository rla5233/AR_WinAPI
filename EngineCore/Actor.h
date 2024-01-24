#pragma once
#include <EngineBase/FTransform.h>
#include "TickObject.h"
#include "NameObject.h"

class ULevel;

	// 설명 : 언리얼에서 A가 붙은 오브젝트는 화면에 위치가 존재한다.
class AActor : public UNameObject, public UTickObject
{
	friend ULevel;
public:
	// constructor destructor
	AActor();
	~AActor();

	// delete Function
	AActor(const AActor& _Other) = delete;
	AActor(AActor&& _Other) noexcept = delete;
	AActor& operator=(const AActor& _Other) = delete;
	AActor& operator=(AActor&& _Other) noexcept = delete;

	FVector GetActorLocation()
	{
		return Transform.GetPosition();
	}

	void SetActorLocation(FVector _Value)
	{
		Transform.SetPosition(_Value);
	}

	void SetActorScale(FVector _Value)
	{
		Transform.SetScale(_Value);
	}

	FTransform GetTransform()
	{
		return Transform;
	}

	ULevel* GetWorld()
	{
		return World;
	}

protected:

private:
	// 객체가 속한 level
	ULevel* World;
	FTransform Transform;

	// 외부에 공개하지 않을것이다.
	void SetWorld(ULevel* _Value)
	{
		World = _Value;
	}
};
