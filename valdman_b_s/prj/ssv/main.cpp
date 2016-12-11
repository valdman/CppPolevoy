#include <map>
#include "ssvdata.h"
#include <iostream>

using namespace std;

void showHelp()
{
    cout
            << "\'open\' - Load data from CSV" << endl
            << "\'man\' - Manually enter CSV" << endl
            << "\'emp\' - Load empty project" << endl
            << "\'sh\' - Show data" << endl
            << "\'save\' - Export data to file" << endl
            << "\'sep\' - Change separator (\',\' by default)" << endl << endl

            << "\'add\' - Add row to file end" << endl
            << "\'ins\' - Insert row to position" << endl
            << "\'rem\' - Remove row from position" << endl << endl

            << "\'h\' or \'?\' - Show this help" << endl
            << "\'q\' - Quit" << endl;
}

void gui()
{
    SsvData ssv;

    bool wannaExit(false);
    bool dataLoaded(false);

    showHelp();

    while (!wannaExit) {
        cout << ">";
        string actionStr;
        string action;
        std::map<string, char> dict{{"open", 1},
                                    {"man",  2},
                                    {"emp",  3},
                                    {"save", 4},
                                    {"add",  5},
                                    {"sh",   6},
                                    {"sep",  7},
                                    {"ins",  8},
                                    {"rem",  9},
                                    {"q",    10},
                                    {"h",    11},
                                    {"?",    11}};
        getline(cin, actionStr);


        switch (dict[actionStr]) {
            case 1 : {
                cout << "Enter full filepath: ";
                string path;
                getline(cin, path);
                ssv.parseSsvFromFile(path);
                cout << endl;
                break;
            }

            case 2: {
                if (ssv.isIsDataLoaded()) {
                    cout << "Data already loaded!" << endl;
                    break;
                }
                string line;
                do {
                    getline(cin, line);
                    if (line.empty()) break;

                    ssv.addRow(line);

                } while (!line.empty());
                break;
            }

            case 3: {
                ssv.clear();
                cout << "Workspace clear" << endl;
                break;
            }

            case 4: {
                if (!ssv.isIsDataLoaded()) {
                    cout << "Not data loaded!" << endl;
                    break;
                }
                cout << "Enter full filepath to save: ";
                string pathToSave;
                getline(cin, pathToSave);
                if (ssv.saveSsvToFile(pathToSave)) {
                    cout << "File saved" << endl;
                } else {
                    cout << "error" << endl;
                }
                break;
            }

            case 5: {
                if (!ssv.isIsDataLoaded()) {
                    cout << "Not data loaded!" << endl;
                    break;
                }
                string rawRow;
                cout << "Enter row: ";
                getline(cin, rawRow);
                ;

                if (ssv.addRow(rawRow)){
                    cout << "Row successfully added" << endl;
                } else {
                    cout << "error" << endl;
                }
                break;
            }

            case 6: {
                if (!dataLoaded) {
                    cout << "No data loaded!" << endl;
                    break;
                }
                string numberToShowStr;
                cout << "Enter row number (\"all\" to show all): ";
                getline(cin, numberToShowStr);


                if (numberToShowStr == "all") {
                    ssv.printSsv(cout);
                } else {
                    int numberToShow;
                    try {
                        numberToShow = std::atoi(numberToShowStr.c_str());
                    } catch (exception) {
                        cout << "Wrong number!" << endl;
                        break;
                    }
                    ssv.printSsv(cout, numberToShow);
                }
                break;
            }

            case 7: {
                string newSeparatorStr;
                cout << "Enter new separator (comma for .csv is preferable): ";
                getline(cin, newSeparatorStr);
                if (newSeparatorStr.length() != 1) {
                    cout << "Separator contain only 1 symbol!" << endl;
                } else {
                    ssv.changeSeparator(newSeparatorStr[0]);
                }
                break;
            }

            case 8: {
                if (!ssv.isIsDataLoaded()) {
                    cout << "No data loaded" << endl;
                    break;
                }
                string numberOfRowToInsertStr;
                ptrdiff_t numberOfRowToInsert;
                cout << "Write number of row to insert: ";
                getline(cin, numberOfRowToInsertStr);
                try {
                    numberOfRowToInsert = std::atoi(numberOfRowToInsertStr.c_str());
                } catch (exception) {
                    cout << "Ivalid number!" << endl;
                    break;
                }

                string rawRow;
                cout << "Enter row to insert: ";
                getline(cin, rawRow);

                if (ssv.insertRow(rawRow, numberOfRowToInsert))
                {
                    cout << "Successfully inserted" << endl;
                } else {
                    cout << "err" << endl;
                }

                break;
            }

            case 9: {
                if (!dataLoaded) {
                    cout << "No data loaded" << endl;
                    break;
                }
                string numberOfRowToRemoveStr;
                ptrdiff_t numberOfRowToRem;
                cout << "Write number of row to remove: ";
                getline(cin, numberOfRowToRemoveStr);
                try {
                    numberOfRowToRem = std::atoi(numberOfRowToRemoveStr.c_str());
                } catch (exception) {
                    cout << "Ivalid number!" << endl;
                    break;
                }

                if (ssv.removeRow(numberOfRowToRem)) {
                    cout << "Successfully removed" << endl;
                } else {
                    cout << "err";
                }
                break;
            }

            case 11: {
                showHelp();
                break;
            }

            case 10: {
                wannaExit = true;
                break;
            }

            default: {
                cout << "Wrong command. \'?\' or \'h\' to see help" << endl;
                break;
            }

        }

    }

}

int main() {
    SsvData ssv;
    ssv.parseSsvFromFile("/Users/boris/ssv/2.csv");

    cout << "Введенная таблица" << endl << endl << ssv << endl << endl;

    cout << "Получим первую строку и изменим имя первой колонки на newId" << endl;

    SsvData::LRow row{ssv.getBindedRow(0)};
    row[0].get() = "newId";

    cout << "Получим вторую колонку и добавим ее в конец" << endl;

    SsvData::Column column{ssv.getColumn(1)};
    ssv.addColumn(column);

    cout << "Изменим 3-ий элемент в 4 колонке на \'CPP\'" << endl;

    ssv.at(2, 3) = "CPP";

    cout << "Выведем первые 3 строки измененных данных, затем очистим загруженные данные" << endl << endl;

    ssv.printSsv(cout, 3);
    ssv.clear();

    cout << endl;

    return 0;
}