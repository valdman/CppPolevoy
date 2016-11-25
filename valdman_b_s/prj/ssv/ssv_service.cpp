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
    int columnNumber{-1};
    Cell cell;
    ssv.clear();
    Row row;

    Cell::const_iterator aChar = inputData.begin();
    while (aChar != inputData.end()) {
        if (*aChar == '"') {
            newLine = false;
            inQuote = !inQuote;
        } else if (*aChar == separator) {
            newLine = false;
            if (inQuote) {
                cell += *aChar;
            } else {
                row.push_back(cell);
                cell.clear();
            }
        } else if (*aChar == '\n' || *aChar == '\r') {
            if (inQuote) {
                cell += *aChar;
            } else {
                if (!newLine) {
                    row.push_back(cell);
                    if (row.size() == columnNumber || columnNumber == -1)
                        ssv.push_back(row);
                    else {
                        throw std::runtime_error(
                                "Wrong format of CSV (number of cell in some row incomparable with another)");
                    }
                    cell.clear();
                    row.clear();
                    newLine = true;
                }
            }
        } else {
            newLine = false;
            cell.push_back(*aChar);
        }

        aChar++;
    }

    if (cell.size())
        row.push_back(cell);

    if (row.size())
        std::reverse(row.begin(), row.end());

    if (row.size() == columnNumber || columnNumber == -1)
        ssv.push_back(row);
    else {
        throw std::runtime_error("Wrong format of CSV (number of cell in some row incomparable with another)");
    }

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

    while (*aChar != '\r' && *aChar != '\n' && *aChar != '\0') {
        if (*aChar == '"') {
            inQuote = !inQuote;
        } else if (*aChar == separator) {
            if (inQuote) {
                cell += *aChar;
            } else {
                resultRow.push_back(cell);
                cell.clear();
            }
        } else {
            cell.push_back(*aChar);
        }

        ++aChar;
    }

    if (cell.size()) {
        resultRow.push_back(cell);
    }

    return resultRow;
}

std::ostream &SsvService::printSsv(std::ostream &ostrm, const Ssv &ssv) {
    printSsv(ostrm, ssv, ssv.size());
    return ostrm;
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

void SsvService::saveSsvToFile(const Ssv &ssv, const std::string &filePath) {
    std::ofstream fileToSave;
    fileToSave.open(filePath);

    for (int i = 0; i < ssv.size(); ++i) {
        Row currentRow{ssv[i]};
        for (int j = 0; j < currentRow.size(); ++j) {
            fileToSave << '\"' << currentRow[j] << "\"" << separator;
        }

        fileToSave << std::endl;
    }

    fileToSave.close();
}
