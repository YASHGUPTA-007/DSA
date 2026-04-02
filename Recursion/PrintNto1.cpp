#include <iostream>
using namespace std;
void oneton(int i, int n)
{
    if (i > n)
        return;

    cout << i << endl;

    oneton(i + 1, n);
}
int main()
{
    int i = 1;

    oneton(i, 10);
}