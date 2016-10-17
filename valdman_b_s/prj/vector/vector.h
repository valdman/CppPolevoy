//
// Created by Борис Вальдман on 17.10.16.
//

#ifndef HG_VECTOR_H_20161017
#define HG_VECTOR_H_20161017


#include <iostream>

class Vector {

public:
    Vector();
    Vector(int init_size);
    Vector(const Vector& vector);
    ~Vector();
    Vector& operator= (const Vector& rhs);

    double& operator[](const ptrdiff_t idx);
    const double& operator[](const ptrdiff_t idx) const;
    ptrdiff_t size() const;
    void resize(const ptrdiff_t size);

    std::ostream& writeTo(std::ostream& ostrm);

private:
    ptrdiff_t size_{0};
    double* pointer_{nullptr};

};

std::ostream& operator<<(std::ostream& ostrm, Vector& obj);


#endif //HG_VECTOR_H_20161017
