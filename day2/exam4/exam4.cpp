// exam4.cpp : ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include "exam4.h"

#define MAX_LOADSTRING 100

// ���� ����:
HINSTANCE hInst;                                // ���� �ν��Ͻ��Դϴ�.
WCHAR szTitle[MAX_LOADSTRING];                  // ���� ǥ���� �ؽ�Ʈ�Դϴ�.
WCHAR szWindowClass[MAX_LOADSTRING];            // �⺻ â Ŭ���� �̸��Դϴ�.

// �� �ڵ� ��⿡ ��� �ִ� �Լ��� ������ �����Դϴ�.
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: ���⿡ �ڵ带 �Է��մϴ�.

    // ���� ���ڿ��� �ʱ�ȭ�մϴ�.
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_EXAM4, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // ���� ���α׷� �ʱ�ȭ�� �����մϴ�.
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_EXAM4));

    MSG msg;

    // �⺻ �޽��� �����Դϴ�.
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}



//
//  �Լ�: MyRegisterClass()
//
//  ����: â Ŭ������ ����մϴ�.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_EXAM4));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_EXAM4);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   �Լ�: InitInstance(HINSTANCE, int)
//
//   ����: �ν��Ͻ� �ڵ��� �����ϰ� �� â�� ����ϴ�.
//
//   ����:
//
//        �� �Լ��� ���� �ν��Ͻ� �ڵ��� ���� ������ �����ϰ�
//        �� ���α׷� â�� ���� ���� ǥ���մϴ�.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // �ν��Ͻ� �ڵ��� ���� ������ �����մϴ�.

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  �Լ�: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  ����:  �� â�� �޽����� ó���մϴ�.
//
//  WM_COMMAND  - ���� ���α׷� �޴��� ó���մϴ�.
//  WM_PAINT    - �� â�� �׸��ϴ�.
//  WM_DESTROY  - ���� �޽����� �Խ��ϰ� ��ȯ�մϴ�.
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // �޴� ������ ���� �м��մϴ�.
            switch (wmId)
            {
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            // TODO: ���⿡ hdc�� ����ϴ� �׸��� �ڵ带 �߰��մϴ�.

			SetPixel(hdc, 100, 100, RGB(255, 0, 0));
			SetPixel(hdc, 101, 100, RGB(255, 0, 0));
			SetPixel(hdc, 102, 100, RGB(255, 0, 0));
			SetPixel(hdc, 103, 100, RGB(255, 0, 0));
			SetPixel(hdc, 104, 100, RGB(255, 0, 0));
			SetPixel(hdc, 105, 100, RGB(255, 0, 0));

			SetPixel(hdc, 100, 105, RGB(255, 155, 0));
			SetPixel(hdc, 100, 101, RGB(255, 155, 0));
			SetPixel(hdc, 100, 102, RGB(255, 155, 0));
			SetPixel(hdc, 100, 103, RGB(255, 155, 0));
			SetPixel(hdc, 100, 104, RGB(255, 155, 0));

			SetPixel(hdc, 105, 105, RGB(255, 255, 0));
			SetPixel(hdc, 105, 104, RGB(255, 255, 0));
			SetPixel(hdc, 105, 103, RGB(255, 255, 0));
			SetPixel(hdc, 105, 102, RGB(255, 255, 0));
			SetPixel(hdc, 105, 101, RGB(255, 255, 0));

			SetPixel(hdc, 101, 105, RGB(0, 0, 255));
			SetPixel(hdc, 102, 105, RGB(0, 0, 255));
			SetPixel(hdc, 103, 105, RGB(0, 0, 255));
			SetPixel(hdc, 104, 105, RGB(0, 0, 255));

			SetPixel(hdc, 200, 201, RGB(24, 59, 255));
			SetPixel(hdc, 200, 202, RGB(24, 59, 255));
			SetPixel(hdc, 200, 203, RGB(24, 59, 255));
			SetPixel(hdc, 200, 204, RGB(24, 59, 255));
			SetPixel(hdc, 200, 205, RGB(24, 59, 255));
			SetPixel(hdc, 200, 206, RGB(24, 59, 255));

			SetPixel(hdc, 205, 201, RGB(179, 255, 50));
			SetPixel(hdc, 205, 202, RGB(179, 255, 50));
			SetPixel(hdc, 205, 203, RGB(179, 255, 50));
			SetPixel(hdc, 205, 204, RGB(179, 255, 50));
			SetPixel(hdc, 205, 205, RGB(179, 255, 50));

			SetPixel(hdc, 210, 201, RGB(60, 155, 155));
			SetPixel(hdc, 210, 202, RGB(60, 155, 155));
			SetPixel(hdc, 210, 203, RGB(60, 155, 155));
			SetPixel(hdc, 210, 204, RGB(60, 155, 155));
			SetPixel(hdc, 210, 205, RGB(60, 155, 155));
			SetPixel(hdc, 210, 206, RGB(60, 155, 155));

			SetPixel(hdc, 215, 201, RGB(255, 200, 0));
			SetPixel(hdc, 215, 202, RGB(255, 200, 0));
			SetPixel(hdc, 215, 203, RGB(255, 200, 0));
			SetPixel(hdc, 215, 204, RGB(255, 200, 0));
			SetPixel(hdc, 215, 205, RGB(255, 200, 0));
			SetPixel(hdc, 215, 206, RGB(255, 200, 0));
			SetPixel(hdc, 215, 207, RGB(255, 200, 0));

			SetPixel(hdc, 220, 201, RGB(80, 10, 200));

			SetPixel(hdc, 220, 202, RGB(30, 30, 140));





            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// ���� ��ȭ ������ �޽��� ó�����Դϴ�.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}