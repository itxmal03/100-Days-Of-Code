#include <iostream>
using namespace std;

template <typename T>
struct Node
{
private:
    T data{};
    Node<T> *nextNodeAddress = nullptr;

public:
    Node<T>() = default;

    Node(T value)
    {
        this->data = value;
        this->nextNodeAddress = nullptr;
    }

    T getData()
    {
        return this->data;
    }

    Node<T> *getNextNodeAddress()
    {
        return this->nextNodeAddress;
    }

    void setData(T val)
    {
        this->data = val;
    }

    void setNextNodeAddress(Node<T> *addr)
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

template <typename T>
struct LinkedList
{
private:
    Node<T> *head{nullptr};
    int size{0};

public:
    LinkedList<T>() = default;
    LinkedList(T val)
    {
        insert(val);
    }

    bool isEmpty()
    {
        return this->head == nullptr;
    }

    void insert(T val)
    {
        Node<T> *newNode = new Node(val);
        if (isEmpty())
        {
            head = newNode;
            this->size++;
        }
        else
        {
            Node<T> *temp = head;
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
        Node<T> *temp = this->head;
        while (temp != nullptr)
        {
            cout << temp->getData() << (temp->getNextNodeAddress() != nullptr ? " , " : "");

            temp = temp->getNextNodeAddress();
        }
        cout << " ]" << endl;
        cout << "Size = " << this->size << endl
             << endl;
    }

    void search(T val)
    {
        Node<T> *temp = this->head;
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
    void push_front(T value)
    {
        Node<T> *newNode = new Node(value);
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

        Node<T> *temp = this->head;
        Node<T> *secondLastNode = nullptr;

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
        Node<T> *temp = this->head;
        Node<T> *nextNode = nullptr;
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
    LinkedList<int> li;
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

    LinkedList<string> sList = {"Aftab"};
    sList.print();

    return 0;
}