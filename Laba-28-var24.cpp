/*Дан  символьный  файл  f.  Записать  в  файл  g  с  сохранением  порядка 
следования те символы файла f, вслед за которым в этом файле идет 
буква «z» (записать всё что до z). */
#include <stdio.h> //библиотеки
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <locale.h>
#include <malloc.h>
#pragma warning (disable : 4996) //чтобы не было ошибок
#define _CRT_SCURE_NO_WARNINGS

void funk(FILE* f, FILE* g) { //функция 
    char* buf = (char*)malloc(sizeof(char*) * 30); //динамическая память
    int i = 0, a; //счётчики

    while ((a = fgetc(f)) != EOF) //читаем первый файл
    {
        buf[i] = a; //записываем его в массив
        i++;
    }
    for (int i = 0; i < sizeof(buf) / sizeof(buf[0]); i++) { // ищем букву
        if (buf[i] != 'z') {
            putc(buf[i], g);
        }
        else { // если нашли завержаем программу
            puts("Успешно выполнено "); //всё выполнено  
            break;
        }
    }
    free(buf); //очищаем память
}

int main()
{
    FILE* f, * g; //наши файлы
    setlocale(LC_ALL, "Russian"); //руссификация текста

    f = fopen("f.txt", "r"); //открываем на чтение
    g = fopen("g.txt", "w"); //открываем на запись

    funk(f, g); //передаём файлы в функцию

    fclose(f); //закрываем файлы
    fclose(g);
    return 0;
}