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

class SortedList
{
private:
    Node *head{nullptr};
    int size{0};

    void insertAtHead(int val)
    {
        Node *newNode = new Node(val);
        if (isEmpty())
        {
            head = newNode;
            size++;
        }

        else
        {
            newNode->setNext(head);
            head = newNode;
            size++;
        }
    }

    void insertAtTail(int val)
    {
        Node *newNode = new Node(val);
        if (isEmpty())
        {
            head = newNode;
            size++;
            return;
        }
        Node *temp = head;
        while (temp->getNext() != nullptr)
        {
            temp = temp->getNext();
        }
        temp->setNext(newNode);
        size++;
    }

    void insertATMiddle(int val, Node *prev, Node *current)
    {
        Node *newNode = new Node(val);
        newNode->setNext(current);
        prev->setNext(newNode);
        size++;
    }

public:
    SortedList() = default;

    void display()
    {
        cout << "[ ";
        Node *temp = head;
        while (temp != nullptr)
        {

            cout << temp->getData() << "  ";
            temp = temp->getNext();
        }
        cout << "] ";
        cout << endl;
    };

    bool isEmpty()
    {
        return head == nullptr;
    }

    void insert(int val)
    {

        Node *prev = nullptr;
        Node *current = head;
        while (current != nullptr && val > current->getData())
        {
            prev = current;
            current = current->getNext();
        }

        if ((isEmpty()))
        {
            insertAtHead(val);
        }
        else if (prev == nullptr && current == head)
        {

            insertAtHead(val);
        }
        else if (current == nullptr && prev != nullptr)
        {
            insertAtTail(val);
        }
        else if (current != nullptr && prev != nullptr)
        {
            insertATMiddle(val, prev, current);
        }
    }

    void clear()
    {

        if (!isEmpty())
        {

            Node *temp = head;
            while (temp != nullptr)
            {
                head = head->getNext();
                delete temp;
                temp = head;
            }
            this->head = nullptr;
        }
    }

    void remove(int val)
    {
        if (isEmpty())
        {
            cout << "List is Already Empty.\n";
            return;
        }

        Node *prev = nullptr;
        Node *current = head;
        while (current != nullptr && val != current->getData())
        {
            prev = current;
            current = current->getNext();
        }

        if (current == nullptr)
        {
            cout << "Value not found.\n";
            return;
        }

        if (prev == nullptr && current != nullptr)
        {

            head = head->getNext();
            delete current;
            size--;
        }
        else if (prev != nullptr && current != nullptr)
        {

            prev->setNext(current->getNext());
            delete current;
        }
    }

    ~SortedList()
    {
        clear();
    }

};

int main()
{

    SortedList s1;
    s1.insert(6);
    s1.insert(2);
    s1.insert(5);
    s1.insert(7);
    s1.insert(8);
    s1.insert(7);
    s1.display();
    // s1.clear();
    s1.display();
    s1.remove(5);
    s1.display();
    s1.remove(9);
    s1.display();
    // s1.insert(6);
    // s1.display();

    return 0;
}