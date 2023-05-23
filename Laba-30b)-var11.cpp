//Laba-30b)
//В стек Stek2 поместить нечетные положительные элементы из Stek1 и найти их сумму.

#include <stdio.h> //библиотеки
#include <stdlib.h>
#include <iostream>
#include <locale>
#define MAX_SIZE 200 // максимальный размер стека
using namespace std; 

typedef struct { //стек на массиве
    int data[MAX_SIZE];
    int top;
} Stack;

void initStack(Stack* st) { // функция инициализации стека
    st->top = -1;
}

int isEmpty(Stack* st) { // функция проверки стека на пустоту
    return st->top == -1;
}

int isFull(Stack* st) { // функция проверки стека на заполненность
    return st->top == MAX_SIZE - 1;
}

void push(Stack* st, int value) { // функция добавления элемента в стек
    if (isFull(st)) {
        cout << "Стек переполнен!\n";
        exit(1);
    }
    st->top++;
    st->data[st->top] = value;
}

int pop(Stack* st) { // функция удаления элемента из стека
    if (isEmpty(st)) {
        //printf("Stack underflow!\n");
        exit(1);
    }
    int value = st->data[st->top];
    st->top--;
    return value;
}

void scan(Stack* st1) { //функция ввода
    cout << "Введите 10 чисел: \n";
    for (int j = 0; j < 10; j++) {
        int a = 0;
        cin >> a;
        push(st1, a);
    }
}

void perenos(Stack* st1, Stack* st2, int sum) {
    while (!isEmpty(st1)) { // переносим нечетные положительные элементы из st1 в st2
        int value = pop(st1);
        if (value > 0 && value % 2 != 0) {
            push(st2, value);
        }
    }
    while (!isEmpty(st2)) sum += pop(st2);    // суммируем элементы в стеке st2

    cout << "\nСумма нечётных положительных элементов: " << sum;
}

int main() {
    setlocale(LC_ALL, "Russian"); //руссификация текста

    Stack st1, st2; //объявлеем стеки
    int sum = 0; //сумма

    initStack(&st1); //инициализируем стеки
    initStack(&st2);

    scan(&st1); // добавляем элементы в стек st1
    perenos(&st1, &st2, sum);
    return 0;
}