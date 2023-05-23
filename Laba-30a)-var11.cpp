//Laba-30a)
//В стек Stek2 поместить нечетные положительные элементы из Stek1 и найти их сумму.

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <locale>
using namespace std;

typedef struct node { // определение структуры узел списка
    int data;           
    struct node* next;  
} Node;

typedef struct stack { // определение структуры стек
    Node* top;      
} Stack;

Node* newNode(int data) { // функция создания нового узла списка
    Node* node = (Node*)malloc(sizeof(Node));  
    if (node) {
        node->data = data;
        node->next = NULL;
    }  
    return node;
}

void initStack(Stack* stack) {  // функция инициализации стека
    stack->top = NULL;  
}


void push(Stack* stack, int data) {  // функция добавления нового узла в стек
    Node* node = newNode(data);     
    node->next = stack->top;        
    stack->top = node;              
}

int pop(Stack* stack) {  // функция удаления верхнего узла из стека
    if (stack->top == NULL) {               
        cout << "Стек пустой!\n";        
        return -1;
    }
    Node* node = stack->top;                
    stack->top = node->next;                
    int data = node->data;                  
    free(node);                             
    return data;                            
}

int sumOddPositives(Stack* stack1, Stack* stack2) { // функция поиска нечетных положительных элементов и вычисления их суммы
    int sum = 0;    
    Node* node = stack1->top;   
    while (node != NULL) {      
        if (node->data > 0 && node->data % 2 == 1) {        
            push(stack2, node->data);       
            sum += node->data;              
        }
        node = node->next;      
    }
    return sum; 
}

void scan(Stack* stack1) { //функция ввода
    cout << "Введите 10 чисел: \n";
    for (int j = 0; j < 10; j++) {
        int a = 0;
        cin >> a;
        push(stack1, a);
    }
}

int main() {
    setlocale(LC_ALL, "Russian"); //руссификация текста

    Stack stack1, stack2;   // создаем два стека

    initStack(&stack1);     // инициализируем стеки
    initStack(&stack2);

    scan(&stack1);       // добавляем элементы в первый стек

    int sum = sumOddPositives(&stack1, &stack2);  // находим нечетные положительные элементы и их сумму
    cout << "\nСумма нечетных положительных элементов: " << sum;  // выводим сумму

    return 0;
}