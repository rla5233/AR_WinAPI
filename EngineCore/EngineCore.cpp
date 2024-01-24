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
	// ������ ����� �� �ؾ�����

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
	// ������ ���۵� �� �ؾ�����
	EngineCore* Ptr = _UserCore;
	GEngine = Ptr;
	Ptr->CoreInit(_hInstance);
	Ptr->Start();
	EngineWindow::WindowMessageLoop(EngineUpdate, EngineEnd);
}

void EngineCore::CoreInit(HINSTANCE _HINSTANCE)
{
	// ����ڵ� (�ߺ� �ʱ�ȭ ����)
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
