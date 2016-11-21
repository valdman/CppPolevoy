#include <iostream>
#include "liststack.h"

using namespace std;

int main() {
    int const testSize{5};
    ListStack<double> listStack;

    cout << "Заполним стек квадратами чисел от 1 до 30 включительно " << endl;
    for (int i = 1; i <= testSize; ++i) {
        listStack.push(i * i);
    }

    ListStack<double> secondStack(listStack);
    cout << "Выведем стек: ";
    for (int i = 1; i <= testSize; ++i) {
        double tmp{secondStack.pop()};
        cout << tmp << " ";
    }
    cout << endl;
    return 0;
}