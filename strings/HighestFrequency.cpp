#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
    string s = "yassh";
    int n = s.size();

    int count = 0;
    int max = 0;
    for (int i = 0; i < n; i++)
    {
        char c = s[i];
        count = 1;

        for (int j = i + 1; j < n; j++)
        {
            if (s[j] == s[i])
            {
                count++;
            }
            if (max < count)
                max = count;
        }
    }
    cout << max;
}