//
// Created by Борис Вальдман on 22.10.16.
//

#ifndef SSV_SSV_SERVICE_H
#define SSV_SSV_SERVICE_H

#include <vector>
#include <string>
#include <iosfwd>
#include <printablei.h>


class SsvData : public PrintableI {
    typedef std::string Cell;
    typedef std::string RawRow;
    typedef std::vector<Cell> Row;
    typedef std::vector<std::reference_wrapper<Cell>> LRow;
    typedef std::vector<Cell> Column;
    typedef std::vector<std::reference_wrapper<Cell>> LColumn;
    typedef std::vector<Row> Ssv;

public:
    SsvData() = default;
    ~SsvData() = default;

    bool parseSsvFromString(const std::string &inputData);
    bool parseSsvFromFile(const std::string &filePath);
    bool saveSsvToFile(const std::string &filePath);

    bool clear();

    bool addRow(const RawRow &rawRow);
    bool addRow(const Row& row);
    bool insertRow(const RawRow& rawRow, ptrdiff_t idxToIns);
    bool removeRow(ptrdiff_t idxToRem);

    bool addColumn(const Column& colToAdd);
    bool removeColumn(ptrdiff_t idxToRemove);
    bool insertColumn(const Column& colToIns, ptrdiff_t idxToIns);
    void addEmptyColumn();
    void addEmptyRow();

    Cell& at(ptrdiff_t rowIndex, ptrdiff_t columnIndex);
    LRow getRow(ptrdiff_t idx);
    LColumn getColumn(ptrdiff_t idx);

    Row parseStrToRow(const RawRow &rawRow);
    char getSeparator();
    bool changeSeparator(const char& newSeparator);

public:
    std::ostream &printSsv(std::ostream &ostrm) const;

    std::ostream &printSsv(std::ostream &ostrm, const ptrdiff_t numberOfRowsToShow) const;


public:
    bool isIsDataLoaded() const;
    ptrdiff_t getRowNumber() const
    {
        return data.size();

    }

    ptrdiff_t getColumnNumber() const
    {
        return data[0].size();
    }

public:
    std::ostream &writeTo(std::ostream &os) const override;

private:
    Ssv data;
    bool isDataLoaded{false};
    char separator{','};
};


#endif //SSV_SSV_SERVICE_H
