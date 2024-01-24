#include "Level.h"
#include "Actor.h"

ULevel::ULevel()
{
}

ULevel::~ULevel()
{
	// level �Ҹ�� �������� ���� Actor���� ���� ������Ѵ�.
	for (std::pair<const int, std::list<AActor*>>& OrderListPair : AllActor)
	{
		std::list<AActor*>& ActorList = OrderListPair.second;
		for (AActor* Actor : ActorList)
		{
			if (nullptr != Actor)
			{
				delete Actor;
				Actor = nullptr;
			}
		}
	}

}

void ULevel::ActorTick(float _DeltaTime)
{
	for (std::pair<const int, std::list<AActor*>>& OrderListPair : AllActor)
	{
		std::list<AActor*>& ActorList = OrderListPair.second;
		for (AActor* Actor : ActorList)
		{
			if (false != Actor->IsOn())
			{
				Actor->Tick(_DeltaTime);
			}
		}
	}
}

void ULevel::ActorInit(AActor* _NewActor)
{
	// Actor�� �����ڿ����� level�� ���õ��� �ʾ� Get
	_NewActor->SetWorld(this);

	_NewActor->BeginPlay();
}