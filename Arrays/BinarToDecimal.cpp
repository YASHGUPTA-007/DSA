#include <iostream>
using namespace std;
int main()
{
    int arr[] = {0, 1, 0, 0, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << n;

    int sum = 0;
    int x = 1;

    for (int i = n - 1; i >= 0; i--)
    {

        sum += arr[i] * x;
        x *= 2;
    }

    cout<<"decimal Conversion is:"<<sum;

    return 0;
}