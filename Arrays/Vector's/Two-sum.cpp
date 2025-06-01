#include <iostream>
#include <vector>
using namespace std;
int twoSum(vector<int> &v, int target)
{

    for (int i = 0; i < v.size() - 1; i++)
    {
        for (int j = i + 1; j < v.size() - 1; j++)
        {
            if (v[i] + v[j] == target)
            {
                cout << "(" << i << "," << j << ")";
            }
        }
    }
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
    int x = 10;

    int Ans = twoSum(v, x);


    return 0;
}