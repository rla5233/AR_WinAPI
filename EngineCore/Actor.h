#pragma once
#include <EngineBase/Transform.h>
#include "TickObject.h"
#include "NameObject.h"
#include "ImageRenderer.h"
#include "Level.h"

class ULevel;
class UActorComponent;
class UImageRenderer;

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

	UImageRenderer* CreateImageRenderer(int Order = 0);

protected:

private:
	std::list<UImageRenderer*> Renderers;
	
	ULevel* World = nullptr;
	FTransform Transform;

	void SetWorld(ULevel* _Value)
	{
		World = _Value;
	}
};
