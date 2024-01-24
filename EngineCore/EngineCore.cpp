#include "EngineCore.h"
#include "Level.h"

EngineCore* GEngine = nullptr;

EngineCore::EngineCore()
{
}

EngineCore::~EngineCore()
{
}

void EngineCore::EngineUpdate()
{}

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
	// 엔진이 시작될 때 해야할일
	EngineCore* Ptr = _UserCore;
	GEngine = Ptr;
	Ptr->CoreInit(_hInstance);
	Ptr->Start();
	EngineWindow::WindowMessageLoop(EngineUpdate, EngineEnd);
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

void EngineCore::Start()
{}

void EngineCore::Update()
{}

void EngineCore::End()
{}
