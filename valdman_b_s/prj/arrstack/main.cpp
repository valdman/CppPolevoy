#include <iostream>
#include "arrstack.h"

using namespace std;

int main() {
    ArrStack stack;
    ArrStack stack2;
    int testSize{15};

    cout << "Заполним стэк этим 1 стек и сразу присвоим новому" << endl << " 2-му стеку 1-ый, а в 3-ий скопируем 2-ой: " << endl;
    for (int i = 0; i < testSize; ++i) {
        stack.Push(i);
        double tmp{stack.Check()};
        cout << tmp << " ";
    }
    stack2 = stack;
    ArrStack stack3{stack2};
    cout << endl;

    cout <<  endl << "Получим последний элемент 1 стека столько раз, каков размер стэка " << endl;
    for (int i = 0; i < testSize; ++i) {
        double tmp{stack.Pop()};
        cout << tmp << " ";
    }

    cout << endl << endl << "Попытаемся получить еще элемент и поймаем ошибку" << endl;
    try {
        stack.Pop();
    } catch (out_of_range) {
        cout << "Ошибка поймана, выход за границы" << endl << endl;
    }


    cout << "Получим последний элемент 2 стека столько раз, каков размер стэка " << endl;
    for (int i = 0; i < testSize; ++i) {
        double tmp{stack2.Pop()};
        cout << tmp << " ";
    }

    cout << endl << endl << "Получим последний элемент 3 стека столько раз, каков размер стэка " << endl;
    for (int i = 0; i < testSize; ++i) {
        double tmp{stack3.Pop()};
        cout << tmp << " ";
    }

    return 0;
}