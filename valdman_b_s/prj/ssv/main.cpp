#include <string>
#include <vector>
#include <iostream>
#include <fstream>

typedef std::string Cell;
typedef std::vector<Cell> Row;
typedef std::vector<Row> Ssv;


using namespace std;

Ssv ParseCSV(const string &csvSource) {
    Ssv lines;
    bool inQuote(false);
    bool newLine(false);
    string field;
    lines.clear();
    vector<string> line;

    string::const_iterator aChar = csvSource.begin();
    while (aChar != csvSource.end()) {
        switch (*aChar) {
            case '"':
                newLine = false;
                inQuote = !inQuote;
                break;

            case ',':
                newLine = false;
                if (inQuote) {
                    field += *aChar;
                } else {
                    line.push_back(field);
                    field.clear();
                }
                break;

            case '\n':
            case '\r':
                if (inQuote) {
                    field += *aChar;
                } else {
                    if (!newLine) {
                        line.push_back(field);
                        lines.push_back(line);
                        field.clear();
                        line.clear();
                        newLine = true;
                    }
                }
                break;

            default:
                newLine = false;
                field.push_back(*aChar);
                break;
        }

        aChar++;
    }

    if (field.size())
        line.push_back(field);

    if (line.size())
        lines.push_back(line);

    return lines;
}

int main() {

    std::ifstream file("/Users/boris/Desktop/plop.csv");

    std::string str((std::istreambuf_iterator<char>(file)),
                    std::istreambuf_iterator<char>());

    Ssv ssv = ParseCSV(str);
    cout << '!';

    return 0;
}