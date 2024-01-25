#include "EnginePlatform/EngineInput.h"
#include "EngineCore.h"
#include "Level.h"

EngineCore* GEngine = nullptr;

EngineCore::EngineCore()
	: MainWindow()
{
}

EngineCore::~EngineCore()
{
}

void EngineCore::EngineTick()
{
	float DeltaTime = GEngine->MainTimer.TimeCheck();
	EngineInput::KeyCheckTick(DeltaTime);
	if (nullptr == GEngine->CurLevel)
	{
		MsgBoxAssert("CurLevel is Nullptr");
	}

	// 레벨이 먼저 틱을 돌린다.
	GEngine->CurLevel->Tick(DeltaTime);
	GEngine->CurLevel->ActorTick(DeltaTime);
}

void EngineCore::EngineEnd()
{
	// 엔진이 종료될 때 해야할일

	for (std::pair<const std::string, ULevel*>& _Pair: GEngine->AllLevel)
	{
		if (nullptr != _Pair.second)
		{
			delete _Pair.second;
			_Pair.second = nullptr;
		}
	}

	GEngine->AllLevel.clear();
}

void EngineCore::EngineStart(HINSTANCE _hInstance, EngineCore* _UserCore)
{
	EngineCore* Ptr = _UserCore;
	GEngine = Ptr;
	Ptr->MainTimer.TimeCheckStart();
	Ptr->CoreInit(_hInstance);
	Ptr->BeginPlay();
	EngineWindow::WindowMessageLoop(EngineTick, EngineEnd);
}

void EngineCore::CoreInit(HINSTANCE _HINSTANCE)
{
	// 방어코드 (중복 초기화 방지)
	if (true == EngineInit)
	{
		return;
	}

	EngineWindow::Init(_HINSTANCE);
	MainWindow.Open();

	EngineInit = true;
}

void EngineCore::BeginPlay()
{}

void EngineCore::Tick(float _DeltaTime)
{}

void EngineCore::End()
{}

void EngineCore::ChangeLevel(std::string_view _Name)
{
	std::string UpperName = EngineString::ToUpper(_Name);

	if (false == AllLevel.contains(UpperName))
	{
		MsgBoxAssert(std::string(_Name) + " Is Not Found");
	}

	// 현재 레벨
	CurLevel = AllLevel[UpperName];
}

void EngineCore::LevelInit(ULevel* _Level)
{
	_Level->BeginPlay();
}