#include <iostream>
#include <clocale>
#include <vector>
#include <algorithm>

using namespace std;

void menu() {
    cout << "------[главное меню]------\n";
    cout << "1 - ввести массив\n";
    cout << "2 - bubble_sort\n";
    cout << "3 - selection_sort\n";
    cout << "4 - insertion_sort\n";
    cout << "0 - выход\n";
    cout << "Пожалуйста, введите цифру для выбора: ";
}

void print_mass(const vector<int>& mass, int sorted_begin = -1, int sorted_end = -1) {
    if (mass.empty()) {
        cout << "массив пуст";
        return;
    }

    for (int i = 0; i < static_cast<int>(mass.size()); i++) {
        if (i == sorted_begin) {
            cout << "[ ";
        }

        cout << mass[i] << " ";

        if (i + 1 == sorted_end) {
            cout << "] ";
        }
    }
}

void input_mass(vector<int>& mass) {
    int n;

    cout << "Введите количество элементов: ";
    cin >> n;

    if (n <= 0) {
        cout << "Количество элементов должно быть больше 0.\n";
        return;
    }

    mass.clear();
    mass.resize(n);

    cout << "Введите элементы массива:\n";
    for (int i = 0; i < n; i++) {
        cin >> mass[i];
    }
}

void bubble_sort(vector<int>& mass) {
    cout << "\nСортировка пузырьком\n";

    int n = static_cast<int>(mass.size());

    if (n < 2) {
        cout << "Сортировать нечего: ";
        print_mass(mass, 0, n);
        cout << "\n";
        return;
    }

    for (int i = 0; i < n - 1; i++) {
        bool be_swap = false;

        for (int j = 0; j < n - 1 - i; j++) {
            if (mass[j] > mass[j + 1]) {
                swap(mass[j], mass[j + 1]);
                be_swap = true;
            }
        }

        if (!be_swap) {
            cout << "Перестановок нет, массив уже отсортирован:\n";
            print_mass(mass, 0, n);
            cout << "\n";
            return;
        }

        cout << "После прохода " << i + 1 << ": ";

        int sorted_begin = n - i - 1;

        if (i == n - 2) {
            sorted_begin = 0;
        }

        print_mass(mass, sorted_begin, n);
        cout << "\n";
    }

    cout << "Сортировка успешно завершена!\n";
}

void selection_sort(vector<int>& mass) {
    cout << "\nСортировка выбором\n";

    int n = static_cast<int>(mass.size());

    if (n < 2) {
        cout << "Сортировать нечего: ";
        print_mass(mass, 0, n);
        cout << "\n";
        return;
    }

    for (int i = 0; i < n - 1; i++) {
        int index_min_on_segment = i;

        for (int j = i + 1; j < n; j++) {
            if (mass[j] < mass[index_min_on_segment]) {
                index_min_on_segment = j;
            }
        }

        if (index_min_on_segment != i) {
            swap(mass[i], mass[index_min_on_segment]);
        }

        cout << "После выбора элемента " << i + 1 << ": ";
        print_mass(mass, 0, i + 1);
        cout << "\n";
    }

    cout << "Итог: ";
    print_mass(mass, 0, n);
    cout << "\n";
}

void insertion_sort(vector<int>& mass) {
    cout << "\nСортировка вставками\n";

    int n = static_cast<int>(mass.size());

    if (n < 2) {
        cout << "Сортировать нечего: ";
        print_mass(mass, 0, n);
        cout << "\n";
        return;
    }

    cout << "Начальная отсортированная часть: ";
    print_mass(mass, 0, 1);
    cout << "\n";

    for (int i = 1; i < n; i++) {
        int current = mass[i];
        int j = i - 1;

        while (j >= 0 && mass[j] > current) {
            mass[j + 1] = mass[j];
            print_mass(mass, 0, i + 1);
            cout << "\n";
            j--;
        }

        mass[j + 1] = current;
    }

    cout << "Итог: ";
    print_mass(mass, 0, n);
    cout << "\n";
}

int main() {
    setlocale(LC_ALL, "");

    vector<int> mass = { 1, 1, 5, 3, 6, 7, 12, 9, 11 };

    int choice;

    do {
        menu();
        cin >> choice;

        switch (choice) {
        case 1:
            input_mass(mass);
            break;

        case 2:
            bubble_sort(mass);
            break;

        case 3:
            selection_sort(mass);
            break;

        case 4:
            insertion_sort(mass);
            break;

        case 0:
            cout << "Выход из программы.\n";
            break;

        default:
            cout << "Ошибка: такого пункта меню нет.\n";
        }

        cout << "\n";

    } while (choice != 0);

    return 0;
}
