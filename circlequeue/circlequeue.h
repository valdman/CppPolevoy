//
// Created by Борис Вальдман on 19.12.16.
//

#ifndef CIRCLEQUEUE_CIRCLEQUEUE_H
#define CIRCLEQUEUE_CIRCLEQUEUE_H


class CircleQueue
{
public:
    CircleQueue() = default;
    CircleQueue(const CircleQueue& circleQueue)
    {
        Node* theirHeadNode{circleQueue.thisNode};
        Node* floatNode{theirHeadNode};
        do {
            push(floatNode->data);
            floatNode = floatNode->next;
        } while (floatNode != theirHeadNode);

    }
    ~CircleQueue() = default;
    /*
    {
        while (size) {
            pop();
        }
        delete thisNode;
    }
     */

    double pop()
    {
        if(!size) {
            throw std::out_of_range("Circlequeue is empty now");
        }
        double res{thisNode->data};

        Node* nextNode{thisNode->next};
        Node* prevNode{thisNode->previous};
        delete thisNode;

        thisNode = nextNode;
        thisNode->previous = prevNode;

        size--;

        return res;
    }

    void push(const double& data)
    {
        Node* newNode(new Node(data));

        if(thisNode != nullptr) {
            newNode->next = thisNode;
            newNode->previous = thisNode->previous;

            thisNode->previous->next = newNode;
            thisNode->previous = newNode;
        } else {
            thisNode = newNode;
            thisNode->next = thisNode;
            thisNode->previous = thisNode;
        }
        size++;
    }

    void rotate(const ptrdiff_t& numberOfRotations)
    {
        for (int i = 0; i < numberOfRotations; ++i)
        {
            thisNode = thisNode->next;
        }
    }

    int getSize()
    {
        return  size;
    }

private:
    struct Node
    {
        Node(double newData) : data{newData} {};

        Node* next{nullptr};
        Node* previous{nullptr};
        double data{0};
    };

    Node* thisNode{nullptr};
    int size{0};
};


#endif //CIRCLEQUEUE_CIRCLEQUEUE_H
