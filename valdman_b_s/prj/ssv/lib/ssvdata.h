//
// Created by Борис Вальдман on 22.10.16.
//

#ifndef HG_H_SSV_DATA_20161016
#define HG_H_SSV_DATA_20161016

#include <vector>
#include <string>
#include <iosfwd>
#include <printablei.h>

class SsvData : public PrintableI {
public:
    typedef std::string Cell;
    typedef std::reference_wrapper<Cell> LCell;
    typedef std::string RawRow;
    typedef std::vector<Cell> Row;
    typedef std::vector<LCell> LRow;
    typedef std::vector<Cell> Column;
    typedef std::vector<LCell> LColumn;
    typedef std::vector<Row> Ssv;

public:
    SsvData() = default;
    SsvData(const SsvData& ssvData) = default;
    ~SsvData() = default;
    SsvData& operator=(const SsvData& ssvData) = default;

    bool parseSsvFromString(const std::string &inputData);
    bool parseSsvFromFile(const std::string &filePath);
    bool saveSsvToFile(const std::string &filePath);
    bool clear();

    bool addRow(const RawRow &rawRow);
    bool addRow(const Row& row);
    bool insertRow(const RawRow& rawRow, ptrdiff_t idxToIns);
    bool removeRow(ptrdiff_t idxToRem);
    void addEmptyRow();

    bool addColumn(const Column& colToAdd);
    bool removeColumn(ptrdiff_t idxToRemove);
    bool insertColumn(const Column& colToIns, ptrdiff_t idxToIns);
    void addEmptyColumn();

    Cell& at(ptrdiff_t rowIndex, ptrdiff_t columnIndex);
    const Cell& at(ptrdiff_t rowIndex, ptrdiff_t columnIndex) const;
    LRow getBindedRow(ptrdiff_t idx);
    Row getRow(ptrdiff_t idx);
    LColumn getBindedColumn(ptrdiff_t idx);
    Column getColumn(ptrdiff_t idx);

    Row parseStrToRow(const RawRow &rawRow);

public:
    std::ostream &printSsv(std::ostream &ostrm) const;
    std::ostream &printSsv(std::ostream &ostrm, const ptrdiff_t numberOfRowsToShow) const;
    std::ostream &writeTo(std::ostream &os) const override;

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

    char getSeparator();
    bool changeSeparator(const char& newSeparator);

private:
    Ssv data;
    bool isDataLoaded{false};
    char separator{','};
};

extern "C" void changeSeparatorInFile(const char* filePath, const char newSeparator);

#endif //HG_H_SSV_DATA_20161016
