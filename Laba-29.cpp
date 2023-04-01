//Вариант-10
//Описать структуру с именем NOTE, содержащую следующие поля :
//•	фамилия, имя;
//•	номер телефона;
//•	дата рождения(массив из трех чисел).
//Написать программу, выполняющую следующие действия :
//•	ввод с клавиатуры данных в массив, состоящий из восьми элементов типа NOTE(записи должны быть размещены по алфавиту);
//•	вывод на экран информации о людях, чьи дни рождения приходятся на месяц, значение которого введено с клавиатуры(если таких нет, вывести соответствующее сообщение).

#define _CRT_SECURE_NO_WARNINGS //отключаем ошибки компилятора
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_NONSTDC_NO_DEPRECATE
#include <stdio.h>
#include <conio.h>
#include <windows.h> //библиотеки
#include <stdlib.h>
#include <locale.h>
#include <iostream>
#pragma warning(suppress : 4996)

struct Note  //структура
{
	char fio[30];  // фамилия и имя
	char telnumb[30]; //номер телефона
	int bdate[30];  //дата рождения
};

void write_struct(int n, struct Note* NOTE) { //функция заполнения структуры
	for (int i = 0; i < n; i++) 
	{
		printf_s(" %d Введите фамилию и имя: ", i + 1);
		std::cin.ignore(); std::cin.getline(NOTE[i].fio, 30);
		printf_s(" Введите номер телефона: "); scanf_s(" %s", &(NOTE[i].telnumb), 30);
		for (int j = 0; j < 3; j++)
		{
			printf_s(" Введите день рождения: "); scanf_s(" %d", &(NOTE[i].bdate[j++]));
			printf_s(" Введите месяц рождения: "); scanf_s(" %d", &(NOTE[i].bdate[j++]));
			printf_s(" Введите год рождения: "); scanf_s(" %d", &(NOTE[i].bdate[j]));
		}
		printf_s("\n");
	}
}

void file_write(int n, struct Note* NOTE) { //функция записи содержимого структур в файл
	FILE* File = fopen("file.txt", "w");
	if (!File) printf_s("ОШИБКА! Файл file.txt не найден! \n");
	else {
		for (int i = 0; i < n; i++) {
			fputs(NOTE[i].fio, File); fputs("\n", File);
			fputs(NOTE[i].telnumb, File); fputs("\n", File);
			for (int j = 0; j < 3; j++) fprintf_s(File, "%d.", NOTE[i].bdate[j]);
			fputs("\n\n", File);
		}
		fclose(File);
		printf_s(" Данные записаны в файл file.txt \n\n");
	}
}

void upor_print(int n, struct Note* NOTE) { //функция упорядоченного вывода записей структуры
	printf_s(" Записи упорядоченные сортировкой:\n\n");
	printf_s(" Фамилия и имя:          Номер телефона:          Дата рождения: \n");
	for (int i = 0; i < n; i++) 
	{
		printf_s(" -----------------------------------------------------------------\n");
		printf_s(" %s", &(NOTE[i].fio));
		printf_s(" %20s", &(NOTE[i].telnumb)); printf_s("              ");
		for (int j = 0; j < 3; j++) printf_s(" %d.", (NOTE[i].bdate[j]));
		printf_s("\n");
	}
	printf_s("\n\n");
}

void zapros(int n, struct Note* NOTE) { //функция вывода данных по запросу месяца рождения
	bool not_found; //флаг
	int month; //месяц рождения
	printf_s("\n Информация о людях, родившихся в месяц, который введён с клавиатуры");
	while (true)  //выводим данные по запросу
	{
		printf_s("\n Введите месяц или 0 для окончания:");
		printf_s("\n");
		scanf_s(" %d", &month);
		if (month == 0) break;
		not_found = true;
		for (int i = 0; i < n; i++) {
			if (NOTE[i].bdate[1] == month)
			{
				printf_s(" Фамилия и имя:          Номер телефона:          Дата рождения: \n");
				printf_s(" -----------------------------------------------------------------\n");
				printf_s(" %s", &(NOTE[i].fio));
				printf_s(" %20s", &(NOTE[i].telnumb)); printf_s("              ");
				for (int j = 0; j < 3; j++) printf_s("%d.", (NOTE[i].bdate[j]));
				printf_s("\n");
				not_found = false;
				printf_s("\n\n");
			}
		}
		if (not_found) printf_s(" Таких людей нет! \n\n");
	}
}

int compare(const void* note1, const void* note2) //функция сортировки
{
	return strcmp((reinterpret_cast<const Note*>(note1))->fio,
		(reinterpret_cast<const Note*>(note2))->fio);
}

int main(int argc, char* argv[]) {
	setlocale(LC_ALL, "Russian"); //руссификация текста
	int n; //количество структур
	printf_s(" Введите количество структур NOTE: "); scanf_s(" %d", &n); //ввод количества структур
	printf_s("\n");	
	Note* NOTE = new Note[n]; //динамическая память под массив структур
	write_struct(n, NOTE); //заполнение структуры
	file_write(n, NOTE); //запись структуры в файл
	qsort(NOTE, n, sizeof(Note), compare); //передача на сортировку
	upor_print(n, NOTE); //вывод в упорядоченном виде
	zapros(n, NOTE); //вывод информации по запросу
	(void)_getch();
	return 0; // конец
}
