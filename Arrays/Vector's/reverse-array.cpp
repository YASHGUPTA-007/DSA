#include <iostream>
#include <vector>
using namespace std;
// reverse array in to new array
int ReverseArray(vector<int> v)
{
    vector<int> vcopy(v.size());

    for (int i = 0; i < v.size(); i++)
    {
        int j = v.size() - 1 - i;
        vcopy[i] = v[j];
    };
    cout << "New Array";
    cout << endl;

    for (int i = 0; i < v.size(); i++)
    {
        cout << vcopy[i];
        cout << endl;
    }
}

int main()
{
    vector<int> v;

    v.push_back(1);
    v.push_back(2);
    v.push_back(59);
    v.push_back(3);
    v.push_back(4);
    v.push_back(9);
    int x = 5;

    ReverseArray(v);

    return 0;
}