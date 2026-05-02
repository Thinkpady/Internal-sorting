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
    //если левый элемент больше, чем правый они меняются местами
    cout << "Сортировка пузырьком\n";
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
    //самый минимальный ставим в начальный, потом второй по минимальности на второе место
    cout << "Сортировка выбором\n";
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
            if (i == index_min_on_segment) {
                break;
            }
            else if ((k == i) || (k == index_min_on_segment)) {
                cout << "[" << (*mass)[k] << "]" << " ";
            }
            else {
                cout << (*mass)[k] << " ";
            }
        }
        index_min_on_segment = static_min_on_segment;
    }
    cout << "\n";
}

void insert_sort(vector<int>* mass) {
    //берем элемент и несем его в лево до тех пор пока он не станет подходящим
    cout << "Сортировка вcтавками\n";
    for (int i = 1; i < (*mass).size(); i++) {
        int cursor = 0;

        bool be_swap = false;
        while (((*mass)[i] >= (*mass)[cursor]) && (cursor < i)){
            cursor++;
            be_swap = true;
        }
    
        (*mass).insert((*mass).begin() + cursor, (*mass)[i]);
        (*mass).erase((*mass).begin() + i + 1);
    }
    print_mass(*mass);
    cout << "\n";
}

int main() {
    vector<int> mass = {1, 1, 5, 3, 6, 7, 12, 9, 11};
    setlocale(LC_ALL, "RU");

    insert_sort(&mass);
    //bubble_sort(&mass);
    //selection_sort(&mass);

    menu();
    return 0;
}