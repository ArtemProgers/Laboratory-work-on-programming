/*Ввести три числа a, b, c. Для каждого числа найти и вывести на экран 
сумму цифр (использовать функцию). */
#include <stdio.h> //библиотеки
#include <locale.h>
#include <time.h>
#include <stdlib.h>
#pragma warning(disable : 4996) //чтобы не было ошибок
#define _CRT_SECURE_NO_WARNINGS 
int a; //вводимое число

int sumNum(int a) { //функция расчёта суммы цифр числа
    int sum = 0;
    int n = a;
    while (n != 0)
    {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int main() {
    setlocale(LC_ALL, "Russian"); //руссификация текста
    for (int i = 0; i < 3; ++i) //цикл вывода
    {
        printf("Введите целое число : ");
        scanf("%d", &a); //вводим число
        printf("Сумма цифер числа: %d", sumNum(a));
        printf("\n");
    }
    return(0);
}