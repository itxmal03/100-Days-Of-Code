#include <iostream>

using namespace std;

class Node
{

private:
    int data{0};
    Node *next{nullptr};

public:
    Node() = default;

    Node(int data)
    {
        setData(data);
        this->next = nullptr;
    }

    void setData(int data)
    {
        this->data = data;
    }
    int getData()
    {

        return this->data;
    }
    Node *getNext()
    {
        return this->next;
    }
    void setNext(Node *next)
    {
        this->next = next;
    }
    void print()
    {
        cout << "Address of Current Node: " << this;

        cout << "\tData: " << this->data;

        cout << "\tAddress of Next Node: " << this->next << endl;
    }
};

int main()
{

    Node n1(5);
    // n1.print();
    Node n2(6);
    Node n3(7);
    Node n4(8);
    Node n5(9);
    n1.setNext(&n2);
    n2.setNext(&n3);
    n3.setNext(&n4);
    n4.setNext(&n5);
    Node *head = &n1;

    Node *temp = head;

    while (temp->getNext() != nullptr)
    {
        temp->print();
        temp = temp->getNext();
    }

    return 0;
}