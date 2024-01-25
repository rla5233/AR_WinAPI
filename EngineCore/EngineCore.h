#pragma once

#include <map>

#include <EngineBase/EngineDebug.h>
#include <EngineBase/EngineString.h>
#include <EngineBase/EngineTime.h>

#include <EnginePlatform/EngineInput.h>
#include <EnginePlatform/EngineWindow.h>

class ULevel;

// ���� :
class EngineCore
{
public:
	// destructor
	~EngineCore();

	// delete Function
	EngineCore(const EngineCore& _Other) = delete;
	EngineCore(EngineCore&& _Other) noexcept = delete;
	EngineCore& operator=(const EngineCore& _Other) = delete;
	EngineCore& operator=(EngineCore&& _Other) noexcept = delete;

	// �ھ� �ʱ�ȭ
	void CoreInit(HINSTANCE _HINSTANCE);

	static void EngineStart(HINSTANCE _hInstance, EngineCore* _UserCore);

	virtual void BeginPlay();
	virtual void Tick(float _DeltaTime);
	virtual void End();

	// �������� ���� �Լ�
	template<typename LevelType>
	void CreateLevel(std::string_view _Name)
	{
		if (true == AllLevel.contains(_Name.data()))
		{
			MsgBoxAssert(std::string(_Name) + " Level Already Exist");
		}

		LevelType* NewLevel = new LevelType();
		AllLevel.insert(std::pair<std::string, ULevel*>(_Name, NewLevel));
	}

	void ChangeLevel(std::string_view _Name);

protected:
	// ���� �ھ�� ���α׷��� 1�� �ִ�.
	// ���� �ƹ��� �� �������� ���ϵ��� ����
	EngineCore();

public:
	// ������â 1���� ������ �����������
	EngineWindow	MainWindow;
	EngineTime		MainTimer;

private:
	// ���� �ʱ�ȭ ����� Ȯ��
	bool EngineInit = false;

	// Level(��������)�� map���� ������ �� �ִ�.
	std::map<std::string, ULevel*> AllLevel;
	ULevel* CurLevel = nullptr;

	void LevelInit(ULevel* _Level);

	static void EngineTick();
	static void EngineEnd();
};

extern EngineCore* GEngine;

// �����Լ��� ����� ���� define �̿� -> ���� ���
#define ENGINESTART(USERCORE) \
int APIENTRY wWinMain(_In_ HINSTANCE hInstance, \
_In_opt_ HINSTANCE hPrevInstance, \
_In_ LPWSTR    lpCmdLine, \
_In_ int       nCmdShow) \
{ \
	LeakCheak; \
	USERCORE NewUserCore = USERCORE(); \
	EngineCore::EngineStart(hInstance, &NewUserCore); \
}