#include <iostream>
#include "liststack.h"

using namespace std;

int main() {
    ListStack listStack;

    cout << "Заполним стек квадратами чисел от 1 до 30 включительно " << endl;
    for (int i = 1; i <= 1e12; ++i) {
        listStack.push(i * i);
    }

    cout << "Выведем стек: ";
    for (int i = 1; i <= 30; ++i) {
        double tmp{listStack.pop()};
        cout << tmp << " ";
    }
    cout << endl;
    return 0;
}