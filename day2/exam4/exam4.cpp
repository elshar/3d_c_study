// exam4.cpp : 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include "exam4.h"

#define MAX_LOADSTRING 100

// 전역 변수:
HINSTANCE hInst;                                // 현재 인스턴스입니다.
WCHAR szTitle[MAX_LOADSTRING];                  // 제목 표시줄 텍스트입니다.
WCHAR szWindowClass[MAX_LOADSTRING];            // 기본 창 클래스 이름입니다.

// 이 코드 모듈에 들어 있는 함수의 정방향 선언입니다.
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

    // TODO: 여기에 코드를 입력합니다.

    // 전역 문자열을 초기화합니다.
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_EXAM4, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // 응용 프로그램 초기화를 수행합니다.
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_EXAM4));

    MSG msg;

    // 기본 메시지 루프입니다.
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
//  함수: MyRegisterClass()
//
//  목적: 창 클래스를 등록합니다.
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
//   함수: InitInstance(HINSTANCE, int)
//
//   목적: 인스턴스 핸들을 저장하고 주 창을 만듭니다.
//
//   설명:
//
//        이 함수를 통해 인스턴스 핸들을 전역 변수에 저장하고
//        주 프로그램 창을 만든 다음 표시합니다.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // 인스턴스 핸들을 전역 변수에 저장합니다.

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
//  함수: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  목적:  주 창의 메시지를 처리합니다.
//
//  WM_COMMAND  - 응용 프로그램 메뉴를 처리합니다.
//  WM_PAINT    - 주 창을 그립니다.
//  WM_DESTROY  - 종료 메시지를 게시하고 반환합니다.
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // 메뉴 선택을 구문 분석합니다.
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
            // TODO: 여기에 hdc를 사용하는 그리기 코드를 추가합니다.

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

// 정보 대화 상자의 메시지 처리기입니다.
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
