#include <iostream>
using namespace std;
// Count the number of elements strictly greater than x
int Product(int target, int size, int arr[])
{
    int count = 0;
    for (int i = 0; i < size; i++)
    {

        if (target < arr[i])
        {
            count++;
        }
    }

    cout << "greater elements than target:" << count;
}
// Check if the given array is sorted or not
void SortedOrNot(int size, int arr[])
{
    bool ascending = true, descending = true;

    for (int i = 0; i < size - 1; ++i)
    {
        if (arr[i] > arr[i + 1])
            ascending = false;
        if (arr[i] < arr[i + 1])
            descending = false;
    }

    if (ascending)
        cout << "Sorted in ascending order!";
    else if (descending)
        cout << "Sorted in descending order!";
    else
        cout << "Not sorted!";
}
// Find the difference between the sum of elements at even indices to the sum of elements at odd indices.
void EvenOddSumDiffernces(int size, int arr[])
{
    int evenSum = 0;
    int Oddsum = 0;

    for (int i = 0; i < size; i++)
    {
        if (i % 2 == 0)
        {
            evenSum += arr[i];
        }
        else
        {
            Oddsum += arr[i];
        }
    }
    cout<<"even indices elemnts sum : "<<evenSum<<endl;
    cout<<"odd indices elemnts sum : "<<Oddsum<<endl;
}
int main()

{
    int arr[] = {10, 20, 30, 40, 50};
    int target = 4;
    int n = sizeof(arr) / sizeof(arr[0]);

    //   Product(target, n, arr);
    //SortedOrNot(n, arr);
    EvenOddSumDiffernces(n, arr);

    return 0;
}