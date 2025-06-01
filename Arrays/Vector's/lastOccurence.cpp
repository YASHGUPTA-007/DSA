#include <iostream>
#include <vector>
using namespace std;
int LastOccurance(int x, vector<int> v)
{
    int lastOccur;
    for (int i = 0; i < v.size(); i++)
    {
        if ( v[i] == x)
        {
            lastOccur = i;
        }
    };
    return lastOccur;
}

int main()
{
    vector<int> v;

    v.push_back(5);
    v.push_back(5);
    v.push_back(5);
    v.push_back(5);
    v.push_back(4);
    v.push_back(9);
    int x = 5;

    int Ans = LastOccurance(x, v);
    cout << "Your last occurance of " << x << " is on index: " << Ans;

    return 0;
}