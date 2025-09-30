#include<iostream>
#include<string>
#include <algorithm>


using namespace std;
int main()
{
    string h = "abcdefghij";

    reverse(h.begin()+3,h.end()-2);

    cout<<"New string : "<<h;
    
     
    return 0;
}