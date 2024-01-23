#include "EngineCore.h"

EngineCore::EngineCore()
{
}

EngineCore::~EngineCore()
{
}

void EngineCore::CoreInit(HINSTANCE _HINSTANCE)
{
	// 방어코드 (중복 초기화 방지)
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
