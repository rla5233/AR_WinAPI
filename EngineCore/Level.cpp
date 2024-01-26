#include "Level.h"
#include "Actor.h"

ULevel::ULevel()
{
}

ULevel::~ULevel()
{
	// level 소멸시 스테이지 안의 Actor들을 삭제 해줘야한다.
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

void ULevel::LevelTick(float _DeltaTime)
{
	for (std::pair<const int, std::list<AActor*>>& OrderListPair : AllActor)
	{
		std::list<AActor*>& ActorList = OrderListPair.second;
		for (AActor* Actor : ActorList)
		{
			if (Actor->IsActive())
			{
				Actor->Tick(_DeltaTime);
			}
		}
	}
}

void ULevel::LevelRender(float _DeltaTime)
{
	for (std::pair<const int, std::list<UImageRenderer*>>& OrderListPair : Renderers)
	{
		std::list<UImageRenderer*>& RendererList = OrderListPair.second;
		for (UImageRenderer* Renderer : RendererList)
		{
			Renderer->
			
		}
	}
}

void ULevel::LevelRelease(float _DeltaTime)
{
	for (std::pair<const int, std::list<AActor*>>& OrderListPair : AllActor)
	{
		std::list<AActor*>& ActorList = OrderListPair.second;

		std::list<AActor*>::iterator Iter = ActorList.begin();
		for (Iter; Iter != ActorList.end();)
		{
			AActor* Actor = *(Iter);

			if (nullptr == Actor)
			{
				MsgBoxAssert("Release Error : Actor is Nullptr");
				return;
			}

			if (Actor->IsDestroy())
			{
				delete Actor;
				Actor = nullptr;
				Iter = ActorList.erase(Iter);
			}
			{
				++Iter;
			}
		}
	}
}

void ULevel::ActorInit(AActor* _NewActor)
{
	// Actor의 생성자에서는 level이 세팅되지 않아 Get
	_NewActor->SetWorld(this);
	_NewActor->BeginPlay();
}