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

class Queue
{
    
private:
    Node *head{nullptr};
    Node *tail{nullptr};
    int size{0};

public:
    Queue() = default;

    bool isEmpty()
    {
        return head == nullptr || tail == nullptr;
    }

    void display()
    {
        cout << "[";
        if (isEmpty())
        {

            cout << " ]";
            cout << "\t Queue is Empty " << endl;
        }

        else
        {

            Node *temp = head;
            while (temp != nullptr)
            {
                cout << temp->getData();
                if (temp->getNext() != nullptr)
                {
                    cout << ", ";
                }
                temp = temp->getNext();
            }

            cout << " ]";

            cout << endl;
            cout << "Size of Queue: " << this->size << endl;
            // peek();
        }
    }

    void Enqueue(int val)
    {
        Node *newNode = new Node(val);

        if (isEmpty())
        {
            head = tail = newNode;
            size++;
        }
        else
        {

            tail->setNext(newNode);
            tail = newNode;
            size++;
        }
    }

    void Dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is already empty \n";
        }
        else
        {

            Node *temp = head;
            int val = temp->getData();
            head = head->getNext();
            delete temp;
            temp = nullptr;
            size--;
            cout << "Value Dequeued : " << val << endl;
        }
    }
};

int main()
{

    Queue q1;

    q1.display();

    q1.Enqueue(57);
    q1.Enqueue(78);
    q1.display();
    q1.Dequeue();
    q1.display();

    return 0;
}