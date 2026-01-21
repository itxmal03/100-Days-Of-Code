#include <iostream>
using namespace std;

void printBoundry(int matrix[4][4]);
void sortMatrix(int matrix[4][4]);
void sortEachRow(int matrix[4][4]);

int main()
{
    int matrix[4][4] = {{9, 3, 4, 6},
                        {9, 8, 6, 9},
                        {7, 2, 1, 4},
                        {8, 5, 7, 0}};

    // printBoundry(matrix);
    // sortEachRow(matrix);
    sortMatrix(matrix);

    return 0;
}

void printBoundry(int matrix[4][4])
{
    cout << "\n Boundry of matrix is: \n";
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (i == 0 || i == 3 || j == 0 || j == 3)
            {
                cout << matrix[i][j] << " ";
            }
            else
            {
                cout << "  ";
            }
        }
        cout << endl;
    }
}

void sortMatrix(int matrix[4][4])
{
    int tempMatrix[16];
    int k = 0;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            tempMatrix[k++] = matrix[i][j];
        }
    }

    for (int z = 1; z < 16; z++)
    {
        int x = z;
        while (x > 0 && tempMatrix[x] < tempMatrix[x - 1])
        {
            swap(tempMatrix[x], tempMatrix[x - 1]);
            x--;
        }
    }


    int a = 0;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            matrix[i][j] = tempMatrix[a];
            a++;
        }
    }

    for (int u = 0; u < 4; u++)
    {
        for (int t = 0; t < 4; t++)
        {
            cout << matrix[u][t] << " ";
        }
        cout << endl;
    }
}

void sortEachRow(int matrix[4][4])
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 1; j < 4; j++)
        {
            int y = j;
            while (y > 0 && matrix[i][y] < matrix[i][y - 1])
            {
                swap(matrix[i][y], matrix[i][y - 1]);
                y--;
            }
        }
    }

    for (int u = 0; u < 4; u++)
    {
        for (int t = 0; t < 4; t++)
        {
            cout << matrix[u][t] << " ";
        }
        cout << endl;
    }
}