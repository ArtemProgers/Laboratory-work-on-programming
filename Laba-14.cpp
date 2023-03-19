/*Ввести  массив  A(n).Если  в  массиве  не  менее  двух  положительных
элементов, то уменьшить все четные элементы массива на 2, иначе –
найти номер последнего минимального элемента массива.*/
#include <stdio.h>
#include <locale.h>
#pragma warning(disable : 4996)
#define _CRT_SECURE_NO_WARNINGS 
int a[10];
int i, j, k;
int min, b, c;
int size = sizeof(a) / sizeof(int);

void minim(int* a)
{
        int b = 0;
        min = a[0];
        for (int c = 0; c < size; c++) {
            if (a[c] < min) {
                min = a[c];
                b = c;
            }
        }
        printf("Номер минимального элемента: ");
        printf("%d", b);
        printf("%s", "\n");  
}
void print(int* a)
{
    int z;
    for (z = 0; z < size; z++) printf("%d%s", a[z], " ");
    printf("%s", "\n");
}

int main()
{
    setlocale(LC_ALL, "Russian");
    printf("Введите элементы массива: \n");

    for (int j = 0; j < size; j++) scanf("%d", &a[j]);
    int k = 0;
    for (int i = 0; i < size; i++)
    {
        if (a[i] > 0) {
            k++;
        }
        if (k >= 2) if (!(a[i] % 2)) a[i] = a[i] - 2;   
    }
    if (k < 2) minim(a);
    print(a);
    return(0);
}