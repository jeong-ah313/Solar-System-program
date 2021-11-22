#include <windows.h>
#include <stdio.h>
#include <math.h>

#define BOX_SIZE 800
#define SUN_R 15        // 태양의 반지름 
#define PI 3.141592654     //PI값

int main(void)
{
    HWND hwnd = GetForegroundWindow();     // 현재 윈도우의  핸들을 구한다. 
    HDC hdc = GetWindowDC(hwnd);           // 윈도우의 디바이스 컨테스트(Device context)의 핸들을 구하여 윈도우에 접근한다. 

    //박스
     // 배경을 흰색으로 설정(테두리도 흰색)
    SelectObject(hdc, CreatePen(PS_SOLID, 5, RGB(255, 255, 255)));
    SelectObject(hdc, CreateSolidBrush(RGB(255, 255, 255)));
    //박스 만들기
    Rectangle(hdc, 0, 0, +BOX_SIZE, BOX_SIZE);

    //원(태양)
     // 그리는 펜의 테두리 색은 흰색, 채우는 색은 빨강색으로 설정
    SelectObject(hdc, CreatePen(PS_SOLID, 1, RGB(255, 255, 255)));
    SelectObject(hdc, CreateSolidBrush(RGB(255, 0, 0)));
    // 원을 그린다. 
    Ellipse(hdc, BOX_SIZE / 2 - SUN_R, BOX_SIZE / 2 - SUN_R, BOX_SIZE / 2 + SUN_R, BOX_SIZE / 2 + SUN_R);


    int x = BOX_SIZE / 2; //태양의 중점좌표
    int y = BOX_SIZE / 2;


    //변수선언
    //태양에서 각 행성들까지의 거리를 나타내주는 변수
    int i;
    int r1; //수성
    int r2; //금성
    int r3; //지구
    int r4; //화성
    int r5; //목성
    int r6; //토성

    //각 행성들의 좌표를 나타내주는 변수
    double x1, y1;
    double x2, y2;
    double x3, y3;
    double x4, y4;
    double x5, y5;
    double x6, y6;

    for (i = 0; i <= 360; i++)
    {
        // 태양과 행성간의 거리
           /* (지구가 1cm일때를 기준으로, 80을 곱해주었으며
           목성과 토성의 경우에는 너무 멀리있어 사각형에 들어오지 않아
           각각 40,35 만큼만 곱해주었습니다.) */
        r1 = 0.3 * 80;
        r2 = 0.6 * 80;
        r3 = 1 * 80;
        r4 = 1.5 * 80;
        r5 = 6 * 40;
        r6 = 10 * 35;

        //좌표
        x1 = x + r1 * cos(4.15 * i * PI / 180);    //수성의 좌표 
        y1 = y - r1 * sin(4.15 * i * PI / 180);     //반시계방향으로 돌아야하기 때문에 -부호 사용

        x2 = x + r2 * cos(1.62 * i * PI / 180);    //금성의 좌표
        y2 = y - r2 * sin(1.62 * i * PI / 180);

        x3 = x + r3 * cos(i * PI / 180);    //지구의 좌표
        y3 = y - r3 * sin(i * PI / 180);

        x4 = x + r4 * cos(0.53 * i * PI / 180);    //화성의 좌표
        y4 = y - r4 * sin(0.53 * i * PI / 180);

        x5 = x + r5 * cos(0.084 * i * PI / 180);    //목성의 좌표
        y5 = y - r5 * sin(0.084 * i * PI / 180);

        x6 = x + r6 * cos(0.034 * i * PI / 180);    //토성의 좌표
        y6 = y - r6 * sin(0.034 * i * PI / 180);


        if (r1 == 0.3 * 80)
        {
            // 그리는 수성의 채우는 색은 주황색으로 설정
            SelectObject(hdc, CreatePen(PS_SOLID, 3, RGB(255, 255, 255)));
            SelectObject(hdc, CreateSolidBrush(RGB(255, 94, 0)));
            Ellipse(hdc, x1 - 10 * 0.4, y1 - 10 * 0.4, x1 + 10 * 0.4, y1 + 10 * 0.4);

        }

        if (r2 == 0.6 * 80)
        {
            // 그리는 금성의 채우는 색은 노랑색으로 설정 
            SelectObject(hdc, CreatePen(PS_SOLID, 5, RGB(255, 255, 255)));
            SelectObject(hdc, CreateSolidBrush(RGB(255, 228, 0)));
            Ellipse(hdc, x2 - 10 * 0.9, y2 - 10 * 0.9, x2 + 10 * 0.9, y2 + 10 * 0.9);

        }

        if (r3 == 1 * 80)
        {
            // 그리는 지구의 채우는 색은 연두색으로 설정 
            SelectObject(hdc, CreatePen(PS_SOLID, 5, RGB(255, 255, 255)));
            SelectObject(hdc, CreateSolidBrush(RGB(171, 242, 0)));
            Ellipse(hdc, x3 - 10, y3 - 10, x3 + 10, y3 + 10);  //지구의 크기를 기준으로 다른 행성의 비율도 맞춤
                                                               //목성과 토성의 크기는 너무 커서 각각 2, 1.5배 해줌

        }

        if (r4 == 1.5 * 80)
        {
            // 그리는 화성의 채우는 색은 파랑색으로 설정 
            SelectObject(hdc, CreatePen(PS_SOLID, 5, RGB(255, 255, 255)));
            SelectObject(hdc, CreateSolidBrush(RGB(0, 0, 255)));
            Ellipse(hdc, x4 - 10 * 0.5, y4 - 10 * 0.5, x4 + 10 * 0.5, y4 + 10 * 0.5);

        }

        if (r5 == 6 * 40)
        {
            // 그리는 목성의 채우는 색은 분홍색으로 설정 
            SelectObject(hdc, CreatePen(PS_SOLID, 5, RGB(255, 255, 255)));
            SelectObject(hdc, CreateSolidBrush(RGB(255, 0, 127)));
            Ellipse(hdc, x5 - 10 * 2, y5 - 10 * 2, x5 + 10 * 2, y5 + 10 * 2);

        }

        if (r6 == 10 * 35)
        {
            // 그리는 토성의 채우는 색은 보라색으로 설정 
            SelectObject(hdc, CreatePen(PS_SOLID, 8.5, RGB(255, 255, 255)));
            SelectObject(hdc, CreateSolidBrush(RGB(128, 65, 217)));
            Ellipse(hdc, x6 - 10 * 1.5, y6 - 10 * 1.5, x6 + 10 * 1.5, y6 + 10 * 1.5);

        }
        Sleep(20);
    }

    return 0;
}