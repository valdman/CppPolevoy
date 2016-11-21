//
// Created by Борис Вальдман on 07.11.16.
//

#ifndef HG_LISTSTACK_H_20161107
#define HG_LISTSTACK_H_20161107

template<class T>
class ListStack {

public:
    ListStack<T>()= default;
    ~ListStack<T>();
    ListStack<T>(const ListStack<T>& stackToCopy);
    ListStack<T>& operator=(const ListStack<T>& stackToEqual); //todo: equal operator

    const T& pop();
    void push(const T& data);

private:
    struct Node{
        Node* pNext_{nullptr};
        T data_{0.0};
    };

private:
    void moveUp();
    void moveDown();
    bool isEmpty();

    void moveDownWithConcreteHead(Node** concreteHead);
    void moveUpWithConcreteHead(Node** concreteHead);

private:
    Node* head_{nullptr};
    ptrdiff_t size{0};
};


#endif //HG_LISTSTACK_H_20161107
