#include <iostream>
#include <vector>
using namespace std;
// reverse array in to new array
int ReverseArray(vector<int> v)
{
    int j = v.size() - 1;

    for (int i = 0; i < v.size(); i++)
    {
        if (i != j)
        {
            int temp = v[i];
            v[i] = v[j];
            v[j] = temp;
        }
    };
    cout << "New Array";
    cout << endl;

    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i];
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
    cout << "array size " << v.size();

    ReverseArray(v);

    return 0;
}