#include <map>
#include "ssv_service.h"

using namespace std;

void showHelp() {
    cout
            << "\'open\' - Load data from CSV" << endl
            << "\'man\' - Manually enter CSV" << endl
            << "\'emp\' - Load empty project" << endl
            << "\'sh\' - Show data" << endl
            << "\'save\' - Export data to file" << endl << endl

            << "\'sep\' - Change separator (\',\' by default)" << endl
            << "\'add\' - Add row to file end" << endl
            << "\'ins\' - Insert row to position" << endl
            << "\'rem\' - Remove row from position" << endl
            << "\'h\' or \'?\' - Show this help" << endl
            << "\'q\' - Quit" << endl;
}

int main() {
    SsvService ssvService;
    Ssv ssv;

    bool wannaExit(false);
    bool dataLoaded(false);

    showHelp();

    while (!wannaExit) {
        cout << ">";
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
                                    {"q",    0},
                                    {"h",    -1},
                                    {"?",    -1}};
        getline(cin, action);

        switch (dict[action]) {
            case 1 : {
                cout << "Enter full filepath: ";
                string path;
                getline(cin, path);
                ssv = ssvService.parseSsvFromFile(path);
                dataLoaded = true;
                cout << endl;
                break;
            }

            case 2: {
                if (dataLoaded) {
                    cout << "Data already loaded!" << endl;
                    break;
                }
                dataLoaded = true;
                RawRow line;
                do {
                    getline(cin, line);
                    if (line.empty()) break;

                    Row rowToAdd{ssvService.parseStrToRow(line)};

                    if (ssv.empty() || rowToAdd.size() == ssv.begin()->size()) {
                        ssv.push_back(rowToAdd);
                    } else {
                        cout << "This row not valid for this CSV. Use row with " << ssv.begin()->size()
                             << " cells, not " << rowToAdd.size() << endl;
                    }

                } while (!line.empty());
                break;
            }

            case 3: {
                dataLoaded = false;
                ssv.clear();
                cout << "Workspace clear" << endl;
                break;
            }

            case 4: {
                if (!dataLoaded) {
                    cout << "Not data loaded!" << endl;
                    break;
                }
                cout << "Enter full filepath to save: ";
                string pathToSave;
                getline(cin, pathToSave);
                ssvService.saveSsvToFile(ssv, pathToSave);
                break;
            }

            case 5: {
                if (!dataLoaded) {
                    cout << "Not data loaded!" << endl;
                    break;
                }
                RawRow rawRow;
                cout << "Enter row: ";
                getline(cin, rawRow);
                Row rowToAdd(ssvService.parseStrToRow(rawRow));

                if (rowToAdd.size() == ssv.begin()->size() || ssv.begin()->size() == 0) {
                    ssv.push_back(rowToAdd);
                } else {
                    cout << "This row not valid for this CSV. Use row with " << ssv.begin()->size() << " cells, not "
                         << rowToAdd.size() << endl;
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
                    ssvService.printSsv(cout, ssv);
                } else {
                    int numberToShow;
                    try {
                        numberToShow = std::atoi(numberToShowStr.c_str());
                    } catch (exception) {
                        cout << "Wrong number!" << endl;
                        break;
                    }
                    ssvService.printSsv(cout, ssv, numberToShow);
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
                    ssvService.separator = newSeparatorStr[0];
                }
                break;
            }

            case 8: {
                if (!dataLoaded) {
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
                if (numberOfRowToInsert >= ssv.size() || numberOfRowToInsert < 0) {
                    cout << "More than number of rows. (In loaded data " << ssv.size() << " rows)" << endl;
                    break;
                }
                RawRow rawRow;
                cout << "Enter row to insert: ";
                getline(cin, rawRow);
                Row rowToInsert{ssvService.parseStrToRow(rawRow)};
                if (rowToInsert.size() != ssv[0].size()) {
                    cout << "This row not valid for this CSV. Use row with " << ssv.begin()->size() << " cells, not "
                         << rowToInsert.size() << endl;
                }
                ssv.insert(ssv.begin() + numberOfRowToInsert, rowToInsert);
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
                if (numberOfRowToRem >= ssv.size() || numberOfRowToRem < 0) {
                    cout << "More than number of rows. (In loaded data " << ssv.size() << " rows)" << endl;
                    break;
                }
                ssv.erase(ssv.begin() + numberOfRowToRem);
                break;
            }

            case -1: {
                showHelp();
                break;
            }

            case 0: {
                wannaExit = true;
                break;
            }

            default: {
                cout << "Wrong command. \'?\' or \'h\' to see help" << endl;
                break;
            }

        }

    }

    return 0;
}