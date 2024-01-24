#pragma once
#include <EnginePlatform/EngineWindow.h>
#include <map>

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

	virtual void EngineStart();
	virtual void EngineUpdate();
	virtual void EngineEnd();

public:
	// ������â 1���� ������ �����������
	EngineWindow MainWindow;

protected:
	// ���� �ھ�� ���α׷��� 1�� �ִ�.
	// ���� �ƹ��� �� �������� ���ϵ��� ����
	EngineCore();

private:
	// ���� �ʱ�ȭ ����� Ȯ��
	bool EngineInit = false;

	std::map<std::string, ULevel*> AllLevel;
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
}