#include <iostream>
using namespace std;
// Calculate the product of all the elements in the given array.
int Product(int n, int arr[])
{
    int product = 1;
    for (int i = 1; i < n; i++)
    {
        product = arr[i] * product;
    }
    cout << "product of all elements is :" << product;
}

// Find the second largest element in the given Array in one pass.
int Smax(int n, int arr[])
{
    int max = INT16_MIN;
    int smax = INT16_MIN;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > max)
        {
            smax = max;
            max = arr[i];
        }
    };
    cout << endl;
    cout << "Second Max :" << smax;
}

// Find the minimum value out of all elements in the array
int Lowest(int n, int arr[])
{
    int lowest = INT32_MAX;
    for (int i = 0; i < n; i++)
    {
        if (lowest > arr[i])
            lowest = arr[i];
    }
    cout << endl;
    cout << "Lowest Element :" << lowest;
}

// Given an array, predict if the array contains duplicates or not
int Duplicate(int n, int arr[])
{

    bool flag = false;
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if(arr[i]==arr[j]){
                flag= true;
                
            }
        }
    }
    cout<<endl;
    if(flag==true){
        cout<<"duplicates found";

    }else{
        cout<<"no duplicates found";
    }
}

int main()

{
    int arr[] = {1, 2, 3, 4, 5,};
    int n = sizeof(arr) / sizeof(arr[0]);

    Product(n, arr);
    Smax(n, arr);
    Lowest(n, arr);
    Duplicate(n, arr);

    return 0;
}