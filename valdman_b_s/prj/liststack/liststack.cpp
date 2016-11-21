//
// Created by Борис Вальдман on 07.11.16.
//

#include "stdexcept"
#include "liststack.h"


template<class T>
void ListStack<T>::moveUp()
{
    Node* upperNode = new Node();
    upperNode->pNext_ = head_;
    head_ = upperNode;
}

template<class T>
void ListStack<T>::moveDown()
{
    Node* downerNode = head_->pNext_;
    delete head_;
    head_ = downerNode;
}

template<class T>
const T& ListStack<T>::pop()
{
    --size;
    moveDown();
    if(isEmpty()) {
        std::out_of_range("Out of stack!");
    }
    double ans{head_->data_};
    return ans;
}

template<class T>
ListStack<T>::~ListStack()
{
    while (!isEmpty())
    {
        pop();
    }
}

template<class T>
bool ListStack<T>::isEmpty() {
    return (head_->pNext_ == nullptr);
}

template<class T>
ListStack<T>::ListStack(const ListStack &stackToCopy)
{
    Node* theirFalseHead = stackToCopy.head_;
    head_ = new Node();

    for (int i = 0; i < stackToCopy.size; ++i) {
        moveUpWithConcreteHead(&head_);
    }

    for (int j = 0; j < stackToCopy.size; ++j) {
        head_->data_= theirFalseHead->data_;
        moveDownWithConcreteHead(&head_);
        moveDownWithConcreteHead(&theirFalseHead);
    }
}

template<class T>
void ListStack<T>::moveDownWithConcreteHead(ListStack::Node** concreteHead)
{
    *concreteHead = (*concreteHead)->pNext_;
}

template<class T>
void ListStack<T>::moveUpWithConcreteHead(ListStack::Node** concreteHead)
{
    Node* upperNode = new Node();
    upperNode->pNext_ = (*concreteHead);
    (*concreteHead) = upperNode;
}

template<class T>
void ListStack<T>::push(const T &data) {
    ++size;
    if (head_ == nullptr) {
        head_ = new Node();
    }

    head_->data_ = data;
    moveUp();

}



