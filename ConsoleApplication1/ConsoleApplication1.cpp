#include <iostream>
#include <clocale>
#include <vector>

using namespace std;

void menu() {
    cout << "------[главное меню]------\n";
    cout << "1 - ввести массив\n";
    cout << "2 - bubble_sort\n";
    cout << "3 - selection_sort\n";
    cout << "4 - insertion_sort\n";
}

void show_mass(vector<int> mass) {
    cout << "Массив: ";
    for (int i = 0; i < mass.size(); i++) {
        cout << mass[i] << " ";
    }
    cout << endl;
}

void bubble_sort(vector<int>* mass) {
    for (int i = 0; i < (*mass).size() - 1; i++) {
        bool be_swap = false;
        for (int j = 0; j < (*mass).size() - i - 1; j++) {
            if ((*mass)[j] > (*mass)[j + 1]) {
                int temp = (*mass)[j];
                (*mass)[j] = (*mass)[j + 1];
                (*mass)[j + 1] = temp;
                be_swap = true;
            }
        }
        if (be_swap == false) {
            cout << "Сортировка успешно завершена\n";
            return;
        }
    }
}

int main() {
    vector<int> mass = { 4, 2, 7, 5, 11 };
    setlocale(LC_ALL, "RU");

    cout << "Исходный ";
    show_mass(mass);

    bubble_sort(&mass);

    cout << "Отсортированный ";
    show_mass(mass);

    menu();
    return 0;
}