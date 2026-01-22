#include <iostream>
using namespace std;

void dupliFinder(int array[9]);
void palindromeCheck(int num, string s);
void fibonacci(int num);
void factorial(int num);
void patterns();
void transpose(int matrix[3][3]);
void rotateImage(int matrix[3][3]);
void identityMatrix(int matrix[3][3]);

int main()
{
    int array[9] = {8, 8, 3, 3, 8, 4, 5, 3, 8};
    int matrix[3][3] = {
        {3, 2, 1},
        {4, 7, 8},
        {2, 1, 6}};
    //  dupliFinder(array);
    /// palindromeCheck(0110, "racecar");
    // fibonacci(10);
    // factorial(4);
    // patterns();
    // transpose(matrix);
    // rotateImage(matrix);
    identityMatrix(matrix);

    return 0;
}

void dupliFinder(int array[9])
{
    for (int i = 1; i < 9; i++)
    {
        int x = i;
        while (x > 0 && array[x] < array[x - 1])
        {
            array[x] = array[x] + array[x - 1];
            array[x - 1] = array[x] - array[x - 1];
            array[x] = array[x] - array[x - 1];
            x--;
        }
    }
    // sorted array
    cout << "Sorted array~\n";
    for (int j = 0; j < 9; j++)
    {
        cout << array[j] << " ";
    }

    int duplicate = -1;
    for (int z = 1; z < 9; z++)
    {
        if (array[z] == array[z - 1])
        {
            duplicate = array[z];
        }
    }
    cout << "\n duplicate is: " << duplicate;

    // number of times repeated
    int counter = 1;
    int dupli = -1;
    int mainCounter = 1;
    int secondDupli = -2;
    int secondCounter = 1;
    for (int y = 1; y < 9; y++)
    {
        if (array[y] == array[y - 1])
        {
            counter++;
        }
        else
        {
            if (counter > mainCounter)
            {
                secondCounter = mainCounter;
                mainCounter = counter;
                dupli = array[y - 1];
                secondDupli = array[y - counter];
            }
            counter = 1;
        }
    }

    if (counter > mainCounter)
    {
        secondCounter = mainCounter;
        mainCounter = counter;
        dupli = array[8];
    }

    if (dupli != -1)
        cout << "\nthe number: " << dupli << " repeats " << mainCounter << " times!" << endl;
    if (secondDupli != -2)
        cout << "Second duplicate number repeats : " << secondCounter << " times\n";
}

void palindromeCheck(int num, string s)
{
    int originalNum = num;
    string originalString = s;
    int reversedNum = 0;
    string reversedString = "";
    while (num > 0)
    {
        reversedNum = reversedNum * 10 + num % 10;
        num = num / 10;
    }
    cout << "Reversed number: " << reversedNum << endl;
    if (reversedNum == originalNum)
        cout << "Number is panlidrome!\n";
    else
        cout << "Number is not palindrome!\n";

    int strLength = s.length() - 1;
    while (strLength >= 0)
    {
        reversedString = reversedString + s[strLength];
        strLength--;
    }
    cout << "Reversed String is: " << reversedString << endl;
    if (reversedString == originalString)
        cout << "String is panlidrome!\n";
    else
        cout << "String is not palindrome!";
}

void fibonacci(int n)
{
    int start = 0;
    int second = 1;
    int next = 0;
    cout << "Fibonacci Series:\n";
    for (int i = 0; i < n; i++)
    {
        cout << start << " ";
        next = start + second;
        start = second;
        second = next;
    }
}

void factorial(int num)
{
    int fac = 1;
    for (int i = num; i > 0; i--)
    {
        fac = fac * i;
    }
    cout << "Factorial of: " << num << " is: " << fac;
}

void patterns()
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << "*";
        }
        cout << endl;
    }

    cout << endl;
    for (int x = 0; x < 5; x++)
    {
        for (int y = 5; y > x; y--)
        {
            cout << "*";
        }
        cout << endl;
    }

    cout << endl;
    for (int x = 0; x < 5; x++)
    {
        for (int i = 5; i > x; i--)
        {
            cout << " ";
        }

        for (int y = 0; y <= x; y++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}

void transpose(int matrix[3][3])
{
    int transpose[3][3];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            transpose[i][j] = matrix[j][i];
        }
    }

    // transpose of matrix
    for (int x = 0; x < 3; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            cout << transpose[x][y] << " ";
        }
        cout << endl;
    }
}

void rotateImage(int matrix[3][3])
{
    int transpose[3][3];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            transpose[i][j] = matrix[j][i];
        }
    }

    for (int x = 0; x < 3; x++)
    {
        int start = 0, end = 2;
        while (start < end)
        {
            swap(transpose[x][start], transpose[x][end]);
            start++;
            end--;
        }
    }

    cout << "rotated image\n";
    for (int x = 0; x < 3; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            cout << transpose[x][y] << " ";
        }
        cout << endl;
    }
}

void identityMatrix(int matrix[3][3])
{
    bool identity = true;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if ((i == j && matrix[i][j] != 1))
            {
                identity = false;
            }
            if (((i != j) && (matrix[i][j] != 0)))
            {
                identity = false;
            }
        }
    }
    if (identity)
        cout << "Yes identity matrix!\n";
    else
        cout << "Not identity!\n";
}