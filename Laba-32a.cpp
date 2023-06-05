//Laba-32a
//В очередь Och2 поместить все латинские буквы из Och1 и найти их количество

#include <iostream> //библиотеки
#include <locale>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

using namespace std; // пространство имён

typedef struct node {
    char data;
    struct node* next;
} Node;

typedef struct queue {
    Node* first;
    Node* last;
    int size;
} Queue;

Queue* createQueue() { // функция инициализации
    Queue* q = (Queue*)malloc(sizeof(Queue));
    if (q) {
        q->first = NULL;
        q->last = NULL;
        q->size = 0;
    }
    return q;
}

void enqueue(Queue* q, char data) { //функция добавления элемента
    Node* n = (Node*)malloc(sizeof(Node));
    if (n) {
        n->data = data;
        n->next = NULL;
        if (q->last != NULL) q->last->next = n;
        q->last = n;
        if (q->first == NULL) q->first = n;
        q->size++;
    }

}

char dequeue(Queue* q) { //функция удаления элемента
    if (q->first == NULL) return '\0';
    Node* n = q->first;
    char data = n->data;
    q->first = n->next;
    if (q->first == NULL) q->last = NULL;
    free(n);
    q->size--;
    return data;
}

int getLatinLetters(Queue* q) { //функция подсчёта букв
    int count = 0;
    Node* current = q->first;
    while (current != NULL) {
        if (isalpha(current->data)) count++;
        current = current->next;
    }
    return count;
}

void scan(Queue* q) {
    char str[100]{};
    cout << "Введите символы в строку без пробелов: ";
    gets_s(str);
    for (int i = 0; str[i] != '\0'; i++) enqueue(q, str[i]);
}

int main() {
    setlocale(LC_ALL, "Russian"); //руссификация текста

    Queue* q = createQueue(); //инициализируем
    
    scan(q); //вводим символы
    int count = getLatinLetters(q); //считаем буквы
    cout << "Количество латинских букв: " << count; //выводим результат
    return 0;
}