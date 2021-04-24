/*
    MIT License

    Copyright (c) 2021 Tim4ukys

    Permission is hereby granted, free of charge, to any person obtaining a copy
    of this software and associated documentation files (the "Software"), to deal
    in the Software without restriction, including without limitation the rights
    to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
    copies of the Software, and to permit persons to whom the Software is
    furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included in all
    copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
    SOFTWARE.
*/
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <iostream>


enum eChislaCode_
{
    eChislaCode_A,
    eChislaCode_B,
    eChislaCode_C
};

float Discriminant(float iChisla[3])
{
    return ((iChisla[eChislaCode_B] * iChisla[eChislaCode_B]) + (-4 * iChisla[eChislaCode_A] * iChisla[eChislaCode_C]));
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::cout << "====== Решалка Уравнений ======      | Coder: Tim4ukys" << std::endl;

    float fChisla[3]{/* 1.f, 1.f, 1.f */};

    std::cout << "Введи число A: ";
    std::cin >> fChisla[eChislaCode_A];

    std::cout << "Введи число B: ";
    std::cin >> fChisla[eChislaCode_B];

    std::cout << "Введи число C: ";
    std::cin >> fChisla[eChislaCode_C];

    std::cout << "======" << std::endl << "Дискриминант равен: ";
    float fDis = Discriminant(fChisla);
    std::cout << fDis << std::endl << "Ответ: ";

    if (fDis < 0.f)
        std::cout << "Решения нет." << std::endl;
    else
    {
        if (fDis == 0.f)
            std::cout << "X = " << ((-1 * fChisla[eChislaCode_B]) / (2 * fChisla[eChislaCode_A]));
        else
            std::cout << "X1 = " << ((-1 * fChisla[eChislaCode_B] + sqrt(fDis)) / (2 * fChisla[eChislaCode_A]))
                      << " | X2 = " << ((-1 * fChisla[eChislaCode_B] - sqrt(fDis)) / (2 * fChisla[eChislaCode_A]));

    }

    std::cout << "\n\nНажми на END чтобы закрыть программу ";
    for (int i = 0; i < 4; Sleep(50))
    {
        if (i == 0)
            std::cout << "\rНажми на END чтобы закрыть программу \\" << std::flush;
        else if (i == 1)
            std::cout << "\rНажми на END чтобы закрыть программу —" << std::flush;
        else if (i == 2)
            std::cout << "\rНажми на END чтобы закрыть программу /" << std::flush;
        else if (i == 3) {
            i = -1;
            std::cout << "\rНажми на END чтобы закрыть программу |" << std::flush;
        }
        i++;

        if (GetAsyncKeyState(VK_END))
            break;
    }

    return 0;
}