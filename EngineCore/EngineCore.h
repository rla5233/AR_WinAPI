#pragma once
#include <EnginePlatform/EngineWindow.h>

// 설명 :
class EngineCore
{
public:
	// constructor destructor
	EngineCore();
	~EngineCore();

	// delete Function
	EngineCore(const EngineCore& _Other) = delete;
	EngineCore(EngineCore&& _Other) noexcept = delete;
	EngineCore& operator=(const EngineCore& _Other) = delete;
	EngineCore& operator=(EngineCore&& _Other) noexcept = delete;

	// 코어 초기화
	void CoreInit(HINSTANCE _HINSTANCE);

	virtual void EngineStart();
	virtual void EngineUpdate();
	virtual void EngineEnd();

public:
	// 윈도우창 1개는 무조건 만들어질것임
	EngineWindow MainWindow;

protected:

private:
	// 엔진 초기화 됬는지 확인
	bool EngineInit = false;
};

// 메인함수를 숨기기 위하 define 이용 -> 옛날 방식
#define ENGINESTART(USERCORE) \
int APIENTRY wWinMain(_In_ HINSTANCE hInstance, \
_In_opt_ HINSTANCE hPrevInstance, \
_In_ LPWSTR    lpCmdLine, \
_In_ int       nCmdShow) \
{ \
	USERCORE NewUserCore; \
	EngineCore* Ptr = &NewUserCore; \
	Ptr->CoreInit(hInstance); \
	Ptr->EngineStart(); \
	EngineWindow::WindowMessageLoop(); \
} \