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
	GEngine->CoreTick();
}

void EngineCore::CoreTick()
{
	float DeltaTime = MainTimer.TimeCheck();
	double dDeltaTime = MainTimer.GetDeltaTime();

	if (1 <= Frame)
	{
		CurFrameTime += DeltaTime;
		if (CurFrameTime <= FrameTime)
		{
			return;
		}

		CurFrameTime -= FrameTime;
		DeltaTime = FrameTime;
	}

	EngineInput::KeyCheckTick(DeltaTime);

	if (nullptr == GEngine->CurLevel)
	{
		MsgBoxAssert("CurLevel is Nullptr");
	}

	// ������ ���� ƽ�� ������.
	CurLevel->Tick(DeltaTime);
	// �������� ���Ϳ� ������Ʈ���� ƽ�� ������ -> �ൿ�Ѵ�.
	CurLevel->LevelTick(DeltaTime);
	// ���������� ������ ���� ȭ�鿡 �׸��� �׸���.
	CurLevel->LevelRender(DeltaTime);
	// �����Ѵ�. (���� ������Ʈ���� �ı��Ѵ�.)
	CurLevel->LevelRelease(DeltaTime);
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
	EngineCore* Ptr = _UserCore;
	GEngine = Ptr;
	Ptr->MainTimer.TimeCheckStart();
	Ptr->CoreInit(_hInstance);
	Ptr->BeginPlay();
	EngineWindow::WindowMessageLoop(EngineTick, EngineEnd);
}

void EngineCore::CoreInit(HINSTANCE _HINSTANCE)
{
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

	CurLevel = AllLevel[UpperName];
}

void EngineCore::LevelInit(ULevel* _Level)
{
	_Level->BeginPlay();
}