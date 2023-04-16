
#define _CRT_SECURE_NO_WARNINGS //отключаем ошибки компилятора
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_NONSTDC_NO_DEPRECATE
#include <iostream> //библиотеки
#include <cstdlib>
#include <string>
#include <iomanip>
#pragma warning(suppress : 4996)
using namespace std; //пространство имён

struct NOTE { //структуры
    string surname; // фамилия
    string name; // имя
    string phone; // номер телефона
    int birthday[3]{}; // дата рождения (массив из трех чисел)
};

void write_struct(struct NOTE* arr,int SIZE) { //функция заполнения структуры
    for (int i = 0; i < SIZE; i++) {
        cout << "Введите фамилию: ";
        cin >> arr[i].surname;
        cout << "Введите имя: ";
        cin >> arr[i].name;
        cout << "Введите номер телефона: ";
        cin >> arr[i].phone;
        cout << "Введите дату рождения (день месяц год): ";
        cin >> arr[i].birthday[0] >> arr[i].birthday[1] >> arr[i].birthday[2];
        cout << "\n";
    }
}

void file_write(int SIZE, struct NOTE* arr, int flag) { //функция записи содержимого структур в файл
    if (flag == 0) {
        FILE* File = fopen("file.txt", "w");
        if (!File) cout << "ОШИБКА! Файл file.txt не найден! \n";
        else {
            for (int i = 0; i < SIZE; i++) {
                fputs(arr[i].surname.c_str(), File); fputs("\n", File);
                fputs(arr[i].name.c_str(), File); fputs("\n", File);
                fputs(arr[i].phone.c_str(), File); fputs("\n", File);
                for (int j = 0; j < 3; j++) fprintf_s(File, "%d.", arr[i].birthday[j]);
                fputs("\n\n", File);
            }
            fclose(File);
            cout << " Данные записаны в файл file.txt \n\n";
        }
    }
    else if (flag == 1) {
        FILE* File1 = fopen("Выходной файл 1.txt", "w");
        if (!File1) cout << "ОШИБКА! Файл file.txt не найден! \n";
        else {
            for (int i = 0; i < SIZE; i++) {
                fputs(arr[i].surname.c_str(), File1); fputs("\n", File1);
                fputs(arr[i].name.c_str(), File1); fputs("\n", File1);
                fputs(arr[i].phone.c_str(), File1); fputs("\n", File1);
                for (int j = 0; j < 3; j++) fprintf_s(File1, "%d.", arr[i].birthday[j]);
                fputs("\n\n", File1);
            }
            fclose(File1);
            cout << " Данные записаны в файл Выходной файл 1.txt \n\n";
        }
    }
    else if (flag == 2) {
        FILE* File2 = fopen("Выходной файл 2.txt", "w");
        if (!File2) cout << "ОШИБКА! Файл file.txt не найден! \n";
        else {
            for (int i = 0; i < SIZE; i++) {
                fputs(arr[i].surname.c_str(), File2); fputs("\n", File2);
                fputs(arr[i].name.c_str(), File2); fputs("\n", File2);
                fputs(arr[i].phone.c_str(), File2); fputs("\n", File2);
                for (int j = 0; j < 3; j++) fprintf_s(File2, "%d.", arr[i].birthday[j]);
                fputs("\n\n", File2);
            }
            fclose(File2);
            cout << " Данные записаны в файл Выходной файл 2.txt \n\n";
        }
    }
}

void delete_struct(struct NOTE* arr, int SIZE, string nomerzapisi_del) { //функция удаления содержимого
    for (int i = 0; i < SIZE; i++) {
        if (arr[i].surname == nomerzapisi_del) {
            arr[i].surname = " ";
            arr[i].name = " ";
            arr[i].phone = " ";
            int a[1] = { };
            for (int j = 0; j < 3; j++) {
                to_string(arr[i].birthday[j]);
                arr[i].birthday[j] = *a;
            }
        }
    }
}

void izmen_struct(string nomerzapisi_izm, int SIZE, struct NOTE* arr) { //функция изменения содержимого
    for (int i = 0; i < SIZE; i++) {
        cout << "Введите фамилию: ";
        cin >> arr[i].surname;
        cout << "Введите имя: ";
        cin >> arr[i].name;
        cout << "Введите номер телефона: ";
        cin >> arr[i].phone;
        cout << "Введите дату рождения (день месяц год): ";
        cin >> arr[i].birthday[0] >> arr[i].birthday[1] >> arr[i].birthday[2];
        cout << "\n Изменения сохранены \n";
    }
}

void izmenenie(struct NOTE* arr, int SIZE) { //функция изменения содержимого структуры
    cout << "Нужно ли внести изменения в содержимое (выберете номер): \n";
    cout << "1. Удалить \n";
    cout << "2. Заменить \n";
    cout << "3. Не изменять \n";
    short flag;
    string nomerzapisi_del;
    string nomerzapisi_izm;
    cin >> flag;
    switch (flag)
    {
    case 1: 
        cout << "Введите фамилию содержащуюся в записи записи, которую необходимо удалить: ";
        cin >> nomerzapisi_del;
        if (nomerzapisi_del.empty()) { cout << "Ошибка! \n"; break; }
        delete_struct(arr, SIZE, nomerzapisi_del);
        file_write(SIZE, arr, 0);
        break;
    case 2: 
        cout << "Введите фамилию содержащуюся в записи, которую необходимо заменить: ";
        cin >> nomerzapisi_izm;
        if (nomerzapisi_izm.empty()) { cout << "Ошибка! \n"; break; }
        izmen_struct(nomerzapisi_izm, SIZE, arr);
        file_write(SIZE, arr, 0);
    case 3: break;
    default: break;
    }
}

void insertionSort(NOTE arr[], int n) { //функция сортировки вставкой
    for (int i = 1; i < n; i++) {
        NOTE key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j].surname > key.surname) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void heapify(NOTE arr[], int size, int root) { // функции пирамидальной сортировки
    int largest = root;
    int left = 2 * root + 1;
    int right = 2 * root + 2;

    if (left < size && arr[left].surname > arr[largest].surname)
        largest = left;

    if (right < size && arr[right].surname > arr[largest].surname)
        largest = right;

    if (largest != root) {
        swap(arr[root], arr[largest]);
        heapify(arr, size, largest);
    }
}

void heapSort(NOTE arr[], int size) {
    for (int i = size / 2 - 1; i >= 0; i--)
        heapify(arr, size, i);

    for (int i = size - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

void sortir(NOTE arr[], int SIZE) { //функция выбора и запуска сортировки
	int vs = 0;
	cout << "Выберете тип сортировки: 1 - Вставкой  2 - Пирамидальная \n";
	cin >> vs;
	switch (vs)
	{
    case 1: insertionSort(arr, SIZE); file_write(SIZE, arr, 1); break;
    case 2: heapSort(arr, SIZE);      file_write(SIZE, arr, 2); break;
	default:
		cout << "Неверное значение! Перезапустите программу и введите правильное значение\n";
		break;
	}
}

void upor_print(int SIZE, struct NOTE* arr) { //функция упорядоченного вывода записей структуры
    cout << " Записи упорядоченные сортировкой:\n\n";
    cout << " Фамилия и имя:          Номер телефона:          Дата рождения: \n";
    for (int i = 0; i < SIZE; i++)
    {
        cout << " -----------------------------------------------------------------\n";
        cout << arr[i].surname << " " << arr[i].name;
        cout << setw(20); cout << arr[i].phone; cout << setw(14);
        for (int j = 0; j < 3; j++) cout << arr[i].birthday[j] << ".";
        cout << "\n";
    }
    cout << "\n\n";
}

void printBirthday(NOTE arr[], int n) { //функция вывода данных по запросу месяца рождения
    cout << "\n Информация о людях, родившихся в месяц, который введён с клавиатуры\n";
    int month;
    bool found;
    while (true) {
        cout << "Введите номер месяца или 0 для окончания: ";
        cin >> month;
        if (month == 0) break;
        found = true;
        for (int i = 0; i < n; i++) {
            if (arr[i].birthday[1] == month) {
                cout << " Фамилия и имя:          Номер телефона:          Дата рождения: \n";
                cout << " -----------------------------------------------------------------\n";
                cout << arr[i].surname << " " << arr[i].name;
                cout << setw(20); cout << arr[i].phone; cout << setw(14);
                for (int j = 0; j < 3; j++) cout << arr[i].birthday[j] << ".";
                cout << "\n";
                found = false;
                cout << "\n\n";
            }
        }
        if (found) cout << " Таких людей нет! \n\n";
    }
}

int main(int argc, char* argv[]) {
    int SIZE = 8;
    setlocale(LC_ALL, "Russian"); //руссификация текста
    cout << "Введите количество структур NOTE: "; cin >> SIZE;
    NOTE* arr = new NOTE[SIZE]; //динамическая память структуры
    write_struct(arr, SIZE); //заполнение структуры
    file_write(SIZE, arr, 0); //запись данных в файл
    izmenenie(arr, SIZE); //вносим изменения если надо
    sortir(arr, SIZE); //сортировка
    upor_print(SIZE, arr); //вывод в упорядоченном виде
    printBirthday(arr, SIZE); // вывод записей с днем рождения в указанном месяце
    return 0;
}