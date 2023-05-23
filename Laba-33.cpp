///* Laba-33 Вариант-10
//Построить список L1 - копию списка L, расположив элементы в обратном порядке 
//(первый элемент списка L - последний элемент списка L1). Заменить элементы списка L, имеющие четные значения,
//на элементы списка L1, имеющие нечетные значения.
//*/

#include <stdio.h> //библиотеки
#include <stdlib.h>
#include <malloc.h>
#include <locale.h>
#pragma warning (disable : 4996) //чтобы не было ошибок
#define _CRT_SCURE_NO_WARNINGS

typedef struct Node { //список
    int data;
    struct Node* next;
};

void push_front(struct Node** head_ref, int new_data) { //функция добавления элементов
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}


void print_list(struct Node* node) { //функция вывода списка
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
}

struct Node* reverse_copy(struct Node* head) { // функция создания обратного списка
    struct Node *prev = NULL, *current = head, *next = NULL;
    struct Node* new_head = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    new_head = prev;
    return new_head;
}

void replace_even_with_odd(struct Node* head, struct Node* head1) { //функция замены элементов 
    struct Node* ptr = head;
    struct Node* ptr1 = head1;

    while (ptr != NULL && ptr1 != NULL) {
        if (ptr->data % 2 == 0) {
            while (ptr1 != NULL && ptr1->data % 2 == 0) {
                ptr1 = ptr1->next;
            }
            if (ptr1 != NULL) {
                ptr->data = ptr1->data;
                ptr1 = ptr1->next;
            }
            else {
                break;
            }
        }
        ptr = ptr->next;
    }
}

int main() {
    setlocale(LC_ALL, "Russian"); //руссификация текста

    struct Node* head = NULL;
    struct Node* head1 = NULL;

    printf_s("Введите значения 8-ми элементов списка L: \n");
    int i = 0;
    while (i < 8) //заполняем список
    {
        int j = 0;
        scanf_s(" %d", &j);
        push_front(&head, j);
        i++;
        printf_s("\n");
    }

    printf("\nСписок L: ");
    print_list(head); //выводим список L

    printf("\nСписок L1 с элементами в обратном порядке: ");
    head1 = reverse_copy(head); //переворачиваем элементы
    print_list(head1); //выводим список L1

    replace_even_with_odd(head, head1); //заменяем элементы

    printf("\nСписок L с заменёнными значениями: ");
    print_list(head); //выводим готовый результат

    return 0;
}