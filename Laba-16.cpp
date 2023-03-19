/*Дан  массив  A(n).Переместить  его  элементы  так, чтобы  в  конце
массива были все отрицательные числа, сохранив при этом порядок
следования  отдельно  для  отрицательных  и  отдельно  для  нулевых  и
положительных  элементов.Дополнительный  массив  не  использо -
вать.*/
#include <stdio.h> //библиотеки
#include <locale.h>
#include <time.h>
#include <stdlib.h>
#pragma warning(disable : 4996) //чтобы не было ошибок
#define _CRT_SECURE_NO_WARNINGS 
int a[10]; //наш массив
int i, j; // для счётчика
int pr = 0; //флаг
int size = sizeof(a) / sizeof(int); //вычисление размера массива

void shift1_left_sequence(int* seq, int size) // функция сдвига влево
{
	int clos = *seq;
	for (int i = 1; i < size; ++i)
		seq[i - 1] = seq[i];
	seq[size - 1] = clos;
}

void print(int* a) // функция вывода
{
	int z;
	for (z = 0; z < size; z++) printf("%d%s", a[z], " ");
	printf("%s", "\n");
}

int main() {
	setlocale(LC_ALL, "Russian"); //русский текст
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
		for (int i = 0; i < size; i++) a[i] = -100 + rand() % 201;
	}
	if (pr == 1) { //ручной ввод
		printf("Введите элементы массива: \n");
		for (int j = 0; j < size; j++) scanf("%d", &a[j]);
	}

	for (int i = 0, j = 0; i < size; i++) //перебор массива с условием 
	{
		if (a[j] < 0)
			shift1_left_sequence(a + j, size - j);
		else
			++j;
	}
	print(a);
	return(0);
}