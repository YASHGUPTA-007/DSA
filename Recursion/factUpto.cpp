#include <iostream>
using namespace std;

int FactUpto(int n)
{
    if (n == 0) return 0;  

    int fact = 1;
    for (int i = 1; i <= n; i++)
    {
        fact = fact * i;
    }
    cout << " factorial of " << n << " is :" << fact;
    cout << endl;
    
    FactUpto(n - 1);
}

int main()
{
    FactUpto(10);

    return 0;
}