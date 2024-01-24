#pragma once
#include "NameObject.h"
#include <map>
#include <list>

class AActor;

// 설명 : 언리얼에서 U는 그냥 엔진에 속해있다는 것을 의미
class ULevel : public UNameObject
{
public:
	// constructor destructor
	ULevel();
	~ULevel();

	// delete Function
	ULevel(const ULevel& _Other) = delete;
	ULevel(ULevel&& _Other) noexcept = delete;
	ULevel& operator=(const ULevel& _Other) = delete;
	ULevel& operator=(ULevel&& _Other) noexcept = delete;

	virtual void BeginPlay() {};
	virtual void Tick(float _DeltaTime) {};

	// Actor 생성 함수 (이걸로 Actor를 만들어야 업데이트를 할 수 있다.)
	template<typename ActorType>
	ActorType* SpawnActor(int _Order = 0)
	{
		ActorType* NewActor = new ActorType();
		ActorInit(NewActor);
		AllActor[_Order].push_back(NewActor);
		return NewActor;
	}

	void ActorTick(float _DeltaTime);
	
protected:

private:
	std::map<int, std::list<AActor*>> AllActor;

	void ActorInit(AActor* _NewActor);
};
