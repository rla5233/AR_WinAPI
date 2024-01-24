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
	if (nullptr == GEngine->CurLevel)
	{
		MsgBoxAssert("CurLevel is Nullptr");
	}

	// ������ ���� ƽ�� ������.
	GEngine->CurLevel->Tick(0.0f);
	GEngine->CurLevel->ActorTick(0.0f);
}

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
	Ptr->BeginPlay();
	EngineWindow::WindowMessageLoop(EngineTick, EngineEnd);
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

	// ���� �������� ����
	CurLevel = AllLevel[UpperName];
}

void EngineCore::LevelInit(ULevel* _Level)
{
	_Level->BeginPlay();
}