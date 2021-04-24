#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <iostream>


enum eChislaCode_
{
    eChislaCode_A,
    eChislaCode_B,
    eChislaCode_C
};

float Discrement(float iChisla[3])
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
    float fDis = Discrement(fChisla);
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