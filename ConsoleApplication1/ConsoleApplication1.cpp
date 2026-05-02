#include <iostream>
#include <clocale>

using namespace std;

void menu() {
	cout << "------[главное меню]------\n";
	cout << "1 - ввести массив\n";
	cout << "2 - buble_sort\n";
	cout << "3 - selection_sort\n";
	cout << "3 - insertion_sort\n";

}

int main() {
	setlocale(LC_ALL, "RU");
	menu();
	return 0;
}