//
// Created by Борис Вальдман on 22.10.16.
//

#include <fstream>
#include <iomanip>
#include "ssv_service.h"

Ssv SsvService::parseSsvFromString(const std::string &inputData) {
    Ssv ssv;
    bool inQuote(false);
    bool newLine(false);
    Cell cell;
    ssv.clear();
    Row row;

    Cell::const_iterator aChar = inputData.begin();
    while (aChar != inputData.end()) {
        switch (*aChar) {
            case '"':
                newLine = false;
                inQuote = !inQuote;
                break;

            case ',':
                newLine = false;
                if (inQuote) {
                    cell += *aChar;
                } else {
                    row.push_back(cell);
                    cell.clear();
                }
                break;

            case '\n':
            case '\r':
                if (inQuote) {
                    cell += *aChar;
                } else {
                    if (!newLine) {
                        row.push_back(cell);
                        ssv.push_back(row);
                        cell.clear();
                        row.clear();
                        newLine = true;
                    }
                }
                break;

            default:
                newLine = false;
                cell.push_back(*aChar);
                break;
        }

        aChar++;
    }

    if (cell.size())
        row.push_back(cell);

    if (row.size())
        std::reverse(row.begin(), row.end());
    ssv.push_back(row);

    return ssv;
}

Ssv SsvService::parseSsvFromFile(const std::string &filePath) {
    std::ifstream file(filePath);

    std::string str((std::istreambuf_iterator<char>(file)),
                    std::istreambuf_iterator<char>());

    return parseSsvFromString(str);
}

Row SsvService::parseStrToRow(const RawRow &rawRow) {
    bool inQuote(false);
    Cell cell;
    Row resultRow;

    Cell::const_iterator aChar = rawRow.begin();
    while (*aChar != '\r' && *aChar != '\n') {
        switch (*aChar) {
            case '"':
                inQuote = !inQuote;
                break;

            case ',':
                if (inQuote) {
                    cell += *aChar;
                } else {
                    resultRow.push_back(cell);
                    cell.clear();
                }
                break;

            default:
                cell.push_back(*aChar);
                break;
                ++aChar;
        }
        if (cell.size())
            resultRow.push_back(cell);
    }

    return resultRow;
}

std::ostream &SsvService::printSsv(std::ostream &ostrm, const Ssv &ssv) {
    printSsv(ostrm, ssv, ssv.size());
}

std::ostream &SsvService::printSsv(std::ostream &ostrm, const Ssv &ssv, const ptrdiff_t numberOfRowsToShow) {
    if (numberOfRowsToShow > ssv.size() || numberOfRowsToShow < 1) {
        throw std::out_of_range("Too much row to show");
    }

    Row thisRow;

    for (int i = 0; i < numberOfRowsToShow; ++i) {
        thisRow = ssv[i];
        for (int j = 0; j < thisRow.size(); ++j) {
            ostrm << std::setw(13) << thisRow[j] << "\t";
        }
        ostrm.put('\n');
    }
    ostrm << std::endl;

    return ostrm;
}
