#include <iostream>
#include <string>
using namespace std;
int main()
{
    // only print till b, Becase of null character

    char ch[] = {'a', 'b', '\0', 'd'};
    cout << ch;
    string name;
    //
    getline(cin, name);
    cout << name;
    return 0;
}