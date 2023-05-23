//Laba-33-var11

#include <stdio.h> //библиотеки
#include <stdlib.h>
#include <locale.h>
#include <malloc.h>
#pragma warning (disable : 4996) //чтобы не было ошибок
#define _CRT_SCURE_NO_WARNINGS

struct node {  // Определение структуры узла списка
    int data;
    struct node* next;
};

void append(struct node** head, int data) { // Функция для добавления узла в конец списка
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    if (new_node) {
        new_node->data = data;
        new_node->next = NULL;

        if (*head == NULL) {
            *head = new_node;
            return;
        }

        struct node* last = *head;
        while (last->next != NULL) {
            last = last->next;
        }

        last->next = new_node;
    }
}

struct node* merge(struct node* l1, struct node* l2) { // Функция для объединения двух списков и сортировки их по возрастанию
    if (l1 == NULL) return l2;
    
    if (l2 == NULL) return l1;

    struct node* result = NULL;

    if (l1->data <= l2->data) {
        result = l1;
        result->next = merge(l1->next, l2);
    }
    else {
        result = l2;
        result->next = merge(l1, l2->next);
    }
    return result;
}

struct node* find_min(struct node* head) {
    struct node* next;

    for (next = head->next; next; next = next->next)
        if (next->data < head->data)
            head = next;

    return head;
}

void sort_ascendant(struct node* list) { //функция сортировки
    for (; list; list = list->next) {
        struct node* minPtr = find_min(list);

        if (minPtr != list) {
            int tmp = list->data;
            list->data = minPtr->data;
            minPtr->data = tmp;
        }
    }
}

void print(struct node* L) { //функция вывода списка
    struct node* current = L; 
    if (current) {
        while (current != NULL) {
            printf("%d ", current->data);
            current = current->next;
        }
    }
    printf_s("\n");
}

int main() {
    setlocale(LC_ALL, "Russian"); //руссификация текста 

    struct node* L1 = NULL; //определение списков
    struct node* L2 = NULL;
    struct node* L = NULL;

    printf_s("Введите значения 4-х элементов списка L1: \n");
    int i1 = 0;
    while (i1 < 4) //заполняем первый список
    {
        int j1 = 0;
        scanf_s(" %d", &j1);
        append(&L1, j1);
        i1++;
        printf_s("\n");
    }
    printf_s("Введите значения 4-х элементов списка L2: \n");
    int i2 = 0;
    while (i2 < 4)   //заполняем второй список
    {
        int j2 = 0;
        scanf_s(" %d", &j2);
        append(&L2, j2);
        i2++;
        printf_s("\n");
    }

    printf_s("Список L1: "); //выводим что понавводили
    print(L1);
    printf_s("Список L1: ");
    print(L2);

    L = merge(L1, L2); //объединяем и сортируем

    sort_ascendant(L); //сортируем по возрастанию

    printf_s("Список L: ");
    print(L); //выводим результат
    return 0;
}
