#pragma once
#include <Windows.h>
#include <string>

// 설명 :
class EngineWindow
{
public:
	// constructor destructor
	EngineWindow();
	~EngineWindow();

	// delete Function
	EngineWindow(const EngineWindow& _Other) = delete;
	EngineWindow(EngineWindow&& _Other) noexcept = delete;
	EngineWindow& operator=(const EngineWindow& _Other) = delete;
	EngineWindow& operator=(EngineWindow&& _Other) noexcept = delete;

	// 윈도우창 띄우기
	void Open(std::string_view _Title = "Title");

	// 윈도우창 초기화
	static void Init(HINSTANCE _hInst);

	// 업데이트와 종료시 할일을 함수포인터로 받아서 실행해준다.
	static unsigned __int64 WindowMessageLoop(void(*_Update)(), void(*_End)());

protected:

private:
	// 객체가 1개의 값을 공유하는 경우 static을 사용할 수 있다.
	static bool WindowLive;
	static HINSTANCE hInstance;
	static LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

	HWND hWnd = nullptr;
	HDC hDc = nullptr;
};
