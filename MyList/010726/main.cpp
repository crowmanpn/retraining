#include <iostream>
#include "Shape.h"
#include "Circle.h"


#include <windows.h>
#include <cmath>

Circle* globCircle = nullptr;

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
    case WM_PAINT: {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hwnd, &ps);

        //Рисуем окружность
        int left = globCircle->GetCenter().m_x - globCircle->GetRad();
        int top = globCircle->GetCenter().m_y - globCircle->GetRad();
        int right = globCircle->GetCenter().m_x + globCircle->GetRad();
        int bottom = globCircle->GetCenter().m_y + globCircle->GetRad();

        Ellipse(hdc, left, top, right, bottom);  // лево, верх, право, низ
        
       
        
        EndPaint(hwnd, &ps);
        return 0;
    }
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    case WM_CREATE:
         globCircle=new Circle(50,Point(30,30));
         break;
    case WM_KEYDOWN:
        switch (wParam)
        {
        case VK_LEFT:
            globCircle->MoveShape(direction::left);
            break;
        case VK_RIGHT:
            globCircle->MoveShape(direction::right);
            break;
        case VK_UP:
            globCircle->MoveShape(direction::top);
            break;
        case VK_DOWN:
            globCircle->MoveShape(direction::down);
            break;
        case 'r':

        case 'R':
            globCircle->MoveShape(direction::down);
            break;
        }
         //globCircle->MoveShape()
    }
    InvalidateRect(hwnd, NULL, TRUE);
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
    LPSTR lpCmdLine, int nCmdShow) {
    WNDCLASS wc = {};
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = L"CircleClass";
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);

    RegisterClass(&wc);

    HWND hwnd = CreateWindowEx(0, L"CircleClass", L"Окружность",
        WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT,
        800, 600, NULL, NULL, hInstance, NULL);

    ShowWindow(hwnd, nCmdShow);

    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}



