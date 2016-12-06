//
// Created by Борис Вальдман on 22.10.16.
//

#include <fstream>
#include <iomanip>
#include "ssvdata.h"

typedef std::string Cell;
typedef std::string RawRow;
typedef std::vector<Cell> Row;
typedef std::vector<Row> Ssv;

bool SsvData::parseSsvFromString(const std::string &inputData) {
    if (isDataLoaded) {
        return false;
    }
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

    data = ssv;
    isDataLoaded = true;
    rowNumber = data.size();
    columnNumber = (data[0].size());
    return true;
}

bool SsvData::parseSsvFromFile(const std::string &filePath) {
    if (isDataLoaded) {
        return false;
    }
    std::ifstream file(filePath);

    std::string str((std::istreambuf_iterator<char>(file)),
                    std::istreambuf_iterator<char>());

    return parseSsvFromString(str);;
}

Row SsvData::parseStrToRow(const RawRow &rawRow) {
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

std::ostream &SsvData::printSsv(std::ostream &ostrm) const
{
    printSsv(ostrm, data.size());
    return ostrm;
}

std::ostream &SsvData::printSsv(std::ostream &ostrm, const ptrdiff_t numberOfRowsToShow) const
{
    if (numberOfRowsToShow > data.size() || numberOfRowsToShow < 1) {
        throw std::out_of_range("Too much row to show");
    }

    Row thisRow;

    for (int i = 0; i < numberOfRowsToShow; ++i) {
        thisRow = data[i];
        for (int j = 0; j < thisRow.size(); ++j) {
            ostrm << std::setw(13) << thisRow[j] << "\t";
        }
        ostrm.put('\n');
    }
    ostrm << std::endl;

    return ostrm;
}

bool SsvData::saveSsvToFile(const std::string &filePath) {
    if (!isDataLoaded) {
        return false;
    }
    std::ofstream fileToSave;
    fileToSave.open(filePath);

    for (int i = 0; i < data.size(); ++i) {
        Row currentRow{data[i]};
        for (int j = 0; j < currentRow.size(); ++j) {
            fileToSave << '\"' << currentRow[j] << "\"" << separator;
        }

        fileToSave << std::endl;
    }

    fileToSave.close();
    return true;
}

bool SsvData::changeSeparator(const char &newSeparator)
{
    separator = newSeparator;
    return true;
}

char SsvData::getSeparator()
{
    return separator;
}

bool SsvData::isIsDataLoaded() const
{
    return isDataLoaded;
}

bool SsvData::addRow(const RawRow &rawRow)
{
    Row rowToAdd{parseStrToRow(rawRow)};

    if (data.empty() || rowToAdd.size() == data.begin()->size()) {
        data.push_back(rowToAdd);
    } else {
        return false;
    }

    ++rowNumber;
    columnNumber = data[0].size();
    return true;
}

bool SsvData::clear()
{
    data.clear();
    isDataLoaded  = false;
    return true;
}

bool SsvData::insertRow(const RawRow& rawRow, ptrdiff_t idxToIns)
{
    if (idxToIns >= data.size() || idxToIns < 0) {
        return false;
    }

    Row rowToInsert{parseStrToRow(rawRow)};
    if (rowToInsert.size() != data[0].size()) {
        return false;
    }
    data.insert(data.begin() + idxToIns, rowToInsert);
    ++rowNumber;
    return true;
}

bool SsvData::removeRow(ptrdiff_t idxToRem)
{
    if (idxToRem >= data.size() || idxToRem < 0) {
        data.erase(data.begin() + idxToRem);
        --rowNumber;
        return true;
    } else {
        return false;
    }
}

Cell& SsvData::at(ptrdiff_t rowIndex, ptrdiff_t columnIndex)
{
    if (!isDataLoaded || rowIndex >= data.size() || columnIndex >= data[0].size())
    {
        throw std::out_of_range("Cell index out of ssv");
    }
    return data[rowIndex][columnIndex];
}

SsvData::Column& SsvData::getColumn(ptrdiff_t idx)
{
    if (!isDataLoaded || idx >= data[0].size())
    {
        throw std::out_of_range("Cell index out of ssv");
    }

    Column res;
    for (ptrdiff_t i = 0; i < data[0].size(); ++i)
    {
        res.push_back(data[i][idx]);
    }

    return res;
}

Row &SsvData::getRow(ptrdiff_t idx)
{
    if (!isDataLoaded || idx >= data.size())
    {
        throw std::out_of_range("Out of rows in ssv");
    }

    return data[idx];
}

Row &SsvData::operator[](ptrdiff_t idx)
{
    if (!isDataLoaded || idx >= data.size())
    {
        throw std::out_of_range("Out of rows in ssv");
    }

    return data[idx];
}

std::ostream &SsvData::writeTo(std::ostream &os) const
{
    this->printSsv(os);
    return os;
}
