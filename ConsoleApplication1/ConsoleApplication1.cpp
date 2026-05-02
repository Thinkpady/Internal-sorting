#include <iostream>
#include <clocale>
#include <vector>
#include <utility>

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

void selection_sort(vector<int>* mass) {
    int static_min_on_segment = (*mass)[0];

    for (int i = 0; i < (*mass).size(); i++) {
        static_min_on_segment = max(static_min_on_segment, (*mass)[i]);
    }

    for (int i = 0; i < (*mass).size()-1; i++) {
        int min_on_segment = static_min_on_segment;
        int index_min_on_segment = 0;
        bool be_swap = false;
        for (int j = i; j < (*mass).size(); j++) {
            if (min_on_segment > (*mass)[j]) {
                min_on_segment = (*mass)[j];
                index_min_on_segment = j;
                be_swap = true;
            }
        }

        swap((*mass)[i], (*mass)[index_min_on_segment]);
        cout << "\n";
        for (int k = 0; k < (*mass).size(); k++) {
            if ((k == i) || (k == index_min_on_segment)) {
                cout << "[" << (*mass)[k] << "]" << " ";
            }
            else {
                cout << (*mass)[k] << " ";
            }
        }
        index_min_on_segment = static_min_on_segment;
        cout << "\n";
    }
    cout << "\n";
    
    
}

int main() {
    vector<int> mass = { 1, 2, 3, 5, 4 };
    setlocale(LC_ALL, "RU");

    selection_sort(&mass);

    menu();
    return 0;
}