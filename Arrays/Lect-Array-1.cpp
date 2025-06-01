#include <iostream>
using namespace std;

int sum(int n, int arr[])
{
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum = sum + arr[i];
    }
    cout << "sum of array = " << sum;
    cout<<endl;
}

int LinearSearch(int n, int arr[], int target)
{


    int flag = false;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == target)
        {
            flag = true;
        }
    }
    if (flag == true)
    {
        cout << "target found";
    }
    else
    {
        cout << "target not found";
    }
}

int main()
{
    int arr[10] = {1, 5, 6, 9, 7, 47, 6, 26, 14, 4};
    int n = 10;
    int target = 2;

    sum(n, arr);
    LinearSearch(n, arr, target);

    return 0;
}