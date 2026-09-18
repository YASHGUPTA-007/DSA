#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
    string str = "aa";
    string str2 = "aa";

    sort(str.begin(), str.end());
    sort(str2.begin(), str2.end());
    if (str == str2)
    {
        cout << "true";
    }
    else
        cout << "false";

    return 0;
}