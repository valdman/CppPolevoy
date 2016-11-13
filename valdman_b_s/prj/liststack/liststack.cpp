//
// Created by Борис Вальдман on 07.11.16.
//

#include "stdexcept"
#include "liststack.h"

void ListStack::push(const double &data)
{
    ++size;
    if (head_ == nullptr) {
        head_ = new Node();
    }

    head_->data_ = data;
    moveUp();
}

void ListStack::moveUp()
{
    Node* upperNode = new Node();
    upperNode->pNext_ = head_;
    head_ = upperNode;
}

void ListStack::moveDown()
{
    Node* downerNode = head_->pNext_;
    delete head_;
    head_ = downerNode;
}

double ListStack::pop()
{
    --size;
    moveDown();
    if(isEmpty()) {
        std::out_of_range("Out of stack!");
    }
    double ans{head_->data_};
    return ans;
}

ListStack::~ListStack()
{
    while (!isEmpty())
    {
        pop();
    }
}

bool ListStack::isEmpty() {
    return (head_->pNext_ == nullptr);
}

ListStack::ListStack(const ListStack &stackToCopy)
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

void ListStack::moveDownWithConcreteHead(ListStack::Node** concreteHead)
{
    *concreteHead = (*concreteHead)->pNext_;
}

void ListStack::moveUpWithConcreteHead(ListStack::Node** concreteHead)
{
    Node* upperNode = new Node();
    upperNode->pNext_ = (*concreteHead);
    (*concreteHead) = upperNode;
}



