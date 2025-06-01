#include<iostream>
using namespace std;
int main()
{
    int arr[10]={1,5,8,2,5,6,4,8,4,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<n;
    return 0;
}