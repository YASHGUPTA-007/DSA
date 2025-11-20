#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
    string str;
    int n;

    cout << "enter your string";
    cin >> str;

    n = str.length() / 2;

    reverse(str.begin(), str.end() - n);
    cout << "your half string :" << str;
    return 0;
}