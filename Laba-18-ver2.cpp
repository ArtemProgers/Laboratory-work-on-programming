/*Если  разность  максимального  и  минимального  элементов  массива
A(n,m) больше 20, то уменьшить все положительные элементы вдвое,
иначе  –  найти  произведение  отрицательных  элементов  каждого
столбца. */
#include <stdio.h> //библиотеки
#include <locale.h>
#include <time.h>
#include <stdlib.h>
#pragma warning(disable : 4996) //чтобы не было ошибок
#define _CRT_SECURE_NO_WARNINGS 
//int a[5][5]; //наш массив
int i, j; // строки и столбцы
int pr = 0; //флаг
int size = 5; //размер

void umenshit(int** a) { //функция уменьшения положит. элем.
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			if (a[i][j] > 0) a[i][j] = a[i][j] / 2;
}

void umnogenie(int** a) { //функция произведения отриц. элем.
	int prois = 1;
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			if (a[i][j] < 0) prois = prois * abs(a[i][j]);
	printf("Произведение отрицательных элементов: ");
	printf("%d", &prois);
	printf("\n");
}

void raschet(int** a) {
	// Считаем минимальный и максимальный
	int min = a[0][0];// берем самый первый элемент массива и считаем, что он минимальный.
	int max = a[0][0];// и он же максимальный. 

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (a[i][j] < min) min = a[i][j];
			if (a[i][j] > max) max = a[i][j];
		}
	}
	if (max - min > 20) umenshit(a);
	else umnogenie(a);

}
void print(int** a) { //функция вывода массива в виде таблицы
	int stro, stol;
	for (stro = 0; stro < size; stro++, putchar('\n'))
		for (stol = 0; stol < size; stol++)
			printf(" %d", a[stro][stol]);
	printf("\n");
}
int main() {
	setlocale(LC_ALL, "Russian"); //русский текст
	
	int** a = (int**)malloc(sizeof(int*) * size); //выделяем память для двухмерного массива
	for (i = 0; i < size; i++)
		a[i] = (int*)malloc(sizeof(int*) * size);

	while (!(pr == 1 || pr == 2)) {  //выбор режима ручной/автоматический ввод
		printf("Введите 1 - ручной ввод, 2 - автоматический \n");
		scanf("%d", &pr);
	}
	printf("Второй раз\n");
	while (1) {
		printf("Введите 1 - ручной ввод, 2 - автоматический \n");
		scanf("%d", &pr);
		if (pr == 1 || pr == 2) break;
	}
	if (pr == 2) { //автоматический ввод
		srand(time(NULL));
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++)
				//a[i][j] = 1 + rand() % 100;
				a[i][j] = -100 + rand() % 201;
		}
	}
	if (pr == 1) { //ручной ввод
		printf("Введите элементы массива: \n");
		for (int i = 0; i < size; i++) //проход столбцов
			for (int j = 0; j < size; j++) //проход строк
				scanf("%d", &a[i][j]);
	}
	print(a); //вывод введённого массива
	raschet(a); //расчёты по условию задачи
	print(a); //вывод обработанного массива
	// освобождение памяти
	free(a);
	return(0); //конец программы
}