#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> v;

    v.push_back(5);
    v.push_back(5);
    v.push_back(5);
    v.push_back(5);
    v.push_back(4);
    v.push_back(9);
    
    for(int i = 0;i<v.size();i++){
        cout<<v[i];
        cout<<endl;
    }
    v.pop_back();
    for(int i = 0;i<v.size();i++){
        cout<<v[i];
        cout<<endl;
    }

    return 0;
}