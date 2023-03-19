//Ввести текст. Исключить из текста все вхождения заданного слова.
#include <stdio.h>  //библиотеки
#include <string.h> 
#include <locale.h>
#pragma warning(disable : 4996) //чтобы не было ошибок
#define _CRT_SECURE_NO_WARNINGS 
char str[80] = " "; //наш текст
char sep[80] = " "; //исключаемое слово

void scan() { //функция ввода
	setlocale(LC_ALL, "Russian"); //руссификация теста
	printf("Введите текст : ");
	gets_s(str); //вводим текст
	printf("Введите слово : ");
	gets_s(sep); //вводим слово
}
void del() { //функция поиска и удаления слов
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
	scan(); //вызываем функции
	del();
	return 0;
}

//То же самое только на С++ раюотает намного лучше
/*
#include <iostream> //библиотеки
#include <sstream>
#include <string>
#include <vector>
#include <locale.h>
using namespace std; //пространство имён
string str; // текст
string slovo; //исключаемое слово

void scan() { //функция ввода
	setlocale(LC_ALL, "Russian"); //руссификация текста
	cout << "Введите текст: ";
	getline(cin, str); //вводим текст
	cout << "Введите слово: ";
	getline(cin, slovo); //вводим слово
}

void del() { //функция поиска и удаления слов
	vector <string> vecstr; //строковый вектор изменённого теста
	string word;
	stringstream s(str); //получаем всё содержимое строки в поток для работы с текстом

	while (s >> word)
		vecstr.push_back(word); //переписываем текст в строковый вектор

	for (int i = 0; i < vecstr.size(); i++) { //перебор вектора
		if (vecstr[i] == slovo) vecstr[i] = ' '; //если нашли введённое слово, то удаляем его
		cout << vecstr[i] + " "; //пословно выводим текст
	}
}

int main() {
	scan(); //вызываем функции
	del();
	cin.get();
	return 0; //конец
}
*/