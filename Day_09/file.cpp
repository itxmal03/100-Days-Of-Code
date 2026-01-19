#include <iostream>
using namespace std;

// Program to remove duplicate elements from a 3x3 matrix
// The matrix is first flattened into a 1D array, sorted, duplicates removed,
// and then mapped back to the matrix. Remaining slots are filled with -1.

int main()
{
    // Original 3x3 matrix with duplicates
    int matrix[3][3] = {
        {1, 2, 3},
        {3, 4, 5},
        {5, 6, 6}};

    int tempArray[9] = {0}; // Temporary array to hold matrix elements
    int k = 0;

    // Flatten the 3x3 matrix into a 1D array
    for (int x = 0; x < 3; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            tempArray[k++] = matrix[x][y];
        }
    }

    //  Sort the array using insertion sort
    for (int i = 1; i < 9; i++)
    {
        int currentElementIndex = i;
        while (currentElementIndex > 0 && (tempArray[currentElementIndex] < tempArray[currentElementIndex - 1]))
        {
            swap(tempArray[currentElementIndex], tempArray[currentElementIndex - 1]);
            currentElementIndex--;
        }
    }

    // Print sorted array
    cout << "\nSorted Array: \n";
    for (int d : tempArray)
    {
        cout << d << " ";
    }
    cout << endl;

    //  Remove duplicates using logical size
    // tempSize keeps track of the valid number of elements in the array
    int tempSize = 9;

    for (int d = 1; d < tempSize; d++)
    {
        // If current element is same as previous, it's a duplicate
        if (tempArray[d] == tempArray[d - 1])
        {
            // Shift all elements to the left to remove the duplicate
            int size = d;
            while (size < tempSize - 1)
            {
                tempArray[size] = tempArray[size + 1];
                size++;
            }
            tempSize--; // Reduce logical size as one duplicate removed
            d--;        // Stay at same index to check new element after shift
        }
    }

    //  Fill remaining slots (after duplicates removed) with -1
    for (int i = tempSize; i < 9; i++)
    {
        tempArray[i] = -1;
    }

    // Print the 1D array after removing duplicates
    cout << "\nDuplicate removed Array: \n";
    for (int d : tempArray)
    {
        cout << d << " ";
    }
    cout << endl;

    //  Map back the 1D array into the 3x3 matrix
    int t = 0;
    for (int x = 0; x < 3; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            matrix[x][y] = tempArray[t++];
        }
    }

    //  Print the final matrix after removing duplicates
    cout << "\nFinal 3x3 Matrix after duplicates removed:\n";
    for (int x = 0; x < 3; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            cout << matrix[x][y] << " ";
        }
        cout << endl;
    }

    return 0;
}
