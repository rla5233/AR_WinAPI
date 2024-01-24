#pragma once
#include <EnginePlatform/EngineWindow.h>
#include <map>

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

	virtual void EngineStart();
	virtual void EngineUpdate();
	virtual void EngineEnd();

public:
	// 윈도우창 1개는 무조건 만들어질것임
	EngineWindow MainWindow;

protected:
	// 엔진 코어는 프로그램에 1개 있다.
	// 따라서 아무나 또 생성하지 못하도록 막음
	EngineCore();

private:
	// 엔진 초기화 됬는지 확인
	bool EngineInit = false;

	std::map<std::string, ULevel*> AllLevel;
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
}