#include <iostream>
#include <string>
using namespace std;
int VowelCount(const string &str)
{
    int count = 0;
    int i = 0;

    while (str[i] != '\0')
    {
        char ch = str[i];
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
            ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')
        {
            count++;
        }
        i++; // increment to avoid infinite loop
    }

    return count;
}

int main()
{
    // only print till b, Becase of null character

    // char ch[] = {'a', 'b', '\0', 'd'};
    // cout << ch;
    // string name;
    // //
    // getline(cin, name);
    // cout << name;

    string input = "Hello, World!";
    int vowels = VowelCount(input);
    cout << "Number of vowels: " << vowels << endl;
    return 0;
}