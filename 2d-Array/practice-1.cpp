#include <iostream>
using namespace std;

int TransposeOfMatrix(int arr,int n,int m){
    cout << "Transpose of Array";
    
        for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[j][i];
        }
        cout << endl;
    }

}

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
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j];
        }
        cout << endl;
    }


    TransposeOfMatrix(arr,n,m);
    return 0;
}