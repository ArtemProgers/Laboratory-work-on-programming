//Ввести текст. Исключить из текста все вхождения заданного слова.
#include <stdio.h>  //библиотеки
#include <string.h> 
#include <locale.h>
#include <malloc.h>
#pragma warning(disable : 4996) //чтобы не было ошибок
#define _CRT_SECURE_NO_WARNINGS 
int n = 80;
int k;
//char str[80] = " "; //наш текст
//char sep[80] = " "; //исключаемое слово

void scan(char* str) { //функция ввода
	int i = 0;
	char c;
	k = 1;
	while (k > 0)
	{
		c = getchar();
		if (c != '\n' && i < n) str[i++] = c;
		else str[i] = k = 0;
	}
}

void del(char* str, char* sep) { //функция поиска и удаления слов
	char* istr; // тут начальные адреса частей строки str	
	istr = strtok(str, sep); // Выделение первой части строки

	while (istr != NULL) // Выделение последующих частей
	{
		printf("%s\t", istr); // вывод очередной выделенной части
		istr = strtok(NULL, sep); // выделение очередной части строки
	}
}

int main(void)
{
	setlocale(LC_ALL, "Russian"); //руссификация теста

	//char* str = (char*)malloc(strlen(str) + 1); //выделяем память для массива текста
	//char* sep = (char*)malloc(strlen(sep) + 1); //выделяем память для массива текста исключаемого слова

	/* выделяем массив необходимого размера */
	if (n > 0) k = n + 1;
	else return -1;     // кривой размер массива
	char* str = (char*)malloc(sizeof(char) * k);
	if (!str) return -1;  // памяти нету, выходим

	/* выделяем массив необходимого размера */
	if (n > 0) k = n + 1;
	else return -1;     // кривой размер массива
	char* sep = (char*)malloc(sizeof(char) * k);
	if (!sep) return -1;  // памяти нету, выходим

	printf("Введите текст : "); // вызываем функцию ввода
	scan(str);
	printf("Введите слово : ");
	scan(sep);

	del(str, sep); // вызываем функцию удаления
	free(str); // очищаем память
	free(sep);
	return 0;
}