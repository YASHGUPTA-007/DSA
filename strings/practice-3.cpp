#include <iostream>
#include <string>

using namespace std;
int main()
{

    int a = 12;
    string bh = "bhkadsbhwfge";
    for (size_t i = 0; i < a; i++)
    {
        if (i % 2 == 0)
        {
            bh[i] = '0';
        }
    }
    cout << "changed one :" << bh;

    return 0;
}