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

class Stack
{
private:
    Node *top{nullptr};
    int size{0};

public:
    Stack() = default;

    bool isEmpty()
    {
        return this->top == nullptr;
    }

    void push(int value)
    {
        Node *newNode = new Node(value);

        if (isEmpty())
        {
            this->top = newNode;
            this->size++;
        }
        else
        {
            newNode->setNext(top);
            top = newNode;
            this->size++;
        }
    }

    int pop()
    {
        if (isEmpty())
        {
            cout << "Nothing to pop!\n";
            return -1;
        }
        else
        {
            Node *temp = top;
            top = top->getNext();
            int val = temp->getData();
            delete temp;
            this->size--;
            return val;
        }
    }

    void print()
    {
        Node *temp = this->top;
        cout << "[ ";
        while (temp != nullptr)
        {
            cout << temp->getData() << (temp->getNext() != nullptr ? " , " : "");
            temp = temp->getNext();
        }
        cout << " ]\n";
    }

    void clear()
    {
        Node *temp = this->top;
        Node *secondNode = nullptr;
        while (temp != nullptr)
        {
            secondNode = temp->getNext();
            delete temp;
            temp = secondNode;
        }
        this->top = nullptr;
        this->size = 0;
    }

    ~Stack()
    {
        clear();
    }
};

int main()
{
    Stack s;
    s.print();
    s.push(12);
    s.push(13);
    s.push(14);
    s.push(15);
    s.print();
    s.clear();
    s.print();

    return 0;
}