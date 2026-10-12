
#include <iostream>
using namespace std;

class ArrayADT
{

private:
    int size;
    int capacity;
    int *data;

    void reSize(int number)
    {
        int *temp = new int[number];
        for (int i = 0; i < size; i++)
        {
            temp[i] = data[i];
        }
        delete[] data;
        capacity = number;
        data = temp;
        temp = nullptr;
    }

public:
    ArrayADT()
    {
        size = 0;
        capacity = 0;
        data = nullptr;
    }
    ArrayADT(int capacity)
    {
        this->capacity = capacity;
        size = 0;
        data = new int[capacity]{0};
    }
    ~ArrayADT()
    {
        if (data != nullptr)
        {
            delete[] data;
            data = nullptr;
        }
    }

    void print()
    {
        cout << "[ ";
        for (int i = 0; i < size; i++)
        {
            cout << data[i];
            if (i != size - 1)
            {
                cout << ", ";
            }
        }
        cout << " ]" << endl;
        cout << "Current Size: " << size << endl;
        cout << "Current Capacity: " << capacity << endl;
    }

    // Adds an element at the end of the array
    void append(int value)
    {
        if (size >= capacity)
        {
            reSize(capacity + 10);
        }
        data[size] = value;
        size++;
    }

    // Inserts value at the given index
    void insert(int index, int value)
    {

        if (index >= size)
        {
            append(value);
            return;
        }

        if (size == capacity)
        {
            reSize(capacity + 10);
        }

        for (int i = size; i >= index + 1; i--)
        {
            data[i] = data[i - 1];
        }
        data[index] = value;
        size++;
    }
    // Deletes value from given index

    void deleteAtIndex(int index)
    {
        if (index < 0 || index >= size)
        {
            return;
        }
        for (int i = index; i < size - 1; i++)
        {
            data[i] = data[i + 1];
        }
        size--;
    }
};


int main()
{
    ArrayADT a1(5);
    a1.append(10);
    a1.append(20);
    a1.append(30);
    a1.append(40);
    a1.append(50);

    cout << "Before delete:" << endl;
    a1.print();

    a1.deleteAtIndex(1);

    cout << "After delete:" << endl;
    a1.print();

    return 0;
}
