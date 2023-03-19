/* Вариант 10 – Составить программу вычисления выражения для введенного Х. */
//#include <iostream>
#include <conio.h> // библиотека ввода-вывода
#include <locale.h> // библиотека локализации текста
#include <math.h> // математическая библиотека
//using namespace std;
const double PI = 3.14; // константа числа Пи
double x; // вводимое значение
double y; // выводимое значение
int main() // основная функция программы
{
    setlocale(LC_ALL, "Rus"); // локализация текста
    //cout << "Введите значение X: \n";
    //cin >> x;
    _cprintf("Введите значение X : \n");
    _cscanf_s("%f", &x);
    double y1 = 1.1 * exp(x); // расчёты данного выражения
    double y2 = sqrt(PI * x);
    double y3 = cos(y2);
    double y4 = fabs(y3) - 0.44;
    float y = y1 + y4;
    //cout << y1 + y4;
    _cprintf("%f", y); //вывод результата
    return (0); //завершение программы
}