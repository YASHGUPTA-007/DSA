#include <iostream>
using namespace std;
int oneton(int n)
{
    if (n == 0)
        return;
    cout << n << endl;
    ;

    oneton(n - 1);
}
int main()
{
    cout << oneton(10);

    return 0;
}