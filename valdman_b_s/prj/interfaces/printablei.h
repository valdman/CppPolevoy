//
// Created by Борис Вальдман on 28.11.16.
//

#ifndef INTERFACES_PRINTABLEI_H
#define INTERFACES_PRINTABLEI_H

#include <iosfwd>

class PrintableI{
public:
    PrintableI() = default;
    virtual std::ostream& writeTo(std::ostream& os) const = 0;
};

inline std::ostream& operator<<(std::ostream& ostream, const PrintableI& obj)
{
    obj.writeTo(ostream);
    return ostream;
}

#endif //INTERFACES_PRINTABLEI_H
