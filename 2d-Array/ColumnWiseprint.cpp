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

    // Wave Print 
    cout << "\n Column wise Wave Form" << endl;

    for(int j=0;j<n;j++){
        if(j%2 == 0){
            for(int i=0;i<m;i++){
                cout<<arr[i][j];
            }
        }else{
            for(int i=m-1;i>=0;i--){
                cout<<arr[i][j];
            }
        }
    }
 
    return 0;
}
