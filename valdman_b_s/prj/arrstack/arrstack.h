//
// Created by Борис Вальдман on 31.10.16.
//

#ifndef HG_ARRSTACK_H_20161031
#define HG_ARRSTACK_H_20161031


class ArrStack {

public:
    ArrStack() = default;
    ArrStack(ArrStack& stack);
    ~ArrStack();

    ArrStack& operator=(const ArrStack& rhs);

public:
    const double& Pop();
    void Push(const double& value);
    const double& Check() const;

private:
    void Resize(const ptrdiff_t newSize);

private:
    ptrdiff_t cursor{-1};
    ptrdiff_t capasity{0};
    double* data{nullptr};
};


#endif //HG_ARRSTACK_H_20161031
