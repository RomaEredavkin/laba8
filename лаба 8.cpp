// лаба 8.cpp : Определяет точку входа для приложения.
//

#include "framework.h"
#include "лаба 8.h"

#define MAX_LOADSTRING 100

// Глобальные переменные:
HINSTANCE hInst;                                // текущий экземпляр
WCHAR szTitle[MAX_LOADSTRING];                  // Текст строки заголовка
WCHAR szWindowClass[MAX_LOADSTRING];            // имя класса главного окна

// Отправить объявления функций, включенных в этот модуль кода:
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

    // TODO: Разместите код здесь.

    // Инициализация глобальных строк
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_MY8, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Выполнить инициализацию приложения:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_MY8));

    MSG msg;

    // Цикл основного сообщения:
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
//  ФУНКЦИЯ: MyRegisterClass()
//
//  ЦЕЛЬ: Регистрирует класс окна.
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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_MY8));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_MY8);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   ФУНКЦИЯ: InitInstance(HINSTANCE, int)
//
//   ЦЕЛЬ: Сохраняет маркер экземпляра и создает главное окно
//
//   КОММЕНТАРИИ:
//
//        В этой функции маркер экземпляра сохраняется в глобальной переменной, а также
//        создается и выводится главное окно программы.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // Сохранить маркер экземпляра в глобальной переменной

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
void house(HDC hdc) {
    MoveToEx(hdc, 150, 350, NULL);
    LineTo(hdc, 275, 250);
    LineTo(hdc, 400, 350);
    LineTo(hdc, 400, 525);
    LineTo(hdc, 150, 525);
    LineTo(hdc, 150, 350);
    LineTo(hdc, 400, 350);
    MoveToEx(hdc, 225, 400, NULL);
    LineTo(hdc, 225, 475);
    LineTo(hdc, 325, 475);
    LineTo(hdc, 325, 400);
    LineTo(hdc, 225, 400);
    MoveToEx(hdc, 275, 400, NULL);
    LineTo(hdc, 275, 475);
    MoveToEx(hdc, 275, 425, NULL);
    LineTo(hdc, 325, 425);
} 
void draweCar(HDC hdc) {
    HPEN hPen = CreatePen(PS_SOLID, 3, RGB(128, 0, 0));
    SelectObject(hdc, hPen);
    HBRUSH hBrush;
    hBrush = CreateSolidBrush(RGB(255, 128, 67));
    SelectObject(hdc, hBrush);
    Rectangle(hdc, 50, 200, 300, 250);
    MoveToEx(hdc, 100, 200, NULL);
    LineTo(hdc, 150, 150);
    LineTo(hdc, 250, 150);
    LineTo(hdc, 300, 200);
    hPen = CreatePen(PS_SOLID, 7, RGB(0, 0, 128));
    SelectObject(hdc, hPen);
    hBrush = CreateHatchBrush(HS_FDIAGONAL, RGB(255, 0, 0));
    SelectObject(hdc, hBrush);
    Ellipse(hdc, 75, 225, 125, 275);
    hPen = CreatePen(PS_SOLID, 7, RGB(0, 128, 0));
    SelectObject(hdc, hPen);
    hBrush = CreateHatchBrush(HS_FDIAGONAL, RGB(0, 255, 0));
    SelectObject(hdc, hBrush);
    Ellipse(hdc, 225, 225, 275, 275);
} 
void bush(HDC hdc) {
    HPEN hPen = CreatePen(PS_SOLID, 2, RGB(0, 210, 0));//дерево
    SelectObject(hdc, hPen);
    int x1 = 0;
    int y1 = 250;
    int x2 = 100;
    int y2 = 250;
    
    do {
        MoveToEx(hdc, x1, y1, NULL);
        LineTo(hdc, x2, y2);
        x1 += 5;
        y1 -= 10;

    } while (x1 <= 100);
    x1 = 100;
    y1 = 50;
    do {
        MoveToEx(hdc, x1, y1, NULL);
        LineTo(hdc, x2, y2);
        x1 += 5;
        y1 += 10;

    } while (x1 <= 200);
    x1 = 150;
    y1 = 0;
    x2 = 150;
    y2 = 100;
} 
void tree(HDC hdc) {
    HPEN hPen = CreatePen(PS_SOLID, 4, RGB(23, 181, 74));//елка
    SelectObject(hdc, hPen);
    MoveToEx(hdc, 450, 525, NULL);
    LineTo(hdc, 525, 450);
    LineTo(hdc, 600, 525);
    LineTo(hdc, 450, 525);
    MoveToEx(hdc, 575, 450, NULL);
    LineTo(hdc, 475, 450);
    LineTo(hdc, 525, 400);
    LineTo(hdc, 575, 450);
    MoveToEx(hdc, 550, 400, NULL);
    LineTo(hdc, 500, 400);
    LineTo(hdc, 525, 375);
    LineTo(hdc, 550, 400);
} 
void tree2(HDC hdc) {
    HPEN hPen = CreatePen(PS_SOLID, 3, RGB(0, 250, 0));//дерево
    SelectObject(hdc, hPen);
    MoveToEx(hdc, 75, 350, NULL);
    LineTo(hdc, 75, 525);
    MoveToEx(hdc, 100, 475, NULL);
    LineTo(hdc, 75, 500);
    MoveToEx(hdc, 25, 450, NULL);
    LineTo(hdc, 75, 490);
    MoveToEx(hdc, 125, 430, NULL);
    LineTo(hdc, 75, 475);
    MoveToEx(hdc, 25, 425, NULL);
    LineTo(hdc, 75, 460);
    MoveToEx(hdc, 130, 400, NULL);
    LineTo(hdc, 75, 440);
    MoveToEx(hdc, 25, 380, NULL);
    LineTo(hdc, 75, 420);
    MoveToEx(hdc, 100, 375, NULL);
    LineTo(hdc, 75, 400);
    MoveToEx(hdc, 55, 355, NULL);
    LineTo(hdc, 75, 375);
}
void stable(HDC hdc) {
    HPEN hPen = CreatePen(PS_SOLID, 5, RGB(30, 39, 210));//конюшня
    SelectObject(hdc, hPen);
    MoveToEx(hdc, 650, 525, NULL);
    LineTo(hdc, 950, 525);
    LineTo(hdc, 950, 225);
    LineTo(hdc, 650, 225);
    LineTo(hdc, 650, 525);
    MoveToEx(hdc, 650, 225, NULL);
    LineTo(hdc, 800, 75);
    LineTo(hdc, 950, 225);
    MoveToEx(hdc, 750, 525, NULL);
    LineTo(hdc, 750, 275);
    LineTo(hdc, 850, 275);
    LineTo(hdc, 850, 525);
    MoveToEx(hdc, 750, 475, NULL);
    LineTo(hdc, 850, 475);
    MoveToEx(hdc, 850, 425, NULL);
    LineTo(hdc, 750, 425);
    MoveToEx(hdc, 800, 425, NULL);
    LineTo(hdc, 800, 475);
    MoveToEx(hdc, 950, 225, NULL);
    LineTo(hdc, 950, 125);
    LineTo(hdc, 900, 125);
    LineTo(hdc, 900, 175);
} 
void tree3(HDC hdc) {
    int x1 = 400, y1 = 150;
    int x2 = 500, y2 = 250;
    HPEN hPen = CreatePen(PS_SOLID, 3, RGB(226, 255, 23));
    SelectObject(hdc, hPen);
    do {//куст
        MoveToEx(hdc, x1, y1, NULL);
        LineTo(hdc, x2, y2);
        x1 += 5;
    } while (x1 <= 600);
} 
void fance(HDC hdc) {
    int x1 = 150;
    int y1 = 0;
    int x2 = 150;
    int y2 = 100;
    HPEN hPen = CreatePen(PS_SOLID, 3, RGB(226, 0, 3));//забор
    SelectObject(hdc, hPen);
    do {
        MoveToEx(hdc, x1, y1, NULL);
        LineTo(hdc, x2, y2);
        x1 += 5;
        x2 += 5;

    } while (x1 <= 450);
} 
void ladder(HDC hdc) {
    HPEN hPen = CreatePen(PS_SOLID, 3, RGB(52, 80, 24));//лестница
    SelectObject(hdc, hPen);
    int x1 = 1000;
    int y1 = 525;
    int x2 = 1000;
    int y2 = 625;
    do {
        MoveToEx(hdc, x1, y1, NULL);
        LineTo(hdc, x2, y2);
        x1 += 100;
        x2 += 100;
        y1 -= 100;
        y2 -= 100;
    } while (x1 <= 1500);
    x1 = 1000;
    y1 = 525;
    x2 = 1100;
    y2 = 525;
    do {
        MoveToEx(hdc, x1, y1, NULL);
        LineTo(hdc, x2, y2);
        x1 += 100;
        x2 += 100;
        y1 -= 100;
        y2 -= 100;
    } while (x1 <= 1500);
    x1 = 1000;
    y1 = 0;
    x2 = 1000;
    y2 = 25;
    hPen = CreatePen(PS_SOLID, 3, RGB(0, 200, 0));//трава
    SelectObject(hdc, hPen);
    do {
        MoveToEx(hdc, x1, y1, NULL);
        LineTo(hdc, x2, y2);
        x1 += 5;
        x2 += 5;

    } while (x1 <= 1300);
} 
void snowman(HDC hdc) {
    HPEN hPen = CreatePen(PS_SOLID, 3, RGB(25, 25, 25));
    SelectObject(hdc, hPen);

    HBRUSH hBrush = CreateSolidBrush(RGB(255, 128, 67));
    SelectObject(hdc, hBrush);
    Ellipse(hdc, 350, 250, 500, 400);
    SelectObject(hdc, hBrush);
    Ellipse(hdc, 375, 200, 475, 300);
    SelectObject(hdc, hBrush);
    Ellipse(hdc, 400, 200, 450, 150);
    SelectObject(hdc, hBrush);
    hPen = CreatePen(PS_SOLID, 3, RGB(25, 0, 0));
    SelectObject(hdc, hPen);
    hBrush = CreateHatchBrush(HS_FDIAGONAL, RGB(25, 25, 25));
    SelectObject(hdc, hBrush);
    Rectangle(hdc, 410, 120, 440, 150);
    Ellipse(hdc, 410, 169, 408, 166);
    Ellipse(hdc, 430, 169, 428, 166);
    MoveToEx(hdc, 380, 245, NULL);
    LineTo(hdc, 330, 240);
    MoveToEx(hdc, 470, 245, NULL);
    LineTo(hdc, 520, 240);
    MoveToEx(hdc, 418, 175, NULL);
    LineTo(hdc, 415, 185);
    hPen = CreatePen(PS_SOLID, 3, RGB(25, 25, 25));
    SelectObject(hdc, hPen);
    hBrush = CreateHatchBrush(HS_FDIAGONAL, RGB(0, 255, 224));
    SelectObject(hdc, hBrush);
    Rectangle(hdc, 600, 300, 800, 500);
    hBrush = CreateSolidBrush(RGB(245, 25, 24));
    SelectObject(hdc, hBrush);
    Rectangle(hdc, 800, 450, 1200, 500);
    hBrush = CreateHatchBrush(HS_FDIAGONAL, RGB(124, 255, 0));
    SelectObject(hdc, hBrush);
    Ellipse(hdc, 650, 450, 750, 550);
    Ellipse(hdc, 1000, 450, 1100, 550);
    hBrush = CreateHatchBrush(HS_FDIAGONAL, RGB(12, 195, 58));
    SelectObject(hdc, hBrush);
    Rectangle(hdc, 800, 100, 850, 150);
    hBrush = CreateHatchBrush(HS_FDIAGONAL, RGB(234, 225, 56));
    SelectObject(hdc, hBrush);
    Rectangle(hdc, 810, 150, 840, 200);

}
//
//  ФУНКЦИЯ: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  ЦЕЛЬ: Обрабатывает сообщения в главном окне.
//
//  WM_COMMAND  - обработать меню приложения
//  WM_PAINT    - Отрисовка главного окна
//  WM_DESTROY  - отправить сообщение о выходе и вернуться
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // Разобрать выбор в меню:
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
            // TODO: Добавьте сюда любой код прорисовки, использующий HDC...
            bush(hdc);
            house(hdc); 
            draweCar(hdc);
            tree(hdc);
            tree2(hdc);
            stable(hdc);
            tree3(hdc);  
            fance(hdc); 
            ladder(hdc);
            snowman(hdc);
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

// Обработчик сообщений для окна "О программе".
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
