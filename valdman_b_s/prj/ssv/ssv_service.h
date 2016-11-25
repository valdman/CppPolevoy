//
// Created by Борис Вальдман on 22.10.16.
//

#ifndef SSV_SSV_SERVICE_H
#define SSV_SSV_SERVICE_H

#include <vector>
#include <string>
#include <iostream>

typedef std::string Cell;
typedef std::string RawRow;
typedef std::vector<Cell> Row;
typedef std::vector<Row> Ssv;

class SsvService {
public:
    SsvService() = default;

    ~SsvService() = default;

    Ssv parseSsvFromString(const std::string &inputData);

    Ssv parseSsvFromFile(const std::string &filePath);

    void saveSsvToFile(const std::string &filePath);

    Row parseStrToRow(const RawRow &rawRow);

public:
    std::ostream &printSsv(std::ostream &ostrm, const Ssv &ssv);

    std::ostream &printSsv(std::ostream &ostrm, const Ssv &ssv, const ptrdiff_t numberOfRowsToShow);
};


#endif //SSV_SSV_SERVICE_H
