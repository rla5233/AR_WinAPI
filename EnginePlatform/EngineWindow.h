#pragma once
#include <Windows.h>
#include <string>

// ���� :
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

	// ������â ����
	void Open(std::string_view _Title = "Title");

	// ������â �ʱ�ȭ
	static void Init(HINSTANCE _hInst);

	// ������Ʈ�� ����� ������ �Լ������ͷ� �޾Ƽ� �������ش�.
	static unsigned __int64 WindowMessageLoop(void(*_Update)(), void(*_End)());

protected:

private:
	// ��ü�� 1���� ���� �����ϴ� ��� static�� ����� �� �ִ�.
	static bool WindowLive;
	static HINSTANCE hInstance;
	static LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

	HWND hWnd = nullptr;
	HDC hDc = nullptr;
};
