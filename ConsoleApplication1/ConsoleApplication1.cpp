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
    cout << "Пожалуйста, введите цифру для выбора\n";
}

void print_mass(vector<int> mass){
    for (int i = 0; i < mass.size(); i++) {
        cout << mass[i] << " ";
    }
}

void bubble_sort(vector<int>* mass) {
    cout << "Исходный массив: ";
    print_mass(*mass);
    cout << "\n";
    for (int i = 0; i < (*mass).size() - 1; i++) {
        bool be_swap = false;
        int c = 0;
        for (int j = 0; j < (*mass).size()-1; j++) {
            if ((*mass)[j] > (*mass)[j + 1]) {
                int temp = (*mass)[j];
                (*mass)[j] = (*mass)[j + 1];
                (*mass)[j + 1] = temp;
                be_swap = true;
                for (int k = 0; k < (*mass).size(); k++) {
                    if ((k == j) || (k == j + 1)) {
                        cout << "[" << (*mass)[k] << "]" << " ";
                    }
                    else {
                        cout << (*mass)[k] << " ";
                    }
                }
                cout << "\n";
            }
         }

            if (be_swap == false) {
                cout << "Сортировка успешно завершена!\n";

                for (int i = 0; i < (*mass).size(); i++) {
                    cout << (*mass)[i] << " ";
                }
                cout << "\n";
                break;
            }
        }
    }

int main() {
    vector<int> mass = { 9, 8, 7, 6, 5 };
    setlocale(LC_ALL, "RU");

    bubble_sort(&mass);

    menu();
    return 0;
}