//
// Created by Борис Вальдман on 22.10.16.
//

#ifndef SSV_SSV_SERVICE_H
#define SSV_SSV_SERVICE_H

#include <vector>
#include <string>
#include <iostream>
#include <printablei.h>


class SsvData : PrintableI {
    typedef std::string Cell;
    typedef std::string RawRow;
    typedef std::vector<Cell> Row;
    typedef std::vector<Cell> Column;
    typedef std::vector<Row> Ssv;

public:
    SsvData() = default;
    ~SsvData() = default;

    bool parseSsvFromString(const std::string &inputData);
    bool parseSsvFromFile(const std::string &filePath);
    bool saveSsvToFile(const std::string &filePath);

    bool clear();

    bool addRow(const RawRow &rawRow);
    bool insertRow(const RawRow& rawRow, ptrdiff_t idxToIns);
    bool removeRow(ptrdiff_t idxToRem);
    Cell& at(ptrdiff_t rowIndex, ptrdiff_t columnIndex);
    Row& getRow(ptrdiff_t idx);
    Row& operator[](ptrdiff_t idx);
    Column& getColumn(ptrdiff_t idx);

    Row parseStrToRow(const RawRow &rawRow);

    char getSeparator();
    bool changeSeparator(const char& newSeparator);

public:
    std::ostream &printSsv(std::ostream &ostrm) const;

    std::ostream &printSsv(std::ostream &ostrm, const ptrdiff_t numberOfRowsToShow) const;


public:
    bool isIsDataLoaded() const;
    ptrdiff_t getRowNumber()
    {
        return rowNumber;

    }

    ptrdiff_t getColumnNumber()
    {
        return columnNumber;
    }

private:
    std::ostream &writeTo(std::ostream &os) const override;

private:
    Ssv data;
    ptrdiff_t rowNumber{0};
    ptrdiff_t columnNumber{0};
    bool isDataLoaded{false};
    char separator{','};
};


#endif //SSV_SSV_SERVICE_H
