#include "EngineCore.h"

EngineCore::EngineCore()
{
}

EngineCore::~EngineCore()
{
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

void EngineCore::EngineStart()
{}

void EngineCore::EngineUpdate()
{}

void EngineCore::EngineEnd()
{}