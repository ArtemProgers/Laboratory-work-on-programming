//Laba-32b
//В очередь Och2 поместить все латинские буквы из Och1 и найти их количество

#include <iostream> //библиотеки
#include <locale>
#include <stdio.h>
#include <ctype.h>

#define MAX_SIZE 100 // максимальный размер очереди
using namespace std; // пространство имён

typedef struct {
    char queue[MAX_SIZE]; // массив элементов очереди
    int front; // индекс первого элемента
    int rear; // индекс последнего элемента
} Queue;

void enqueue(Queue* q, char c) { // функция для добавления элемента в очередь
    if (q->rear == MAX_SIZE - 1) {
        cout << "Очередь полная\n";
        return;
    }
    q->rear++;
    q->queue[q->rear] = c;
}

char dequeue(Queue* q) { // функция для удаления элемента из очереди
    if (q->front > q->rear) {
        cout << "Очередь пустая\n";
        return '\0';
    }
    char removed = q->queue[q->front];
    q->front++;
    return removed;
}

void scan(Queue* och1) { // функция заполнения очереди
    cout << "Введите 10 символов в очередь Och1:" << endl;
    for (int i = 0; i < 10; i++) {
        cout << "Символ " << i + 1 << ": ";
        char a = 0;
        cin >> a;
        cout << "\n";
        enqueue(och1, a);
    }
}


void poisk(Queue och1, Queue och2) { // функция поиска символов
    int count = 0; 
    while (och1.front <= och1.rear) {
        char c = dequeue(&och1);
        if (isalpha(c)) {
            count++;
            enqueue(&och2, c);
        }
    }
    cout << "Количество латинских букв: " << count;
}



int main() {
    setlocale(LC_ALL, "Russian"); //руссификация текста

    Queue och1 = { { }, 0, 10}; // инициализируем
    Queue och2 = { {0}, 0, -1 }; 

    scan(&och1); //вводим значения
    poisk(och1, och2); //ищем буквы и их количество
    return 0;
}