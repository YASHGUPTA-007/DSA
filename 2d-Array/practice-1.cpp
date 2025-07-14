#include <iostream>
using namespace std;

// int TransposeOfMatrix(int arr,int n,int m){
//     cout << "Transpose of Array";

//         for (int i = 0; i < m; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             cout << arr[j][i];
//         }
//         cout << endl;
//     }

// }

int main()
{
    int m = 3;
    int n = 3;
    int arr[m][n];
    cout << "Enter elements";
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
        cout << endl;
    }
    cout << "Printing Elements";
    cout << endl;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j];
        }
        cout << endl;
    }
    cout << "Transpose of Array";
    cout << endl;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[j][i];
        }
        cout << endl;
    }

    cout << "Transpose in the same Array";

    cout << endl;

    // Transpose in the same matrix
    for (int i = 0; i < m; i++)
    { // rows
        for (int j = i + 1; j < n; j++)
        { // cols
            // Swapping arr[i][j] and arr[j][i]
            int temp = arr[i][j];
            arr[i][j] = arr[j][i];
            arr[j][i] = temp;
        }
        cout << endl;
    }

    // Print the in-place transposed matrix
    cout << "\nMatrix after in-place transpose:" << endl;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
