//
// Created by Борис Вальдман on 07.11.16.
//

#ifndef HG_LISTSTACK_H_20161107
#define HG_LISTSTACK_H_20161107

template<class T>
class ListStack {

public:
    ListStack()= default;
    ~ListStack()
    {
        while (!isEmpty())
        {
            pop();
        }
    }

    ListStack(const ListStack& stackToCopy)
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

    ListStack& operator=(const ListStack<T>& stackToEqual); //todo: equal operator

    const T& pop()
    {
        --size;
        moveDown();
        if(isEmpty()) {
            std::out_of_range("Out of stack!");
        }
        return head_->data_;
    }

    void push(const T& data)
    {
        ++size;
        if (head_ == nullptr) {
            head_ = new Node();
        }

        head_->data_ = data;
        moveUp();

    }

private:
    struct Node{
        Node* pNext_{nullptr};
        T data_{0.0};
    };

private:
    void moveUp()
    {
        Node* upperNode = new Node();
        upperNode->pNext_ = head_;
        head_ = upperNode;
    }

    void moveDown()
    {
        Node* downerNode = head_->pNext_;
        delete head_;
        head_ = downerNode;
    }

    bool isEmpty()
    {
        return (head_->pNext_ == nullptr);
    }

    void moveDownWithConcreteHead(Node** concreteHead)
    {
        *concreteHead = (*concreteHead)->pNext_;
    }

    void moveUpWithConcreteHead(Node** concreteHead)
    {
        Node* upperNode = new Node();
        upperNode->pNext_ = (*concreteHead);
        (*concreteHead) = upperNode;
    }

private:
    Node* head_{nullptr};
    ptrdiff_t size{0};
};


#endif //HG_LISTSTACK_H_20161107
