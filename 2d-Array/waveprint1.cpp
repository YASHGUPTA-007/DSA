#include <iostream>
using namespace std;

int main()
{
    int m = 3;
    int n = 3;
    int arr[m][n];

    // Input
    cout << "Enter elements of the 3x3 matrix:" << endl;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }

    // Print Matrix
    cout << "\nMatrix Elements:" << endl;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    // Wave Print (Row-wise)
    cout << "\nWave Form (Row-wise):" << endl;
    for (int i = 0; i < m; i++)
    {
        if (i % 2 == 0) // even row: left to right
        {
            for (int j = 0; j < n; j++)
            {
                cout << arr[i][j] << " ";
            }
        }
        else // odd row: right to left
        {
            for (int j = n - 1; j >= 0; j--)
            {
                cout << arr[i][j] << " ";
            }
        }
        cout << endl;
    }

    return 0;
}
