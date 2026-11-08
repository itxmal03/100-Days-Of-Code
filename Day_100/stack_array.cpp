#include <iostream>
using namespace std;

class Stack
{
private:
    int size = 0;
    int top = -1;
    int capacity = 3;
    int *stackArray{nullptr};

public:

    Stack(int capacity = 3)
    {
        this->capacity = capacity;
        this->stackArray = new int[this->capacity];
    }

    // prevent shallow-copy double-free
    Stack(const Stack &) = delete;
    Stack &operator=(const Stack &) = delete;

    bool isEmpty()
    {
        return this->top == -1;
    }

    bool isFull()
    {
        return this->top == capacity - 1;
    }

    void resize()
    {
        int newCapacity = capacity * 10;
        int *tempArr = new int[newCapacity];
        for (int i = 0; i <= top; i++)
        {
            tempArr[i] = stackArray[i];
        }
        delete[] stackArray;
        stackArray = tempArr;
        tempArr = nullptr;
        this->capacity = newCapacity;
    }

    void push(int val)
    {
        // reallocate if the array was freed by clear()
        if (stackArray == nullptr)
        {
            stackArray = new int[capacity];
        }

        if (isFull())
        {
            cout << "Stack overflow\n Resizing it!\n";
            resize();
        }

        this->top++;
        stackArray[top] = val;
        this->size++;
    }

    int pop()
    {
        if (isEmpty())
        {
            cout << "Stack underflow\n";
            return -1;
        }
        int val = stackArray[top];
        this->top--;
        this->size--;
        return val;
    }

    int peek()
    {
        if (isEmpty())
        {
            cout << "Stack is empty\n";
            return -1;
        }
        return stackArray[top];
    }

    void clear()
    {
        delete[] this->stackArray;
        this->size = 0;
        this->top = -1;
        this->stackArray = nullptr;
    }

    void print()
    {
        cout << "[ ";
        for (int i = 0; i <= top; i++)
        {
            cout << stackArray[i] << (i != top ? " , " : "");
        }
        cout << " ]\n";
    }

    void reverse()
    {
        int start = 0;
        int end = top;
        while (start < end)
        {
            int temp = stackArray[start];
            stackArray[start] = stackArray[end];
            stackArray[end] = temp;
            start++;
            end--;
        }
    }

    void sort()
    {
        // insertion sort
        for (int i = 1; i <= top; i++)
        {
            int j = i;
            while (j > 0 && stackArray[j - 1] > stackArray[j])
            {
                swap(stackArray[j - 1], stackArray[j]);
                j--;
            }
        }
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
    s.reverse();
    s.print();
    s.sort();
    s.print();
    s.clear();
    return 0;
}