/* Laba-30-b
В стек Stek2 поместить все строки из Stek1, начинающиеся на букву «z»
(реализация стека на основе массива)*/

#define _CRT_SECURE_NO_WARNINGS //библиотеки
#include <iostream>
#include <locale>
using namespace std;
#define MAX_SIZE 100 // максимальный размер стека

typedef struct //стек на массиве
{
    char arr[MAX_SIZE][30]; //массив строк
    int top; //индекс вершины 
} Stack;

void push(Stack* s, char str[]) // функция добавления строки в стек
{
    if (s->top < MAX_SIZE - 1) strcpy(s->arr[++(s->top)], str);
}

void pop(Stack* s) // функция удаления строки из стека
{
    if (s->top >= 0) s->top--; 
}

char* top(Stack* s) // функция получения строки из вершины стека
{
    char* str = NULL;
    if (s->top >= 0) str = s->arr[s->top]; 
    return str;
}

void scan(Stack* Stek1) { //функция ввода
    cout << "Введите 10 строк: \n";
    for (int j = 0; j < 10; j++) {
        char a[80] = {};
        cin.getline(a, 80);
        push(Stek1, a);
    }
}

void filter(Stack* Stek1, Stack* Stek2) { //функция поиска строк
    for (int i = 0; i <= Stek1->top; i++) {
        char* str = Stek1->arr[i];
        if (str[0] == 'z') push(Stek2, str);
    }
}

void print(Stack* Stek2) { //функция вывода
    cout << "\nСодержимое Stek2 после переноса: ";
    while ((Stek2->top) >= 0) {
        cout << endl << top(Stek2);
        pop(Stek2);
    }
}

int main() {
    setlocale(LC_ALL, "Russian"); //руссификация текста

    Stack Stek1 = { {}, -1 }; // инициализация стеков
    Stack Stek2 = { {}, -1 }; 

    scan(&Stek1); //вводим строки
  
    filter(&Stek1, &Stek2); //фильтруем Stek1 и перенос в Stek2

    print(&Stek2); //выводим содержимое
    return 0;
}