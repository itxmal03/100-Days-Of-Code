#include <iostream>
using namespace std;

void sortEachRow(int matrix[3][3]);

int main()
{
    int matrix[3][3] = {{4, 3, 6}, {11, 1, 12}, {0, 2, -1}};
    sortEachRow(matrix);
    cout << endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

void sortEachRow(int matrix[3][3])
{
    for (int i = 0; i < 3; i++) // Step 1: select row
    {
        for (int j = 1; j < 3; j++) // Step 2: start from 2nd element
        {
            int key = matrix[i][j]; // Step 3: element to insert
            int k = j - 1;

            while (k >= 0 && matrix[i][k] > key) // Step 4: shift
            {
                matrix[i][k + 1] = matrix[i][k];
                k--;
            }

            matrix[i][k + 1] = key; // Step 5: insert
        }
    }
}
