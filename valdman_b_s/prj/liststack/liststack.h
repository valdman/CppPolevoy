//
// Created by Борис Вальдман on 07.11.16.
//

#ifndef HG_LISTSTACK_H_20161107
#define HG_LISTSTACK_H_20161107


class ListStack {

public:
    ListStack()= default;
    ~ListStack();
    ListStack(const ListStack& stackToCopy); //todo: construct of copy
    ListStack& operator=(const ListStack& stackToEqual); //todo: equal operator

    double pop();
    void push(const double &data);

private:
    struct Node{
        Node* pNext_{nullptr};
        double data_{0.0};
    };

private:
    void moveUp();
    void moveDown();
    bool isEmpty();

    void moveDownWithConcreteHead(Node** concreteHead);
    void moveUpWithConcreteHead(Node** concreteHead);

private:
    Node* head_{nullptr};
    int size{0};
};


#endif //HG_LISTSTACK_H_20161107
