//
// Created by Борис Вальдман on 22.10.16.
//

#ifndef SSV_SSV_SERVICE_H
#define SSV_SSV_SERVICE_H

#include <vector>
#include <string>
#include <iostream>


class SsvData {
    typedef std::string Cell;
    typedef std::string RawRow;
    typedef std::vector<Cell> Row;
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

    Row parseStrToRow(const RawRow &rawRow);

    char getSeparator();
    bool changeSeparator(const char& newSeparator);

public:
    std::ostream &printSsv(std::ostream &ostrm);

    std::ostream &printSsv(std::ostream &ostrm, const ptrdiff_t numberOfRowsToShow);


public:
    bool isIsDataLoaded() const;

private:
    Ssv data;
    bool isDataLoaded{false};
    char separator{','};
};


#endif //SSV_SSV_SERVICE_H
