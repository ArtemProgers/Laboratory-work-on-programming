/* Laba-30-a 
В стек Stek2 поместить все строки из Stek1, начинающиеся на букву «z» 
(реализация стека на основе односвязанного списка)*/

#define _CRT_SECURE_NO_WARNINGS //библиотеки
#include <locale>
#include <stdio.h>
#include <malloc.h>
#include <iostream>
using namespace std;

struct node { //стек на односвязном списке
    char str[100];
    struct node* next;
};

void push(struct node** head, char* str) { //функция добавления строки в стек
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    if (new_node) {
        strcpy(new_node->str, str);
        new_node->next = (*head);
        (*head) = new_node;
    }
}

void scan(struct node** Stek1) { //функция ввода
    cout << "Введите 10 строк: \n";
    for (int j = 0; j < 10; j++) {
        char a[80] = {};
        cin.getline(a, 80);
        push(Stek1, a);
    }
}

void filter(struct node** from, struct node** to) { //функция поиска строк
    while (*from != NULL) {
        if ((*from)->str[0] == 'z') {
            push(to, (*from)->str);
        }
        *from = (*from)->next;
    }
}

void print(struct node** Stek2) { //функция вывода
    cout << "\nСодержимое Stek2 после переноса: ";
    while (Stek2 != NULL) {  
        if ((*Stek2)->str == NULL) break;
        cout <<endl <<(*Stek2)->str ;
        *Stek2 = (*Stek2)->next;
    }
}

int main() {
    setlocale(LC_ALL, "Russian"); //руссификация текста

    struct node* Stek1 = NULL; //инициализация стеков
    struct node* Stek2 = NULL;

    scan(&Stek1); //вводим строки

    filter(&Stek1, &Stek2); //фильтруем Stek1 и перенос в Stek2

    print(&Stek2); //выводим содержимое

    return 0;
}