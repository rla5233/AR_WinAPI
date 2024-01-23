#pragma once
#include <EnginePlatform/EngineWindow.h>

// ���� :
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

	// �ھ� �ʱ�ȭ
	void CoreInit(HINSTANCE _HINSTANCE);

	virtual void EngineStart();
	virtual void EngineUpdate();
	virtual void EngineEnd();

public:
	// ������â 1���� ������ �����������
	EngineWindow MainWindow;

protected:

private:
	// ���� �ʱ�ȭ ����� Ȯ��
	bool EngineInit = false;
};

// �����Լ��� ����� ���� define �̿� -> ���� ���
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