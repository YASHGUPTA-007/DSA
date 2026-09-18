#include <iostream>
using namespace std;

int Bubblesort(int arr[], int n)
{
    for (int i = 0; i <= n-1; i++)
    {
        for (int j = i + 1; j <= n-1; j++)
        {
            if (arr[j] < arr[i])
            {
                swap(arr[i], arr[j]);
            }
        }
    }
};

using namespace std;
int main()
{

    return 0;
}