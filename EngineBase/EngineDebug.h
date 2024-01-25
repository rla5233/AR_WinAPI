#pragma once
#include <Windows.h>
#include <assert.h>
#include <string>
#include <string_view>

namespace EngineDebug
{
	#define LeakCheak _CrtSetDbgFlag(_CRTDBG_LEAK_CHECK_DF | _CRTDBG_ALLOC_MEM_DF)
	#define MsgBoxAssert(VALUE) \
	std::string ErrorText = std::string(VALUE); \
	MessageBoxA(nullptr, ErrorText.c_str(), "Fatal Error", MB_OK); assert(false)
}