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

class LinkedList
{
private:
    Node *head{nullptr};
    int size{0};

public:
    LinkedList() = default;

    bool isEmpty()
    {
        return this->head == nullptr;
    }

    int count()
    {
        return this->size;
    }

    void insertAtEnd(int value)
    {
        Node *newNode = new Node(value);

        if (isEmpty())
        {
            this->head = newNode;
            this->size++;
        }
        else
        {
            Node *temp = head;

            while (temp->getNext() != nullptr)
            {
                temp = temp->getNext();
            }
            temp->setNext(newNode);
            this->size++;
        }
    }

    void insertAtBegining(int value)
    {
        Node *newNode = new Node(value);

        if (isEmpty())
        {
            this->head = newNode;
            this->size++;
        }
        else
        {
            newNode->setNext(head);
            head = newNode;
            this->size++;
        }
    }

    void pop()
    {
        Node *temp = this->head;
        Node *secondLastNode = nullptr;
        if (temp == nullptr)
        {
            cout << "Nothing to pop! List is already empty." << endl;
            return;
        }
        else
        {
            while (temp->getNext() != nullptr)
            {
                secondLastNode = temp;
                temp = temp->getNext();
            }
            delete temp;
            secondLastNode->setNext(nullptr);
            this->size--;
        }
    }

    void deleteHead()
    {
        Node *temp = head;
        head = head->getNext();
        delete temp;
    }

    void print()
    {
        if (isEmpty())
        {
            cout << "List is empty . Nothing to show!!  ";
        }

        Node *temp = head;
        cout << "[ ";
        while (temp != nullptr)
        {
            cout << temp->getData() << (temp->getNext() != nullptr ? " , " : "");
            temp = temp->getNext();
        }
        cout << " ]" << endl;

        Node *temp2 = head;
        while (temp2 != nullptr)
        {
            cout << temp2 << endl;
            temp2 = temp2->getNext();
        }
        cout << endl;
    }

    void search(int value)
    {
        Node *temp = this->head;
        int pos = 0;
        while (temp != nullptr)
        {
            if (temp->getData() == value)
            {
                cout << "The value" << temp->getData() << " exists at address: " << temp << " at position " << pos + 1 << endl;
                return;
            }
            pos++;
            temp = temp->getNext();
        }
        cout << "The value " << value << " does not exists !!!" << endl;
    }

    void deleteByValue(int value)
    {
        Node *temp = this->head;
        Node *prev = nullptr;

        while (temp->getData() != value && temp != nullptr)
        {
            prev = temp;
            temp = temp->getNext();
        }
        if (temp == nullptr)
        {
            cout << "the list is empty!!" << endl;
            return;
        }

        if (prev == nullptr)
        {
            head = temp->getNext();
        }
        else
        {
            prev->setNext(temp->getNext());
        }
        delete temp;
        this->size++;
    }

    void reverse()
    {
        Node *prev = nullptr;
        Node *curr = this->head;
        Node *next = nullptr;

        while (curr != nullptr)
        {
            next = curr->getNext();
            curr->setNext(prev);
            prev = curr;
            curr = next;
        }
        this->head = prev;
    }

    int min()
    {
        Node *temp = this->head;
        int min = __INT_MAX__;

        while (temp != nullptr)
        {
            if (temp->getData() < min)
            {
                min = temp->getData();
            }
            temp = temp->getNext();
        }
        return min;
    }

    int max()
    {
        Node *temp = this->head;
        int max = temp->getData();

        while (temp != nullptr)
        {
            if (temp->getData() > max)
            {
                max = temp->getData();
            }
            temp = temp->getNext();
        }
        return max;
    }

    void sort()
    {
        
    }

    void clear()
    {
        Node *temp = this->head;
        Node *nextNode = nullptr;

        while (temp != nullptr)
        {
            nextNode = temp->getNext();
            delete temp;
            cout << temp << " deleted" << endl;
            cout << "temp is pointed to next address: " << nextNode << endl;
            temp = nextNode;
        }
    }
};

int main()
{
    LinkedList li;
    li.print();
    cout << endl;
    li.insertAtEnd(1);
    li.insertAtEnd(2);
    li.insertAtEnd(3);
    li.insertAtEnd(4);
    li.insertAtEnd(5);
    li.print();
    li.insertAtBegining(0);
    li.print();
    li.search(10);
    li.search(5);
    li.pop();
    li.deleteHead();
    li.reverse();
    li.print();
    cout << "min : " << li.min() << endl;
    cout << "max : " << li.max() << endl;

    li.clear();

    return 0;
}