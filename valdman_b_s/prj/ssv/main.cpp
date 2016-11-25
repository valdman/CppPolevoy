#include <map>
#include "ssv_service.h"

using namespace std;

void showHelp() {
    cout
            << "\'open\' - Load data from CSV" << endl
            << "\'man\' - Manually enter CSV" << endl
            << "\'emp\' - Load empty project" << endl
            << "\'save\' - Export data to file" << endl
            << "\'add - Add row to file end" << endl
            << "\'sh\' - Show data" << endl
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
        std::map<string, char> dict{{"open", '1'},
                                    {"man",  '2'},
                                    {"emp",  '3'},
                                    {"save", '4'},
                                    {"add",  '5'},
                                    {"sh",   '6'},
                                    {"q",    'q'},
                                    {"h",    'h'},
                                    {"?",    'h'}};
        getline(cin, action);

        switch (dict[action]) {
            case '1' : {
                cout << "Enter full filepath: ";
                string path;
                getline(cin, path);
                ssv = ssvService.parseSsvFromFile(path);
                dataLoaded = true;
                cout << endl;
                break;
            }

            case '2': {
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

            case '3': {
                break;
            }

            case '4': {
                if (!dataLoaded) {
                    cout << "Not data loaded!" << endl;
                    break;
                }
                cout << "Enter full filepath to save: ";
                string pathToSave;
                getline(cin, pathToSave);
                break;
            }

            case '5': {
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

            case '6': {
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

            case 'h': {
                showHelp();
                break;
            }

            case 'q': {
                wannaExit = true;
                break;
            }

            default: {
                cout << "Wrong command" << endl;
                break;
            }

        }

    }

    return 0;
}