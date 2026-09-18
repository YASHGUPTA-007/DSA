#include <iostream>
using namespace std;

using namespace std;
int main()
{

    int arr[] = {3, 5, 1, 2, 4};
    int n = 5;
    for (int i = 0; i < n ; i++)
    {
        cout << arr[i];
    }
    cout<<endl;

    for (int i = 0; i < n - 1; i++)
    {

        int min = INT16_MAX;
        int minI = 0;

        for (int j = i; j < n; j++)
        {

            if (arr[j] < min)
            {
                min = arr[j];
           minI = j;
            }
        }
        swap(arr[i] , arr[minI]);

    }


    for (int i = 0; i < n ; i++)
    {
        cout << arr[i];
    }
    return 0;
}