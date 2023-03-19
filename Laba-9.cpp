/*Ввести натуральное число N. Заменить в его записи четные цифры на 0. */
#include <stdio.h> //библиотеки
#include <math.h>
#include <locale.h>
#include <string>
#pragma warning(disable : 4996) //исключения ошибок ввода-вывода
#define _CRT_SECURE_NO_WARNINGS 
using namespace std; // подключаем пространсва имён
int main()
{
    setlocale(LC_ALL, "Russian"); //перевод на русский
    long int n; // наше число
    printf("Введите число: ");
    scanf("%d", &n); //вводим число
    string s = to_string(n); //преобразуем в строку
    for (int i = 0; i < s.length(); i++) //перебираем всю строку
        ((int)s[i] % 2 == 0 ? s[i] = '0' : s[i]);
    n = stol(s); //строку обратно в число
    printf("%lld", n); //вывод 
    return 0;
}