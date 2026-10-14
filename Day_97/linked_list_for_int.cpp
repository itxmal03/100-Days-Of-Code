#include <iostream>
using namespace std;

struct Node
{
private:
    int data = 0;
    Node *nextNodeAddress = nullptr;

public:
    Node() = default;

    Node(int value)
    {
        this->data = value;
        this->nextNodeAddress = nullptr;
    }

    int getData()
    {
        return this->data;
    }

    Node *getNextNodeAddress()
    {
        return this->nextNodeAddress;
    }

    void setData(int val)
    {
        this->data = val;
    }

    void setNextNodeAddress(Node *addr)
    {
        this->nextNodeAddress = addr;
    }

    void printNode()
    {
        cout << "The address of Node: " << this << " and the data stored at it: " << this->data << endl;
        cout << "The address of next Node: " << this->nextNodeAddress << endl;
    }

    ~Node()
    {
        cout << "Node released!!!" << endl;
    };
};

struct LinkedList
{
private:
    Node *head{nullptr};
    int size{0};

public:
    LinkedList() = default;
    LinkedList(int val)
    {
        insert(val);
    }

    bool isEmpty()
    {
        return this->head == nullptr;
    }

    void insert(int val)
    {
        Node *newNode = new Node(val);
        if (isEmpty())
        {
            head = newNode;
            this->size++;
        }
        else
        {
            Node *temp = head;
            while (temp->getNextNodeAddress() != nullptr)
            {
                temp = temp->getNextNodeAddress();
            }
            temp->setNextNodeAddress(newNode);
            this->size++;
        }
    }

    void print()
    {
        cout << "[ ";
        Node *temp = this->head;
        while (temp != nullptr)
        {
            cout << temp->getData() << (temp->getNextNodeAddress() != nullptr ? " , " : "");

            temp = temp->getNextNodeAddress();
        }
        cout << " ]" << endl;
        cout << "Size = " << this->size << endl
             << endl;
    }

    void search(int val)
    {
        Node *temp = this->head;
        while (temp != nullptr)
        {
            if (temp->getData() == val)
            {
                cout << "The value : " << val << " exists at address: " << temp << endl;
                return;
            }
            temp = temp->getNextNodeAddress();
        }
        cout << "The value : " << val << " does not exist in this list !" << endl;
    }

    // push new element at first
    void push_front(int value)
    {
        Node *newNode = new Node(value);
        if (isEmpty())
        {
            this->head = newNode;
            this->size++;
        }
        else
        {
            newNode->setNextNodeAddress(this->head);
            this->head = newNode;
            this->size++;
        }
    }

    // drop last node
    void pop()
    {

        if (this->head == nullptr)
        {
            cout << "The List is empty. Nothing to pop!" << endl;
            return;
        }

        if (this->head->getNextNodeAddress() == nullptr)
        {
            delete this->head;
            this->head = nullptr;
            this->size--;
            return;
        }

        Node *temp = this->head;
        Node *secondLastNode = nullptr;

        while (temp->getNextNodeAddress() != nullptr)
        {
            secondLastNode = temp;
            temp = temp->getNextNodeAddress();
        }

        delete temp;
        secondLastNode->setNextNodeAddress(nullptr);
        this->size--;
    }

    void clear()
    {
        Node *temp = this->head;
        Node *nextNode = nullptr;
        while (temp != nullptr)
        {
            nextNode = temp->getNextNodeAddress();
            delete temp;
            temp = nextNode;
        }
        this->head = nullptr;
        this->size = 0;
    }

    ~LinkedList()
    {
        clear();
        cout << "Linked List Cleared\n"
             << endl;
    }
};

int main()
{
    LinkedList li;
    li.insert(961);
    li.insert(933);
    li.insert(2025);
    li.print();
    li.pop();
    li.print();
    LinkedList l2(56);
    l2.print();
    l2.clear();
    l2.pop();
    li.push_front(1);
    li.print();
    li.search(933);
    li.search(-1);
    return 0;
}