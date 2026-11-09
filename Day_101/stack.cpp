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
};

class Stack
{
private:
    Node *top{nullptr};
    int size{0};

public:
    Stack() = default;

    void push(int data)
    {
        Node *newNode = new Node(data);
        if (top == nullptr)
        {
            top = newNode;
            size++;
        }
        else
        {
            newNode->setNext(top);
            top = newNode;
            size++;
        }
    }

    int pop()
    {
        int value = top->getData();
        Node *temp = top->getNext();
        delete top;
        top = temp;
        return value;
    }

    void display()
    {
        Node *temp = top;
        cout << "[ ";
        while (temp != nullptr)
        {
            cout << temp->getData() << " ";
            temp = temp->getNext();
        }
        cout << " ]" << endl;
    }
};

int main()
{

    Stack s1;
    s1.display();
    s1.push(4);
    s1.push(5);
    s1.push(7);
    s1.display();
    s1.push(9);
    s1.push(20);
    s1.display();
    int v = s1.pop();
    cout << "returned value " << v << endl;
    s1.display();
    s1.pop();
    v = s1.pop();
    cout << "returned value " << v << endl;
    s1.pop();
    v = s1.pop();
    cout << "returned value " << v << endl;
    s1.pop();
    v = s1.pop();
    cout << "returned value " << v << endl;
    s1.pop();
    v = s1.pop();
    cout << "returned value " << v << endl;
    s1.display();
    return 0;
}