#include <stdio.h>
#include <conio.h>

enum eChislaCode
{
    eChislaCode_A,
    eChislaCode_B,
    eChislaCode_C
};

double Discriminant(double p_arr[3])
{
    return ((p_arr[eChislaCode_B] * p_arr[eChislaCode_B]) + (-4 * p_arr[eChislaCode_A] * p_arr[eChislaCode_C]));
}

int main(void)
{
    printf("====== ��蠫�� �ࠢ����� ======\t| Coder: Tim4ukys\n");

    double fChisla[3];
    memset(fChisla, 0, sizeof(double)*3);

    for (int i = 0; i < 3; i++)
    {
        printf("������ �᫮ %c: ", 'A' + i);
        scanf("%f", fChisla + i);
    }

    double fDis = Discriminant(fChisla);
    printf("======\n���ਬ����� ࠢ��: %f\n�⢥�: ", fDis);

    if (fDis < 0.f)
    {
        printf("��襭�� ���.");
    }
    else
    {
        if (fDis == 0.0)
        {
            printf("X = %f", (-1 * fChisla[eChislaCode_B]) / (2 * fChisla[eChislaCode_A]));
        }
        else 
        {
            printf("X1 = %f | X2 = %f", (-1 * fChisla[eChislaCode_B] + sqrt(fDis)) / (2 * fChisla[eChislaCode_A]), 
                (-1 * fChisla[eChislaCode_B] - sqrt(fDis)) / (2 * fChisla[eChislaCode_A]));
        }
    }

    printf("\n\n������ �� ENTER, �⮡� ������� �ணࠬ��...");
    while (!_kbhit() || getchar() != '\n') {}

    return 0;
}