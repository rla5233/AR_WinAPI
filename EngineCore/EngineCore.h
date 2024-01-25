#pragma once

#include <map>

#include <EngineBase/EngineDebug.h>
#include <EngineBase/EngineString.h>
#include <EngineBase/EngineTime.h>

#include <EnginePlatform/EngineInput.h>
#include <EnginePlatform/EngineWindow.h>

class ULevel;

// 설명 :
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

	// 코어 초기화
	void CoreInit(HINSTANCE _HINSTANCE);

	static void EngineStart(HINSTANCE _hInstance, EngineCore* _UserCore);

	virtual void BeginPlay();
	virtual void Tick(float _DeltaTime);
	virtual void End();

	// 스테이지 생성 함수
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
	// 엔진 코어는 프로그램에 1개 있다.
	// 따라서 아무나 또 생성하지 못하도록 막음
	EngineCore();

public:
	// 윈도우창 1개는 무조건 만들어질것임
	EngineWindow	MainWindow;
	EngineTime		MainTimer;

private:
	// 엔진 초기화 됬는지 확인
	bool EngineInit = false;

	// Level(스테이지)는 map으로 관리할 수 있다.
	std::map<std::string, ULevel*> AllLevel;
	ULevel* CurLevel = nullptr;

	void LevelInit(ULevel* _Level);

	static void EngineTick();
	static void EngineEnd();
};

extern EngineCore* GEngine;

// 메인함수를 숨기기 위해 define 이용 -> 옛날 방식
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