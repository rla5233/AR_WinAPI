#include "EngineWindow.h"
#include <EngineBase/EngineDebug.h>

bool EngineWindow::WindowLive = true;
HINSTANCE EngineWindow::hInstance;

EngineWindow::EngineWindow()
{
}

EngineWindow::~EngineWindow()
{
}

LRESULT CALLBACK EngineWindow::WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
        break;
    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hWnd, &ps);
        EndPaint(hWnd, &ps);
    }
    break;
    case WM_DESTROY:
        // 윈도우 종료시
        WindowLive = false;
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

void EngineWindow::Init(HINSTANCE _hInst)
{
    hInstance = _hInst;
}

void EngineWindow::Open(std::string_view _Title)
{
    // 윈도우 설정 초기화
    WNDCLASSEXA wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc = WndProc;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = hInstance;
    wcex.hIcon = nullptr; // 아이콘
    wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wcex.lpszMenuName = nullptr; // 메뉴바
    wcex.lpszClassName = "DefaultWindow";
    wcex.hIconSm = nullptr;

    RegisterClassExA(&wcex);
    
    // 윈도우 창 띄우기
    HWND hWnd = CreateWindowA("DefaultWindow", _Title.data(), WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

    if (!hWnd)
    {
        MsgBoxAssert("Creating Window Fail.");
        return;
    }

    hDC = GetDC(hWnd);

    ShowWindow(hWnd, SW_SHOW);
    UpdateWindow(hWnd);
}

unsigned __int64 EngineWindow::WindowMessageLoop(void(*_Update)(), void(*_End)())
{
    MSG msg = {};

    // 기본 메시지 루프
    while (WindowLive)
    {
        if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }

        if (nullptr != _Update)
        {
            _Update();
        }
    }

    if (nullptr != _End)
    {
        _End();
    }

    return msg.wParam;
}