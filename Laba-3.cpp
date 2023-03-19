/* Вариант 10 – На  шахматной  доске  стоят  черный  король  и  белые  ладья  и  слон. 
Проверить,  есть  ли  угроза  королю,  и  если  есть,  то  от  кого  именно. 
Король может  ходить  на одну клетку  в  любую сторону.  Ладья  ходит 
только по горизонтали и вертикали. Слон ходит только по диагонали. */
#include <conio.h> // библиотеки ввода-вывода
#include <stdio.h>
#include <ctype.h> //библиотека обработки символов
#include <locale.h> // библиотека локализации текста
#include <math.h> // математическая библиотека

int kor_g, lad_g, slon_g; // Горизонтальные координаты короля, ладьи и слона 
char kor_v, lad_v, slon_v; // Вертикальные координаты короля, ладьи и слона
int kor_vi, lad_vi, slon_vi; // Переведеные в числовые значения координаты

int main() // основная функция программы
{ 
	setlocale(LC_ALL, "Rus"); // локализация текста
    printf("Введите координаты фигур\n"); 
    printf("Король (цифра+буква)  \n");
    scanf_s("%d", &kor_g); //вводим координаты короля
    scanf_s("%c", &kor_v);

    printf("Ладья (цифра+буква) \n");
    scanf_s("%d", &lad_g); //вводим координаты ладьи
    scanf_s("%c", &lad_v);
 
    printf("Слон (цифра+буква) \n");
    scanf_s("%d", &slon_g); //вводим координаты слона
    scanf_s("%c", &slon_v);

    kor_v = tolower(kor_v); //перевод к нижнему регистру
    slon_v = tolower(slon_v);
    lad_v = tolower(lad_v);

    kor_vi = kor_v - 'a' + 1; //преобразование координат в числа
    slon_vi = slon_v - 'a' + 1;
    lad_vi = lad_v - 'a' + 1;

    if ((kor_g < 1 || kor_g > 8) || (kor_vi < 1 || kor_vi > 8) || // проверка введённых данных
        (lad_g < 1 || lad_g > 8) || (lad_vi < 1 || lad_vi > 8) ||
        (slon_g < 1 || slon_g > 8) || (slon_vi < 1 || slon_vi > 8))
    {
        printf("Ошибка, имеется фигура за доской или введены некоректнные данные!\n");
        _getch();
        return 1;
    }

    if ((slon_g == kor_g && slon_vi == kor_vi) || //фигуры занимают одну и ту же позицию?
        (kor_g == lad_g && kor_vi == slon_vi) ||
        (slon_g == lad_g && slon_vi == lad_vi))
    {
        printf("Ошибка! Фигуры занимают одну позиции.\n");
        _getch();
        return 1;
    }
    // Решение задачи.
       // Условие 1 Ладья и король на одной линии. 
               //Слон стоит между ладьей и королем, и мешает бить.
       // Если нет то вывод координаты атакующей ладьи.
       // Проверка на помехи со стороны слона
    if ((kor_vi == lad_vi || kor_g == lad_g) && !((((((kor_vi == slon_vi) &&
        (slon_vi == lad_vi)) && ((slon_g > lad_g) && (slon_g < kor_g))) || ((slon_g < lad_g)
            && (slon_g > kor_g)))) || ((kor_g == slon_g == lad_g) && (((kor_vi > slon_vi)
                && (slon_vi > lad_vi)) || ((slon_vi > kor_vi) && (slon_vi < lad_vi))))))
    {
        printf("\n%d%c ", lad_g, lad_v);
        // Теперь проверяем слона
        if (abs(slon_g - kor_g) == abs(slon_vi - kor_vi))
        {
            printf("%d%c", slon_g, slon_v);
            _getch();
            return 1;
        }
        _getch();
        return 1;
    }
    //Если условие 1 с ладьей не удовлетворено, то снова проверка слона, но уже с учетом помех от ладьи.
    else
    {
        if ((abs(slon_g - kor_g) == abs(slon_vi - kor_vi)))
        {
            if (abs(kor_g - lad_g) == abs(kor_vi - lad_vi))
            {
                if (((lad_g > kor_g) && (lad_g < slon_g)) || ((lad_g < kor_g) && (lad_g > slon_g)))
                {
                    printf("\nНет решений!");
                    _getch();
                    return 1;
                }
                else
                {
                    printf("\n%d%c", slon_g, slon_v);
                    _getch();
                    return 1;
                }
            }
            else
            {
                printf("\n%d%c", slon_g, slon_v);
                _getch();
                return 1;
            }
        }
        // Если же и слон не удовлетворен, то вывод надписи об отсутствии решений.
        else
        {
            printf("\nНет решений!");
            _getch();
            return 1;
        }
    }
    _getch();
    return (0);
}
