//
// Created by Борис Вальдман on 22.10.16.
//

#include <fstream>
#include <iomanip>
#include "ssvdata.h"

bool SsvData::parseSsvFromString(const std::string &inputData) {
    if (isDataLoaded) {
        return false;
    }
    Ssv ssv;
    bool inQuote(false);
    bool newLine(false);
    ptrdiff_t columnNumber{-1};
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
                    if (row.size() == columnNumber || columnNumber == -1) {
                        ssv.push_back(row);
                        if (columnNumber == -1) {
                            columnNumber = row.size();
                        }
                    }
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

    data = ssv;
    isDataLoaded = true;
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

SsvData::Row SsvData::parseStrToRow(const RawRow &rawRow) {
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
    if (numberOfRowsToShow > getRowNumber() || numberOfRowsToShow < 1) {
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

    for (int i = 0; i < getRowNumber(); ++i) {
        Row currentRow{data[i]};
        for (int j = 0; j < getColumnNumber(); ++j) {
            fileToSave << '\"' << currentRow[j] << "\"";
            if(j != currentRow.size() - 1) {
                fileToSave << separator;
            }
        }
        if (i != getRowNumber() - 1) {
            fileToSave << std::endl;
        }
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

    return addRow(rowToAdd);
}

bool SsvData::clear()
{
    data.clear();
    isDataLoaded  = false;
    return true;
}

bool SsvData::insertRow(const RawRow& rawRow, ptrdiff_t idxToIns)
{
    if (!isDataLoaded || idxToIns >= getRowNumber() || idxToIns < 0) {
        return false;
    }

    Row rowToInsert{parseStrToRow(rawRow)};
    if (rowToInsert.size() != data[0].size()) {
        return false;
    }
    data.insert(data.begin() + idxToIns, rowToInsert);
    return true;
}

bool SsvData::removeRow(ptrdiff_t idxToRem)
{
    if (!isDataLoaded || idxToRem >= getRowNumber() || idxToRem < 0) {
        data.erase(data.begin() + idxToRem);
        return true;
    } else {
        return false;
    }
}

SsvData::Cell& SsvData::at(ptrdiff_t rowIndex, ptrdiff_t columnIndex)
{
    if (!isDataLoaded || rowIndex >= getRowNumber() || columnIndex >= getColumnNumber())
    {
        throw std::out_of_range("Cell index out of ssv");
    }
    return data[rowIndex][columnIndex];
}

SsvData::LColumn SsvData::getColumn(ptrdiff_t idx)
{
    if (!isDataLoaded || idx >= getColumnNumber())
    {
        throw std::out_of_range("Cell index out of ssv");
    }

    LColumn res;
    for (ptrdiff_t i = 0; i < getRowNumber(); ++i)
    {
        res.push_back(data[i][idx]);
    }

    return res;
}

SsvData::LRow SsvData::getRow(ptrdiff_t idx)
{
    if (!isDataLoaded || idx >= getRowNumber())
    {
        throw std::out_of_range("Out of rows in ssv");
    }

    LRow res;

    for (int i = 0; i < getRowNumber(); ++i) {
        res.push_back(data[idx][i]);
    }

    return res;
}

std::ostream &SsvData::writeTo(std::ostream &os) const
{
    this->printSsv(os);
    return os;
}

bool SsvData::addColumn(const SsvData::Column &columnToAdd)
{
    if((columnToAdd.size() == getRowNumber() && columnToAdd.size() != 0) || !isDataLoaded) {
        for (int i = 0; i < getRowNumber(); ++i) {
            data[i].push_back(columnToAdd[i]);
        }

        return true;
    }
    return false;
}

void SsvData::addEmptyColumn()
{
    for (int i = 0; i < getRowNumber(); ++i) {
        data[i].push_back("");
    }
}

bool SsvData::insertColumn(const SsvData::Column &colToIns, ptrdiff_t idxToIns)
{
    if (!isDataLoaded || idxToIns >= getColumnNumber() || idxToIns < 0) {
        return false;
    } else {
        for (int i = 0; i < getRowNumber(); ++i) {
            data[i].insert(data[i].begin() + idxToIns, colToIns[i]);
        }
    }
    return true;
}

bool SsvData::removeColumn(ptrdiff_t idxToRemove)
{
    if(!isDataLoaded || idxToRemove >= getColumnNumber() || idxToRemove < 0) {
        return false;
    } else {
        for (int i = 0; i < getRowNumber(); ++i) {
            data[i].erase(data[i].begin() + idxToRemove);
        }
    }
    return true;
}

void SsvData::addEmptyRow()
{
    Row empRow;
    data.push_back(empRow);
}

bool SsvData::addRow(const Row &row)
{
    if (!isDataLoaded || row.size() == getColumnNumber()) {
        data.push_back(row);
        return true;
    } else {
        return false;
    }
}
