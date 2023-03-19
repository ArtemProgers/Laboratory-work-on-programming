/*Даны  символьные  файлы  f  и  g.  Записать  в  файл  h  сначала
компоненты  файла  f,  затем  -  компоненты  файла  g  с  сохранением
порядка.*/
#include <stdio.h> //библиотеки
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <locale.h>
#define SIZE 2048 //максимальный размер компонентов файла
#pragma warning (disable : 4996) //чтобы не было ошибок
#define _CRT_SCURE_NO_WARNINGS
FILE* f, * g, * h; //наши файлы

void sloch(FILE* a) { //функция записи в файл
    char buf[SIZE]; //здесь храним данные из полученного файла
    int sz = 0;
    puts("Введите длину строки:");
    scanf("%d", &sz);
    while (!feof(a)) {
        fgets(buf, SIZE, a);
        int size = strlen(buf);
        if (buf[0] == '\n') { //пропускаем пустые строки
            continue;
        }
        else
            // размер меньше буфера, обрезаем строку до sz*
            if (sz < size) {
                buf[sz] = '\0';
                fputs(buf, h);
                fputs("\n", h);
            }
            else
                // а тут ничего не нужно, т.к. символ "\n" уже прочитан
                fputs(buf, h);
    }
}

int main()
{
    setlocale(LC_ALL, "Russian"); //руссификация текста

    f = fopen("f.txt", "r"); //открываем на чтение
    g = fopen("g.txt", "r"); //открываем на чтение
    h = fopen("h.txt", "w"); //открываем на запись

    if (!g || !f || !h) { //проверка наличия файлов
        puts("Ошибка. Файл не найден\n");
        exit(1);
    }

    sloch(f); //передаём файлы в функцию
    sloch(g);
    fclose(h); //закрываем файлы
    fclose(g);
    fclose(f);
    puts("Успешно выполнено "); //всё выполнено
    return 0;
}