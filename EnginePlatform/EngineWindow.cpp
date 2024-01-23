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

void EngineWindow::Open(std::string_view _Title)
{
    // ������ ���� �ʱ�ȭ
    WNDCLASSEXA wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc = WndProc;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = hInstance;
    wcex.hIcon = nullptr; // ������
    wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wcex.lpszMenuName = nullptr; // �޴���
    wcex.lpszClassName = "DefaultWindow";
    wcex.hIconSm = nullptr;

    RegisterClassExA(&wcex);
    
    // ������ â ����
    HWND hWnd = CreateWindowA("DefaultWindow", _Title.data(), WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

    if (!hWnd)
    {
        MsgBoxAssert("Creating Window Fail.");
        return;
    }

    hDc = GetDC(hWnd);

    ShowWindow(hWnd, SW_SHOW);
    UpdateWindow(hWnd);
}

void EngineWindow::Init(HINSTANCE _hInst)
{
    hInstance = _hInst;
}

unsigned __int64 EngineWindow::WindowMessageLoop()
{
    MSG msg = {};

    // �⺻ �޽��� �����Դϴ�:
    while (WindowLive)
    {
        if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return msg.wParam;
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
        // ������ �����
        WindowLive = false;
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}