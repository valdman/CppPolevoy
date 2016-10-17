#include <iostream>
#include "vector.h"

void runTests();

using namespace std;

int main() {

    runTests();

    return 0;
}

void runTests() {
    cout << "Создадим вектор размера 10 и проинициализируем его элементы половинами квадратов индексов: " << endl;
    Vector vector(10);

    for (int i = 0; i < 10; ++i) {
        vector[i] = (i * i) / 2.0;
    }
    cout << vector << endl << endl;
    double a = vector[3];

    try {
        cout << "Попытаемся обратиться к 11 элементу " << endl;
        vector[11];
    }catch (out_of_range)
    {
        cout << "Выход за границы!" << endl;
    }

    cout << endl;

    cout << "Создадим новый вектор, и скопируем через operatop= в него прошлый вектор" << endl;
    Vector newVector;
    newVector = vector;
    cout << newVector << endl;


    cout << endl;

    cout << "Изменим размер вектора до 7 " << endl;
    newVector.resize(7);
    cout << newVector << endl;

    cout << endl;

    cout << "Изменим размер вектора до 14 " << endl;
    newVector.resize(14);
    cout << newVector << endl;
}